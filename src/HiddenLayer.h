#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include <memory>
#include "Layer.h"

class HiddenLayer : public Layer {

protected:


public:

    HiddenLayer(const int &, const int &, const double &, const double &);

    virtual doubleArray feed(const doubleArray &);


    // Arguments:
    // Arg0: next layer's deltas
    // Arg1: next layer
    // Arg2: this layer's activations
    // Arg3: previous layer's activations
    // Returns: this layer's deltas
    virtual doubleArray trainLayer(const doubleArray &, layerPtr const next, const doubleArray &, const doubleArray &);

};

#endif