#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include "InnerNeuron.h"


class OutputNeuron : public InnerNeuron {
    public:
        OutputNeuron();
        virtual ~OutputNeuron();
        void mapNeuron();

    protected:

    private:
};

#endif // OUTPUTNEURON_H
