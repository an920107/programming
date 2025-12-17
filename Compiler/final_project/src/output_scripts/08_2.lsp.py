try:
	from type import *
	def f_0x105237490(x):
		return (x + Int(1))
	bar = f_0x105237490
	def f_0x105237700():
		return Int(2)
	bar_z = f_0x105237700
	print(bar(bar_z()))
except Exception as e: print(e)
