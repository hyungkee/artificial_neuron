#include "BiasNeuron.h"

void BiasNeuron::updateZ() {
	z = 1;
}

double BiasNeuron::getZ() {
	return 1;
}

double BiasNeuron::getA() {
	return 1;
}
