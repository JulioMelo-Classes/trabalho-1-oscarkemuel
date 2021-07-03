#ifndef FUNCOES_KENOBET_HPP
#define FUNCOES_KENOBET_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using std::stringstream;
using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

class KenoBet {
  public:
    //! Creates an empty Keno bet. OK
    KenoBet( ) : m_wage(0)
    { /* empty */ };

    /*! Adds a number to the spots only if the number is not already there.
        @param spot_ The number we wish to include in the bet.
        @return T if number chosen is successfully inserted; F otherwise. OK*/
    bool add_number( number_type spot_ );

    /*! Sets the amount of money the player is betting.
        @param wage_ The wage.
        @return True if we have a wage above zero; false otherwise. OK*/
    bool set_wage( cash_type wage_ );

    //! Resets a bet to an empty state. OK
    void reset( void );

    /*! Retrieves the player's wage on this bet.
        @return The wage value. OK*/
    cash_type get_wage( void ) const;

    /*! Returns to the current number of spots in the player's bet.
        @return Number of spots present in the bet. OK*/
    size_t size( void ) const;

    /*! Determine how many spots match the hits passed as argument.
        @param hits_ List of hits randomly chosen by the computer.
        @return An vector with the list of hits. */
    set_of_numbers_type
    get_hits( const set_of_numbers_type & hits_ ) const;

    /*! Return a vector< spot_type > with the spots the player has picked so far.
        @return The vector< spot_type > with the player's spots picked so far.  OK*/
    set_of_numbers_type get_spots( void ) const;

    /*! Sets the number of rounds for the bet.
        @param rounds The number of rounds.
        @return T if the chosen number of rounds is successfully entered; F otherwise. OK*/
    bool setRounds( number_type rounds );

    /*! Returns a number_type with the number of rounds for the bet.
        @return The number_type with the number of betting rounds.  OK*/
    number_type getRounds( void ) const;

    /*! Returns float with the number of credits per round.
        @return The float with the number of credits per round.  OK*/
    float getCreditPerRound( void ) const;

    /*! Scroll through the third line of the file to trigger add_number.
        @return T if the number chosen to bet is a type number; F otherwise..  OK*/
    bool setValues(const std::string& s);

    std::vector<std::vector<float> > get_table(void);

    //! Start the game.
    void startGame( void );

  private:
    set_of_numbers_type m_spots;  //<! The player's bet.
    cash_type m_wage;             //<! The player's wage.
    number_type rounds;           //<! The player's rounds.

    std::vector<std::vector<float> > payoff_table = { //<! Payoff table
    { 0, 3 },
    { 0, 1, 9 },
    { 0, 1, 2, 16 },
    { 0, 0.5, 2, 6, 12 },
    { 0, 0.5, 1, 3, 15, 50 },
    { 0, 0.5, 1, 2, 3, 30, 75 },
    { 0, 0.5, 0.5, 1, 6, 12, 36, 100 },
    { 0, 0.5, 0.5, 1, 3, 6, 19, 90, 720 },
    { 0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200 },
    { 0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800 },
    { 0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000 },
    { 0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000 },
    { 0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000 },
    { 0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500 },
    { 0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000 }
    };
};

#endif
