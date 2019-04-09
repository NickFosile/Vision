#include "NetworkDisplay.h"

void NetworkDisplay::info(std::string msg, colors fg, colors bg) {

    t.fb(cyan, bg);
    std::cout<<"[";
    t.fb(red, bg);
    std::cout<<"Vision";
    t.fb(cyan, bg);
    std::cout<<"]:";
    t.fb(fg,bg);
    std::cout<<msg<<std::endl;
}

void NetworkDisplay::error(std::string error) {
    t.fb(cyan);
    std::cout<<"[";
    t.fb(red);
    std::cout<<"Error ";
    t.fb(cyan);
    std::cout<<"]";
    t.fb(dark_red);
    std::cout<<error<<std::endl;
}

void NetworkDisplay::denied(std::string msg) {
    t.fb(red, black);
    std::cout<<"[-]: " << msg << std::endl;
}

void NetworkDisplay::processing(std::string msg) {
    t.fb(dark_yellow);
    std::cout<<"[!]: ";
    t.fb(magenta);
    std::cout<<msg<<std::endl;
}

void NetworkDisplay::success(std::string msg) {
    t.fb(green);
    std::cout<<"[+]: "<<msg<<std::endl;
}

void NetworkDisplay::infotable(std::string *info, short int infoLength, colors fg, colors bg) {
    short int maxsize = 0;
    short int i = 0;
    for(i=0;i<infoLength;i++) {
        if((short int)info[i].length() > maxsize)
            maxsize = (short int) info[i].length();

    }
    maxsize += (short int)2;
    t.fb(cyan,black);
    std::cout<<"\n\t\tNETWORK INFORMATION"<<std::endl;
    std::cout<<"\t\t";
    for(i=0;i<maxsize;i++)
        std::cout<<"=";
    std::cout<<std::endl;
    for(i=0;i<infoLength;i++) {
        t.fb(cyan,black);
        std::cout<<"\t\t|";
        t.fb(fg,bg);

        std::string a = info[i];
        if((short int)info[i].length() < maxsize - 2) {
           short int diff = maxsize - 2 - (short int) info[i].length();
           for(;diff> 0; diff--)
                a += " ";
        }
        std::cout<<a;
        t.fb(cyan,black);
        std::cout<<"|"<<std::endl;
    }
    std::cout<<"\t\t";
    for(i=0;i<maxsize;i++)
        std::cout<<"=";
    std::cout<<std::endl;
    std::cout<<std::endl;
}
