#ifndef NETWORK_H
#define NETWORK_H

#include "json.hpp"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <memory>

using json = nlohmann::json;

typedef std::vector<hiddenLayerPtr> hiddenLayerArray;

class Network {

protected:

    neuronArray layers;

    doubleArray momentums, learningRates;

    


public:

    Network(const std::string &);



};

typedef std::shared_ptr<Network> networkPtr;

#endif