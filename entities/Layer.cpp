#include "Layer.h"

Layer::Layer(){
    this->setDesc("basic Layer");
    this->setIndex((unsigned int)0);
    this->setSize((unsigned int)0);
}

void Layer::setDesc(std::string desc) {
    this->description = desc;
}

std::string Layer::getDesc() {
    return this->description;
}

void Layer::setIndex(unsigned int newIndex) {
    this->index = newIndex;
}

unsigned int Layer::getIndex() {
    return this->index;
}

void Layer::setSize(unsigned int newSize) {
    this->size = newSize;
}

unsigned int Layer::getSize() {
    return this->size;
}
Layer::~Layer() {
    //dtor
}
