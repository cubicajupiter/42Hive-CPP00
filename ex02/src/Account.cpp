#include "Account.hpp"
#include <iostream>

//INFORMATION DISPLAY FUNCTIONS
int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void    Account::_displayTimestamp( void ) {
    time_t      time_now;
    struct tm   timestruct;
    char        buf[80];

    timestruct = *localtime(&time_now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &timestruct);
    std::cout << buf;
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" + std::to_string(getNbAccounts()) << ";"
    << "total:" + std::to_string(getTotalAmount()) << ";"
    << "deposits:" + std::to_string(getNbDeposits()) << ";"
    << "withdrawals:" + std::to_string(getNbWithdrawals()) << std::endl;
}

void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" + std::to_string(this->_accountIndex) << ";"
    << "amount:" + std::to_string(this->_amount) << ";"
    << "deposits:" + std::to_string(this->_nbDeposits) << ";"
    << "withdrawals:" + std::to_string(this->_nbWithdrawals) << std::endl;
}


//CONSTRUCTORS
Account::Account( void ) {
    this->_accountIndex += 1; //index probably screwed
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
Account::Account( int initial_deposit ) {
    this->_accountIndex += 1; //index probably screwed
    this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;;
}


//DESTRUCTOR
Account::~Account( void ) {
    std::cout << "index:" + std::to_string(this->_accountIndex) << ";"
    << "amount:" + std::to_string(this->_amount) << ";"
    << "closed" << std::endl;
}


//ACCOUNT MANIPULATION FUNCTIONS
void    Account::makeDeposit( int deposit ) {
    std::cout << "index:" + std::to_string(this->_accountIndex) << ";"
    << "p_amount:" + std::to_string(this->_amount) << ";"
    << "deposit:" + std::to_string(deposit) << ";";
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << "amount" + std::to_string(this->_amount)
    << "nb_deposit" + std::to_string(this->_nbDeposits) << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal ) {
    std::cout << "index:" + std::to_string(this->_accountIndex) << ";"
    << "p_amount:" + std::to_string(this->_amount) << ";"
    << "withdrawal:";
    if (checkAmount() < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }
    else {
        this->_amount -= withdrawal;
        std::cout << withdrawal;
    }
    std::cout << "amount:" + std::to_string(this->_amount) << ";"
    << "nb_withdrawals:" + std::to_string(this->_nbWithdrawals) << std::endl;
    return true;
}

int Account::checkAmount( void ) const {
    return this->_amount;
}