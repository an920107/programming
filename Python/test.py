from random import randint
import string


STR1 = string.digits
STR2 = "+-*/"

for _ in range(50):
    print(STR1[randint(0, len(STR1) - 1)], end= "")
    print(STR2[randint(0, len(STR2) - 1)], end= "")

print(STR1[randint(0, len(STR1) - 1)])