#ifndef POINT_H
#define POINT_H

#include <vector>
#include <string>

class Perceptron {
	public:
		Perceptron();
		Perceptron(std::string, int);
		~Perceptron();

		void addData();
		void perceptronRule(double, double, double);
		void perceptronRule(double, double);
		double evaluate(double, double, double);
		double calcSigmoid(double lc);
		void printString();

		double nodes[4] = {1.0,1.0, 1.0,1.0};
		std::string fname;

		int instNo;
		double n = 0.01;
		double outputValue = 0.0;
};

#endif