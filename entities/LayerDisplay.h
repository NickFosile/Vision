#ifndef LAYERDISPLAY_H
#define LAYERDISPLAY_H
#include "Terminal.h"
#include <iostream>
#include <string>

extern Terminal t;

class LayerDisplay {
    public:

    protected:
        void info(std::string description, std::string msg, colors fg = magenta, colors bg = black);
        void error(std::string description, std::string msg, colors fg = red, colors bg = black);
        void stats(std::string *info, short int infolength, colors fg = black, colors bg = dark_yellow);


    private:
};

#endif // LAYERDISPLAY_H
