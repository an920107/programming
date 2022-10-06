from random import randint

DIR = "OJ/tmp/"

class problem:
    n: int
    s: str
    def __init__(self, n: int, s: str) -> None:
        self.n = n
        self.s = s

def solve(n: int, s: str) -> str:
    if (len(s) <= n):
        return s
    return s[:2] + str(len(s) - 3) + s[-1]

def gen_str(length: int) -> str:
    s = ""
    for _ in range(length):
        s += chr(randint(65, 90))
    return s

def gen_problem() -> problem:
    length = randint(1, 100)
    n = randint(5, 100)
    s = gen_str(length)
    return problem(n, s)

for i in range(1, 23):
    p = gen_problem()
    open(DIR + str(i) + ".in", "w").write(str(p.n) + "\n" + p.s)
    open(DIR + str(i) + ".out", "w").write(solve(p.n, p.s))

open(DIR + "23.in", "w").write("5\n" + "A" * 100)
open(DIR + "23.out", "w").write("AA97A")

open(DIR + "24.in", "w").write("5\nA")
open(DIR + "24.out", "w").write("A")

open(DIR + "25.in", "w").write("5\nAAAAA")
open(DIR + "25.out", "w").write("AAAAA")