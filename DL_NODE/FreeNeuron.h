#pragma once
#include "Neuron.h"

class FreeNeuron : public Neuron {
public:
	// constructor
	FreeNeuron() {};
	FreeNeuron(double(*_actFunc)(double z)) : Neuron(_actFunc) {};

	// getter
	double getZ();
	double getA();

	// method
	void updateZ();

	// destructor
	virtual ~FreeNeuron() {};
};