#include "Neuron.h"
#include <string>

Neuron::Neuron(){
    this->description = "Basic Neuron ";
    this->data = 0.0;
    this->activation = 0.0;
}

void Neuron::setData(double newData) {
    this->data = newData;
}
double Neuron::getData() {
    return this->data;
}

void Neuron::setActivation(double newActivation) {
    this->activation = newActivation;
}
double Neuron::getActivation() {
    return this->activation;
}

void Neuron::setIndex(unsigned int newIndex) {
    this->index = newIndex;
}
unsigned int Neuron::getIndex() {
    return this->index;
}

std::string Neuron::getDesc() {
    return this->description;
}
void Neuron::setDesc(std::string newDesc) {
    this->description = newDesc;
}

Neuron::~Neuron()
{
    //dtor
}
