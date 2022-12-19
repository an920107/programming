import random
import os

os.system("clear")

lines = open("Python/students.txt", "r").readlines()
students = [x.strip("\n") for x in lines]

random.shuffle(students)
print(students[:2])
