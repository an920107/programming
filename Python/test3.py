import random

lst = [x for x in range(2000)]
random.shuffle(lst)
for x in lst:
    print(x, end=" ")
print()