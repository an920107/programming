from random import randint


DIR = "OJ/tmp/"


def solve(n: int, file) -> None:
    if (n % 2 == 0):
        n //= 2
    else:
        n = n * 3 + 1
    file.write(str(n) + "\n")
    if n == 1: return
    solve(n, file)


for i in range(1, 19):
    rnd = randint(1E3, 1E6)
    open(DIR + str(i) + ".in", "w").write(str(rnd))
    f = open(DIR + str(i) + ".out", "w")
    solve(rnd, file= f)
    f.close()

rnd = 2
open(DIR + "19.in", "w").write(str(rnd))
f = open(DIR + "19.out", "w")
solve(rnd, file= f)
f.close()

rnd = 3
open(DIR + "20.in", "w").write(str(rnd))
f = open(DIR + "20.out", "w")
solve(rnd, file= f)
f.close()
