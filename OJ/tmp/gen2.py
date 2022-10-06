from random import randint
import string

DIR = "OJ/tmp/"
CH_COLLECTION = string.ascii_letters + string.digits + " "

def solve(s: str, n: int, u: int, l: int) -> str:
    new_s = ""
    for ch in s:
        ch_ord = ord(ch)
        if 48 <= ch_ord <= 57:
            ch_ord += n
            if ch_ord < 48: ch_ord += 10
            elif ch_ord > 57: ch_ord -= 10
        elif 65 <= ch_ord <= 90:
            ch_ord += u
            if ch_ord < 65: ch_ord += 26
            elif ch_ord > 90: ch_ord -= 26
        elif 97 <= ch_ord <= 122:
            ch_ord += l
            if ch_ord < 97: ch_ord += 26
            elif ch_ord > 122: ch_ord -= 26
        new_s += chr(ch_ord)
    return new_s

def gen_str() -> str:
    length = randint(1, 10000)
    s = ""
    for _ in range(length):
        s += CH_COLLECTION[randint(0, len(CH_COLLECTION) - 1)]
    return s

for i in range(1, 50):
    s = gen_str()
    n = randint(-10, 10)
    u = randint(-26, 26)
    l = randint(-26, 26)
    open(DIR + str(i) + ".in", "w").write("%s\n%d %d %d" % (s, n, u, l))
    open(DIR + str(i) + ".out", "w").write(solve(s, n, u, l))

open(DIR + "50.in", "w").write(" \n0 0 0")
open(DIR + "50.out", "w").write(" ")
