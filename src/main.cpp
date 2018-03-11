#include "Network.h"
#include "Functions.h"
#include "json.hpp"
#include <memory>
#include <iostream>
#include <fstream>

int main(){

    networkPtr net = networkPtr(new Network("settings.json"));

    doubleArray inputs = {
        1.0,
        0.0
    };

    for(int i = 0; i < 1000; i++) net->train("trainingData.json");

    Functions::printDoubleArray(net->feed(inputs));

    std::cout << "No errors!\n";

    return 0;

}