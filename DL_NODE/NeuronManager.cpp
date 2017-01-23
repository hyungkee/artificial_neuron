#include"NeuronManager.h"

void NeuronManager::setLearningData(int _dataNum, int _inputSize, int _outputSize, double** X, double** Y) {

	// remove pre data.
	removeLearningData();

	// set new data.
	dataNum = _dataNum;
	inputSize = _inputSize;
	outputSize = _outputSize;

	for (int i = 0; i < dataNum; i++) {
		double* input = new double[inputSize];
		std::memcpy(input, X[i], sizeof(double)*inputSize);
		inputQ.push(input);

		double* output = new double[outputSize];
		std::memcpy(input, Y[i], sizeof(double)*outputSize);
		outputQ.push(output);
	}
}

void NeuronManager::removeLearningData() {
	for (int i = 0; i < inputQ.size(); i++) {
		delete[] inputQ.front();
		inputQ.pop();
	}
	inputSize = 0;

	for (int i = 0; i < outputQ.size(); i++) {
		delete[] outputQ.front();
		outputQ.pop();
	}
	outputSize = 0;
}

void NeuronManager::doLearning() {
	for (int i = 0; i < dataNum; i++) {
		double* input = inputQ.front();
		inputQ.pop();
		// TODO : do learning!!

		delete[] input;
	}
}

std::vector<double> NeuronManager::test(std::vector<double> testInput) {
	// TODO
	return std::vector<double>();
}

void NeuronManager::updateNeuron(Neuron* neuronPtr) {
	updateQ.push(neuronPtr);
}