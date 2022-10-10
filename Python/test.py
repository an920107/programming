def foo(x, y, t):
    if x > 1E20:
        return
    print("%2d: %-20d" % (t, x))
    foo(y, x + y, t + 1)

foo(1, 1, 1)

