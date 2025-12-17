try:
	from type import *
	print((Int(1) if Bool(True) else Int(2)))
	print((Int(1) if Bool(False) else Int(2)))
except Exception as e: print(e)
