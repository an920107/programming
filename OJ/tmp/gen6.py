from math import gcd
from random import randint

DIR = "OJ/tmp/"

class Fraction:
    def __init__(self, p: int, q: int) -> None:
        self.p = p
        self.q = q

    def __str__(self) -> str:
        return str(self.p) + " " + str(self.q)

    def __reduce(self):
        __gcd = gcd(self.p, self.q)
        self.p //= __gcd
        self.q //= __gcd
        return self 

    def __add__(self, obj):
        self.p = self.p * obj.q + obj.p * self.q
        self.q = self.q * obj.q
        return self.__reduce()

    def __sub__(self, obj):
        self.p = self.p * obj.q - obj.p * self.q
        self.q = self.q * obj.q
        if self.p == 0:
            return Fraction(0, 1)
        return self.__reduce()

    def __mul__(self, obj):
        self.p *= obj.p
        self.q *= obj.q
        return self.__reduce()

    def __truediv__(self, obj):
        self.p *= obj.q
        self.q *= obj.p
        return self.__reduce()
    
    def __gt__(self, obj):
        return self.p * obj.q > obj.p * self.q

def solve(f1: Fraction, f2: Fraction, c: str) -> Fraction:
    if c == '+': return f1 + f2
    if c == '-': return f1 - f2
    if c == '*': return f1 * f2
    if c == '/': return f1 / f2
    return None


OPERATOR = "+-*/"
for i in range(1, 47):
    while True:
        f1 = Fraction(randint(1, 1E4), randint(1, 1E4))
        f2 = Fraction(randint(1, 1E4), randint(1, 1E4))
        if f1 > f2: break
    c = OPERATOR[randint(0, len(OPERATOR) - 1)]
    open(DIR + str(i) + ".in", "w").write(str(f1) + f" {c} " + str(f2))
    open(DIR + str(i) + ".out", "w").write(str(solve(f1, f2, c)))

f1 = Fraction(1, 1)
f2 = Fraction(1, 1)
c = '+'
open(DIR + str(47) + ".in", "w").write(str(f1) + f" {c} " + str(f2))
open(DIR + str(47) + ".out", "w").write(str(solve(f1, f2, c)))

f1 = Fraction(1, 1)
f2 = Fraction(1, 1)
c = '-'
open(DIR + str(48) + ".in", "w").write(str(f1) + f" {c} " + str(f2))
open(DIR + str(48) + ".out", "w").write(str(solve(f1, f2, c)))

f1 = Fraction(1, 1)
f2 = Fraction(1, 1)
c = '*'
open(DIR + str(49) + ".in", "w").write(str(f1) + f" {c} " + str(f2))
open(DIR + str(49) + ".out", "w").write(str(solve(f1, f2, c)))

f1 = Fraction(1, 1)
f2 = Fraction(1, 1)
c = '/'
open(DIR + str(50) + ".in", "w").write(str(f1) + f" {c} " + str(f2))
open(DIR + str(50) + ".out", "w").write(str(solve(f1, f2, c)))