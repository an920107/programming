from numpy import double, void
import pylab

pylab.figure(figsize = (12, 6))
lower = 0
upper = 10
n = 1001
dx = (upper - lower) / (n - 1)

def mul(k) -> double:
    res = 1
    for i in range(k):
        res *= i + 1
    return res

def foo(x, k) -> double:
    res = 0
    for i in range(k):
        res += ((-1) ** i) * (x ** (i + 1)) / mul(i)
    return res


xs = [lower + i * dx for i in range(n)]
for i in range(1, 21):
    ys = [foo(x, i) for x in xs]
    pylab.plot(xs, ys, label = "P" + str(i))

ys = [x * pylab.exp(-x) for x in xs]
pylab.plot(xs, ys, label = "x exp(-x)")

pylab.title("Taylor polynomials with different orders for x exp(-x)")
pylab.xlabel("x")
pylab.ylabel("y")
pylab.legend()
pylab.xlim(lower, upper)
pylab.ylim(-2, 3)
pylab.grid(axis='both')
pylab.show()
