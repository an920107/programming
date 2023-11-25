import multiprocessing
import math

def run():
    x = 1
    while True:
        print(x)
        x *= 1.00000001
        if x > 2:
            x = math.sqrt(x)

l = [multiprocessing.Process(target=run) for _ in range(100)]
for p in l:
    p.start()

for p in l:
    p.join()