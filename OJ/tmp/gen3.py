from random import randint

DIR = "OJ/tmp/"

def isPrime(n: int) -> bool:
    if n == 2: return True
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0: return False
    return True

def solve(n: int) -> int:
    for i in range(n - 1, 1, -1):
        if isPrime(i): return i
    return 2

for i in range(1, 50):
    n = randint(4, 1E4)
    open(DIR + str(i) + ".in", "w").write(str(n))
    open(DIR + str(i) + ".out", "w").write(str(solve(n)))

open(DIR + str(50) + ".in", "w").write("3")
open(DIR + str(50) + ".out", "w").write("2")

# for i in range(3, 100):
#     print(i, solve(i))
