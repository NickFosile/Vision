#include "InnerLayer.h"

InnerLayer::InnerLayer() {
    this->connectionsSum = (unsigned int) 0;
    this->activator = nullptr;
    this->active = false;

}

void InnerLayer::setBiasNode(BiasNeuron *biasNode) {
    this->biasNode = biasNode;
}

void InnerLayer::setActivationFunction(ActivationFunction x) {

    if(x == HyperbolicTangent) {
        this->activator = new TanhActivator;
    }
    else {
        //todo throw error
        std::cout << "Error activation function not set."<<std::endl;
        return;
    }

    this->active = true;
}

unsigned int InnerLayer::getConnectionsSum(){
    return this->connectionsSum;
}

void InnerLayer::setConnectionsSum(unsigned int connSum) {
    this->connectionsSum = connSum;
}

BiasNeuron* InnerLayer::getBiasNode() {
    return this->biasNode;
}

void InnerLayer::deleteBiasNode() {
delete this->biasNode;
}

InnerLayer::~InnerLayer() {
    //dtor
}
