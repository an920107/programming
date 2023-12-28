try:
	from type import *
	def f_0x5586048a2e10(x):
		return (x + 1 if type(x) == type(1) == int else error_())
	bar = f_0x5586048a2e10
	def f_0x5586048a3d30():
		return 2
	bar_z = f_0x5586048a3d30
	print(bar(bar_z()) if type(bar(bar_z())) == int else error_())
except Exception as e: print(e)
