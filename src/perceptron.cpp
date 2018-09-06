#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <ctype.h>
#include "point.h"

using namespace std;

//Default contr
Perceptron::Perceptron() {

}

//initializes a perceptron with instance no and adds in the training data
Perceptron::Perceptron(std::string fname, int instNo): fname(fname), instNo(instNo)  {

}

//destructor
Perceptron::~Perceptron() {

}

//applies the perceptron rule : sigma wixi and then sigmoid
void Perceptron::perceptronRule(double input1, double input2, double input3) {
   double sigma = (input1*nodes[0]) + (input2*nodes[1]) + (input3*nodes[2]) + nodes[3];
   double t = calcSigmoid(sigma);
   cout << "Neuron Output "<<instNo <<": "<< t << endl;
   outputValue = t;
}

//applies the perceptron rule : sigma wixi and then sigmoid
void Perceptron::perceptronRule(double input1, double input2) {
   double sigma = (input1*nodes[0]) + (input2*nodes[1]) + nodes[2];
   double t = calcSigmoid(sigma);
   cout << "Output Neuron Output "<<instNo <<": "<< t << endl;
   outputValue = t;
}

double Perceptron::evaluate(double input1, double input2, double input3) {
   int sigma = (input1*nodes[0]) + (input2*nodes[1]) + (input3*nodes[2]) + nodes[3];
   return calcSigmoid(sigma);
}

void Perceptron::printString() {
   cout
   << "The Perceptron "
   << instNo
   << " has weights "
   << nodes[0] << ", " 
   << nodes[1] << " and a bias of"
   << nodes[2]
   << endl;
}

double Perceptron::calcSigmoid(double lc) {
   return 1.0/(1+exp(-lc));
}

//opens a text file
//adds training data and usses the perception rul to change weightings
void Perceptron::addData() {

   ifstream ifs(fname.c_str());
   vector<double> inputData;
   string line;
   string word;

   //read in all values into a vector
   if (ifs.is_open()) {
      while(getline(ifs, line)){
         stringstream iss(line);
         while(iss>>word)
            inputData.push_back(stod(word));
      }
   }
   ifs.close();
   if(inputData.size()>2) {
      perceptronRule(inputData.at(0), inputData.at(1), inputData.at(2));
   }
   else {
      perceptronRule(inputData.at(0), inputData.at(1));
   }
}
