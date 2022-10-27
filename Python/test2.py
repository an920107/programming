from math import gcd

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

line = input().split(' ')
print(solve(Fraction(int(line[0]), int(line[1])), Fraction(int(line[3]), int(line[4])), line[2]))