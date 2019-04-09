#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include "BiasNeuron.h"
#include "Layer.h"
#include "InnerLayer.h"
#include "HiddenNeuron.h"

class HiddenLayer : public Layer, public InnerLayer {
    public:
        HiddenLayer();
        virtual ~HiddenLayer();
        void initialize(unsigned int, unsigned int);
        double* getOutput();
        void setInput(double*, unsigned int);
        void mapLayer();
        double* getAllConnectionWeights();

    protected:

    private:
        HiddenNeuron *neuronPool;
};

#endif // HIDDENLAYER_H
