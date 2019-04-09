#ifndef INNERNEURON_H
#define INNERNEURON_H

#include <Neuron.h>
#include "BiasNeuron.h"


class InnerNeuron : public Neuron {
    public:
        InnerNeuron();
        virtual ~InnerNeuron();
        void setWeight(double, unsigned int);
        double getWeight(unsigned int);
        void setWeights(double*, unsigned int connectionsCount);
        double* getWeights();
        void initRandWeights(unsigned int);
        void setBias(double);
        double getBias();
        void setBiasWeight(double);
        double getBiasWeight();
        void setBiasNode(BiasNeuron*);
        BiasNeuron* getBiasNode();
        double setRandBiasWeight();
        bool halfReset();
        void setConnectionsCount(unsigned int);
        unsigned int getConnectionsCount();
        bool isConnected();

    protected:
        double *weights;
        double bias;
        BiasNeuron *biasNode;
        double biasWeight;
        unsigned int connectionCount;
        bool connected;

    private:
};

#endif // INNERNEURON_H
