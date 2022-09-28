from random import randint

DIR = "OJ/tmp/"

def randfloat() -> float:
    return randint(1, 999999) / 10000

def solve(score:float) -> str:
    score = round(score)
    if score >= 90: return "A+"
    if score >= 85: return "A"
    if score >= 80: return "A-"
    if score >= 77: return "B+"
    if score >= 70: return "B-"
    if score >= 67: return "C+"
    if score >= 63: return "C"
    if score >= 60: return "C-"
    return "F"

for f in range(1, 41):
    score = randint(1, 99) if f < 20 else randfloat()
    open(DIR + str(f) + ".in", "w").write(str(score))
    open(DIR + str(f) + ".out", "w").write(solve(score))

open(DIR + "41.in", "w").write("90")
open(DIR + "41.out", "w").write(solve(90))
open(DIR + "42.in", "w").write("85")
open(DIR + "42.out", "w").write(solve(85))
open(DIR + "43.in", "w").write("80")
open(DIR + "43.out", "w").write(solve(80))
open(DIR + "44.in", "w").write("77")
open(DIR + "44.out", "w").write(solve(77))
open(DIR + "45.in", "w").write("70")
open(DIR + "45.out", "w").write(solve(70))
open(DIR + "46.in", "w").write("67")
open(DIR + "46.out", "w").write(solve(67))
open(DIR + "47.in", "w").write("63")
open(DIR + "47.out", "w").write(solve(63))
open(DIR + "48.in", "w").write("60")
open(DIR + "48.out", "w").write(solve(60))
open(DIR + "49.in", "w").write("0")
open(DIR + "49.out", "w").write(solve(0))
open(DIR + "50.in", "w").write("100")
open(DIR + "50.out", "w").write(solve(100))