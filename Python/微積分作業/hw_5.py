import pylab

pylab.figure(figsize=(9, 9))

lower = 0
upper = pylab.pi * 14
n = 10001
dx = (upper - lower) / n

xs = [lower + i * dx for i in range(n)]
rs = [pylab.sin(x * 8 / 7) for x in xs]

pylab.polar(xs, rs)

pylab.title("r = sin(x * 8 / 7)", color="red")
pylab.show()