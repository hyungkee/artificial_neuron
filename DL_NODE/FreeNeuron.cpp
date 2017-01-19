#include<vector>
#include "Neuron.h"
#include "FreeNeuron.h"

void FreeNeuron::updateZ() {
	double acc = 0;
	std::vector<double>::iterator w_iter = weights.begin();
	std::vector<Neuron*>::iterator n_iter = neuron_ptrs.begin();

	for (int i = 0; i < inNum; i++) {
		double weight = *w_iter;
		Neuron* neuron_ptr = *n_iter;
		acc += weight * (neuron_ptr->getA());
	}
	
	z = acc;
}

double FreeNeuron::getZ() {
	return z;
}

double FreeNeuron::getA() {
	return actFunc(z);
}
