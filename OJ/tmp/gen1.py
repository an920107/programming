from random import randint

DIR = "OJ/tmp/"

def randfloat() -> float:
    return randint(0, 1000000) / 10000

def solve(score:list, credit:list) -> tuple:
    sum = 0
    weigh_sum = 0
    credit_sum = 0
    for (s, c) in zip(score, credit):
        sum += s
        weigh_sum += s * c
        credit_sum += c
    return (round(sum / len(score), 1), round(weigh_sum / credit_sum, 1))

for f in range(1, 24):
    score = []
    credit = []
    for i in range(5):
        score.append(randint(0, 100) if f < 15 else randfloat())
    for i in range(5):
        credit.append(randint(1, 20))
    open(DIR + str(f) + ".in", "w").write("\n".join(map(str, score + credit)))
    open(DIR + str(f) + ".out", "w").write("\n".join(map(str, solve(score, credit))))

open(DIR + "24.in", "w").write("\n".join(map(str, (100, 100, 100, 100, 100, 1, 1, 1, 1, 1))))
open(DIR + "24.out", "w").write("\n".join(map(str, (100.0, 100.0))))
open(DIR + "25.in", "w").write("\n".join(map(str, (0, 0, 0, 0, 0, 1, 1, 1, 1, 1))))
open(DIR + "25.out", "w").write("\n".join(map(str, (0.0, 0.0))))