try:
	from type import *
	print(1 if type(1) == int else error_())
	print(2 if type(2) == int else error_())
	print(3 if type(3) == int else error_())
	print(4 if type(4) == int else error_())
except Exception as e: print(e)
