import numpy as np

class PowerMethod:
    def __init__(self, matrix, tol=1e-6, max_iter=1000):
        """
        matrix : square numpy array
        tol : convergence tolerance
        max_iter : maximum iterations
        """
        self.A = np.array(matrix, dtype=float)
        self.tol = tol
        self.max_iter = max_iter

    def compute(self, x0=None):
        n = self.A.shape[0]
        if x0 is None:
            x = np.ones(n)
        else:
            x = np.array(x0, dtype=float)

        x = x / np.linalg.norm(x)  # normalize initial vector
        eigenvalue = 0

        for iteration in range(1, self.max_iter+1):
            y = np.dot(self.A, x)
            new_eigenvalue = np.max(np.abs(y))  # approximate dominant eigenvalue
            x = y / np.linalg.norm(y)

            if abs(new_eigenvalue - eigenvalue) < self.tol:
                return new_eigenvalue, x, iteration

            eigenvalue = new_eigenvalue

        print("Warning: Power method did not converge in given iterations")
        return eigenvalue, x, self.max_iter
