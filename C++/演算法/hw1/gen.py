import random

with open("input", "w") as file:
    for i in range(1, 5001):
        x = chr(random.randint(49, 57))
        y = chr(random.randint(49, 57))
        for _ in range(i - 1):
            x += chr(random.randint(48, 57))
            y += chr(random.randint(48, 57))
        file.write(f"{x} {y}\n")