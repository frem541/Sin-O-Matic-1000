#ifndef MATH_UTILITY_H
#define MATH_UTILITY_H

#define _USE_MATH_DEFINES

#include <vector>

enum AngleType {DEG, RAD};

void computeSin(double start, double end, double step, AngleType angleType, std::vector<double>& results);

double degToRad(double value);

#endif // MATH_UTILITY_H
