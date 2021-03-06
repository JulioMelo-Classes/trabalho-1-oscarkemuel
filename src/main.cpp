#include <iostream>
#include <fstream>
#include <vector>
#include "../include/kenobet.hpp"

/*! Write an array in [ 1 2 3 ] format
  @param array Array of type set_of_numbers_type .*/
void printArray(set_of_numbers_type array) {
  cout << "[ ";
  for (auto &n : array) {
    cout << to_string(n);
    cout << " ";
  }
  cout << "]";
}

/*
Avaliação
Processamento do Arquivo de Entrada: 1
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 1

Comentários
- Vi que você não usou algoritmos de ordenação, o que poderia melhorar bastante a complexidade (tempo de execução)
para encontrar os hits
- Você poderia dividir mais o programa em termos das checagens do arquivo de entrada e interface textual, o que
reduziria bastante o main.
*/

int main(int argc, char *argv[]){
  ifstream file;
  string row;
  string path = "../data/";
  path += argv[1];
  int line = 0;

  file.open(path);

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
    table_type table = bet.get_table();
    cash_type total = wage;

    if(size == 0){
      cout << "Formato errado" << endl;
      return 0;
    }

    cout
    << ">>> Aposta lida com sucesso!" << endl
    << "    " << "Você apostará um total de $" << wage << " créditos" << endl
    << "    " << "Jogará um total de " << rounds << " rodadas," " apostando $"<< creditPerRound << " cŕeditos por rodada" << endl << endl
    << "    " << "Sua aposta tem " << size << " números, eles são: ";
    printArray(spots);
    cout << endl;

    cout << "        " << "----------+-----------" << endl
    << "        " << "Hits      | Retorno" << endl;
    for (int i = 0; i < (size + 1) ; i++){
      cout << "        " << i << "         | " << table[size-1][i] << endl;
    }

    // start rounds
    srand(time(NULL));
    for (int i = 0; i < rounds; i++){
      set_of_numbers_type numbers = {};
      cout << "        " << "------------------------------------------------------------" << endl
      << "        "
      << "Esta é a rodada #" << i+1 << " de " << rounds << ", sua aposta é $" << creditPerRound << ". Boa sorte!" << endl

      << "        Os números sorteados são: ";
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
        };
      }
      printArray(numbers);
      cout  << endl << endl;
      set_of_numbers_type hits = bet.get_hits(numbers);
      float retorno = table[size-1][hits.size()];
      float faturamento = retorno * creditPerRound;
      total -= creditPerRound;
      total += faturamento;

      cout << "        "
      << "Você acertou os números ";
      printArray(hits);
      cout << ", um total de " << hits.size() << " hits de " << size << endl
      << "        "
      << "Sua taxa de retorno é " << retorno << " , assim você sai com: $" << faturamento << endl
      << "        "
      << "Você possui um total de: $" << total << " créditos." << endl;
    }

    cout << ">>> Fim das rodadas!" << endl
    << "--------------------------------------------------------------------" << endl << endl
    << "======= Sumário =======" << endl
    << ">>> Você gastou um total de $" << wage << " créditos" << endl;

    if((total-wage) > 0){
      cout << ">>> Hooray! você ganhou $" << (total-wage) << " créditos!" << endl;
    }

    cout << ">>> Você está saindo do jogo com um total de $" << total << " créditos." << endl << endl;
  }else {
    cout << "Problema ao ler arquivo" << endl;
    return 0;
  }
}
