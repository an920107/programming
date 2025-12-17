class Bool:
    def __init__(self, value: bool):
        self.value = value
    
    def __repr__(self) -> str:
        return '#t' if self.value else '#f'
    
    def __or__(self, other):
        if isinstance(other, Bool):
            return Bool(self.value or other.value)
        else:
            error()
    
    def __and__(self, other):
        if isinstance(other, Bool):
            return Bool(self.value and other.value)
        else:
            error()
    
    def __not__(self):
        return Bool(not self.value)

    def __bool__(self):
        return self.value

class Int:
    def __init__(self, value: int):
        self.value = value
    
    def __repr__(self) -> str:
        return str(self.value)
    
    def __add__(self, other):
        if isinstance(other, Int):
            return Int(self.value + other.value)
        else:
            error()
    
    def __sub__(self, other):
        if isinstance(other, Int):
            return Int(self.value - other.value)
        else:
            error()
    
    def __mul__(self, other):
        if isinstance(other, Int):
            return Int(self.value * other.value)
        else:
            error()

    def __floordiv__(self, other):
        if isinstance(other, Int):
            return Int(self.value // other.value)
        else:
            error()
    
    def __mod__(self, other):
        if isinstance(other, Int):
            return Int(self.value % other.value)
        else:
            error()
    
    def __lt__(self, other):
        if isinstance(other, Int):
            return Bool(self.value < other.value)
        else:
            error()

    def __le__(self, other):
        if isinstance(other, Int):
            return Bool(self.value <= other.value)
        else:
            error()

    def __gt__(self, other):
        if isinstance(other, Int):
            return Bool(self.value > other.value)
        else:
            error()

    def __ge__(self, other):
        if isinstance(other, Int):
            return Bool(self.value >= other.value)
        else:
            error()

    def __eq__(self, value: object):
        if isinstance(value, Int):
            return Bool(self.value == value.value)
        else:
            error()

    def __ne__(self, value: object):
        if isinstance(value, Int):
            return Bool(self.value != value.value)
        else:
            error()

def error():
    raise Exception("Type error.")
