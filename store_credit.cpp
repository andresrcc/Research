#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


vector<int> calculate(int credit, vector<int> prices){
  int length = prices.size();
  int sum;
  vector<int> indices;
  int i,j, compare;

  for(i=0;i<length;i++){
    compare = prices[i];
    for(j=0;j<length;j++){
      if(i != j){
	sum = compare + prices[j];
	if(sum == credit){
	  indices.push_back(i);
	  indices.push_back(j);
	  return indices;
	}
      }
    }
  }
  indices.push_back(0);
  indices.push_back(0);
  return indices;
}

int main(int argc, char *argv[]){
  string token;
  int cases, i, j, credit, items;
  vector<int> prices;
  vector<int> indices;
  
  ifstream f("input1.in");

  f >> token;
  cases = atoi(token.c_str());
  for(i = 0; i < cases; i++){
    f >> token;
    credit = atoi(token.c_str());
    f >> token;
    items = atoi(token.c_str());
    j = 0;
    while (j < items && f>>token){
      prices.push_back(atoi(token.c_str()));
      j++;
    }

    indices = calculate(credit, prices);

    if (indices[0] == 0 && indices[1] == 0){
      cout << "Case" << i  << ": ";
      cout << "No elements found that add up to given credit";
    }else{
      cout << "Case" << i  << ": ";
      cout <<  indices[0] << " " << indices[1] << endl;
    }
    prices.clear();

  }
  return 0;
}
