'''
Assignment 05
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

def StripFirstZero(_str):
    if (len(_str) <= 1): return _str
    for i in range(len(_str)):
        if (_str[i] != "0"):
            return _str[i:]

def IsBinary(_str):
    for char in _str:
        if (char != "0" and char != "1"):
            return False
    return True

while (True):
    bin_str = input("Binary: ")
    if (bin_str == "-1"): break
    if (not IsBinary(bin_str)):
        print("Not Binary Number!")
        continue
    hex_str = ""
    bin_str_list = []
    bin_len = len(bin_str)
    bin_left = bin_len % 4
    if (bin_left != 0):
        bin_str_list = [bin_str[0: bin_left]]
    for i in range(bin_len // 4):
        bin_str_list.append(bin_str[bin_left + i * 4: bin_left + i * 4 + 4])
    hex_list = [0 for i in range(len(bin_str_list))]
    for i in range(len(bin_str_list)):
        for j in range(len(bin_str_list[i])):
            hex_list[i] += int(bin_str_list[i][len(bin_str_list[i]) - j - 1]) * (2 ** j)
    for elm in hex_list:
        if (elm >= 0 and elm <= 9): hex_str += str(elm)
        else: hex_str += chr(elm + 55)
    print(StripFirstZero(hex_str))
