#ifndef NEURONDISPLAY_H
#define NEURONDISPLAY_H
#include <iostream>
#include <string>
#include "Terminal.h"

extern Terminal t;

class NeuronDisplay {

protected:
    void info(std::string description, std::string msg);
    void streamWeights(double weight, bool init= false);
    void endWeightStream();
    void initWeightStream();
};

#endif // NEURONDISPLAY_H
