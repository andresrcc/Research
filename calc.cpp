#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Calculator {
public:
  Calculator(int, string, int);
  int add(int a, int b);
  void printValues();
private:
  int a,b;
  string op;
};

Calculator::Calculator(int left, string operation, int right): a(left), b(right), op(operation){
}

void Calculator::printValues(){
  cout << a << op << b << endl;
}

int main(int argc, char* argv[]){
  Calculator calc( atoi(argv[1]), (string)argv[2], atoi(argv[3]) );
  calc.printValues();
  return 0;
}
