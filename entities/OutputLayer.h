#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H
#include "OutputNeuron.h"
#include "Layer.h"
#include "InnerLayer.h"

class OutputLayer : public Layer, public InnerLayer {
    public:
        OutputLayer();
        virtual ~OutputLayer();
        double* getOutput();
        void setInput(double*, unsigned int);
        void mapLayer();
        void initialize(unsigned int, unsigned int);
        double* getAllConnectionWeights();

    protected:

    private:
        OutputNeuron *neuronPool;
};

#endif // OUTPUTLAYER_H
