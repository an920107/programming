try:
	from type import *
	(1 + 2 + 3 + (True or False if type(True) == type(False) == bool else error_()) if type(1) == type(2) == type(3) == type((True or False if type(True) == type(False) == bool else error_())) == int else error_())
except Exception as e: print(e)
