#include "OutputNeuron.h"
#include <iostream>

OutputNeuron::OutputNeuron() {
    this->setDesc("Output Neuron");
    this->setIndex((unsigned int)0);
}

void OutputNeuron::mapNeuron() {
    std::string description = this->getDesc() + " " + std::to_string(this->getIndex());
    std::string msg = " data: " + std::to_string(this->getData()) + " activation: " + std::to_string(this->getActivation()) + " Connections: " + std::to_string(this->getConnectionsCount());
    msg += "\n\t\t\t\t\tBias/BiasWeight: " + std::to_string(this->getBias()) + "/" + std::to_string(this->getBiasWeight());
    this->info(description, msg);
    unsigned int i = 0;
    this->initWeightStream();
    for(i=0; i<this->getConnectionsCount();i++)
        this->streamWeights(this->weights[i]);
    this->endWeightStream();
}


OutputNeuron::~OutputNeuron(){
    //dtor
}
