#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <memory>
#include <string>
#include "Neuron.h"


class Layer {

protected:

    neuronArray neurons;

    double momentum, learningRate;

    std::string type;

public:

    Layer(const int&, const int&, const double &, const double &, const std::string &);

    virtual doubleArray feed(const doubleArray &) = 0;

    virtual int getNeuronCount();

    virtual neuronArray const getNeurons();

};

typedef std::shared_ptr<Layer> layerPtr;

#endif