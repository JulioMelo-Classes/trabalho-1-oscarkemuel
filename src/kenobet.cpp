#include "../include/kenobet.hpp"

bool KenoBet::add_number( number_type spot_ ){
  bool contains = false;
  int cont = 0;
  for (int i = 0; i < m_spots.size(); i++){
    if(m_spots[i] == spot_) contains = true;
    cont++;
  }

  if(contains){
    cout << "Números repetidos!!" << endl;
    return false;
  }

  if(m_spots.size() == 15){
    cout << "Máximo de 15 apostas" << endl;
    return false;
  }

  this->m_spots.push_back(spot_);
  return true;
}

set_of_numbers_type KenoBet::get_spots( void ) const{
  return m_spots;
}

bool KenoBet::set_wage( cash_type wage_ ){
  try{
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

  return spots;
}

string KenoBet::printWage( void ){
  string wage;

  wage += to_string(get_wage());

  return wage;
}
