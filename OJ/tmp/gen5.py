from random import randint

DIR = "OJ/tmp/"

def solve(x: str, n: int, m: int) -> str:
    num = 0
    for ch in x:
        num *= n
        num += ord(ch) - 48 if ord(ch) <= 57 else ord(ch) - 55
    if num == 0:
        return "0"
    result = ""
    while num > 0:
        result = (chr(num % m + 48) if num % m <= 9 else chr(num % m + 55)) + result
        num //= m
    return result

for i in range(1, 48):
    n = randint(2, 36)
    m = randint(2, 36)
    x = solve(str(randint(1, 1E8)), 10, n)
    open(DIR + str(i) + ".in", "w").write(f"{x}\n{n}\n{m}")
    open(DIR + str(i) + ".out", "w").write(solve(x, n, m))

open(DIR + "48.in", "w").write(f"ZZZZZ\n36\n36")
open(DIR + "48.out", "w").write(solve("ZZZZZ", 36, 36))

open(DIR + "49.in", "w").write(f"100000000\n10\n36")
open(DIR + "49.out", "w").write(solve("100000000", 10, 36))

open(DIR + "50.in", "w").write(f"0\n10\n36")
open(DIR + "50.out", "w").write(solve("0", 10, 36))