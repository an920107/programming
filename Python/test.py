def isPrime(n):
    for i in range(2, n):
        if (n % i == 0): return False
    return True

n = int(input())

for i in range(2, n):
    if (n % i == 0):
        if (isPrime(i)):
            print(i)
