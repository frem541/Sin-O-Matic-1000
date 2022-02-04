#include "math_utility.h"
#include <cmath>

void computeSin(double start, double end, double step, AngleType angleType, std::vector<double>& results)
{
    size_t count = floor((end-start)/step)+1;
    results.clear();
    results.reserve(count);
    if (angleType == DEG)
    {
        start = degToRad(start);
        end = degToRad(end);
        step = degToRad(step);
    }
    double argument = start;
    for (size_t i = 0; i < count; i++)
    {
        results.push_back(sin(argument));
        argument+=step;
    }
}

double degToRad(double value)
{
    return value/180*M_PI;
}
