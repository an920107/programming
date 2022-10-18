step = 0

def foo(n: int):
    global step
    if (n == 1): return
    if (n % 2 == 0):
        print("%d is even, so I take half: " % (n), end= "")
        n //= 2
    else:
        print("%d is odd, so I make 3n + 1: " % (n), end= "")
        n = n * 3 + 1
    print(n)
    step += 1
    foo(n)


print("Hailstone Sequence")
n = int(input("Enter an Integer: "))
foo(n)
print("It took %d steps to reach 1" % (step))