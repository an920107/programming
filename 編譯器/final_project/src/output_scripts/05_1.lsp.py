try:
	from type import *
	print((1 if (True if type(True) == bool else error_()) else 2) if type((1 if (True if type(True) == bool else error_()) else 2)) == int else error_())
	print((1 if (False if type(False) == bool else error_()) else 2) if type((1 if (False if type(False) == bool else error_()) else 2)) == int else error_())
except Exception as e: print(e)
