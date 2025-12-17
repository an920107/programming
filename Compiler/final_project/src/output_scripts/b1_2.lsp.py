try:
	from type import *
	def f_0x10337c720(a, b):
		return (a if (a < b) else b)
	min = f_0x10337c720
	def f_0x10337cde0(a, b):
		return (a if (a > b) else b)
	max = f_0x10337cde0
	def f_0x10337dc90(a, b):
		return (min(a, b) if (Int(0) == (max(a, b) % min(a, b))) else gcd(min(a, b), (max(a, b) % min(a, b))))
	gcd = f_0x10337dc90
	print(gcd(Int(100), Int(88)))
	print(gcd(Int(1234), Int(5678)))
	print(gcd(Int(81), Int(54)))
except Exception as e: print(e)
