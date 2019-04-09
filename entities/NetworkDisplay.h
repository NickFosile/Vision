#ifndef NETWORKDISPLAY_H
#define NETWORKDISPLAY_H
#include <string>
#include <iostream>
#include "Terminal.h"

extern Terminal t;

class NetworkDisplay {
    public:

    protected:
        void info(std::string msg, colors fg=gray, colors bg=black);
        void success(std::string msg);
        void error(std::string error);
        void denied(std::string msg);
        void processing(std::string msg);
        void infotable(std::string* info, short int infoLength, colors fg=green, colors bg=black);

    private:
};

#endif // NETWORKDISPLAY_H
