#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::cout;
using std::string;
using std::ifstream;
using std::stringstream;
using std::atoi;
using std::endl;

class translator {
public:
  vector<int> translate(string token);
  void print(vector<int> translation);
  translator();
private:
  void fill_table();
  map<char,int> table;
};

translator::translator(){
  fill_table();
}


void translator::fill_table(){

  for(int i = 0; i <= 9; i++){
    switch(i){
    case 0:
      table['+'] = 0;
      break;
    case 1:
      break;
    case 2:
      table['A'] = 2;
      table['b'] = 22;
      table['c'] = 222;
      break;
    case 3:
      table['d'] = 3;
      table['e'] = 33;
      table['f'] = 333;
      break;
    case 4:
      table['g'] = 4;
      table['h'] = 44;
      table['i'] = 444;
      break;
    case 5:
      table['j'] = 5;
      table['k'] = 55;
      table['l'] = 555;
      break;
    case 6:
      table['m'] = 6;
      table['n'] = 66;
      table['o'] = 666;
      break;
    case 7:
      table['p'] = 7;
      table['q'] = 77;
      table['r'] = 777;
      table['s'] = 7777;
      break;
    case 8:
      table['t'] = 8;
      table['u'] = 88;
      table['v'] = 888;
      break;
    case 9:
      table['w'] = 9;
      table['x'] = 99;
      table['y'] = 999;
      table['z'] = 9999;
      break;

    }
  }
}

vector<int>translator::translate(string token){
  int length = token.size();
  vector<int> translation;
  int value;
  for(int i = 0; i < length; i++){
    value = table[token[i]];
    translation.push_back(value);
  }
  return translation;
}

void translator::print(vector<int> translation){
  int length = translation.size();
  for (int i = 0; i < length; i++){
    cout << translation[i];
  }
}

int main(){
  ifstream f("input2.in");
  stringstream ss;
  int cases;
  string token;
  translator phonekeys;
  vector<int> translation;

  std::getline(f,token);
  ss << token;
  ss >> token;
  cases = atoi(token.c_str());

  for(int i = 1; i <= cases; i++){
    std::getline(f,token);
    ss << token;
    while(ss >> token){
      translation = phonekeys.translate(token);
      phonekeys.print(translation);
      cout << ' ';
    }
    cout << endl;
  }
}
