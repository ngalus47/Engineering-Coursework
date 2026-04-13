import numpy as np

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

lengthA = max(A.shape)
lengthB = len(B)

print("lengthA =", lengthA)
print("lengthB =", lengthB)

C = np.vstack((A, B))

print("C =")
print(C)

D = C[1:4, 2:4]

print("D =")
print(D)

E = D.T

print("E =")
print(E)

m, n = E.shape

print("m =", m)
print("n =", n)

x = np.linspace(0, 2*np.pi, 50)

print("x =")
print(x)

col_max = np.max(A, axis=0)
col_min = np.min(A, axis=0)

print("Column max =", col_max)
print("Column min =", col_min)

row_max = np.max(A, axis=1)
row_min = np.min(A, axis=1)

overall_max = np.max(A)
overall_min = np.min(A)

print("Row max =", row_max)
print("Row min =", row_min)
print("Overall max =", overall_max)
print("Overall min =", overall_min)

meancolA = np.mean(A, axis=0)
meanrowA = np.mean(A, axis=1)

sumcolA = np.sum(A, axis=0)
sumrowA = np.sum(A, axis=1)

meanA = np.mean(A)
sumA = np.sum(A)

print("Column mean =", meancolA)
print("Row mean =", meanrowA)
print("Column sum =", sumcolA)
print("Row sum =", sumrowA)
print("Overall mean =", meanA)
print("Overall sum =", sumA)

F = np.random.randint(1, 10, (3, 4))
G = np.random.randint(1, 10, (3, 4))

print("F =")
print(F)
print("\nG =")
print(G)

scalar_mult = 2 * F
addFG = F + G
subFG = F - G
elem_mult = F * G

print("2F =")
print(scalar_mult)

print("\nF + G =")
print(addFG)

print("\nF - G =")
print(subFG)

print("\nElementwise F * G =")
print(elem_mult)

print("F shape =", F.shape)
print("A shape =", A.shape)

H = F @ A.T

print("H =")
print(H)

F = np.random.randint(-4, 5, (5, 3))
G = np.random.randint(-4, 5, (5, 3))

print("F =")
print(F)
print("\nG =")
print(G)

sizeF = F.shape
sizeA = A.shape

print("\nsizeF =", sizeF)
print("sizeA =", sizeA)

H = F @ A

print("\nH =")
print(H)

I = np.eye(3)

print("I =")
print(I)

Z = np.zeros((3, 4))
O = np.ones((2, 4))

print("Z =")
print(Z)

print("\nO =")
print(O)

D_diag = np.diag([1, 2, 7])

print("D_diag =")
print(D_diag)

M = np.random.randint(1, 10, (6, 6))

diag_entries = np.diag(M)

print("M =")
print(M)

print("\nDiagonal entries =")
print(diag_entries)

n = 6

main_diag = 2 * np.ones(n)
upper_diag = -1 * np.ones(n - 1)
lower_diag = -1 * np.ones(n - 1)

T = np.diag(main_diag) + np.diag(upper_diag, 1) + np.diag(lower_diag, -1)

print("T =")
print(T)
