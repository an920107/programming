try:
	from type import *
	print(((Int(1) + Int(2) + Int(3)) if (Int(1) < Int(2)) else (Int(1) * Int(2) * Int(3) * Int(4) * Int(5))))
	print((Int(0) if (Int(9) == (Int(2) * Int(5))) else (Int(1) if Bool(True) else Int(2))))
except Exception as e: print(e)
