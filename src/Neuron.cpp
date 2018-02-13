#include "Neuron.h"
#include "Functions.h"
#include "Random.h"


Neuron::Neuron(int inputs){
    this->weights.resize(inputs);
    for(auto &weight : this->weights){
        weight = Random::randomDouble();
    }
}

double Neuron::feed(const doubleArrayRef in){
    double sum = 0.0;

    if(in.size() != this->weights.size()) return -1; // *** ghetto error code lol ***

    for(int i = 0; i < in.size(); i++){
        sum += this->weights[i] * in[i];
    }

    return Functions::sigmoid(sum);
}

void Neuron::train(const doubleArrayRef deltas, const double &learningRate, const double &momentum){
    if(this->lastDeltas.empty()){

        for(int i = 0; i < this->weights.size(); i++){
            this->lastDeltas[i] = deltas[i] * learningRate;
            this->weights[i] -= lastDeltas[i];
        }

    }else{

        for(int i = 0; i < this->weights.size(); i++){
            this->lastDeltas[i] = (this->lastDeltas[i] * momentum + (1 - momentum) * deltas[i]) * learningRate;
            this->weights[i] -= lastDeltas[i];
        }

    }
}

BiasNeuron::BiasNeuron() : Neuron(0){

}

double BiasNeuron::feed(const doubleArrayRef){
    return 1.0;
}

void BiasNeuron::train(const doubleArrayRef deltas, const double &learningRate, const double &momentum){
    // Just do nothing lol
    // Added this for compatibility reasons and to save myself from headacke lol
}