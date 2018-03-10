#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <memory>
#include <iostream>

int main(){

    inputLayerPtr p = inputLayerPtr(new InputLayer(5));
    hiddenLayerPtr h = hiddenLayerPtr(new HiddenLayer(3, 4, 0.3, 0.1));
    outputLayerPtr o = outputLayerPtr(new OutputLayer(3, 4, 0.3, 0.1));

    std::cout << "No errors!\n";

    return 0;

}