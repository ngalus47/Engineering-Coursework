import numpy as np

# Step 1: Create matrices A and B
A = np.array([
    [1, 2, -10, 4],
    [3, 4, 5, -6],
    [3, 3, -2, 5]
])

B = np.array([3, 3, 4, 2])

print("A =")
print(A)
print("\nB =")
print(B)

# Step 2: Find lengths
lengthA = max(A.shape)
lengthB = len(B)

print("\nlengthA =", lengthA)
print("lengthB =", lengthB)

# Step 3: Add B as the fourth row of A to create C
C = np.vstack((A, B))

print("\nC =")
print(C)

# Step 4: Extract rows 2 to 4 and columns 3 to 4 from C to create D
D = C[1:4, 2:4]

print("\nD =")
print(D)

# Step 5: Transpose D to create E
E = D.T

print("\nE =")
print(E)

# Step 6: Find the size of E
m, n = E.shape

print("\nm =", m)
print("n =", n)

# Step 7: Create equally spaced values from 0 to 2*pi
x = np.linspace(0, 2*np.pi, 50)

print("\nx =")
print(x)

# Step 8: Column max and min of A
col_max = np.max(A, axis=0)
col_min = np.min(A, axis=0)

print("\nColumn max =", col_max)
print("Column min =", col_min)

# Step 9: Row max and min, overall max and min
row_max = np.max(A, axis=1)
row_min = np.min(A, axis=1)
overall_max = np.max(A)
overall_min = np.min(A)

print("\nRow max =", row_max)
print("Row min =", row_min)
print("Overall max =", overall_max)
print("Overall min =", overall_min)

# Step 10: Means and sums
meancolA = np.mean(A, axis=0)
meanrowA = np.mean(A, axis=1)
sumcolA = np.sum(A, axis=0)
sumrowA = np.sum(A, axis=1)
meanA = np.mean(A)
sumA = np.sum(A)

print("\nColumn mean =", meancolA)
print("Row mean =", meanrowA)
print("Column sum =", sumcolA)
print("Row sum =", sumrowA)
print("Overall mean =", meanA)
print("Overall sum =", sumA)

# Step 11: Random integer matrices F and G, size 5x3, values from -4 to 4
F = np.random.randint(-4, 5, (5, 3))
G = np.random.randint(-4, 5, (5, 3))

print("\nF =")
print(F)
print("\nG =")
print(G)

# Step 12: Operations on F and G
ScMultF = 0.4 * F
SumFG = F + G
DiffFG = F - G
ElProdFG = F * G

print("\n0.4 * F =")
print(ScMultF)
print("\nF + G =")
print(SumFG)
print("\nF - G =")
print(DiffFG)
print("\nElementwise F * G =")
print(ElProdFG)

# Step 13: Sizes of F and A
sizeF = F.shape
sizeA = A.shape

print("\nsizeF =", sizeF)
print("sizeA =", sizeA)

# Step 14: Matrix multiplication H = F * A
H = F @ A

print("\nH =")
print(H)

# Step 15: Identity matrix
I = np.eye(3)

print("\nI =")
print(I)

# Step 16: Zero and one matrices
Z = np.zeros((3, 4))
O = np.ones((2, 4))

print("\nZ =")
print(Z)
print("\nO =")
print(O)

# Step 17: Diagonal matrix with entries 1, 2, 7
D_diag = np.diag([1, 2, 7])

print("\nD_diag =")
print(D_diag)

# Step 18: Random 6x6 matrix and its diagonal entries
M = np.random.randint(1, 10, (6, 6))
diag_entries = np.diag(M)

print("\nM =")
print(M)
print("\nDiagonal entries =")
print(diag_entries)

# Step 19: Tridiagonal matrix
n = 6
main_diag = 2 * np.ones(n)
upper_diag = -1 * np.ones(n - 1)
lower_diag = -1 * np.ones(n - 1)

T = np.diag(main_diag) + np.diag(upper_diag, 1) + np.diag(lower_diag, -1)

print("\nT =")
print(T)
