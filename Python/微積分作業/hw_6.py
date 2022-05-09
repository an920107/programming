from sympy import *

x = Symbol("x")
y = cos(x)**3

_y = y
for i in range(3):
    _y = Derivative(_y, x)
    pprint(_y)
    _y = _y.doit().expand()
    print("=", _y, end="\n\n")

for i in range(3):
    _y = Integral(_y, x)
    pprint(_y)
    _y = _y.doit().expand()
    print("=", _y, end="\n\n")