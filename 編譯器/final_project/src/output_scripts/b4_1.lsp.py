try:
	from type import *
	def f_0x5560599a1b10(x):
		def f_0x5560599a1a90(y):
			return (x + y if type(x) == type(y) == int else error_())
		return f_0x5560599a1a90
	add_x = f_0x5560599a1b10
	z = add_x(10)
	print(z(1) if type(z(1)) == int else error_())
except Exception as e: print(e)
