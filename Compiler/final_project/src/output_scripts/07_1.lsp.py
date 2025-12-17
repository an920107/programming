try:
	from type import *
	def f_0x103504500(x):
		return (x + Int(1))
	print(f_0x103504500(Int(3)))
	def f_0x103504ac0(a, b):
		return (a + b)
	print(f_0x103504ac0(Int(4), Int(5)))
except Exception as e: print(e)
