print("Weather Master")

QUIT_CODE = -100

lst = []
cold_count = 0
while True:
    t = int(input(f"Next Temperature: (or {QUIT_CODE} to quit)? "))
    if (t == QUIT_CODE): break
    if (t < 16): cold_count += 1
    lst.append(t)

print(f"Highest temperature = {max(lst)}")
print(f"Lowest temperature = {min(lst)}")
print(f"Average = {(sum(lst) / len(lst)):.1f}")
print(f"{cold_count} cold day(s)")