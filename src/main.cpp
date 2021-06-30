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
    cout << "\n>>> Lendo arquivo de apostas [" << argv[1] << "], por favor aguarde..." << endl;
    cout << "---------------------------------------------------------------------" << endl;

    try{
      while (getline(file, row)){
      if(line == 0){
        status = bet.set_wage(stof(row));
      }
      if(line == 1){
        bet.setRounds(stoi(row));
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

    cout
    << ">>> Aposta lida com sucesso!" << endl
    << "    " << "Você apostará um total de $" << bet.get_wage() << " créditos" << endl
    << "    " << "Jogará um total de " << bet.getRounds() << " rodadas," " apostando $"<< bet.getCreditPerRound() << " cŕeditos por rodada" << endl << endl
    << "    Sua aposta tem " << bet.size() << " números, eles são: " << bet.printSpots() << endl
    << endl;
  }else {
    cout << "Problema ao ler arquivo" << endl;
    return 0;
  }
}
