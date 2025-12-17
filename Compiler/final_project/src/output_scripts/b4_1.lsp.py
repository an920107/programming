try:
	from type import *
	def f_0x10479c5f0(x):
		def f_0x10479c590(y):
			return (x + y)
		return f_0x10479c590
	add_x = f_0x10479c5f0
	z = add_x(Int(10))
	print(z(Int(1)))
except Exception as e: print(e)
