import random
import os

os.system("clear")

lines = open("students.txt", "r").readlines()
students = [x.strip("\n") for x in lines]

students.remove("蔡宜縈")
random.shuffle(students)
students.insert(0, "蔡宜縈")
print(students[:2])