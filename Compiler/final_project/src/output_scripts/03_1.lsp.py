try:
	from type import *
	(Int(1) + Int(2) + Int(3))
	(Int(4) * Int(5) * Int(6))
	print((Int(1) + (Int(2) + Int(3) + Int(4)) + (Int(4) * Int(5) * Int(6)) + (Int(8) // Int(3)) + (Int(10) % Int(3))))
	print((Int(10) % Int(4)))
	print(((Int(1) + Int(2)) - Int(4)))
	print(Int(-256))
except Exception as e: print(e)
