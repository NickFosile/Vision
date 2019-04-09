#include "InputLayer.h"
#include "InputNeuron.h"

InputLayer::InputLayer() {
    this->setDesc("Input Layer");
    this->setIndex((unsigned int)0);
    this->setSize((unsigned int)0);
    this->neuronPool = nullptr;
}
void InputLayer::initialize(unsigned int size) {
    if(this->neuronPool != nullptr) {
        //todo throw error
        return;
    }
    this->neuronPool = new InputNeuron[size];
    this->setSize(size);
    unsigned int i = 0;
    for(i=0;i<this->getSize();i++) {
        this->neuronPool[i].setIndex(i);
    }
}

void InputLayer::mapLayer() {
    this->info(this->getDesc() + " " + std::to_string(this->getIndex()), " size: " + std::to_string(this->getSize()));
    unsigned int i = 0;
    for(i=0; i < this->getSize();i++) {
        this->neuronPool[i].mapNeuron();
    }
}

double* InputLayer::getOutput() {
    if(this->neuronPool == nullptr) {
        //todo throw error
        return nullptr;
    }
    double *output = new double[this->getSize()];
    unsigned int i = 0;
    for(i=0;i<this->getSize();i++) {
        output[i] = this->neuronPool[i].getActivation();
    }
    return output;
}

void InputLayer::setInput(double* data, unsigned int length) {
    if(length != this->getSize()){
        //todo throw data length error
        return;
    }
    if(this->neuronPool == nullptr) {
        //todo throw layerNotBuilt error
        return;
    }
    unsigned int i =0;
    for(i=0; i<length;i++) {
       this->neuronPool[i].setData(data[i]);
    }

}

InputLayer::~InputLayer(){
    //dtor
}
