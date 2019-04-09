#include "NeuralNetwork.h"
/** A neural network class containing layers and Neurons
*/
NeuralNetwork::NeuralNetwork() {
    this->built = false;
    this->ready = false;
    this->layersCount = (unsigned int) 0;
    this->neuronsCount = (unsigned int) 0;
    this->connections = (unsigned int) 0;
    this->hiddenLayersCount = (unsigned int) 0;
    this->dataPresent = false;
    this->outputReady = false;
}
/** Creates a classic Neural Network and sets random weights and biases.
This network will require training.
@param inputLayerSize
the number of neurons in the input layer
@param hiddenLayersCount
the number of hidden layers in the ANN
@param *hiddenLayersSizes
an array containing the size of each hidden layer. Each size in
the array corresponds to each hidden layer, in order. ATTENTION the number of sizes in the
array must be equal to the number of hidden layers
@param outputLayerSize
the number of neurons in the output layer.
*/
void NeuralNetwork::initialize(unsigned int inputLayerSize,
                               unsigned int hiddenLayersCount,
                               unsigned int *hiddenLayersSizes,
                            unsigned int outputLayerSize) {

    if(this->built || this->ready) {
        //todo throw error
        t.fb(red);
        std::cout<<"Neural Network already initialized. Please create a new one"<<std::endl;
        return;
    }
    /* build input layer. */

    this->info(" Creating Input Layer with " + std::to_string(inputLayerSize) + " Neurons.");
    this->inputLayer = new InputLayer;
    this->inputLayer->initialize(inputLayerSize);
    this->success("--- Input Layer created successfully.");
    this->neuronsCount += inputLayerSize;
    this->layersCount++;


    /* create hidden layers */
    unsigned int i = 0;
    this->info("Creating " + std::to_string(hiddenLayersCount)+ " Hidden Layers...");

    for(i=0;i<hiddenLayersCount;i++) {
        this->processing("--- Hidden Layer " + std::to_string(i+1) + " with " + std::to_string(hiddenLayersSizes[i]) + " Hidden Neurons..");

    this->hlayers = new HiddenLayer[hiddenLayersCount];
    }


    for(i=0;i<hiddenLayersCount;i++) {
        unsigned int numConnections;
        if(i == (unsigned int)0) {
            numConnections = this->inputLayer->getSize();
        }
        else {
            numConnections = this->hlayers[i-1].getSize();
        }

        this->hlayers[i].setIndex(i + 1);
        this->hlayers[i].initialize(hiddenLayersSizes[i], numConnections);
        this->hlayers[i].setActivationFunction(HyperbolicTangent);
        this->connections += numConnections * hiddenLayersSizes[i];
        this->layersCount++;
        this->hiddenLayersCount++;
        this->neuronsCount+=hiddenLayersSizes[i];

    }
    this->success(" Created " + std::to_string(this->getHiddenLayersCount())+ " Hidden Layers.");

    this->info(" Creating Output Layer with " + std::to_string(outputLayerSize) + " Neurons.");
    this->outputLayer = new OutputLayer;
    this->outputLayer->setIndex(hiddenLayersCount + 1);
    this->outputLayer->initialize(outputLayerSize, this->hlayers[hiddenLayersCount-1].getSize());
    this->outputLayer->setActivationFunction(HyperbolicTangent);
    this->layersCount++;
    this->connections += this->hlayers[hiddenLayersCount-1].getSize() * outputLayerSize;
    this->neuronsCount+= outputLayerSize;
    this->success(" Output Layer created successfully.");
    this->info(" Artificial Neural Network is ready with weighted connections RANDOMLY SET.",white, dark_blue);
    this->built = true;
    this->ready = true;
    t.reset();

}
/**Returns true if there is available output data on the output layer. On failed propagations, it returns false.
*/
bool NeuralNetwork::isOutputAvailiable() {
    return this->outputReady;
}

/** Returns the total number of Neurons in the Network.*/
unsigned int NeuralNetwork::getNeuronsCount() {
    return this->neuronsCount;
}

/**Returns the total number of Layers in the Network.*/
unsigned int NeuralNetwork::getLayersCount() {
    return this->layersCount;
}

/**Returns an array of doubles representing all the connection weights in all layers, ordered the same as the layers.
ex. The first double is the first weight of the first neuron of the first hidden layer, the second is the second weight in the first neuron of the first hidden layer, etc.
ATTENTION you must delete the returned pointer to the array, or a memory leak will occure.*/
double* NeuralNetwork::getAllWeights() {
    unsigned int connectionCount = (unsigned int) 0;
    unsigned int i;
    for(i=0;i<this->getHiddenLayersCount(); i++)
        connectionCount += this->hlayers[i].getConnectionsSum();
    connectionCount += this->outputLayer->getConnectionsSum();
    std::cout<<connectionCount<<" total connections"<<std::endl;
    double *weights = new double[connectionCount];
    unsigned int k = (unsigned int) 0;
    for(i=0;i<this->getHiddenLayersCount();i++) {
        unsigned int connSum = this->hlayers[i].getConnectionsSum();
        double *layerWeights = this->hlayers[i].getAllConnectionWeights();
        unsigned int j;
        for(j=0;j<connSum;j++) {
            weights[k] = layerWeights[j];
            k++;

        }
        delete layerWeights;
    }
    double *outWeights = this->outputLayer->getAllConnectionWeights();
    unsigned int connSum = this->outputLayer->getConnectionsSum();
    unsigned int j;
    for(j=0;j<connSum;j++) {
        weights[k] = outWeights[j];

        k++;
    }
    delete [] outWeights;

    return weights;
}

/**Returns the size of the output length, which is essensially the same with the size of the output layer. so the length will
always be the same. In case of zero, that means the output neurons pool is not initialized yet, so the whole neural network needs to be
built and initialized. */
unsigned int NeuralNetwork::outputSize() {
    return this->outputLayer->getSize();
}

double* NeuralNetwork::getFinalOutput() {

    return this->outputLayer->getOutput();
}
/** Outputs in console all network entities
with their data.*/
void NeuralNetwork::mapNetwork() {
    if(!this->ready) {
        this->error("[Mapping] Network has not been initialized yet. Aborting mapping.");
        return;
    }
    std::string *info = new std::string[5];
    info[0] = "1 Input Layer";
    info[1] = std::to_string(this->getHiddenLayersCount()) + " Hidden Layers";
    info[2] = "1 Output Layer";
    info[3] = std::to_string(this->getLayersCount()) + " Total Layers" ;
    info[4] = std::to_string(this->getNeuronsCount()) + " Total Neurons";
    this->infotable(info, (short int)5);
    delete info;
    this->inputLayer->mapLayer();
    unsigned int i = 0;
    for(i=0;i<this->getHiddenLayersCount();i++){
        this->hlayers[i].mapLayer();
    }

    this->outputLayer->mapLayer();
    return;
}
/** Changes the number indicating how many hidden layers the Network contains.
ATTENTION it doesn't change the actual number of hidden layers. Setting a number that
does not correspond to the actual number of hidden layers, will cause instability and errors.
@param num the number of Hidden Layers.
*/
void NeuralNetwork::setHiddenLayersCount(unsigned int num) {
    this->hiddenLayersCount = num;
}
/**Returns the number of hidden layers in the Network.*/
unsigned int NeuralNetwork::getHiddenLayersCount() {
    return this->hiddenLayersCount;
}

/**Insert data to the Neural Network. The data should be normalized, and with length equal to the number of
input Neurons. Throws error if the Neural Network is not built, or if the dataLength doesn't fit input layer size.

@param
data: array of doubles that represents the data to be fed.
@param
dataLength: the length of the data.*/
void NeuralNetwork::feed(double *data, unsigned int dataLength) {
    if(!this->ready){
        //todo throw error
        return;
    }
    if(this->inputLayer->getSize() != dataLength) {
        //throw error
        return;
    }
    this->inputLayer->setInput(data, dataLength);
    this->dataPresent = true;
}

/**Begins pushing the data through the network until it generates output. Throws an error if the neural network
is not fed data before this method is called, also throws error if network is not ready to work. If successful, the output data will be ready to be received,
and the length of the output data will be available.*/
void NeuralNetwork::fullForwardPropagate() {
    this->outputReady = false;
    if(!this->ready) {
        //todo throw error
        return;
    }
    if(!this->dataPresent) {
        //todo throw error
        return;
    }
    std::cout<<"Pushing Input Layer data to next layer."<<std::endl;
    double *data = this->inputLayer->getOutput();
    unsigned int i = (unsigned int)0;
    for(i=0;i<this->getHiddenLayersCount();i++) {
        std::cout<< "[!] Pushing data to Hidden Layer " << this->hlayers[i].getIndex() << std::endl;
        if(i==(unsigned int) 0) {
            //get data from input layer
            this->hlayers[i].setInput(data, this->inputLayer->getSize());
            delete [] data;
        }
        else {
            //get data from previous hidden layer.
            double *results = this->hlayers[i-1].getOutput();
            this->hlayers[i].setInput(results, this->hlayers[i-1].getSize());
            delete [] results;

        }
    }

    std::cout<< "[!] Pushing data to Output Layer " << std::endl;
    double *hiddenData = this->hlayers[this->getHiddenLayersCount() - (unsigned int) 1].getOutput();
    this->outputLayer->setInput(hiddenData, this->hlayers[this->getHiddenLayersCount() - (unsigned int) 1].getSize());
    delete [] hiddenData;
    std::cout<< "*** FORWARD PROPAGATION COMPLETE. OUTPUT AVAILIABLE. ***"<<std::endl;
    this->outputReady = true;

}

NeuralNetwork::~NeuralNetwork() {
    delete this->inputLayer;
    /*todo call a dispose function for each hidden layer.*/
    delete [] this->hlayers;
    delete this->outputLayer;
}
