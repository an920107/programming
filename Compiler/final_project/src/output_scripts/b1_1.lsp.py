try:
	from type import *
	def f_0x1049489c0(n):
		return (n if (n < Int(3)) else (n * fact((n - Int(1)))))
	fact = f_0x1049489c0
	print(fact(Int(2)))
	print(fact(Int(3)))
	print(fact(Int(4)))
	print(fact(Int(10)))
	def f_0x104949d90(x):
		return (x if (x < Int(2)) else (fib((x - Int(1))) + fib((x - Int(2)))))
	fib = f_0x104949d90
	print(fib(Int(1)))
	print(fib(Int(3)))
	print(fib(Int(5)))
	print(fib(Int(10)))
	print(fib(Int(20)))
except Exception as e: print(e)
