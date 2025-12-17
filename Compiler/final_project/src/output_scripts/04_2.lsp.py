try:
	from type import *
	print((Bool(True) or Bool(True) or Bool(False)))
	print((Bool(False) or (Bool(False) and Bool(True)) or (not(Bool(False)))))
	print((Bool(True) and (not(Bool(False))) and (Bool(False) or Bool(True)) and (Bool(True) and (not(Bool(True))))))
except Exception as e: print(e)
