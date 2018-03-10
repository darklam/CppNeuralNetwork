#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include "Layer.h"

class OutputLayer : public Layer {

public:

    OutputLayer(const int &, const int &, const double &, const double &);

   doubleArray feed(const doubleArray &);

   doubleArray trainLayer(const doubleArray &, const doubleArray &, const doubleArray &);

};

typedef std::shared_ptr<OutputLayer> outputLayerPtr;

#endif