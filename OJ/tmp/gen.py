from random import randint


DIR = "OJ/tmp/"

for i in range(1, 16):
    open(DIR + str(i) + ".in", "w").write(str(i))
    open(DIR + str(i) + ".out", "w").write("*" * i)

for i in range(16, 26):
    rnd = randint(100, 9999)
    open(DIR + str(i) + ".in", "w").write(str(rnd))
    open(DIR + str(i) + ".out", "w").write("*" * rnd)