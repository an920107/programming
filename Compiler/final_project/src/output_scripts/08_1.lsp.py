try:
	from type import *
	def f_0x102987790(a, b, c):
		return (a + b + (b * c))
	foo = f_0x102987790
	print(foo(Int(10), Int(9), Int(8)))
except Exception as e: print(e)
