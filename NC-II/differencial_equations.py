import math
from prettytable import PrettyTable  

class DifferentialEquations:
    def __init__(self, func, exact=None):
        self.func = func
        self.exact = exact

    def euler(self, x0, y0, h, xn):
        xs, ys = [x0], [y0]
        while x0 < xn:
            y0 = y0 + h * self.func(x0, y0)
            x0 += h
            xs.append(round(x0, 4))
            ys.append(y0)
        return xs, ys

    def modified_euler(self, x0, y0, h, xn):
        xs, ys = [x0], [y0]
        while x0 < xn:
            k1 = self.func(x0, y0)
            k2 = self.func(x0 + h, y0 + h * k1)
            y0 = y0 + (h / 2) * (k1 + k2)
            x0 += h
            xs.append(round(x0, 4))
            ys.append(y0)
        return xs, ys

    def rk4(self, x0, y0, h, xn):
        xs, ys = [x0], [y0]
        while x0 < xn:
            k1 = self.func(x0, y0)
            k2 = self.func(x0 + h / 2, y0 + (h / 2) * k1)
            k3 = self.func(x0 + h / 2, y0 + (h / 2) * k2)
            k4 = self.func(x0 + h, y0 + h * k3)
            y0 = y0 + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
            x0 += h
            xs.append(round(x0, 4))
            ys.append(y0)
        return xs, ys

    def display_table(self, x0, y0, h, xn):
        x_euler, y_euler = self.euler(x0, y0, h, xn)
        x_mod, y_mod = self.modified_euler(x0, y0, h, xn)
        x_rk4, y_rk4 = self.rk4(x0, y0, h, xn)

        table = PrettyTable(["x", "Euler", "Mod Euler (RK2)", "RK4", "Exact Sol"])

        for i in range(len(x_euler)):
            exact_val = self.exact(x_euler[i]) if self.exact else "-"
            table.add_row([
                round(x_euler[i], 4),
                round(y_euler[i], 6),
                round(y_mod[i], 6),
                round(y_rk4[i], 6),
                round(exact_val, 6) if exact_val != "-" else "-"
            ])
        print(table)
