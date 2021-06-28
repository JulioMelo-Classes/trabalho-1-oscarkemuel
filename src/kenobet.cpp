#include "../include/kenobet.hpp"

bool KenoBet::add_number( number_type spot_ ){
  try{
    this->m_spots.push_back(spot_);
    return true;
  }
  catch(const std::exception& e){
    return false;
  }
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

void KenoBet::setValues(const std::string& s) {
  string text = s;

  stringstream text_stream(text);
  string item;

  try{
    while (std::getline(text_stream, item, ' ')) {
      this->add_number(stoi(item));
    }
  } catch(const std::exception& e) {
    cout << "Erro" << endl;
  }
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
