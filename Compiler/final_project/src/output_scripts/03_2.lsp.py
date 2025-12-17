try:
	from type import *
	print((Int(10) % (Int(1) + Int(2))))
	print(((Int(1) // Int(2)) * Int(4)))
	print(((Int(1) + Int(2) + Int(3) + (Int(4) - Int(5)) + Int(6) + (Int(7) // Int(8)) + (Int(9) % Int(10))) - Int(11)))
except Exception as e: print(e)
