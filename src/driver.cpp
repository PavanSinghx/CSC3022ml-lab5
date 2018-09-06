#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

#include "point.h"

using namespace std;

int main(){

   double y = 0.36;
  
   //loads up perceptron with default wights and bias

   //hidden layers
   cout << "Question One" << endl;
   cout << "" <<endl;

   Perceptron input1("../input1.txt", 1);
   //weights
   input1.nodes[0] = 0.1;input1.nodes[1] = 0.2;input1.nodes[2] = 0.5;input1.nodes[3] = 0.1;
   input1.addData();

   Perceptron input2("../input2.txt", 2);
   //weights
   input2.nodes[0] = -0.4;input2.nodes[1] = 1;input2.nodes[2] = -0.6;input2.nodes[3] = -0.3;
   input2.addData();


   cout << "" <<endl;

   cout << "Question Two" << endl;
   cout << "" <<endl;

   Perceptron input3("../input3.txt", 3);

   //weights
   input3.nodes[0] = input1.outputValue;
   input3.nodes[1] = input2.outputValue;
   input3.nodes[2] = -0.3;

   input3.addData();

   cout << "" <<endl;

   cout << "Question Three" << endl;
   cout << "" <<endl;
   

   double ms1 = (y-input1.outputValue)*(y-input1.outputValue);
   double ms2 = (y-input2.outputValue)*(y-input2.outputValue);

   double q3 = 0.5*(y-input3.outputValue)*(y-input3.outputValue);
   cout << "The Mean Square: " <<q3<< endl;
}

