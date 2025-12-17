try:
	from type import *
	print(Bool(True))
	print(Bool(False))
	print((Bool(True) and Bool(False)))
	print((Bool(True) and Bool(True)))
	print((Bool(True) or Bool(False)))
	print((Bool(False) or Bool(False)))
	print((not(Bool(True))))
	print((not(Bool(False))))
except Exception as e: print(e)
