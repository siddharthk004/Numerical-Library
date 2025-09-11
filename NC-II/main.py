
########################################
# Name :- Siddharth Satish Kardile     #
# Numerical-II Library in PY           #
########################################

from interpolation import Interpolation

########################
#    Interpolation     #
########################
 
interp = Interpolation()

# Langranges Interpolation
x_pts = [-2,0,2]
y_pts = [4,2,3]
x = float(input("Enter Value of X for lagrange interplation: "))
print("Lagrange at :", interp.lagrange(x_pts, y_pts, x))

# Forward Interpolation
x_pts = [-2,0,1,2]
y_pts = [1,1,4,17]
x = float(input("Enter Value of X for forward interpolation: "))
print("Forward at :", interp.forward(x_pts, y_pts, x))

# Backward Interpolation
x_pts = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6]
y_pts = [7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031]
x = float(input("Enter Value of X for Backward interpolation: "))
print("Backward at :", interp.backward(x_pts, y_pts, x))

# Strling Interpolation

# Divided Difference Interpolation

##############################
#   Numerical Integration    #
##############################
