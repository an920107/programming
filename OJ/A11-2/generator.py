#%%
from cyaron import *

def gen_r(n):
    s = ""
    for i in range(48, 58):
        s += chr(i)
    for i in range(65, 91):
        s += chr(i)
    for i in range(97, 123):
        s += chr(i)
    return "".join([s[randint(0, 61)] for i in range(n)])

def gen_b(n):
    return "".join([chr(randint(48, 49)) for i in range(n)])

def gen_s(n):
    return "".join([chr(48) for i in range(n)])

def gen_test():
    lst = []
    n = randint(10, 30)
    for i in range(n):
        lst.append(gen_r(randint(1, 99)))
    for i in range(n):
        lst.append(gen_b(randint(1, 99)))
    for i in range(n):
        lst.append(gen_s(randint(1, 99)))
    return lst
    

#%%

test = [gen_test() for i in range(50)]

test_size = len(test)

for i in range(test_size):
    test_data = IO(file_prefix='', data_id=i+1)

    l = len(test[i])
    for j in range(l):
        test_data.input_writeln(test[i][j])

    test_data.input_writeln(-1)

    test_data.output_gen("/Users/an920107/Documents/Programming/OJ/A11-2/AC.exe")
