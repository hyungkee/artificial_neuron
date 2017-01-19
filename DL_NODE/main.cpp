#include<iostream>
#include<vector>

#include"NeuronManager.h"
#include"MLActivation.h"
#include"BiasNeuron.h"
#include"FreeNeuron.h"
#include"Neuron.h"


// main for test
int main() {
	std::vector<Neuron*> input;
	std::vector<Neuron*> hidden;
	std::vector<Neuron*> output;

	// make test neurons
	input.push_back(new BiasNeuron(1));
	input.push_back(new FreeNeuron(1, Logistic));
	input.push_back(new FreeNeuron(1, Logistic));
	input.push_back(new FreeNeuron(1, Logistic));
	input.push_back(new FreeNeuron(1, Logistic));

	hidden.push_back(new BiasNeuron(2));
	hidden.push_back(new FreeNeuron(2, Logistic));
	hidden.push_back(new FreeNeuron(2, Logistic));
	hidden.push_back(new FreeNeuron(2, Logistic));
	hidden.push_back(new FreeNeuron(2, Logistic));

	output.push_back(new FreeNeuron(3, Logistic));
	output.push_back(new FreeNeuron(3, Logistic));

	// make connections

	// do learning
	int m = 100; // size of test case
	double **x; // inputs of test case
	double *y; // outputs of test case

	/* read m, x and y */

	for (int i = 0; i < m; i++) {
		std::vector<Neuron*>::iterator input_iter = input.begin();
		for (; input_iter != input.end(); ++input_iter) {
			Neuron* neuronPtr = *input_iter;
			// TODO : should be able to Set A directly.
//			neuronPtr->setA(<!--test inputs-->); 
			NeuronManager::getNeuronManager().updateNeuron(neuronPtr);
		}
	}

	system("pause");
	return 0;
}