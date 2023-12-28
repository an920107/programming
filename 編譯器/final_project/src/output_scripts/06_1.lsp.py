try:
	from type import *
	x = 1
	print(x if type(x) == int else error_())
	y = (1 + 2 + 3 if type(1) == type(2) == type(3) == int else error_())
	print(y if type(y) == int else error_())
except Exception as e: print(e)
