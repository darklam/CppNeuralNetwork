#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <memory>
#include "Neuron.h"


class Layer {

protected:

    neuronArray neurons;

    double momentum, learningRate;

public:

    Layer(const int&, const int&, const double &, const double &);

    virtual doubleArray feed(const doubleArray &) = 0;

    virtual int getNeuronCount();

    virtual neuronArray const getNeurons();

};

typedef std::shared_ptr<Layer> layerPtr;

#endif