num = int(input())
prime = [2]
for i in range(2, num):
    if i not in prime:
        for x in prime:
            if i % x == 0:
                continue
        prime.append(i)
print(prime[-1])