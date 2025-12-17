try:
	from type import *
	def f_0x101308520(f, x):
		return f(x)
	foo = f_0x101308520
	def f_0x101308a40(x):
		return (x - Int(1))
	print(foo(f_0x101308a40, Int(10)))
except Exception as e: print(e)
