import dis


def f1(x):
    return x // 4


def f2(x):
    return x >> 2


def f3(x):
    return x / 4


dis.dis(f1)
dis.dis(f2)
dis.dis(f3)
