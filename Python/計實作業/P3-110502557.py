'''
Practice 03
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1003-B
'''

def create_file(file_name, file_context):
    file = open(file_name, "w")
    file.write(file_context)
    print("File name: " + file_name)
    print("Context: " + file_context)
    file.close()

create_file(input("Create a file: "), input("Write something: "))