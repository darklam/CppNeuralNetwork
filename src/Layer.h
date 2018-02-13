#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <memory>
#include "Neuron.h"

typedef std::shared_ptr<Neuron> neuronPtr;
typedef std::vector<neuronPtr> neuronArray;

class Layer {

protected:

    neuronArray neurons;

public:

    Layer(const int&, const int&);

    virtual doubleArray feed(const doubleArrayRef) = 0;

};

#endif