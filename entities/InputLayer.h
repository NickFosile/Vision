#ifndef INPUTLAYER_H
#define INPUTLAYER_H
#include "Layer.h"
#include "InputNeuron.h"


class InputLayer:public Layer {
    public:
        InputLayer();
        virtual ~InputLayer();
        void setInput(double*, unsigned int length);
        double* getOutput();
        void initialize(unsigned int size);
        void mapLayer();

    protected:

    private:
       InputNeuron* neuronPool;

};

#endif // INPUTLAYER_H
