try:
	from type import *
	def f_0x55a04c726560(n):
		return (n if ((n < 3 if type(n) == type(3) == int else error_()) if type((n < 3 if type(n) == type(3) == int else error_())) == bool else error_()) else (n * fact((n - 1 if type(n) == type(1) == int else error_())) if type(n) == type(fact((n - 1 if type(n) == type(1) == int else error_()))) == int else error_()))
	fact = f_0x55a04c726560
	print(fact(2) if type(fact(2)) == int else error_())
	print(fact(3) if type(fact(3)) == int else error_())
	print(fact(4) if type(fact(4)) == int else error_())
	print(fact(10) if type(fact(10)) == int else error_())
	def f_0x55a04c7298b0(x):
		return (x if ((x < 2 if type(x) == type(2) == int else error_()) if type((x < 2 if type(x) == type(2) == int else error_())) == bool else error_()) else (fib((x - 1 if type(x) == type(1) == int else error_())) + fib((x - 2 if type(x) == type(2) == int else error_())) if type(fib((x - 1 if type(x) == type(1) == int else error_()))) == type(fib((x - 2 if type(x) == type(2) == int else error_()))) == int else error_()))
	fib = f_0x55a04c7298b0
	print(fib(1) if type(fib(1)) == int else error_())
	print(fib(3) if type(fib(3)) == int else error_())
	print(fib(5) if type(fib(5)) == int else error_())
	print(fib(10) if type(fib(10)) == int else error_())
	print(fib(20) if type(fib(20)) == int else error_())
except Exception as e: print(e)
