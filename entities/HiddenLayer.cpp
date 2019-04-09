#include "HiddenLayer.h"
#include "BiasNeuron.h"
#include <iostream>
/**Creates a hidden layer.*/
HiddenLayer::HiddenLayer() {
    this->neuronPool = nullptr;
    this->setDesc("Hidden Layer");
}
/**Initializes a hidden layer, populating it with hidden neurons. Also inits randomly the connection weights
and creates a bias neuron to be used with all neurons in this layer, with default value 1.0.

@param size the number of neurons it should contain.
@param connectionsCount the number of neurons IN THE PREVIOUS layer, so as to initialize
corresponding connections. (connection weights created pseudo-randomly.*/
void HiddenLayer::initialize(unsigned int size, unsigned int connectionsCount) {
    if(this->neuronPool != nullptr) {
        //todo throw error
        std::cout<<"hiddenlayer creation error"<<std::endl;
        return;
    }
    this->setConnectionsSum(size * connectionsCount);
    BiasNeuron *a = new BiasNeuron;
    this->setBiasNode(a);
    this->neuronPool = new HiddenNeuron[size];
    this->setSize(size);
    unsigned int i = 0;
    for(i=0;i < this->getSize(); i++) {
        this->neuronPool[i].setBiasNode(this->getBiasNode());
        this->neuronPool[i].setRandBiasWeight();
        this->neuronPool[i].halfReset();
        this->neuronPool[i].setIndex(i);
        this->neuronPool[i].initRandWeights(connectionsCount);
    }
}

/**Prints on the console info about this layer and all its neurons.*/
void HiddenLayer::mapLayer() {
    this->info(this->getDesc() + " " + std::to_string(this->getIndex()), " size: " + std::to_string(this->getSize()));
    unsigned int i = 0;
    for(i=0;i<this->getSize();i++) {
        this->neuronPool[i].mapNeuron();
    }
}

/**Returns an array of all the connection weights of this layer's neurons with the previous layer's neurons.
ATTENTION you must delete the returned array, Or a memory leak will occure.*/
double* HiddenLayer::getAllConnectionWeights() {
    unsigned int i;
    unsigned int j;
    unsigned int k = (unsigned int) 0; //weights array index
    double *weights = new double[this->getConnectionsSum()];
    for(i=0;i<this->getSize();i++) {
        double *neuronWeights = this->neuronPool[i].getWeights();
        for(j=0; j < this->neuronPool[i].getConnectionsCount();j++) {
            weights[k] = neuronWeights[j];
            k++;
        }
    }
    return weights;
}
/**Returns an array of all activations of this layer' neuron activations. The array is on the free store, so delete it after use.*/
double* HiddenLayer::getOutput() {
    if(this->neuronPool == nullptr){
        //todo throw error
        return nullptr;
    }
    unsigned int i = 0;
    double *outputData = new double[this->getSize()];
    for(i=0;i<this->getSize();i++) {
        outputData[i] = this->neuronPool[i].getActivation();
    }
    return outputData;

}
/**Accepts an array of activation values from the previous layer to feed neurons of this layer.

@param data the array of activations.
@param dataLength, the length of the array.*/
void HiddenLayer::setInput(double* data, unsigned int dataLength) {

    if(dataLength != this->getConnectionsSum()/ this->getSize()) {
        //todo throw error
        this->error(this->getDesc() + std::to_string(this->getIndex()), " data length is not the same with the number of connections");
        std::cout<< "connections="<<this->getConnectionsSum();
        std::cout<<"\n data size="<<dataLength;
        return;
    }
    if(!this->active) {
        //todo throw error
        this->error(this->getDesc() + std::to_string(this->getIndex()), " This layer has no activation function.");
    }
    unsigned int i = (unsigned int) 0;
    for(i=0;i< this->getSize(); i++) {
        double rawData = 0.000000000000;
        unsigned int j = (unsigned int) 0;
        for(j=0;j<dataLength;j++) {
            double weight = this->neuronPool[i].getWeight(j);
            double result = weight * data[j];
            rawData += result;
        }
        this->neuronPool[i].setData(rawData);
        double activationValue = this->activator->activate(rawData + this->neuronPool[i].getBias());
        this->neuronPool[i].setActivation(activationValue);

    }
    //this function is ready.
}

HiddenLayer::~HiddenLayer() {
    this->deleteBiasNode();
    /*todo call a dispose on all neurons.*/
    delete this->neuronPool;
}
