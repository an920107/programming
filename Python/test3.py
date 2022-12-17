import random
import os

os.system("clear")

students = []
with open("students.txt", "r") as file:
    for line in file.readlines():
        students.append(line.strip("\n"))

print("蔡宜縈")
students.remove("蔡宜縈")

rnd = random.randint(0, len(students) - 1)
print(students.pop(rnd))
