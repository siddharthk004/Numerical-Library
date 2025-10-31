import math
import matplotlib.pyplot as plt

class DifferentialEquations:
    def __init__(self, func, exact=None):
        """
        func: dy/dx = f(x, y)
        exact: exact solution function y(x) (optional)
        """
        self.func = func
        self.exact = exact

    # Euler method
    def euler(self, x0, y0, h, xn):
        xs, ys = [x0], [y0]
        while x0 < xn:
            y0 = y0 + h * self.func(x0, y0)
            x0 += h
            xs.append(round(x0, 4))
            ys.append(y0)
        return xs, ys

    # Modified Euler / RK2
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

    # RK4 method
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

    # Display table in pure python
    def display_table(self, x0, y0, h, xn):
        x_euler, y_euler = self.euler(x0, y0, h, xn)
        _, y_mod = self.modified_euler(x0, y0, h, xn)
        _, y_rk4 = self.rk4(x0, y0, h, xn)

        print("\n{:<8} {:<12} {:<15} {:<12} {:<12}".format("x", "Euler", "Mod Euler(RK2)", "RK4", "Exact"))
        print("-"*65)

        for i in range(len(x_euler)):
            exact_val = self.exact(x_euler[i]) if self.exact else "-"
            print("{:<8.4f} {:<12.6f} {:<15.6f} {:<12.6f} {:<12}".format(
                x_euler[i],
                y_euler[i],
                y_mod[i],
                y_rk4[i],
                round(exact_val,6) if exact_val != "-" else exact_val
            ))

    # Plot solutions
    def plot_solutions(self, x0, y0, h, xn):
        x_euler, y_euler = self.euler(x0, y0, h, xn)
        _, y_mod = self.modified_euler(x0, y0, h, xn)
        _, y_rk4 = self.rk4(x0, y0, h, xn)
        x_exact = x_euler
        y_exact = [self.exact(x) for x in x_exact] if self.exact else None

        plt.figure(figsize=(10,6))
        plt.plot(x_euler, y_euler, 'r--', label="Euler")
        plt.plot(x_euler, y_mod, 'g-.', label="Modified Euler (RK2)")
        plt.plot(x_euler, y_rk4, 'b-', label="RK4")
        if y_exact:
            plt.plot(x_exact, y_exact, 'k', label="Exact Solution")
        plt.title("Numerical Solutions of ODE")
        plt.xlabel("x")
        plt.ylabel("y")
        plt.legend()
        plt.grid(True)
        plt.show()
        
    def error_vs_h(self, x0, y0, xn):
        """Analyze how the global error behaves with changing step size h."""
        h_values = [0.5, 0.4, 0.3, 0.25, 0.2, 0.15, 0.1, 0.08, 0.05, 0.03, 0.02, 0.01]
        errors = []

        for h in h_values:
            # Euler method computation
            x, y = x0, y0
            while x < xn:
                y = y + h * self.func(x, y)   
                x += h

            exact_val = self.exact(xn)
            error = abs(exact_val - y)
            errors.append(error)

            print(f"h = {h:<6} | Euler y({xn}) = {y:.6f} | Exact = {exact_val:.6f} | Error = {error:.6f}")


        # ---- Plot Error vs h ----
        plt.figure(figsize=(8, 5))
        plt.plot(h_values, errors, 'o-b', linewidth=2, markersize=6)
        plt.xlabel("Step Size (h)")
        plt.ylabel("Global Error |Exact - Euler|")
        plt.title("Error Behavior of Euler Method vs Step Size (h)")
        plt.grid(True)
        plt.gca().invert_xaxis()  # smaller h on right side (error decreases visually)
        plt.show()
