# C(m, n)
def C(m, n):
    result = 1
    for i in range(n):
        result *= m - i
    for i in range(n):
        result //= n - i
    return result

print(C(int(input()), int(input())))