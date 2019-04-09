#include "NeuronDisplay.h"

void NeuronDisplay::info(std::string description, std::string msg) {
    t.fb(cyan,black);
    std::cout<<"\t\t[";
    t.fb(yellow);
    std::cout<<description;
    t.fb(cyan, black);
    std::cout<<"]: ";
    t.fb(white, black);
    std::cout<<msg<<std::endl;
}

void NeuronDisplay::initWeightStream() {
    this->streamWeights(0.0, true);
    return;
}

void NeuronDisplay::streamWeights(double weight, bool init) {
    static unsigned short int count = (unsigned short int)0;
    if(init) {
        count = (unsigned short int)0;
        return;
    }
    if(count == (unsigned short int)0)
        std::cout<< "\t\t\t\t";
    t.fb(white, blue);
    std::cout<<weight;
    count++;
    if(count >= (unsigned short int)20){
        count = (unsigned short int) 0;
        std::cout<< std::endl << "\t\t\t\t";
    }
}

void NeuronDisplay::endWeightStream() {
    std::cout<<std::endl;
    t.reset();
}
