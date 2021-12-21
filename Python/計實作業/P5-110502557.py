'''
Practice 05
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1003-B
'''

while (True):
    continue_flag = False
    num = input("NUM(BIN) : ")
    if (num == "-1"): break
    for char in num:
        if (char != "0" and char != "1"):
            print("Not Binary Number !\n")
            continue_flag = True
            break
    if (continue_flag): continue
    print("NUM(DEC) after X16 : {0}\nNUM(OCT) : {1}\n".format(str(int(num, 2) * 16), oct(int(num, 2) * 16).lstrip("0o")))
