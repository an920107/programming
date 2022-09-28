from random import randint

DIR = "OJ/tmp/"

def solve(n:int) -> bool:
    return False if n % 2 == 1 or n < 4 else True

for f in range(1, 101):
    open(DIR + str(f) + ".in", "w").write(str(f))
    open(DIR + str(f) + ".out", "w").write("YES" if solve(f) else "NO")