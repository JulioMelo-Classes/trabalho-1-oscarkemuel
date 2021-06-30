#include "../include/kenobet.hpp"

bool KenoBet::add_number( number_type spot_ ){

  // validations
  for (int i = 0; i < m_spots.size(); i++){
    if(m_spots[i] == spot_) {
      cout << "Número (" << m_spots[i] << ") repetido!!" << endl;
      return false;
    }
  }

  if(m_spots.size() == 15){
    cout << "Máximo de 15 apostas" << endl;
    return false;
  } else if(spot_ < 1 || spot_ > 80){
    cout << "Apenas números ente 1 e 80" << endl;
    return false;
  }
  // validations

  this->m_spots.push_back(spot_);
  return true;
}

set_of_numbers_type KenoBet::get_spots( void ) const{
  return m_spots;
}

bool KenoBet::set_wage( cash_type wage_ ){
  try{
    if(wage_ <= 0){
      cout << "Apostas apenas acima de 0" << endl;
      return false;
    }

    this->m_wage = wage_;
    return true;
  }
  catch(const std::exception& e){
    return false;
  }
}

cash_type KenoBet::get_wage( void ) const{
  return m_wage;
}

void KenoBet::reset( void ){
  this->m_spots.clear();
}

bool KenoBet::setRounds( number_type rounds ){
  this->rounds = rounds;

  return true;
}

number_type KenoBet::getRounds( void ) const{
  return rounds;
}

size_t KenoBet::size( void ) const{
  return m_spots.size();
}

float KenoBet::getCreditPerRound( void ) const{
  return m_wage / rounds;
}

bool KenoBet::setValues(const std::string& s) {
  string text = s;

  stringstream text_stream(text);
  string item;

  try{
    while (std::getline(text_stream, item, ' ')) {
      bool isAdd = this->add_number(stoi(item));
      if(!isAdd) return false;
    }
  } catch(const std::exception& e) {
    cout << "Aposte apenas números!!" << endl;
    return false;
  }

  return true;
}

string KenoBet::printSpots(void) {
  string spots;
  spots += "[ ";
  for (auto &n : m_spots) {
    spots += to_string(n);
    spots += " ";
  }
  spots += "]";

  // for (size_t i = 0; i < count; i++){
  //   /* code */
  // }


  return spots;
}
