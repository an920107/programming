try:
	from type import *
	def f_0x102f28cc0(a, b):
		def f_0x102f28920(a):
			return ((Int(0) - a) if (a < Int(0)) else a)
		abs = f_0x102f28920
		return abs((a - b))
	diff = f_0x102f28cc0
	print(diff(Int(1), Int(10)))
	print(diff(Int(10), Int(2)))
except Exception as e: print(e)
