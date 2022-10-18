from random import randint

DIR = "OJ/tmp/"

def solve(s: str) -> None:
    dic = {}
    lst = s.split(" ")
    for elm in lst:
        elm = elm.strip(".")
        elm = elm.strip(",")
        elm = elm.lower()
        if elm in dic.keys():
            dic[elm] += 1
        else:
            dic[elm] = 1
    lst = list(dic.items())
    lst.sort(reverse= True, key= lambda tup : tup[1])
    for tup in lst:
        print(tup[0], tup[1])

def chance(percent: int) -> bool:
    if percent >= 100: return True
    if percent <= 0: return False
    chance_list = [True for _ in range(percent)] + [False for _ in range(100 - percent)]
    return chance_list[randint(0, 99)]

def gen() -> str:
    str_list = list({chr(randint(97, 122)) for _ in range(randint(1, 20))})
    for n in range(randint(1, len(str_list) ** 2)):
        new_str = ""
        n += 1
        i = 0
        while n > 0:
            if n % 2 == 1:
                new_str += str_list[i]
            n //= 2
            i += 1
        if new_str not in str_list:
            str_list.append(new_str)
    output_list = []
    total_len = 0
    while total_len < 900:
        new_str = str_list[randint(0, len(str_list) - 1)] + ("," if chance(10) else ("." if chance(10) else ""))
        output_list.append(new_str)
        total_len += len(new_str) + 1
    result = ""
    for ch in " ".join(output_list):
        if 97 <= ord(ch) <= 122 and chance(10):
            result += chr(ord(ch) - 32)
        else:
            result += ch
    result += " " + str_list[randint(0, len(str_list) - 1)] + "."
    return result
    

# for i in range(1, 50):
#     open(DIR + str(i) + ".in", "w").write(gen())

# open(DIR + str(50) + ".in", "w").write("a.")

print(gen())