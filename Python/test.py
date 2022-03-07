from cmath import log
import pylab

for i in range(2, 20):
    print(i, end = "")
    print("\t", end = "")
    print(log(i) / i)