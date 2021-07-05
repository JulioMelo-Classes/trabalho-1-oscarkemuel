#include "../include/kenobet.hpp"

bool KenoBet::add_number( number_type spot_ ){

  // validations --------------
  for (int i = 0; i < this->size(); i++){
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
  // --------------------------

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

bool KenoBet::setValues(const std::string& s) {
  string text = s;
  cout << "TESTE" << text << endl;

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

set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) const{
  set_of_numbers_type hits;
  // cout << hits_.size() << endl;

  for (int i = 0; i < size(); i++){
    for (int j = 0; j < 20; j++){
      if(m_spots[i] == hits_[j]) hits.push_back(hits_[j]);
    }
  }

  return hits;
}

std::vector<std::vector<float>> KenoBet::get_table(void){
  return payoff_table;
}
