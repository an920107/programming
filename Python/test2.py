import random
import os

os.system("clear")

students = []
with open("Python/students.txt", "r") as file:
    for line in file.readlines():
        students.append(line.strip("\n"))

for i in range(2):
    rnd = random.randint(0, len(students) - 1)
    print(students.pop(rnd))