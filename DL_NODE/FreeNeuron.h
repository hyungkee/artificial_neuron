#pragma once
#include "Neuron.h"

class FreeNeuron : public Neuron {
public:
	// constructor
	FreeNeuron() {};
	FreeNeuron(int _level) : Neuron(_level) {};
	FreeNeuron(double(*_actFunc)(double z)) : Neuron(_actFunc) {};
	FreeNeuron(int _level, double(*_actFunc)(double z)) : Neuron(_level, _actFunc) {};

	// getter
	double getZ();
	double getA();

	// method
	void updateZ();

	// destructor
	virtual ~FreeNeuron() {};
};