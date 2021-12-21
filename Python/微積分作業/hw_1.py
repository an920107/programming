import pylab
# y = cos(x)^2 / sqrt(max(1, 2x-1))
# 0 <= x <= 10*pi

a = 0
b = 10 * pylab.pi
n = 1001
dx = (b - a) / (n - 1)

xs = [a + i * dx for i in range(n)]
ys = [pylab.cos(x) ** 2 / pylab.sqrt(max(1, 2 * x - 1)) for x in xs]

pylab.plot(xs, ys)
pylab.title("f(x) = cos(x)^2 / sqrt(max(1, 2x-1))")
pylab.xlabel("x")
pylab.ylabel("y")
pylab.xlim(a, b)
pylab.ylim(0, 1)
pylab.grid(axis='both')
pylab.show()
