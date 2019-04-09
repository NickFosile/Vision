#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <Neuron.h>


class InputNeuron : public Neuron {
    public:
        InputNeuron();
        virtual ~InputNeuron();
        void setData(double);
        void setActivation(double);
        void mapNeuron();
    protected:

    private:
};

#endif // INPUTNEURON_H
