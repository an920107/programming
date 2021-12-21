import matplotlib.pyplot as plt

class chaos:
    """
    models the dynamical system (math): x_{t+1} = r x_t (1- x_t)
    """
    def __init__(self, x0 , r):
        "initialize with state x0 and parameter r"
        self.x, self.r = x0 , r

    def update(self):
        "apply the map to update state."
        self.x = self.r * self.x * (1 - self.x)

    def generate_sequence(self, n):
        "generate and return a sequence of length n."
        path = []
        for i in range (n):
            path.append(self.x)
            self.update()
        return path

fig, ax = plt.subplots()
x0 = 0.1
r = 2.5
chaos = chaos(x0, r)
while r<4:
    chaos.r = r
    t = chaos.generate_sequence(1000)[950:]
    ax.plot([r]*len(t), t, 'b.', ms=0.6)
    r = r+0.005

ax.set_title('plot the tail of transition rule:$x_{t+1}=r*x_t*(1-x_t)$')
ax.set_xlabel('parameter ($r$)')
ax.set_ylabel('state space ($x_t$)')
plt.show()