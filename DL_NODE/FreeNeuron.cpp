#include<vector>
#include "Neuron.h"
#include "FreeNeuron.h"
#include "NeuronManager.h"

void FreeNeuron::updateZ() {
	double acc = 0;
	std::vector<double>::iterator w_iter = weights.begin();
	std::vector<Neuron*>::iterator i_n_iter = inNeuronPtrs.begin();

	// calculate Z
	for (int i = 0; i < getInNum(); i++) {
		double weight = *w_iter;
		Neuron* neuronPtr = *i_n_iter;
		acc += weight * (neuronPtr->getA());
	}
	
	// update Z
	z = acc;

	// forward propagation
	std::vector<Neuron*>::iterator o_n_iter = outNeuronPtrs.begin();
	for (int i = 0; i < getOutNum(); i++) {
		Neuron* neuronPtr = *o_n_iter;
//		neuronPtr->updateZ(); // TODO : it should be changed to inserting to priority Queue.(In Process based simulation..)
//		NeuronManager::getNeuronManager().updateNeuron(neuronPtr);
	}
}

double FreeNeuron::getZ() {
	return z;
}

double FreeNeuron::getA() {
	return actFunc(z);
}
