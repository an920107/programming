from random import randint

DIR = "OJ/tmp/"

def isPrime(n: int) -> bool:
    for i in range(2, n // 2 + 2):
        if n % 2 == 0:
            return False
    return True

def solve(n: int) -> int:
    for i in range(n - 1, 1, -1):
        if isPrime(i):
            return i
    return 2

# for i in range(1, 50):
#     n = randint(4, 1E5)
#     open(DIR + str(i) + ".in", "w").write(str(n))
#     open(DIR + str(i) + ".out", "w").write(str(solve(n)))

print(solve(int(input())))