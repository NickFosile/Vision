#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include "NetworkDisplay.h"

class NeuralNetwork: public NetworkDisplay {
    public:
        NeuralNetwork();
        virtual ~NeuralNetwork();
        void initialize(unsigned int inputLayerSize,
                        unsigned int hiddenLayersCount,
                        unsigned int *hiddenLayersSizes,
                        unsigned int outputLayerSize);


        unsigned int getHiddenLayersCount();
        unsigned int getLayersCount();
        unsigned int getNeuronsCount();
        double* getAllWeights();
        void mapNetwork();
        void feed(double*, unsigned int);
        void fullForwardPropagate();
        unsigned int connections;
        bool isOutputAvailiable();
        unsigned int outputSize();
        double* getFinalOutput();



    protected:
        void setLayersCount(unsigned int);
        void setHiddenLayersCount(unsigned int);
        void setNeuronsCount(unsigned int);

        bool dataPresent;

    private:
        InputLayer* inputLayer;
        HiddenLayer *hlayers;
        OutputLayer* outputLayer;
        unsigned int hiddenLayersCount;
        unsigned int layersCount;
        unsigned int neuronsCount;
        bool built;
        bool ready;
        bool outputReady;

};

#endif // NEURALNETWORK_H
