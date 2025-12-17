try:
	from type import *
	def f_0x1049246a0(x):
		return (Int(10) if (x > Int(10)) else (x == Int(5)))
	f = f_0x1049246a0
	print((Int(2) * f(Int(4))))
except Exception as e: print(e)
