s = "aabbbbeeeeffggg"

prev = s[0]
x = 1

for char in s[1:]:
    if char != prev:
        print(f"{prev}{x}", end="")
        prev = char
        x = 1
    else:
        x += 1

print(f"{prev}{x}", end="")