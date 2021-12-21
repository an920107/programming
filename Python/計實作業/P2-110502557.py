'''
Practice 02
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1003-B
'''

import random

randnum = random.randint(1, 100)
count = 0
while (True):
    guess = int(input("輸入一數字 : "))
    count += 1
    if (randnum > guess): print("比", guess, "還要大")
    elif (randnum < guess): print("比", guess, "還要小")
    else: break
print("猜對了！總共猜了", count, "次")