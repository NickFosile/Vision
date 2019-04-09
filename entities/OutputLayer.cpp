#include "OutputLayer.h"

OutputLayer::OutputLayer() {
    this->setDesc("Output Layer");
    this->setIndex((unsigned int)0);
    this->neuronPool = nullptr;
    this->setSize((unsigned int)0);

}

void OutputLayer::initialize(unsigned int sizee, unsigned int connectionsCount) {

    if(this->neuronPool != nullptr) {
        //todo throw error
        this->error(this->getDesc() + " " + std::to_string(this->getIndex()),"outputlayer creation error");
        return;
    }
    BiasNeuron *a = new BiasNeuron;
    this->setBiasNode(a);
    this->neuronPool = new OutputNeuron[sizee];
    this->setSize(sizee);
    this->setConnectionsSum(sizee * connectionsCount);
    unsigned int i = 0;
    for(i=0;i < this->getSize(); i++) {
        this->neuronPool[i].setBiasNode(this->getBiasNode());
        this->neuronPool[i].setRandBiasWeight();
        this->neuronPool[i].halfReset();
        this->neuronPool[i].setIndex(i);
        this->neuronPool[i].initRandWeights(connectionsCount);
    }
}

double* OutputLayer::getOutput() {
    if(this->neuronPool == nullptr) {
        //todo throw error no availiable output
        return nullptr;
    }
    unsigned int i = 0;
    double *outputData = new double[this->getSize()];
    for(i=0;i<this->getSize();i++) {
        outputData[i] = this->neuronPool[i].getActivation();
    }
    return outputData;
}

void OutputLayer::setInput(double *data, unsigned int dataLength) {
    if(dataLength != this->getConnectionsSum()/ this->getSize()) {
        //todo throw error
        this->error(this->getDesc() + std::to_string(this->getIndex()), " data length is not the same with the number of connections");
        return;
    }
    if(!this->active) {
        //todo throw error
        this->error(this->getDesc() + std::to_string(this->getIndex()), " This layer has no activation function.");
        return;
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

double* OutputLayer::getAllConnectionWeights() {
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

void OutputLayer::mapLayer() {

    this->info(this->getDesc() + " " + std::to_string(this->getIndex())," size:" + std::to_string(this->getSize()));
    unsigned int i = 0;
    for(i=0;i<this->getSize();i++) {
        this->neuronPool[i].mapNeuron();
    }
}

OutputLayer::~OutputLayer()
{
    //dtor
}
