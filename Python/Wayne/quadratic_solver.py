import math

class Quadratic:
    def __init__(self, a: int, b: int, c: int) -> None:
        self.a = a
        self.b = b
        self.c = c

    def solve(self):
        q = self.b * self.b - 4 * self.a * self.c
        if (q < 0):
            print("No real root!")
        else:
            q_sqrt = math.sqrt(q)
            if (q == 0):
                print("One root: %.1f" % (-self.b / 2 / self.a))
            else:
                print("Two roots: %.1f, %.1f" % ((-self.b + q_sqrt) / 2 / self.a, (-self.b - q_sqrt) / 2 / self.a))

        

print("Quadratic Solver")
solve = Quadratic(int(input("a: ")), int(input("b: ")), int(input("c: ")))
solve.solve()