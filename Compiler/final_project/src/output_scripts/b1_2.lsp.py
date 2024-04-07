try:
	from type import *
	def f_0x55fe44fb4cd0(a, b):
		return (a if ((a < b if type(a) == type(b) == int else error_()) if type((a < b if type(a) == type(b) == int else error_())) == bool else error_()) else b)
	min = f_0x55fe44fb4cd0
	def f_0x55fe44fb65d0(a, b):
		return (a if ((a > b if type(a) == type(b) == int else error_()) if type((a > b if type(a) == type(b) == int else error_())) == bool else error_()) else b)
	max = f_0x55fe44fb65d0
	def f_0x55fe44fb8610(a, b):
		return (min(a, b) if ((0 == (max(a, b) % min(a, b) if type(max(a, b)) == type(min(a, b)) == int else error_()) if type(0) == type((max(a, b) % min(a, b) if type(max(a, b)) == type(min(a, b)) == int else error_())) else error_()) if type((0 == (max(a, b) % min(a, b) if type(max(a, b)) == type(min(a, b)) == int else error_()) if type(0) == type((max(a, b) % min(a, b) if type(max(a, b)) == type(min(a, b)) == int else error_())) else error_())) == bool else error_()) else gcd(min(a, b), (max(a, b) % min(a, b) if type(max(a, b)) == type(min(a, b)) == int else error_())))
	gcd = f_0x55fe44fb8610
	print(gcd(100, 88) if type(gcd(100, 88)) == int else error_())
	print(gcd(1234, 5678) if type(gcd(1234, 5678)) == int else error_())
	print(gcd(81, 54) if type(gcd(81, 54)) == int else error_())
except Exception as e: print(e)
