'''
Exam 03
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

while (True):
    num_str = input()
    if (num_str == "-1"): break
    num_list = []
    for elm in num_str:
        if (ord(elm) >= 48 and ord(elm) <= 57):
            num_list.append(ord(elm) - 48)
        elif (ord(elm) >= 65 and ord(elm) <= 90):
            num_list.append(ord(elm) - 55)
        else:
            num_list.append(ord(elm) - 61)
    max_num = max(num_list)
    num_len = len(num_list)

    for i in range(max_num + 1, 63):
        num_dec = 0
        for j in range(num_len):
            num_dec += num_list[num_len - j - 1] * (i ** j)
        # print(num_dec)
        if (num_dec % (i - 1) == 0):
            print(i)
            break
        if (i == 62):
            print("such number is impossible!")
            break
