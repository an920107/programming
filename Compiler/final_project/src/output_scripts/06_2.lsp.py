try:
	from type import *
	a = (Int(1) * Int(2) * Int(3) * Int(4))
	b = (Int(10) + Int(-5) + Int(-2) + Int(-1))
	print((a + b))
except Exception as e: print(e)
