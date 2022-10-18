from random import randint

DIR = "OJ/tmp/"

f = open(DIR + "out.txt", "w")
t = int(1E6)
f.write(str(t) + "\n")
for i in range(t):
    f.write("%d %d %d\n" % (randint(-1E7, 1E7), randint(-1E7, 1E7), randint(-1E7, 1E7)))