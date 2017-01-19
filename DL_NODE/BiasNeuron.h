#pragma once
#include "Neuron.h"

class BiasNeuron : public Neuron {
public:
	// constructor
	BiasNeuron() {};
	BiasNeuron(int _level) : Neuron(_level) {};
	BiasNeuron(double(*_actFunc)(double z)) : Neuron(_actFunc) {};
	BiasNeuron(int _level, double(*_actFunc)(double z)) : Neuron(_level, _actFunc) {};

	// getter
	double getZ();
	double getA();

	// method
	void updateZ();

	// destructor
	virtual ~BiasNeuron() {};
};