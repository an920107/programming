try:
	from type import *
	def f_0x558b1e45e9f0(f, x):
		return f(x)
	foo = f_0x558b1e45e9f0
	def f_0x558b1e460020(x):
		return (x - 1 if type(x) == type(1) == int else error_())
	print(foo(f_0x558b1e460020, 10) if type(foo(f_0x558b1e460020, 10)) == int else error_())
except Exception as e: print(e)
