#include "Network.h"
#include "Functions.h"
#include "json.hpp"
#include <memory>
#include <iostream>
#include <fstream>

int main(){

    networkPtr net = networkPtr(new Network("settings.json"));

    std::vector< doubleArray > inputs = {
        {1.0, 0.0},
        {1.0, 1.0},
        {0.0, 1.0},
        {0.0, 0.0}
    };

    net->train("trainingData.json");

    for(int i = 0; i < inputs.size(); i++){

        Functions::printDoubleArray(inputs[i]);

        std::cout << "Network output: ";
        Functions::printDoubleArray(net->feed(inputs[i]));

        std::cout << "\n\n";

    }

    return 0;

}