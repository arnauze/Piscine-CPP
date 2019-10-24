#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) {

    // Constructor of the Account class. I use an initialization list to give my _amount variable its value
    // First I output a message giving some informations about the creation

    this->_displayTimestamp();
    std::cout << "index:" << this->getNbAccounts() << ";amount:" << this->_amount << ";created" << std::endl;

    // Then I set all of my Account instance variables

    this->_accountIndex = this->_nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    // And I update the Account static variables

    _nbAccounts += 1;
    _totalAmount += initial_deposit;

    return ;
}

Account::~Account( void ) {

    // Destructor of the Account class
    // First I output a message giving some information about the destruction

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;

    // Then I update the Account static variables

    _nbAccounts -= 1;
    _totalAmount -= this->_amount;

    return ;
}

int          Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int          Account::getTotalAmount( void ) {
    return _totalAmount;
}

int          Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int          Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void          Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void            Account::_displayTimestamp( void ) {
    std::cout << "[20150406_153629] ";
}

void            Account::displayStatus( void ) const {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int             Account::checkAmount( void ) const {
    return this->_amount;
}

void            Account::makeDeposit( int deposit ) {

    // Function called when we want to make a deposit on an Account instance
    // First I output some informations about the transaction

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;

    // Then I update the instance variables

    this->_nbDeposits += 1;
    this->_amount += deposit;

    // And I finally update the Account static variables

    _totalAmount += deposit;
    _totalNbDeposits += 1;

}

bool            Account::makeWithdrawal( int withdrawal ) {

    // Function called when we want to make a withdrawal on an Account instance

    this->_displayTimestamp();

    if (withdrawal > this->_amount) {

        // If the Account tries to withdraw more money that what he has then we output an error message

        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return false;

    } else {

        // Otherwise we output some informations about the transaction

        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;

        // Then we change the instance variables

        this->_nbWithdrawals += 1;
        this->_amount -= withdrawal;

        // And finalyy we change the Account static variables

        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;

        return true;

    }
}