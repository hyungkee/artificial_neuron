#pragma once
#include<queue>
#include"Neuron.h"

class CompareNeuron {
public:
	bool operator()(Neuron* nm1, Neuron* nm2) {
		return nm1->getLevel() > nm2->getLevel();
	}
};

// it's singleton class
class NeuronManager {
public:
	// constructor
	NeuronManager() : dataNum(0), inputSize(0), outputSize(0) {};

	//method
	void setLearningData(int _dataNum, int _inputSize, int _outputSize, double** X, double** Y);
	void removeLearningData();
	void doLearning();
	std::vector<double> test(std::vector<double> testInput);

	void updateNeuron(Neuron* neuronPtr);

	// destructor
	virtual ~NeuronManager() { removeLearningData(); };


protected:
	int dataNum;
	int inputSize;
	int outputSize;
	std::queue<double*> inputQ;
	std::queue<double*> outputQ;
	std::priority_queue<Neuron*, std::vector<Neuron*>, CompareNeuron> updateQ; // TODO : set priority func
};