#ifndef RANDOM_H
#define RANDOM_H

// Again functions that generate random numbers and I thought it would be
// useful to group them here for reuse

namespace Random {

    double randomDouble(double, double);
    double randomDouble(double);
    double randomDouble();

    int randomInt(int, int);
    int randomInt(int);
    int randomInt();

}

#endif