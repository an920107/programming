'''
Practice 04
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1003-B
'''

def CountFormula(x_int, y_int, operator_str):
    if (operator_str == "+"): return x_int + y_int
    elif (operator_str == "-"): return x_int - y_int
    elif (operator_str == "*"): return x_int * y_int

def IsFormulaCorrect(formula_str):
    formula_list = formula_str.split()
    return True if CountFormula(int(formula_list[0]), int(formula_list[2]), formula_list[1]) == int(formula_list[4]) else False

file_r = open("test.txt", "r")
file_w = open("ans-110502557.txt", "w")
for line_str in file_r.readlines():
    file_w.write("T\n" if IsFormulaCorrect(line_str) else "F\n")
