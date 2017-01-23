#include<iostream>
#include<vector>

#include"NeuronManager.h"
#include"MLActivation.h"
#include"BiasNeuron.h"
#include"FreeNeuron.h"
#include"Neuron.h"


// main for test
int main() {
	NeuronManager neuronManager;

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

	output.push_back(new BiasNeuron(3));
	output.push_back(new FreeNeuron(3, Logistic));
	output.push_back(new FreeNeuron(3, Logistic));

	// make connections
	input.at(0)->connectNeuron(hidden.at(1));
	input.at(0)->connectNeuron(hidden.at(2));
	input.at(0)->connectNeuron(hidden.at(3));
	input.at(0)->connectNeuron(hidden.at(4));
	input.at(1)->connectNeuron(hidden.at(1));
	input.at(1)->connectNeuron(hidden.at(4));
	input.at(2)->connectNeuron(hidden.at(1));
	input.at(2)->connectNeuron(hidden.at(2));
	input.at(2)->connectNeuron(hidden.at(3));
	input.at(3)->connectNeuron(hidden.at(2));
	input.at(3)->connectNeuron(hidden.at(3));
	input.at(3)->connectNeuron(hidden.at(4));
	input.at(4)->connectNeuron(hidden.at(1));
	input.at(4)->connectNeuron(hidden.at(4));

	hidden.at(0)->connectNeuron(output.at(1));
	hidden.at(0)->connectNeuron(output.at(2));
	hidden.at(1)->connectNeuron(output.at(1));
	hidden.at(2)->connectNeuron(output.at(1));
	hidden.at(2)->connectNeuron(output.at(2));
	hidden.at(3)->connectNeuron(output.at(1));
	hidden.at(3)->connectNeuron(output.at(2));
	hidden.at(4)->connectNeuron(output.at(2));

	// do learning

	int dataNum = 5;
	int inputSize = 4;
	int outputSize = 2;
	double **X; // inputs of test case
	double **Y; // outputs of test case

	FILE *fp;
	fopen_s(&fp, "input.txt", "r");

	fscanf_s(fp, "%d %d %d", &dataNum, &inputSize, &outputSize);

	X = new double*[dataNum];
	for (int i = 0; i < dataNum; i++) {
		X[i] = new double[inputSize];
		for (int j = 0; j < inputSize; j++)
			fscanf_s(fp, "%lf", &X[i][j]);
	}

	Y = new double*[dataNum];
	for (int i = 0; i < dataNum; i++) {
		Y[i] = new double[outputSize];
		for (int j = 0; j < outputSize; j++)
			fscanf_s(fp, "%lf", &Y[i][j]);
	}

	neuronManager.setLearningData(dataNum, inputSize, outputSize, X, Y);
	neuronManager.doLearning();


	// do testing
	std::vector<double> testInput;
	testInput.push_back(10);
	testInput.push_back(20);
	testInput.push_back(30);
	testInput.push_back(40);

	std::vector<double> testOutput;
	testOutput = neuronManager.test(testInput);

	system("pause");
	return 0;
}