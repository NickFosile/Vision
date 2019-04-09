#ifndef BIASNEURON_H
#define BIASNEURON_H


class BiasNeuron {
    public:
        BiasNeuron();
        void setValue(double);
        double getValue();

    protected:
        double value;

    private:
};

#endif // BIASNEURON_H
