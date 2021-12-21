#%%
from cyaron import *

lim = 1000

def gen(a, b, c, d):
    ret = [0, [a, b], [c, d]]
    if b != c:
        return ret
    ret[0] = 1
    p = []
    for i in range(a):
        tmp = []
        for j in range(b):
            tmp.append(randint(-lim, lim))
        p.append(tmp)
    ret.append(list(p))
    p = []
    for i in range(c):
        tmp = []
        for j in range(d):
            tmp.append(randint(-lim, lim))
        p.append(tmp)
    ret.append(list(p))
    return ret

def gen2():
    a = randint(1, 5)
    b = randint(1, 5)
    c = randint(1, 5)
    return gen(a, b, b, c)

def gen3():
    a = randint(1, 5)
    b = randint(1, 5)
    c = randint(1, 5)
    d = randint(1, 5)
    return gen(a, b, c, d)

#%%

test = [gen(1, 1, 1, 1), gen(1, 5, 5, 1), gen(5, 5, 5, 5), gen(1, 2, 3, 4), gen(4, 5, 5, 5), gen(5, 4, 5, 5), gen(5, 5, 4, 5), gen(5, 5, 5, 4), 
        gen(3, 3, 2, 2), gen(2, 3, 2, 3), gen(2, 3, 3, 3), gen(2, 3, 3, 2), gen(5, 1, 1, 5), gen(5, 4, 2, 2), gen(1, 1, 2, 1)]

for i in range(10): test.append(gen2())
for i in range(10): test.append(gen3())

T = len(test)

for i in range(T):
    test_data = IO(file_prefix='', data_id=i+1)

    t, x, y = test[i][0], test[i][1], test[i][2]
    test_data.input_writeln(x[0], x[1]) 
    test_data.input_writeln(y[0], y[1]) 
    if t == 1:
        for j in test[i][3]:
            test_data.input_writeln(*j)
        for j in test[i][4]:
            test_data.input_writeln(*j)

    test_data.output_gen('/Users/an920107/Downloads/A9-1/a.exe')

# %%
