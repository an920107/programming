import os
import random
import wandb

# 編譯

os.system("g++ -std=c++17 游宗穎_110502557_n2.cpp -o n2")
os.system("g++ -std=c++17 游宗穎_110502557_karatsuba.cpp -o karatsuba")


# 測試

wandb.init(project="algorithm-homework-1", name="table")

n2_nanosecs = []
karatsuba_nanosecs = []

for i in range(1, 100):
    x = chr(random.randint(49, 57))
    y = chr(random.randint(49, 57))
    for _ in range(i - 1):
        x += chr(random.randint(48, 57))
        y += chr(random.randint(48, 57))
    with open("input", "w") as file:
        file.write(f"{x} {y}")
    
    os.system("./n2 -t 200 < input > output")
    with open("output", "r") as file:
        n2_nanosecs.append(int(file.readline()))
    
    os.system("./karatsuba -t 200 < input > output")
    with open("output", "r") as file:
        karatsuba_nanosecs.append(int(file.readline()))

    wandb.log({"n2": n2_nanosecs[-1]}, step=i)
    wandb.log({"karatsuba": karatsuba_nanosecs[-1]}, step=i)
