#pragma once
#include "Neuron.h"

class BiasNeuron : public Neuron {
public:
	// constructor
	BiasNeuron() {};
	BiasNeuron(double(*_actFunc)(double z)) : Neuron(_actFunc) {};

	// getter
	double getZ();
	double getA();

	// method
	void updateZ();

	// destructor
	virtual ~BiasNeuron() {};
};