arr = [4,5,0,1,9,0,5,0]

def func(arr):
	j = 0
	i = 0

	while i < len(arr):
		if arr[i] == 0:
			i += 1
		else:
			arr[i], arr[j] = arr[j], arr[i]
			i += 1
			j += 1
	
	return arr

print(func(arr))