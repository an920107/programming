def foo(lst):
    lst[0] = 0
    lst_cp = lst
    lst_cp[0] = 2

lst = [1]
foo(lst)
print(lst)