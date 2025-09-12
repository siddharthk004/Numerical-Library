class Interpolation:

    def __init__(self, x_points, y_points):
        self.x_points = x_points
        self.y_points = y_points

    def lagrange(self, x):
        n = len(self.x_points)
        res = 0
        i = 0
        while i < n:
            term = self.y_points[i]
            j = 0
            while j < n:
                if j != i:
                    term = term * (x - self.x_points[j]) / (self.x_points[i] - self.x_points[j])
                j = j + 1
            res = res + term
            i = i + 1
        return res

    def forward(self, x):
        n = len(self.x_points)
        h = self.x_points[1] - self.x_points[0]

        diff = []
        diff.append(self.y_points[:])
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

        u = (x - self.x_points[0]) / h
        res = self.y_points[0]
        uterm = 1
        fact = 1
        i = 1
        while i < n:
            uterm = uterm * (u - (i - 1))
            fact = fact * i
            res = res + (uterm * diff[i][0]) / fact
            i = i + 1
        return res

    def backward(self, x):
        n = len(self.x_points)
        h = self.x_points[1] - self.x_points[0]

        diff = []
        diff.append(self.y_points[:])
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

        u = (x - self.x_points[n - 1]) / h
        res = self.y_points[n - 1]
        uterm = 1
        fact = 1
        i = 1
        while i < n:
            uterm = uterm * (u + (i - 1))
            fact = fact * i
            res = res + (uterm * diff[i][-1]) / fact
            i = i + 1
        return res

    def stirling(self, x):
        n = len(self.x_points)
        h = self.x_points[1] - self.x_points[0]

        diff = []
        diff.append(self.y_points[:])
        i = 1
        while i < n:
            row = []
            j = 0
            while j < n - i:
                row.append(diff[i - 1][j + 1] - diff[i - 1][j])
                j = j + 1
            diff.append(row)
            i = i + 1

        mid = n // 2
        x0 = self.x_points[mid]
        u = (x - x0) / h

        res = self.y_points[mid]
        if mid - 1 >= 0:
            res = res + u * (diff[1][mid] + diff[1][mid - 1]) / 2

        uterm = 1
        fact = 1
        i = 2
        while i < n:
            if i % 2 == 0:
                fact = fact * i
                uterm = uterm * (u ** 2 - (i // 2 - 1) ** 2)
                res = res + (uterm * diff[i][mid - i // 2]) / fact
            else:
                fact = fact * i
                uterm = u * (u ** 2 - (i // 2) ** 2)
                avg = (diff[i][mid - (i + 1)//2] + diff[i][mid - (i - 1)//2]) / 2
                res = res + (uterm * avg) / fact
            i = i + 1
        return res

    def divided_difference(self, x):
        n = len(self.x_points)
        diff = []
        for i in range(n):
            row = [0] * n
            diff.append(row)
        i = 0
        while i < n:
            diff[i][0] = self.y_points[i]
            i = i + 1

        j = 1
        while j < n:
            i = 0
            while i < n - j:
                diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (self.x_points[i + j] - self.x_points[i])
                i = i + 1
            j = j + 1

        res = diff[0][0]
        term = 1
        j = 1
        while j < n:
            term = term * (x - self.x_points[j - 1])
            res = res + diff[0][j] * term
            j = j + 1
        return res
