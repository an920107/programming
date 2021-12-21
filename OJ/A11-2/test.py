from cyaron import *

test_data = IO(file_prefix='', data_id=100)
test_f = open("13.in", "r")
test = test_f.readlines()

for i in range(len(test)):
    test[i].strip("\n")
    test_data.input_writeln(test[i])

test_data.input_writeln(-1)

test_data.output_gen("/Users/an920107/Documents/Programming/C++/test.exe")