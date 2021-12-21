#%%
from cyaron import *

def gen_t(n):
    data = [randint(-1E9, 1E9) for i in range(n * n // 2)]
    rvs = data.copy()
    rvs.reverse()
    if (n % 2 == 1): data += [randint(-1E9, 1E9)]
    data += rvs
    data = [n] + data
    return data

def gen_r(n):
    data = [n] + [randint(-1E9, 1E9) for i in range(n * n)]
    return data

def gen_num():
    return randint(1, 100)

#%%

test = [gen_t(n + 1) for n in range(20) for i in range(n + 1)]
test += [gen_r(n + 1) for n in range(20) for i in range(n + 1)]
test += [gen_t(gen_num()) for i in range(20)]
test += [gen_r(gen_num()) for i in range(20)]

test_len = len(test)

for i in range(test_len // 10):
    test_data = IO(file_prefix='', data_id=i+1)

    for j in range(10):
        t= test[i * 10 + j][0]
        arr = test[i * 10 + j][1:]

        test_data.input_writeln(t)
        for k in range(t * t):
            test_data.input_write(arr[k])
            if ((k + 1) % t == 0):
                test_data.input_writeln("")
            else:
                test_data.input_write(" ")

    test_data.input_writeln(-1)

    test_data.output_gen("/Users/an920107/Documents/Programming/OJ/A11-1/AC.exe")
