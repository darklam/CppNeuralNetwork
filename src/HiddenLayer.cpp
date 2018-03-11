#include "HiddenLayer.h"
#include "Functions.h"

HiddenLayer::HiddenLayer(const int &neuronCount, const int &inputsPerNeuron, const double &momentum, const double &learningRate) :
Layer(neuronCount, inputsPerNeuron, momentum, learningRate, "hidden"){

    this->neurons.push_back(neuronPtr(new BiasNeuron()));

}

doubleArray HiddenLayer::feed(const doubleArray &in){

    doubleArray out;
    out.resize(this->neurons.size());

    for(int i = 0; i < this->neurons.size(); i++){

        out[i] = this->neurons[i]->feed(in);

    }

    return out;

}

// Don't know why I put const in the layerPtr argument to the right
// while the rest are to the left (makes no difference) but I'll
// keep it there to give the code some character before it develops
// one on its own lol

doubleArray HiddenLayer::trainLayer(

    const doubleArray &nextDeltas,
    layerPtr const next,
    const doubleArray &activations,
    const doubleArray &previousActivations

){

    neuronArray const nextLayer = next->getNeurons();
    doubleArray layerDeltas;

    layerDeltas.resize(this->getNeuronCount());

    // The -1 omits the last neuron (the bias)

    for(int i = 0; i < this->getNeuronCount() - 1; i++){

        double sum = 0.0;

        for(int j = 0; j < nextLayer.size(); j++)
            sum += nextDeltas[j] * nextLayer[j]->getWeight(i);

        double neuronDelta = sum * Functions::sigmoidDerivative(activations[i]);

        layerDeltas[i] = neuronDelta;

        neuronPtr current = this->neurons[i];

        doubleArray neuronDeltas;
        neuronDeltas.resize(previousActivations.size());

        for(int j = 0; j < previousActivations.size(); j++)
            neuronDeltas[j] = neuronDelta * previousActivations[j];

        current->train(neuronDeltas, this->learningRate, this->momentum);

    }

    return layerDeltas;

}