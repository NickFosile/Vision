#include <iostream>
#include "NeuralNetwork.h"
#include <fstream>
#include <string>
#include "Terminal.h"
#include <chrono>

Terminal t;
/* Code here is a bit messy because I hardcode some values in order to check if the network
is built and working. I will correct it soon.*/
int main(){
    std::ifstream in;
    in.open("banner", std::ios::in);
    std::string line;

    t.fb(cyan);
    while(std::getline(in, line))
        std::cout<<line<<std::endl;
    in.close();
    t.reset();
    std::cout<<std::endl;
    NeuralNetwork *a = new NeuralNetwork;
    std::cout<<"Create testing network? By selecting no, you will enter values manually (y/n):";
    char answer;
    std::cin>>answer;
    unsigned int inputLayerSize = (unsigned int)15;
    unsigned int hiddenLayerCount = (unsigned int)3;
    unsigned int outputLayerCount = (unsigned int)5;
    unsigned int *sizes;
    if(answer == 'n') {
        std::cout<<"Number of neurons in Input Layer:";
        std::cin>>inputLayerSize;
        std::cout<<"\nNumber of Hidden Layers:";
        std::cin>>hiddenLayerCount;
        sizes = new unsigned int[hiddenLayerCount];
        unsigned int i = (unsigned int) 0;
        for(i=0; i<hiddenLayerCount;i++) {
            std::cout<<"\nNumber of Neurons in "<<i+1<<" hidden Layer:";
            std::cin>>sizes[i];
        }
        std::cout<<"\nNumber of Neurons in OutputLayer: ";
        std::cin>>outputLayerCount;
    }
    else {
        sizes = new unsigned int[hiddenLayerCount];
        sizes[0] = 10;
        sizes[1] = 11;
        sizes[2] = 9;
    }

    auto start = std::chrono::high_resolution_clock::now();
    a->initialize(inputLayerSize,hiddenLayerCount, sizes, outputLayerCount);
    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> benchmark = ending - start;
    std::cout<<"Benchmark:"<< benchmark.count()<<std::endl;
    delete sizes;
    //a->mapNetwork();
            //todo fix it in case you change test values.
        double testData[15] = {0.45345,0.974553,2.3453423,1.43534,0.567544,7.23452,2.43534,1.5464334,0.123421,0.000234,0.043534,1.00004,0.654634,0.67542,-0.4353243};
        double randTestData[inputLayerSize];
        unsigned int xxx = (unsigned int )0;
        unsigned int yyy = (unsigned int )0;

        for(xxx=0;xxx<inputLayerSize;xxx++) {
                randTestData[xxx] = testData[yyy];
            if(yyy == (unsigned int) 14) {
                yyy = (unsigned int) 0;
                continue;
            }
            yyy++;

        }
        auto feedstart = std::chrono::high_resolution_clock::now();
        a->feed(randTestData,inputLayerSize);
        a->fullForwardPropagate();
        unsigned int outsize = a->outputSize();
        auto feedend = std::chrono::high_resolution_clock::now();
        double *out = a->getFinalOutput();
        unsigned int x = (unsigned int)0;

        //a->mapNetwork();
        std::cout<<"OUTPUT =========================\n";
        for(x = 0; x<outsize; x++)
            std::cout<<out[x]<< " ";
        std::cout<<"\n===================================================\n";
        std::chrono::duration<double> procbenchmark = feedend - feedstart;
        std::cout<<"Benchmark of data feed, process and output CYCLE:"<< procbenchmark.count()<<std::endl;


    return 0;
    //error below
    double *weights = a->getAllWeights();
    unsigned int i;
    t.fb(red);
    std::cout<< "\n===========\nALL WEIGHTS\n===========\n";
    t.reset();
    t.fb(black,dark_yellow);
    for(i=0;i < a->connections;i++) {
        std::cout<<weights[i] << " ";
    }
    delete weights;
    return 0;
}
