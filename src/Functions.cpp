#include "Functions.h"
#include <cmath>
#include <iostream>


double Functions::sigmoid(double x){
    return 1 / (1 + exp(-x));
}

double Functions::sigmoidDerivative(double x){
    return Functions::sigmoid(x) * (1 - Functions::sigmoid(x));
}

void Functions::printDoubleArray(const doubleArray &in){

    std::cout << "{ ";

    for(const auto &element : in){

        std::cout << element << " ";

    }

    std::cout << "}\n";

}