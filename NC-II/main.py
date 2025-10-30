
########################################
# Name :- Siddharth Satish Kardile     #
# Numerical-II Library in PY           #
########################################

from interpolation import Interpolation
from NumericalIntegration import NumericalIntegration
from difference import Difference
from differencial_equations import DifferentialEquations
from power_method import PowerMethod
import numpy as np
import math


########################
#    Interpolation     #
########################
print("---------------------------------------------------")
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
print("---------------------------------------------------")

##############################
#     Difference Formula     #
##############################

x_points = [0,1,2,3]
y_points = [0,1,4,9]

d = Difference(x_points, y_points)
x = float(input("Enter value of x: "))

print("\nForward difference table:")
for col in d.forward_difference_table():
    print(col)
print("f(x) Forward:", d.forward_interpolate(x))

print("\nBackward difference table:")
for col in d.backward_difference_table():
    print(col)
print("f(x) Backward:", d.backward_interpolate(x))

print("\nDivided difference table:")
for col in d.divided_difference_table():
    print(col)
print("f(x) Divided:", d.divided_interpolate(x))

# odd points
x_points = [0,1,2,3,4]
y_points = [0,1,4,9,16]
d = Difference(x_points, y_points)

print("\n Strling Central difference table:")
for col in d.strling_central_difference_table():
    print(col)
print("f(x) Stirling:", d.stirling_interpolate(x))

print("---------------------------------------------------")
print("---------------------------------------------------")

#################################
# Differential Equation Methods #
#################################

def f(x, y):
    return x + y

def exact(x):
    return 2 * math.exp(x) - x - 1

de = DifferentialEquations(f, exact)

x0 = 0
y0 = 1
xn = 1
h = 0.1

print("\n------- Differential Equation Solutions -------")
de.display_table(x0, y0, h, xn)

# Plot solutions
de.plot_solutions(x0, y0, h, xn)
print("---------------------------------------------------")
print("---------------------------------------------------")

# find h and Error then print both line when h decreases then error behaves 

# array that store h and error 
# Error = Euler method - Exact Solution

#################################
#         Power Methods         #
#################################

A = np.array([[4, 1, 1],
              [2, 3, 1],
              [1, 1, 2]])

pm = PowerMethod(A, tol=1e-6, max_iter=100)
eigenvalue, eigenvector, iterations = pm.compute()

print("Dominant Eigenvalue:", eigenvalue)
print("Corresponding Eigenvector:", eigenvector)
print("Iterations taken:", iterations)

print("---------------------------------------------------")
print("---------------------------------------------------")
