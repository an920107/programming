a_f = open("13.out", "r")
b_f = open("100.out", "r")

a_l = a_f.readlines()
b_l = b_f.readlines()

for i in range(len(a_l)):
    a_l[i].strip("\n")
    b_l[i].strip("\n")
    if (a_l[i] != b_l[i]): print(a_l[i] + " " + b_l[i])