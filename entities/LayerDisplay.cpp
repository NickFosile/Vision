#include "LayerDisplay.h"

void LayerDisplay::info(std::string description, std::string msg, colors fg, colors bg) {
    t.fb(white, black);
    std::cout<<"[";
    t.fb(black, gray);
    std::cout<< description;
    t.fb(white, black);
    std::cout<<"]: ";
    t.fb(fg, bg);
    std::cout<<msg<<std::endl;
    t.reset();
}

void LayerDisplay::error(std::string description, std::string msg, colors fg, colors bg) {
    t.fb(fg, bg);
    std::cout<<"[Error]:";
    this->info(description, msg, dark_red, black);

}

void LayerDisplay::stats(std::string *info, short int infoLength, colors fg, colors bg) {
    short int i;
    t.fb(fg, bg);
    for(i=0;i<infoLength;i++)
        std::cout<<info[i];

}


