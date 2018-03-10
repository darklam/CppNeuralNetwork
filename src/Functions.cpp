#include "Functions.h"
#include <cmath>


double Functions::sigmoid(double x){
    return 1 / (1 + exp(-x));
}

double Functions::sigmoidDerivative(double x){
    return Functions::sigmoid(x) * (1 - Functions::sigmoid(x));
}