#include "InnerNeuron.h"
#include <iostream>
#include "Randomizer.h"

InnerNeuron::InnerNeuron(){
    this->bias = 0.0;
    this->biasWeight = 0.0;
    this->weights = nullptr;
    this->connectionCount = (unsigned int) 0;
    this->connected = false;
}

void InnerNeuron::setWeight(double newWeight, unsigned int index) {
    if(this->weights != nullptr) {

        this->weights[index] = newWeight;
    }
}

double InnerNeuron::getWeight(unsigned int index) {
    if(this->weights == nullptr) {
        return 0.0;
    }
    return this->weights[index];
}

void InnerNeuron::setWeights(double* weightsArray, unsigned int connectionsCount) {
    if(this->weights == nullptr) {
        this->weights = new double[connectionsCount];
        this->setConnectionsCount(connectionsCount);
        this->connected = true;
    }
    else if (this->getConnectionsCount() != connectionsCount){
        //TODO throw error
        return;
    }
    unsigned int i = 0;
    for(i=0;i<connectionsCount;i++) {
        this->weights[i] = weightsArray[i];
    }
}

void InnerNeuron::initRandWeights(unsigned int connectionsCount) {
    Randomizer rand;
    if(this->weights == nullptr) {
        double randomWeights[connectionsCount];
        unsigned int i = 0;
        for(i=0;i<connectionsCount;i++) {
            randomWeights[i] = rand.randomWeight();
        }
        this->setWeights(randomWeights, connectionsCount);
    }
    else if(this->weights != nullptr) {
        if(this->getConnectionsCount() != connectionsCount) {
            std::cout<<"[Error] Inner neurons: the connections number and the number of new weights are different."<<std::endl;
            return;
        }
        else {
            unsigned int i =0;
            for(i=0;i<connectionsCount;i++) {
               this->weights[i] = rand.randomWeight();
            }
        }
    }
}

bool InnerNeuron::isConnected() {
    return this->connected;
}
double* InnerNeuron::getWeights() {
    return this->weights;
}

void InnerNeuron::setConnectionsCount(unsigned int count) {
    this->connectionCount = count;
}

unsigned int InnerNeuron::getConnectionsCount() {
    return this->connectionCount;
}

void InnerNeuron::setBias(double newBias) {
    this->bias = newBias;
}

double InnerNeuron::getBias() {
    return this->bias;
}

void InnerNeuron::setBiasWeight(double newBiasWeight) {
    this->biasWeight = newBiasWeight;
}

double InnerNeuron::getBiasWeight() {
    return this->biasWeight;
}

void InnerNeuron::setBiasNode(BiasNeuron * newBiasNode) {
    this->biasNode = newBiasNode;
}

BiasNeuron* InnerNeuron::getBiasNode() {
    return this->biasNode;
}

double InnerNeuron::setRandBiasWeight() {

    this->biasWeight = Randomizer::randomWeight();
    return this->biasWeight;
}

bool InnerNeuron::halfReset() {
    //todo complete it
    this->setBias(this->getBiasNode()->getValue() * this->getBiasWeight());
    return true;
}

InnerNeuron::~InnerNeuron()
{
    //dtor
}
