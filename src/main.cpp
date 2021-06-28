#include <iostream>
#include <fstream>
#include <vector>
#include "../include/kenobet.hpp"

int main(int argc, char *argv[]){
  ifstream file;
  string row;
  int line = 0;
  file.open(argv[1]);
  KenoBet bet;

  if(file.is_open()){
    while (getline(file, row)){
      if(line == 0){
        bet.set_wage(stof(row));
      }
      if(line == 2) bet.setValues(row);
      line++;
    }
    file.close();

    cout << bet.printSpots() << endl;
    cout << setprecision(2) << bet.printWage() << endl;
  }else {
    cout << "Problema ao ler arquivo" << endl;
    return 0;
  }
}
