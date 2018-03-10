#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "Layer.h"

class InputLayer : public Layer {

public:

    InputLayer(const int &);

    virtual doubleArray feed(const doubleArray &);


};

typedef std::shared_ptr<InputLayer> inputLayerPtr;

#endif