
class Interpolation:

    def lagrange(self, x_points, y_points, x):
        n = len(x_points)
        res = 0
        i = 0
        while i < n:
            term = y_points[i]
            j = 0
            while j < n:
                if j != i:
                    term = term * (x - x_points[j]) / (x_points[i] - x_points[j])
                j = j + 1
            res = res + term
            i = i + 1
        return res

    def backward(self, x_points, y_points, x) :
        n = len(x_points)
        h = x_points[1] - x_points[0]

        diff = []
        diff.append(y_points[:])
        i = 1
        while i < n:
            row = []
            j = 0
            while j < n - i:
                val = diff[i - 1][j + 1] - diff[i - 1][j]
                row.append(val)
                j = j + 1
            diff.append(row)
            i = i + 1

        u = (x - x_points[n - 1]) / h
        res = y_points[n - 1]
        uterm = 1
        fact = 1
        i = 1
        while i < n:
            uterm = uterm * (u + (i - 1))
            fact = fact * i
            res = res + (uterm * diff[i][len(diff[i]) - 1]) / fact
            i = i + 1
        return res

    def forward(self, x_points, y_points, x):
        n = len(x_points)
        h = x_points[1] - x_points[0]

        diff = []
        diff.append(y_points[:])
        i = 1
        while i < n:
            row = []
            j = 0
            while j < n - i:
                val = diff[i - 1][j + 1] - diff[i - 1][j]
                row.append(val)
                j = j + 1
            diff.append(row)
            i = i + 1

        u = (x - x_points[0]) / h
        res = y_points[0]
        uterm = 1
        fact = 1
        i = 1
        while i < n:
            uterm = uterm * (u - (i - 1))
            fact = fact * i
            res = res + (uterm * diff[i][0]) / fact
            i = i + 1
        return res
    
    