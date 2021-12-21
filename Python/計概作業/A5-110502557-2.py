'''
Assignment 05
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

def XOR(p, q):
    return bool((p or q) and not(p and q))

def BinPlus(x, y):
    carry = False
    bin_len = len(x)
    result = [False for i in range(bin_len)]
    for i in range(bin_len - 1, -1, -1):
        result[i] = XOR(XOR(x[i], y[i]), carry)
        carry = (x[i] and y[i]) or (x[i] and carry) or (y[i] and carry)
    return result

def BinPlusOne(x):
    bin_len = len(x)
    one_bin = [False for i in range(bin_len)]
    one_bin[bin_len - 1] = True
    return BinPlus(x, one_bin)

while (True):
    formula_str = input()
    if (formula_str == "-1"): break
    bin_a = [False]
    bin_b = []
    num_a_str = num_b_str = "0"
    result_str = ""
    for char in formula_str:
        if (len(bin_b) == 0):
            if (char == "+"): bin_b = [False]
            elif (char == "-"): bin_b = [True]
            else: num_a_str += char
        else: num_b_str += char
    while (len(num_a_str) < len(num_b_str)): num_a_str = "0" + num_a_str
    while (len(num_a_str) > len(num_b_str)): num_b_str = "0" + num_b_str
    for char in num_a_str:
        if (char == "0"): bin_a.append(False)
        else: bin_a.append(True)
    for char in num_b_str:
        if (char == "0"): bin_b.append(XOR(bin_b[0], False))
        else: bin_b.append(XOR(bin_b[0], True))
    if (bin_b[0]): bin_b = BinPlusOne(bin_b)
    result_list = BinPlus(bin_a, bin_b)
    first_zero_flag = True
    for elm in result_list:
        if (first_zero_flag):
            if (elm): first_zero_flag = False
            else: continue
        if (elm): result_str += "1"
        else: result_str += "0"
    print(result_str)
