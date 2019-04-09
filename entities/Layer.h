#ifndef LAYER_H
#define LAYER_H
#include "LayerDisplay.h"

class Layer: public LayerDisplay {
    public:
        Layer();
        virtual ~Layer();
        void setDesc(std::string);
        std::string getDesc();
        void setIndex(unsigned int);
        unsigned int getIndex();
        virtual void setSize(unsigned int);
        unsigned int getSize();
        virtual double* getOutput() = 0;
        virtual void setInput(double*, unsigned int length) = 0;
        virtual void mapLayer()=0;

    protected:

    private:
        std::string description;
        unsigned int index;
        unsigned int size;

};

#endif // LAYER_H
