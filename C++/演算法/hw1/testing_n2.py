import os
import random
import wandb

# 編譯

os.system("g++ -std=c++17 游宗穎_110502557_n2.cpp -o n2")


# 測試

wandb.init(project="algorithm-homework-1", name="n2")

with open("input", "r") as file:
    testing_inputs = file.readlines()

n2_nanosecs = []

for i in range(1, 10001, 2):
    with open("input_n2", "w") as file:
        file.write(testing_inputs[i - 1].strip("\n"))
    
    os.system("./n2 -t 1 < input_n2 > output_n2")
    with open("output_n2", "r") as file:
        n2_nanosecs.append(int(file.readline()))
    
    wandb.log({"cost time": n2_nanosecs[-1] / 1E6}, step=i)
