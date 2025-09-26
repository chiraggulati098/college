arr = [1,0,2,0,1,0,2]

def func(arr):
    l, r = 0, len(arr) - 1

    for i in range(len(arr)):
        if arr[i] == 1:     continue
        if arr[i] == 0:
            arr[i], arr[l] = arr[l], arr[i]
            l += 1
        else:
            arr[i], arr[r] = arr[r], arr[i]
            r -= 1

    return arr

print(func(arr))