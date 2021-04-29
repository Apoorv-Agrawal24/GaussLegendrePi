#include <iostream>
#include <cmath>
#include <limits>

/*
    This program uses the Gauss Legendre algorithm to approximate the digits of pi
    Go to https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm for more information
*/

double pi()
{
    long double a0, b0, t0, p0;
    a0 = 1.0;
    b0 = 1 / sqrt(2);
    t0 = 1.0 / 4.0;
    p0 = 1.0;

    long double an, bn, pn, tn;

    int i = 0;
    long double pi;

    // Extends the precision for std::cout printing
    typedef std::numeric_limits<double> db1;
    std::cout.precision(db1::max_digits10);

    while (i < 4)
    {
        // Actual algorithm
        an = (a0 + b0) / 2.0;
        bn = sqrt(a0 * b0);
        tn = t0 - (p0 * (a0 - an) * (a0 - an));
        pn = 2 * p0;
        
        a0 = an;
        b0 = bn;
        p0 = pn;
        t0 = tn;

        pi = (an + bn) * (an + bn) / (4 * tn);
        std::cout << pi << std::endl;
        i++;
    }

    return pi;
}

int main()
{
    std::cout << "Pi: " << pi() << std::endl;
    return 0;
}

