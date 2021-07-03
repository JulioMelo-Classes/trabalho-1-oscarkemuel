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

    // definitions
    cash_type wage = bet.get_wage();
    number_type rounds = bet.getRounds();
    size_t size = bet.size();
    set_of_numbers_type spots = bet.get_spots();
    float creditPerRound = wage/rounds;
    std::vector<std::vector<float> > table = bet.get_table();
    cash_type total = wage;

    cout
    << ">>> Aposta lida com sucesso!" << endl
    << "    " << "Você apostará um total de $" << wage << " créditos" << endl
    << "    " << "Jogará um total de " << rounds << " rodadas," " apostando $"<< creditPerRound << " cŕeditos por rodada" << endl << endl
    << "    " << "Sua aposta tem " << size << " números, eles são: ";
    cout << "[ ";
    for (auto &n : spots) {
      cout << to_string(n);
      cout << " ";
    }
    cout << "]" << endl;

    cout << "        " << "----------+-----------" << endl;
    cout << "        " << "Hits      | Retorno" << endl;
    for (int i = 0; i < (size + 1) ; i++){
      cout << "        " << i << "         | " << table[size-1][i] << endl;
    }

    // start rounds
    srand(time(NULL));
    for (int i = 0; i < rounds; i++){
      set_of_numbers_type numbers = {};
      cout << "        " << "------------------------------------------------------------" << endl;
      cout << "        ";
      cout << "Esta é a rodada #" << i+1 << " de " << rounds << ", sua aposta é $" << creditPerRound << ". Boa sorte!" << endl;

      cout << "        Os números sorteados são: [ ";
      while (numbers.size() < 20){
        int number = (rand() %(80)+1);
        bool isFree = true;
        for (int i = 0; i < numbers.size(); i++){
          if(numbers[i] == number){
            isFree = false;
            break;
          }else {
            isFree = true;
          }
        }
        if(isFree) {
          numbers.push_back(number);
          cout << number << " ";
        };
      }
      cout << "]" << endl << endl;
      set_of_numbers_type hits = bet.get_hits(numbers);
      float retorno = table[size-1][hits.size()];
      float faturamento = retorno * creditPerRound;
      total -= creditPerRound;
      total += faturamento;

      cout << "        ";
      cout << "Você acertou os números ";
      cout << "[ ";
      for (auto &n : hits) {
        cout << to_string(n);
        cout << " ";
      }
      cout << "], um total de " << hits.size() << " hits de " << size << endl;

      cout << "        ";
      cout << "Sua taxa de retorno é " << retorno << " , assim você sai com: $" << faturamento << endl;
      cout << "        ";
      cout << "Você possui um total de: $" << total << " créditos." << endl;
    }

    cout << ">>> Fim das rodadas!" << endl;
    cout << "--------------------------------------------------------------------" << endl << endl;
    cout << "======= Sumário =======" << endl;
    cout << ">>> Você gastou um total de $" << wage << " créditos" << endl;

    if((total-wage) > 0){
      cout << ">>> Hooray! você ganhou $" << (total-wage) << " créditos!" << endl;
    }

    cout << ">>> Você está saindo do jogo com um total de $" << total << " créditos." << endl << endl;
  }else {
    cout << "Problema ao ler arquivo" << endl;
    return 0;
  }
}
