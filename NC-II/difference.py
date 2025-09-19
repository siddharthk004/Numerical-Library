from interpolation import Interpolation

class Difference:
    def __init__(self, x, y):
        self.x_values = x
        self.y_values = y
        self.interp = Interpolation(x, y)

    def forward_difference_table(self):
        n = len(self.y_values)
        diff = [self.y_values[:]]  

        for i in range(1, n):
            col = []
            for j in range(n - i):
                col.append(diff[i - 1][j + 1] - diff[i - 1][j])
            diff.append(col)

        return diff

    def backward_difference_table(self):
        n = len(self.y_values)
        diff = [self.y_values[:]]  

        for i in range(1, n):
            col = []
            for j in range(n - i):
                col.append(diff[i - 1][j + 1] - diff[i - 1][j])
            diff.append(col)

        for i in range(len(diff)):
            diff[i] = diff[i][::-1]
        return diff

    def divided_difference_table(self):
        n = len(self.x_values)
        diff = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n):
            diff[i][0] = self.y_values[i]

        for j in range(1, n):
            col = []
            for i in range(n - j):
                diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (self.x_values[i + j] - self.x_values[i])

        return diff

    def central_difference_table(self):
        n = len(self.y_values)
        diff = [self.y_values[:]]

        for i in range(1, n):
            col = []
            for j in range(n - i):
                col.append(diff[i - 1][j + 1] - diff[i - 1][j])
            diff.append(col)

        return diff
    
    def forward_interpolate(self, x):
        return self.interp.forward(x)

    def backward_interpolate(self, x):
        return self.interp.backward(x)

    def divided_interpolate(self, x):
        return self.interp.divided_difference(x)

    def stirling_interpolate(self, x):
        return self.interp.stirling(x)