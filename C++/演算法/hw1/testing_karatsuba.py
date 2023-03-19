import os
import random
import wandb

# 編譯

os.system("g++ -std=c++17 游宗穎_110502557_karatsuba.cpp -o karatsuba")


# 測試

wandb.init(project="algorithm-homework-1", name="karatsuba")

with open("input", "r") as file:
    testing_inputs = file.readlines()

karatsuba_nanosecs = []

for i in range(1, 10001, 2):
    with open("input_karatsuba", "w") as file:
        file.write(testing_inputs[i - 1].strip("\n"))
    
    os.system("./karatsuba -t 1 < input_karatsuba > output_karatsuba")
    with open("output_karatsuba", "r") as file:
        karatsuba_nanosecs.append(int(file.readline()))

    wandb.log({"cost time": karatsuba_nanosecs[-1] / 1E6}, step=i)
