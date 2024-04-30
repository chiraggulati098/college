import sys

def MatrixChainOrder(p, i, j):
    if i == j:
        return 0

    _min = sys.maxsize

    for k in range(i, j):
        count = (MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i-1] * p[k] * p[j])
        _min = min(_min, count)

    return _min

arr = [1, 2, 3, 4, 3]
print("Minimum number of multiplications is",
MatrixChainOrder(arr, 1, len(arr)-1))