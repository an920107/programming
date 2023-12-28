try:
	from type import *
	print(0 if type(0) == int else error_())
	print(-123 if type(-123) == int else error_())
	print(456 if type(456) == int else error_())
except Exception as e: print(e)
