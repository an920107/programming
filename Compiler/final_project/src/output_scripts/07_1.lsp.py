try:
	from type import *
	def f_0x55feec5ace80(x):
		return (x + 1 if type(x) == type(1) == int else error_())
	print(f_0x55feec5ace80(3) if type(f_0x55feec5ace80(3)) == int else error_())
	def f_0x55feec5ae290(a, b):
		return (a + b if type(a) == type(b) == int else error_())
	print(f_0x55feec5ae290(4, 5) if type(f_0x55feec5ae290(4, 5)) == int else error_())
except Exception as e: print(e)
