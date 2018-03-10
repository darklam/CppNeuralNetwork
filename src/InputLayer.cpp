#include "InputLayer.h"

InputLayer::InputLayer(const int &neuronCount) : Layer(neuronCount, 1, 0, 0, "input"){

}

doubleArray InputLayer::feed(const doubleArray &in){

    doubleArray out;
    out.resize(this->neurons.size());

    for(int i = 0; i < this->neurons.size(); i++){

        out[i] = this->neurons[i]->feed(in[i]);

    }

    return out;

}