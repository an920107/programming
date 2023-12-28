try:
	from type import *
	a = (1 * 2 * 3 * 4 if type(1) == type(2) == type(3) == type(4) == int else error_())
	b = (10 + -5 + -2 + -1 if type(10) == type(-5) == type(-2) == type(-1) == int else error_())
	print((a + b if type(a) == type(b) == int else error_()) if type((a + b if type(a) == type(b) == int else error_())) == int else error_())
except Exception as e: print(e)
