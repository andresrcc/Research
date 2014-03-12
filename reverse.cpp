#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

vector<string> rev(string token){
  stringstream ss;
  vector<string> words;
  int i, length;
  string temp;

  ss << token;
  while(ss>>token){
    words.push_back(token);
  }
  length = words.size();

  for(i = 0; i < length-1 - i; i++){ 
    temp = words[length-1-i];
    words[length-1-i] = words[i];
    words[i] = temp;
  }
  return words;

}


int main(){
  int cases, i, j, length;
  string token;
  vector<string> rev_words;

  ifstream f("input2.in");
  
  f >> token;
  cases = atoi(token.c_str());
  getline(f,token);
  for (i = 0; i < cases; i++){
    getline(f,token);
    
    rev_words = rev(token);

    length = rev_words.size();
    cout << "Case #" << i+1 << ": ";
    for(j = 0; j < length; j++){
      cout << rev_words[j] << " ";
    }
    cout << endl;
    rev_words.clear();
  }
}

