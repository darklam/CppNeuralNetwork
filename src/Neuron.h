#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <memory>

typedef std::vector<double> doubleArray;


class Neuron {

protected:

    doubleArray weights;
    doubleArray lastDeltas;

public:

    Neuron(int);

    virtual double feed(const doubleArray &);

    virtual double feed(const double &);

    virtual void train(const doubleArray &, const double&, const double&);

    virtual doubleArray getWeights();

    virtual double getWeight(const int &);


};

class BiasNeuron : public Neuron {

public:

    BiasNeuron();

    virtual double feed(const doubleArray &);

    virtual void train(const doubleArray &, const double &, const double &);
};


typedef std::shared_ptr<Neuron> neuronPtr;
typedef std::vector<neuronPtr> neuronArray;

#endif