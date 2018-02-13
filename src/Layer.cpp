#include "Layer.h"
#include "Neuron.h"

Layer::Layer(const int &size, const int &inputsPerNeuron){
    this->neurons.resize(size);

    for(int i = 0; i < size; i++){
        this->neurons[i] = neuronPtr(new Neuron(inputsPerNeuron));
    }
}