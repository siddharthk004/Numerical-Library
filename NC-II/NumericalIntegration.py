

class NumericalIntegration:
    def __init__(self, x_points, y_points):
        self.x_points = x_points
        self.y_points = y_points

    def trapezoidal(self):
        n = len(self.x_points)
        h = self.x_points[1] - self.x_points[0]
        res = self.y_points[0] + self.y_points[n - 1]

        i = 1
        while i < n - 1:
            res = res + 2 * self.y_points[i]
            i = i + 1
 
        ans = (h / 2) * res
        return ans

    def simpson_one_third(self):
        n = len(self.x_points)
        # if (n - 1) % 2 != 0:
        #     print("Need even number of intervals")
        h = self.x_points[1] - self.x_points[0]
        res = self.y_points[0] + self.y_points[n - 1]

        i = 1
        while i < n - 1:
            if i % 2 == 0:
                res = res + 2 * self.y_points[i]
            else:
                res = res + 4 * self.y_points[i]
            i = i + 1

        ans = (h / 3) * res
        return ans

    def simpson_three_eighth(self):
        n = len(self.x_points)
        # if (n - 1) % 3 != 0:
        #     print("Need intervals divisible by 3")
        h = self.x_points[1] - self.x_points[0]
        res = self.y_points[0] + self.y_points[n - 1]

        i = 1
        while i < n - 1:
            if i % 3 == 0:
                res = res + 2 * self.y_points[i]
            else:
                res = res + 3 * self.y_points[i]
            i = i + 1

        ans = (3 * h / 8) * res
        return ans
