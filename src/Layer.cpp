#include "Layer.h"
#include "Neuron.h"

Layer::Layer(const int &size, const int &inputsPerNeuron, const double &momentum, const double &learningRate, const std::string &type) :
momentum(momentum), learningRate(learningRate), type(type){
    this->neurons.resize(size);

    for(int i = 0; i < size; i++){
        this->neurons[i] = neuronPtr(new Neuron(inputsPerNeuron));
    }
}

int Layer::getNeuronCount(){

    return this->neurons.size();

}

neuronArray const Layer::getNeurons(){

    return this->neurons;

}