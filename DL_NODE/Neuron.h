#pragma once
#include<iostream>
#include<vector>

class Neuron {
public:

	// constructor
	Neuron() : errors(0), inNum(0), actFunc(NULL), z(0) {};
	Neuron(double(*_actFunc)(double z)) :errors(0), inNum(0), actFunc(_actFunc), z(0) { }

	// getter
	virtual double getZ() = 0; // pure virtual func
	virtual double getA() = 0; // pure virtual func
	double getError() { return errors; }
	int getInNum() { return inNum; }

	// setter
	void setActFunc(double(*_actFunc)(double z)) { actFunc = _actFunc; }

	// methods
	virtual void updateZ() = 0; // pure virtual func
	Neuron& addNeuron(Neuron* neuron_ptr) {
		inNum++;
		neuron_ptrs.push_back(neuron_ptr);
		return (*this);
	}

	// virtual destructor
	virtual ~Neuron() {
	}

protected:
	int inNum;
	double z;
	double errors;
	double (*actFunc)(double z);
	std::vector<double>	weights;
	std::vector<Neuron*> neuron_ptrs;
};