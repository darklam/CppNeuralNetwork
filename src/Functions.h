#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

// Some useful functions that are used throughout the whole project
// so I thought grouping and reusing them in a namespace woule be a good idea
// *** SUBJECT TO CHANGE LOL ***

typedef std::vector<double> doubleArray;

namespace Functions {

    double sigmoid(double);

    double sigmoidDerivative(double);

    void printDoubleArray(const doubleArray &);

}


#endif