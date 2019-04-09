#include "BiasNeuron.h"

/**A bias neuron with iternal value of 1.0. Can be changed.*/
BiasNeuron::BiasNeuron() {
    this->value = 1.0;
    //ctor
}

/**Sets a new value for the bias Neuron.

@param newValue the new value.*/
void BiasNeuron::setValue(double newValue) {
    this->value = newValue;
}
/**Returns the value of the bias neuron.*/
double BiasNeuron::getValue() {
    return this->value;
}

