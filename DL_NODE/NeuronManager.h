#pragma once
#include<queue>
#include"Neuron.h"

// it's singleton class
class NeuronManager {
public:
	// constructor
	NeuronManager() {};

	// class getter(singleton object)
	static NeuronManager& getNeuronManager() { return nm; };

	//method
	void updateNeuron(Neuron* neuronPtr) {
		updateQ.push(neuronPtr);
	}

	// destructor
	virtual ~NeuronManager() {};

protected:
	static NeuronManager nm;
	std::priority_queue<Neuron*> updateQ; // TODO : set priority func
};