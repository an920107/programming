#%%
from random import shuffle
from cyaron import *

def generate_board():
    base = 3
    side = base*base

    # pattern for a baseline valid solution
    def pattern(r,c): return (base*(r%base)+r//base+c)%side

    # randomize rows, columns and numbers (of valid base pattern)
    from random import sample
    def shuffle(s): return sample(s,len(s))
    rBase = range(base)
    rows  = [ g*base + r for g in shuffle(rBase) for r in shuffle(rBase) ]
    cols  = [ g*base + c for g in shuffle(rBase) for c in shuffle(rBase) ]
    nums  = shuffle(range(1,base*base+1))

    # 隨機產生的數獨數字盤
    board = [ [nums[pattern(r,c)] for c in cols] for r in rows ]

    # # 移除部分數字，產生數獨題目
    # squares = side*side
    # empties = squares * 3//4
    # for p in sample(range(squares),empties):
    #     board[p//side][p%side] = 0

    for i in range(len(board)):
        for j in range(len(board[i])):
            board[i][j] = str(board[i][j])

    return board

def brk(board):
    board[randint(0, 8)][randint(0, 8)] = str(randint(1, 9))
    return board

#%%

test = [generate_board() for i in range(15)]
test += [brk(generate_board()) for i in range(35)]
test_size = len(test)

for i in range(test_size):
    test_data = IO(file_prefix='', data_id=i+1)

    for row in range(9):
        test_data.input_writeln(" ".join(test[i][row]))

    test_data.output_gen("/Users/an920107/Documents/Programming/OJ/A13/a.exe")
