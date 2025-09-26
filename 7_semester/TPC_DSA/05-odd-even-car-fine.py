arr = [5, 2, 3, 7]
d = 12
x = 200

def func(arr, d, cost):
    res = 0

    even = 1 if d % 2 == 0 else 0
    for x in arr:
        if even:
            if x % 2 != 0:  res += 1
        else:
            if x % 2 == 0:  res += 1

    return res * cost

print(func(arr, d, x))