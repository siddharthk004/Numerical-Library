########################################
# Name :- Siddharth Satish Kardile     #
# NDVI Central Difference Analysis     #
########################################

from pystac_client import Client
import planetary_computer
import geopandas as gpd
import rasterio
import numpy as np
from datetime import datetime
import pandas as pd
import matplotlib.pyplot as plt
from shapely.geometry import box

# --- Step 1: Define region (example: around Pune, India) ---
# bounding box: minx, miny, maxx, maxy (lon/lat)
bbox = box(73.7, 18.3, 74.0, 18.7)  # approx. Pune region
aoi = gpd.GeoDataFrame([1], geometry=[bbox], crs="EPSG:4326")

# --- Step 2: Connect to MODIS NDVI collection ---
catalog = Client.open("https://planetarycomputer.microsoft.com/api/stac/v1")
collection = "modis-13Q1-061"  # MOD13Q1 v6.1
search = catalog.search(
    collections=[collection],
    intersects=aoi.geometry[0],
    datetime="2024-01-01/2024-12-31",
)
items = list(search.get_items())
print(f"Found {len(items)} scenes")
# After: items = list(search.get_items())
# print(f"Found {len(items)} scenes")

# # Add this debug block:
# if len(items) > 0:
#     print("Available asset keys in the first item:")
#     print(list(items[0].assets.keys()))
#     print("Collection ID:", items[0].collection_id)
#     exit()

# --- Step 3: Read NDVI values for each date ---
records = []
for item in items:
    signed_asset = planetary_computer.sign(item.assets["250m_16_days_NDVI"])

    with rasterio.open(signed_asset.href) as src:
        ndvi = src.read(1).astype("float32")
        ndvi[ndvi == src.nodata] = np.nan
        ndvi *= 0.0001  # scale factor
        mean_ndvi = np.nanmean(ndvi)

        # ---- FIXED DATE HANDLING ----
        # Some items lack item.datetime, so fall back to start_datetime
        if item.datetime:
            date = item.datetime.date()
        else:
            # parse from properties if needed
            date_str = item.properties.get("start_datetime") or item.properties.get("end_datetime")
            date = datetime.fromisoformat(date_str).date()

        records.append({"Date": date, "NDVI": mean_ndvi})

# --- Step 4: Build DataFrame ---
df = pd.DataFrame(records).sort_values("Date")
df["Days"] = (df["Date"] - df["Date"].min()).dt.days
print(df.head())

# --- Step 5: Interpolate missing values ---
df["NDVI"] = df["NDVI"].interpolate()

# --- Step 6: Compute Central Difference ---
df["dNDVI_dt"] = np.gradient(df["NDVI"], df["Days"])

# --- Step 7: Plot ---
plt.figure(figsize=(8,5))
plt.plot(df["Date"], df["NDVI"], "o-", label="NDVI")
plt.plot(df["Date"], df["dNDVI_dt"], "s--", label="dNDVI/dt (Central Difference)")
plt.xlabel("Date"); plt.ylabel("NDVI / Rate")
plt.title("NDVI Trend and Rate of Change - Pune Region (MOD13Q1)")
plt.legend(); plt.grid(True)
plt.show()

# --- Step 8: Save results ---
df.to_csv("VegetationData/NDVI_Pune_2024.csv", index=False)
print("Saved: VegetationData/NDVI_Pune_2024.csv")
