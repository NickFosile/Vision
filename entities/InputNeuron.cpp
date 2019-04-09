#include "InputNeuron.h"
#include <iostream>

InputNeuron::InputNeuron(){
    this->setDesc("Input Neuron");
    this->setIndex((unsigned int)0);
    this->setActivation(0.0);
    this->setData(0.0);

}

void InputNeuron::setData(double newData) {
    this->data = newData;
    this->activation = newData;

}

void InputNeuron::mapNeuron() {

    std::string description = this->getDesc() + " " + std::to_string(this->getIndex());
    std::string msg = " Data/Activation = " + std::to_string(this->getData());
    this->info(description, msg);

}

void InputNeuron::setActivation(double newActivation) {
    this->data = newActivation;
    this->activation = newActivation;
}

InputNeuron::~InputNeuron() {
    //dtor
}
