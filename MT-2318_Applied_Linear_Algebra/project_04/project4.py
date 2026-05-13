import numpy as np
from scipy.linalg import lu
from sympy import Matrix
import time

# Task 1: Generate matrix A and vector b
print("Step 1:")
A = np.array([
    [17, 24,  1,  8, 15],
    [23,  5,  7, 14, 16],
    [ 4,  6, 13, 20, 22],
    [10, 12, 19, 21,  3],
    [11, 18, 25,  2,  9]
], dtype=float)

b = np.array([10, 26, 42, 59, 38], dtype=float)

print("A =")
print(A)
print("\nb =", b)

# Task 2: Solve using numpy's built-in solver
print("\nStep 2:")
x = np.linalg.solve(A, b)
print("x =", x)

# Task 3: Compute the residual
print("\nStep 3:")
r = A @ x - b
print("r =", r)

# Task 4: LU Decomposition
print("\nStep 4:")
P, L, U = lu(A)
x1 = np.linalg.solve(U, np.linalg.solve(L, P.T @ b))
r1 = A @ x1 - b
err1 = x - x1
print("x1 =", x1)
print("r1 =", r1)
print("err1 =", err1)

# Task 5: Solving yA = b (equivalent to MATLAB's b'/A)
print("\nStep 5:")
y = np.linalg.solve(A.T, b)
print("y =", y)

# Task 6: Solving using explicit inverse matrix
print("\nStep 6:")
x2 = np.linalg.inv(A) @ b
r2 = A @ x2 - b
err2 = x - x2
print("x2 =", x2)
print("r2 =", r2)
print("err2 =", err2)

# Task 7: Reduced row echelon form
print("\nStep 7:")
augmented = Matrix(np.hstack([A, b.reshape(-1, 1)]))
C, pivot_cols = augmented.rref()
C = np.array(C.tolist(), dtype=float)
x3 = C[:, 5]
err3 = x - x3
r3 = A @ x3 - b
print("x3 =", x3)
print("err3 =", err3)
print("r3 =", r3)

# Task 8: Computational time comparison
print("\nStep 8:")
Num = 100
A_big = np.random.rand(Num, Num) + Num * np.eye(Num)
b_big = np.random.rand(Num)

def numerical_rref(M):
    M = M.copy()
    rows, cols = M.shape
    pivot_row = 0
    for col in range(cols):
        if pivot_row >= rows:  # <-- add this check
            break
        pivot = np.argmax(np.abs(M[pivot_row:, col])) + pivot_row
        if abs(M[pivot, col]) < 1e-10:
            continue
        M[[pivot_row, pivot]] = M[[pivot, pivot_row]]
        M[pivot_row] /= M[pivot_row, col]
        for r in range(rows):
            if r != pivot_row:
                M[r] -= M[r, col] * M[pivot_row]
        pivot_row += 1
    return M

print("Matrix size %d x %d" % (Num, Num))

t0 = time.time()
x1_big = np.linalg.solve(A_big, b_big)
print(f"np.linalg.solve: {time.time() - t0:.4f} seconds")

t0 = time.time()
x2_big = np.linalg.inv(A_big) @ b_big
print(f"np.linalg.inv:   {time.time() - t0:.4f} seconds")

t0 = time.time()
aug = np.hstack([A_big, b_big.reshape(-1,1)])
C_big = numerical_rref(aug)
print(f"rref:            {time.time() - t0:.4f} seconds")

# Task 9: Overdetermined system
print("\nStep 9:")
clear = lambda: None  # no need to clear in Python
A9 = np.array([[1,2,3],[4,5,6],[7,8,10],[9,11,12]], dtype=float)
b9 = np.array([1,2,3,4], dtype=float)

x, residuals, rank, sv = np.linalg.lstsq(A9, b9, rcond=None)
r = A9 @ x - b9
print("x =", x)
print("r =", r)

# Verify via normal equations
y = np.linalg.solve(A9.T @ A9, A9.T @ b9)
err = x - y
print("y =", y)
print("err =", err)

# Task 10: Underdetermined system
print("\nStep 10:")
A10 = np.array([[1,2,3],[4,5,6],[7,8,9],[10,11,12]], dtype=float).T
b10 = np.array([1,3,5], dtype=float)

# Particular solution from lstsq
x, _, _, _ = np.linalg.lstsq(A10, b10, rcond=None)
r1 = A10 @ x - b10
print("x =", x)
print("r1 =", r1)

# Minimum-norm solution via pseudoinverse
y = np.linalg.pinv(A10) @ b10
r2 = A10 @ y - b10
print("y =", y)
print("r2 =", r2)

# Null space (homogeneous solutions)
from scipy.linalg import null_space
N = null_space(A10)
print("Null space basis:\n", N)

# General solution: pick any constants C1, C2
C = np.array([1, 2])
z = N @ C + x
print("z =", z)
print("Verify Az=b:", np.allclose(A10 @ z, b10))
