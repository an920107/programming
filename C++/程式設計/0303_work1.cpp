#include <iostream>
#include <cstdlib>
using namespace std;

double f(double x) {
    return 3*x*x*x + 2*x - 1;
}

int main() {
    double x;
    x = -3.2; printf("f(%4.1lf) = %8.3lf\n", x, f(x));
    x = -2.1; printf("f(%4.1lf) = %8.3lf\n", x, f(x));
    x =    0; printf("f(%4.1lf) = %8.3lf\n", x, f(x));
    x =  2.1; printf("f(%4.1lf) = %8.3lf\n", x, f(x));
    system("pause");
    return 0;
}
