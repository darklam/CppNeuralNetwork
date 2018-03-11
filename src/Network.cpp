#include "Network.h"
#include <fstream>
#include <string>

typedef std::vector<std::string> stringArray;
typedef std::vector<int> intArray;

// Not final code

// When this code is bought by Microsoft for billions of dollars
// or by Elon Musk to save us from Skynet remember that
// it is all part of the plan :)

Network::Network(const std::string &filename){

    std::ifstream i(filename);

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

    for(const auto &layer : this->layers){

        out = layer->feed(out);

    }

    return out;

}

// filename is the json file containing the training data

void Network::train(const std::string &filename){

    std::ifstream i(filename);

    json j;

    i >> j;

    i.close();

    std::vector<doubleArray> inputData = j["inputData"].get< std::vector<doubleArray> >();
    
    std::vector<doubleArray> outputData = j["outputData"].get< std::vector<doubleArray> >();

    for(int i = 0; i < inputData.size(); i++){

        this->train(inputData[i], outputData[i]);

    }

}

void Network::train(const doubleArray &in, const doubleArray &out){

    std::vector< doubleArray > layerOutputs;

    doubleArray temp = in;

    for(const auto &layer : this->layers){

        temp = layer->feed(temp);

        layerOutputs.push_back(temp);

    }

    doubleArray deltas;

    // First train the output layer that is different

    deltas = this->outputLayer->trainLayer(
        out,
        layerOutputs.back(),
        layerOutputs[layerOutputs.size() - 2]
    );

    for(int i = this->layers.size() - 2; i >= 1; i--){

        if(this->layers[i]->getType() != "hidden") break;

        HiddenLayer *curr = (HiddenLayer*) this->layers[i].get();

        deltas = curr->trainLayer(
            deltas,
            this->layers[i + 1],
            layerOutputs[layerOutputs.size() - 1 - i],
            layerOutputs[layerOutputs.size() - 2 - i]
        );

    }

}