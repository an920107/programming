from math import sqrt

QUIT_CODE = -100

def is_prime(n: int) -> bool:
    if (n == 1): return False
    if (n == 2): return True
    if (n % 2 == 0): return False
    for i in range(3, int(sqrt(n)) + 1, 2):
        if (n % i == 0): return False
    return True

print("Prime Checker")
while True:
    n = int(input("n = "))
    if (n == QUIT_CODE): break
    print(f"{n} is " + ("" if is_prime(n) else "not ") + "a prime number.")
print("Have a good one!")