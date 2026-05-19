import numpy as np

# B3 modified: element [2,3] changed from 12 → 13 to break linear dependence
B3 = np.array([
    [1,  2,  3,  4],
    [5,  6,  7,  8],
    [9, 10, 11, 13]   # 12 → 13
], dtype=float)

print("Matrix B3:")
print(B3)
print()

rank = np.linalg.matrix_rank(B3)
target_dim = B3.shape[0]  # R^3 means dimension 3

print(f"Rank of B3:           {rank}")
print(f"Target dimension (R^n): {target_dim}")
print()

if rank == target_dim:
    print("span(B3) = R^3  →  YES, the columns span R^3")
else:
    print(f"span(B3) ≠ R^3  →  NO, the columns only span a {rank}-dimensional subspace of R^3")

# Show row reduction to make it concrete
print()
print("Row reduction (RREF) to confirm:")
from sympy import Matrix
rref, pivots = Matrix(B3).rref()
print(rref)
print(f"Pivot columns: {pivots}")
print(f"Number of pivots (rank): {len(pivots)}")

# ─────────────────────────────────────────────────────────────
# THEOREM: The columns of A corresponding to leading 1's (pivot
# columns) in the RREF form a basis for col space(A) = span(B3)
# ─────────────────────────────────────────────────────────────
print()
print("=" * 55)
print("THEOREM: Pivot columns of A form a basis for col(A)")
print("=" * 55)

# Step 1 — show RREF and identify pivot columns
print()
print("Step 1: RREF of B3")
print(rref)
print(f"  Leading 1's are in columns: {[p + 1 for p in pivots]} (1-indexed)")

# Step 2 — extract those columns from the ORIGINAL matrix (not RREF)
basis = B3[:, list(pivots)]
print()
print("Step 2: Extract those columns from the ORIGINAL B3")
for i, p in enumerate(pivots):
    print(f"  Col {p+1} (original): {B3[:, p]}")

print()
print("Basis for col(B3):")
print(basis)

# Step 3 — verify they are linearly independent
basis_rank = np.linalg.matrix_rank(basis)
print()
print("Step 3: Verify the basis vectors are linearly independent")
print(f"  Rank of basis matrix: {basis_rank}")
print(f"  Number of basis vectors: {basis.shape[1]}")
if basis_rank == basis.shape[1]:
    print("  → Linearly independent  ✓")
else:
    print("  → NOT linearly independent  ✗")

# Step 4 — verify they span the same space as all columns of B3
print()
print("Step 4: Verify basis spans the same space as all columns of B3")
full_rank  = np.linalg.matrix_rank(B3)
basis_rank2 = np.linalg.matrix_rank(basis)
if full_rank == basis_rank2:
    print(f"  rank(B3) = {full_rank}, rank(basis) = {basis_rank2}  →  same column space  ✓")
else:
    print(f"  rank(B3) = {full_rank}, rank(basis) = {basis_rank2}  →  different spaces  ✗")

print()
print(f"Conclusion: col(B3) is spanned by {len(pivots)} vector(s), "
      f"forming a {len(pivots)}-dimensional subspace of R^{B3.shape[0]}")

# ─────────────────────────────────────────────────────────────
# DEMONSTRATION: Removing the free variable column (col 3)
# leaves exactly the pivot columns — a clean basis for col(B3)
# ─────────────────────────────────────────────────────────────
print()
print("=" * 55)
print("DEMONSTRATION: Remove col 3 (free variable) → basis")
print("=" * 55)

free_cols  = [i for i in range(B3.shape[1]) if i not in pivots]
print(f"\nFree variable column(s) (0-indexed): {free_cols}")
print(f"  Col {free_cols[0]+1} (original): {B3[:, free_cols[0]]}  ← redundant, not in basis")

B3_reduced = np.delete(B3, free_cols, axis=1)
print()
print("B3 after removing col 3:")
print(B3_reduced)

# Check linear independence
reduced_rank = np.linalg.matrix_rank(B3_reduced)
n_cols       = B3_reduced.shape[1]
print()
print(f"Rank of reduced matrix: {reduced_rank}")
print(f"Number of columns:      {n_cols}")

if reduced_rank == n_cols == B3.shape[0]:
    print("\n→ All columns are linearly independent  ✓")
    print("→ Columns span R^3                      ✓")
    print("→ This IS a basis for col(B3)           ✓")

# Confirm with RREF — all columns should now be pivot columns
rref2, pivots2 = Matrix(B3_reduced).rref()
print()
print("RREF of reduced matrix:")
print(rref2)
print(f"Pivot columns: {[p+1 for p in pivots2]} (all columns are pivots — no free variables)")
