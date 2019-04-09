#ifndef INNERLAYER_H
#define INNERLAYER_H
#include "BiasNeuron.h"
#include "TanhActivator.h"
#include <iostream>//todo remove it after cleaning debug couts.

enum ActivationFunction {
    HyperbolicTangent = 0

};

class InnerLayer {
    public:
        InnerLayer();
        virtual ~InnerLayer();
        void setBiasNode(BiasNeuron*);
        BiasNeuron* getBiasNode();
        virtual double* getAllConnectionWeights()=0;
        unsigned int getConnectionsSum();
        void setActivationFunction(ActivationFunction x);

    protected:
        void setConnectionsSum(unsigned int);
        void deleteBiasNode();
        Activator *activator;
        bool active;


    private:
        BiasNeuron *biasNode;
        unsigned int connectionsSum;

};

#endif // INNERLAYER_H
