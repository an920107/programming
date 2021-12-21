t = int(input())
for i in range(t):
    sum = 0
    n = int(input())
    if n > 0:
        str = input().split()
        for j in range(n):
            sum += int(str[j]) * (j + 1)
    print(sum)