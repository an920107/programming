try:
	from type import *
	print('#t' if (True if type(True) == bool else error_()) else '#f')
	print('#t' if (False if type(False) == bool else error_()) else '#f')
	print('#t' if ((True and False if type(True) == type(False) == bool else error_()) if type((True and False if type(True) == type(False) == bool else error_())) == bool else error_()) else '#f')
	print('#t' if ((True and True if type(True) == type(True) == bool else error_()) if type((True and True if type(True) == type(True) == bool else error_())) == bool else error_()) else '#f')
	print('#t' if ((True or False if type(True) == type(False) == bool else error_()) if type((True or False if type(True) == type(False) == bool else error_())) == bool else error_()) else '#f')
	print('#t' if ((False or False if type(False) == type(False) == bool else error_()) if type((False or False if type(False) == type(False) == bool else error_())) == bool else error_()) else '#f')
	print('#t' if ((not(True if type(True) == bool else error_())) if type((not(True if type(True) == bool else error_()))) == bool else error_()) else '#f')
	print('#t' if ((not(False if type(False) == bool else error_())) if type((not(False if type(False) == bool else error_()))) == bool else error_()) else '#f')
except Exception as e: print(e)
