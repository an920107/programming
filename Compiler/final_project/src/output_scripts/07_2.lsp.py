try:
	from type import *
	x = 0
	def f_0x55d020ee5960(x, y, z):
		return (x + (y * z if type(y) == type(z) == int else error_()) if type(x) == type((y * z if type(y) == type(z) == int else error_())) == int else error_())
	print(f_0x55d020ee5960(10, 20, 30) if type(f_0x55d020ee5960(10, 20, 30)) == int else error_())
	print(x if type(x) == int else error_())
except Exception as e: print(e)
