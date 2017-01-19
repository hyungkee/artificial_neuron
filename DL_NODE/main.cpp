#include<iostream>
#include<vector>

#include"MLActivation.h"
#include"BiasNeuron.h"
#include"FreeNeuron.h"
#include"Neuron.h"


int main() {
	std::vector<Neuron*> input;
	std::vector<Neuron*> hidden;
	std::vector<Neuron*> output;

	input.push_back(new BiasNeuron());
	input.push_back(new FreeNeuron(Logistic));
	input.push_back(new FreeNeuron(Logistic));
	input.push_back(new FreeNeuron(Logistic));
	input.push_back(new FreeNeuron(Logistic));


	hidden.push_back(new BiasNeuron());
	hidden.push_back(new FreeNeuron(Logistic));
	hidden.push_back(new FreeNeuron(Logistic));
	hidden.push_back(new FreeNeuron(Logistic));
	hidden.push_back(new FreeNeuron(Logistic));

	output.push_back(new FreeNeuron(Logistic));
	output.push_back(new FreeNeuron(Logistic));

	system("pause");
	return 0;
}