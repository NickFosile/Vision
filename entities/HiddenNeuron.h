#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H

#include "InnerNeuron.h"


class HiddenNeuron : public InnerNeuron {
    public:
        HiddenNeuron();
        virtual ~HiddenNeuron();
        void mapNeuron();

    protected:

    private:
};

#endif // HIDDENNEURON_H
