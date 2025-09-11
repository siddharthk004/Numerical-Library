from interpolation import Interpolation


interp = Interpolation()


x_points = [-2,0,2]
y_points = [4,2,3]
x = 2
print("Lagrange at :", interp.lagrange(x_points, y_points, x))

x_points = [-2,0,1,2]
y_points = [1,1,4,17]
x = 1
print("Forward at :", interp.forward(x_points, y_points, x))

x_points = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6]
y_points = [7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031]
x = 1.2
print("Backward at :", interp.backward(x_points, y_points, x))
