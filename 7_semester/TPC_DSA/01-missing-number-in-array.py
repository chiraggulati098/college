# missing number

arr = [1,2,3,4,5,6,8,9]
n = len(arr)

arr = set(arr)
for i in range(1, n+2):
    if i not in arr:
        print(i)
        break