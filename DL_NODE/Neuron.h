#pragma once
#include<iostream>
#include<vector>

class Neuron {
public:

	// constructor
	Neuron() : level(1), errors(0), actFunc(NULL), z(0) {};
	Neuron(int _level) : level(_level), errors(0), actFunc(NULL), z(0) {};
	Neuron(double(*_actFunc)(double z)) :level(0), errors(0), actFunc(_actFunc), z(0) { }
	Neuron(int _level, double(*_actFunc)(double z)) :level(_level), errors(0), actFunc(_actFunc), z(0) { }

	// getter
	virtual double getZ() = 0; // pure virtual func
	virtual double getA() = 0; // pure virtual func
	double getError()	{	return errors;}
	int getInNum()		{	return inNeuronPtrs.size();}
	int getOutNum()		{	return outNeuronPtrs.size();}
	int getLevel()		{	return level;}

	// setter
	void setActFunc(double(*_actFunc)(double z)) { actFunc = _actFunc; }

	// methods
	virtual void updateZ() = 0; // pure virtual func
	Neuron& connectNeuron(Neuron* targetNeuronPtr) {
		inNeuronPtrs.push_back(targetNeuronPtr);
		targetNeuronPtr->outNeuronPtrs.push_back(this);
		return (*this);
	}

	// virtual destructor
	virtual ~Neuron() {
	}

protected:
	int level;
	double z;
	double errors;
	double (*actFunc)(double z);
	std::vector<double>	weights;
	std::vector<Neuron*> inNeuronPtrs;
	std::vector<Neuron*> outNeuronPtrs;
};