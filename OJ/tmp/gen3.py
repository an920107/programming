from random import randint

DIR = "OJ/tmp/"

prize = (200000, 40000, 10000, 4000, 1000, 200)

def solve(input: list) -> int:
    correct = []
    invoice = []
    flag = False
    for elm in input:
        if elm == ".":
            flag = True
            continue
        if flag:
            invoice.append(elm)
            continue
        else:
            correct.append(elm)
    sum = 0
    for i in range(6):
        for cor in correct:
            to_remove = []
            for inv in invoice:
                if cor == inv[i:]:
                    sum += prize[i]
                    to_remove.append(inv)
            for rm in to_remove:
                invoice.remove(rm)
        correct = list(map(lambda s: s[1:], correct))
    return sum

def gen() -> list:
    result = []
    num_list = [f"{i:03d}" for i in range(1000)]
    for _ in range(999):
        rnd = randint(0, len(num_list) - 1)
        result.append("".join([str(randint(0, 9)) for _ in range(5)]) + num_list[rnd])
        num_list.remove(num_list[rnd])
    result.append(".")
    tmp = set()
    for _ in range(999):
        tmp.add("".join([str(randint(0, 9)) for _ in range(8)]))
    result.extend(list(tmp))
    result.append(".")
    return result



for i in range(1, 10):
    lst = gen()
    open(DIR + str(i) + ".in", "w").write("\n".join(lst))
    open(DIR + str(i) + ".out", "w").write(str(solve(lst)))

lst = ["12345678", ".", "12345678", "02345678", "00345678", "00045678", "00005678", "00000678", "00000078", "00000008", "00000000", "."]
open(DIR + "10.in", "w").write("\n".join(lst))
open(DIR + "10.out", "w").write(str(solve(lst)))


correct = []
invoice = []
while True:
    s = input()
    if s == ".":
        break
    correct.append(s)
while True:
    s = input()
    if s == ".":
        break
    invoice.append(s)
sum = 0
for i in range(6):
    for cor in correct:
        to_remove = []
        for inv in invoice:
            if cor == inv[i:]:
                sum += prize[i]
                to_remove.append(inv)
        for rm in to_remove:
            invoice.remove(rm)
    correct = list(map(lambda s: s[1:], correct))
print(sum)

    