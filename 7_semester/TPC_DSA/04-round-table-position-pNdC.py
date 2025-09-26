n = 4   # number of people

def factorial(n):
    if n <= 1:  return 1
    else:       return n * factorial(n - 1)

def func(n):
    return 2 * factorial(n - 1)

print(func(n))