#ifndef NEURON_H
#define NEURON_H

#include <vector>

typedef std::vector<double> & doubleArrayRef;
typedef std::vector<double> doubleArray;


class Neuron {

protected:

    doubleArray weights;
    doubleArray lastDeltas;

public:

    Neuron(int);

    virtual double feed(const doubleArrayRef);

    virtual void train(const doubleArrayRef, const double&, const double&);


};

class BiasNeuron : public Neuron {

public:

    BiasNeuron();

    virtual double feed(const doubleArrayRef);

    virtual void train(const doubleArrayRef, const double &, const double &);
};

#endif