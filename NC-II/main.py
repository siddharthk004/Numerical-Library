
########################################
# Name :- Siddharth Satish Kardile     #
# Numerical-II Library in PY           #
########################################

from interpolation import Interpolation
from NumericalIntegration import NumericalIntegration

########################
#    Interpolation     #
########################
print("---------------------------------------------------")

x_pts = [-2,0,2]
y_pts = [4,2,3]

interp = Interpolation(x_pts, y_pts)

x = float(input("Enter X: "))

print("---------------------------------------------------")

print("Lagrange interpolation:", interp.lagrange(x))
print("Forward interpolation:", interp.forward(x))
print("Backward interpolation:", interp.backward(x))
print("Stirling interpolation:", interp.stirling(x))
print("Newton Divided Difference:", interp.divided_difference(x))

print("---------------------------------------------------")

##############################
#   Numerical Integration    #
##############################

x_points = [0,1,2,3]
y_points = [0,1,4,9]

ni = NumericalIntegration(x_points, y_points)

print("Trapezoidal:", ni.trapezoidal())
print("Simpson 1/3:", ni.simpson_one_third())
print("Simpson 3/8:", ni.simpson_three_eighth())

print("---------------------------------------------------")
