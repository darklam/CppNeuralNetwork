#ifndef NETWORK_H
#define NETWORK_H

#include "json.hpp"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <memory>

using json = nlohmann::json;

typedef std::vector<hiddenLayerPtr> hiddenLayerArray;

typedef std::vector<layerPtr> layerArray;

class Network {

protected:

    inputLayerPtr inputLayer;
    outputLayerPtr outputLayer;
    hiddenLayerArray hiddenLayers;

    layerArray layers;

    doubleArray momentums, learningRates;

    


public:

    Network(const std::string &);

    doubleArray feed(const doubleArray &);

    void train(const std::string &);

    void train(const doubleArray &, const doubleArray &);



};

typedef std::shared_ptr<Network> networkPtr;

#endif