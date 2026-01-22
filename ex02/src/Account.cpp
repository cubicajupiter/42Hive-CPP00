/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:58:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/22 16:00:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <ctime>

// static definitions need to be defined in a .cpp file as well.
	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

//HELPER FUNCTION
std::string to_string(int value) {
    std::ostringstream  ss;

    ss << value;
    return ss.str();
}

//INFORMATION DISPLAY FUNCTIONS
int Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void    Account::_displayTimestamp( void ) {
    time_t      time_now = std::time(0);
    struct tm   timestruct;
    char        buf[80];

    timestruct = *localtime(&time_now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &timestruct);
    std::cout << buf;
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" + to_string(getNbAccounts()) << ";"
    << "total:" + to_string(getTotalAmount()) << ";"
    << "deposits:" + to_string(getNbDeposits()) << ";"
    << "withdrawals:" + to_string(getNbWithdrawals()) << std::endl;
}

void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "amount:" + to_string(this->_amount) << ";"
    << "deposits:" + to_string(this->_nbDeposits) << ";"
    << "withdrawals:" + to_string(this->_nbWithdrawals) << std::endl;
}


//CONSTRUCTORS
Account::Account( void ) {
    Account::_nbAccounts++;
    this->_accountIndex = Account::_nbAccounts - 1; //index probably screwed
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "amount:" + to_string(this->_amount) << ";"
    << "created" << std::endl;
}

Account::Account( int initial_deposit ) {
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    this->_accountIndex = Account::_nbAccounts - 1; //index probably screwed
    this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "amount:" + to_string(this->_amount) << ";"
    << "created" << std::endl;
}


//DESTRUCTOR
Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "amount:" + to_string(this->_amount) << ";"
    << "closed" << std::endl;
}


//ACCOUNT MANIPULATION FUNCTIONS
void    Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "p_amount:" + to_string(this->_amount) << ";"
    << "deposit:" + to_string(deposit) << ";";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << "amount:" + to_string(this->_amount) << ";"
    << "nb_deposit:" + to_string(this->_nbDeposits) << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" + to_string(this->_accountIndex) << ";"
    << "p_amount:" + to_string(this->_amount) << ";"
    << "withdrawal:";
    if (checkAmount() < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }
    else {
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        std::cout << withdrawal << ";";
    }
    std::cout << "amount:" + to_string(this->_amount) << ";"
    << "nb_withdrawals:" + to_string(this->_nbWithdrawals) << std::endl;
    return true;
}

int Account::checkAmount( void ) const {
    return this->_amount;
}