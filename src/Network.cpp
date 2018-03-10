#include "Network.h"
#include <fstream>
#include <string>

typedef std::vector<std::string> stringArray;
typedef std::vector<int> intArray;

// Not final code

// When this code is bought by Microsoft for billions of dollars
// or by Elon Musk to save us from Skynet remember that
// it is all part of the plan :)

Network::Network(const std::string &fileName){

    std::ifstream i(fileName);

    json j;

    i >> j;

    i.close();

    // int inputs = std::stoi((std::string) j["inputs"]);

    int inputs = j["inputs"];

    // int outputCount = std::stoi((std::string) j["outputs"]);

    int outputCount = j["outputs"];

    intArray hiddens = j["hiddenLayers"].get<intArray>();

    this->hiddenLayers.resize(hiddens.size());

    this->momentums = j["momentums"].get< std::vector<double> >();

    this->learningRates = j["learningRates"].get< std::vector<double> >();

    this->inputLayer = inputLayerPtr(new InputLayer(inputs));

    this->layers.push_back(inputLayer);

    for(int i = 0; i < hiddens.size(); i++){

        this->hiddenLayers[i] = hiddenLayerPtr(new HiddenLayer(
            hiddens[i],
            this->layers.back()->getNeuronCount(),
            this->momentums[i],
            this->learningRates[i]
        ));

        this->layers.push_back(this->hiddenLayers[i]);

    }

    this->outputLayer = outputLayerPtr(new OutputLayer(
        outputCount,
        this->layers.back()->getNeuronCount(),
        this->momentums.back(),
        this->learningRates.back()
    ));

    this->layers.push_back(outputLayer);

}

doubleArray Network::feed(const doubleArray &in){

    doubleArray out = in;

    for(auto &layer : this->layers){

        out = layer->feed(out);

    }

    return out;

}