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
  bool status = true;

  if(file.is_open()){
    try{
      while (getline(file, row)){
      if(line == 0){
        status = bet.set_wage(stof(row));
      }
      if(line == 2) status = bet.setValues(row);
      line++;
      if(!status) return 0;
    }
    } catch(const std::exception& e) {
      cout << "Formato incorreto" << endl;
      return 0;
    }

    file.close();

    cout << bet.printSpots() << endl;
    cout << setprecision(2) << bet.printWage() << endl;
  }else {
    cout << "Problema ao ler arquivo" << endl;
    return 0;
  }
}
