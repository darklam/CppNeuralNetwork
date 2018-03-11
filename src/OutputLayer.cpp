#include "OutputLayer.h"
#include "Functions.h"

OutputLayer::OutputLayer(const int &neuronCount, const int &inputsPerNeuron, const double &momentum, const double &learningRate) :
Layer(neuronCount, inputsPerNeuron, momentum, learningRate, "output"){

}

doubleArray OutputLayer::feed(const doubleArray &in){

    doubleArray out;
    out.resize(this->neurons.size());

    for(int i = 0; i < out.size(); i++){
        out[i] = this->neurons[i]->feed(in);
    }

    return out;

}

doubleArray OutputLayer::trainLayer(
    const doubleArray &target,
    const doubleArray &activations,
    const doubleArray &previousActivations
){

    doubleArray layerDeltas;
    layerDeltas.resize(this->neurons.size());


    #pragma omp parallel for
    for(int i = 0; i < layerDeltas.size(); i++){

        neuronPtr current = this->neurons[i];
        double deltaCurrent = (activations[i] - target[i]) * Functions::sigmoidDerivative(activations[i]);
        layerDeltas[i] = deltaCurrent;
        
        doubleArray deltas;
        deltas.resize(previousActivations.size());

        for(int j = 0; j < deltas.size(); j++){

            deltas[j] = previousActivations[j] * deltaCurrent;

        }

        current->train(deltas, this->learningRate, this->momentum);

    }

    return layerDeltas;

}
