#ifndef NEURON_H
#define NEURON_H
#include "NeuronDisplay.h"

class Neuron : public NeuronDisplay {
    public:
        Neuron();
        virtual ~Neuron();
        virtual void setData(double);
        virtual double getData();
        virtual void setActivation(double);
        virtual double getActivation();
        void setIndex(unsigned int);
        unsigned int getIndex();
        std::string getDesc();
        void setDesc(std::string);
        virtual void mapNeuron()=0;


    protected:
        double data;
        double activation;
        unsigned int index;
        std::string description;

    private:
};

#endif // NEURON_H
