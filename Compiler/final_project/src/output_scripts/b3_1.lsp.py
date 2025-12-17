try:
	from type import *
	def f_0x102f9c9b0(x, y):
		def f_0x102f9c550(x):
			return (x * x)
		square = f_0x102f9c550
		return (square(x) + square(y))
	dist_square = f_0x102f9c9b0
	print(dist_square(Int(3), Int(4)))
except Exception as e: print(e)
