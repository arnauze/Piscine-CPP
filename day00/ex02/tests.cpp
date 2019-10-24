// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.class.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;	// Creates an empty array of Accounts
	typedef std::vector<int>								  ints_t;		// Creates an empty array of int
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;	// Creates a pair of pointers to arrays

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );	// Gets the size required for allocating the array
	accounts_t				accounts( amounts, amounts + amounts_size );	// Fill the array of Accounts using the "amounts" variables as initial_deposit
	accounts_t::iterator 	acc_begin	= accounts.begin();					// acc_begin is now pointing to the first account of the "accounts" array
	accounts_t::iterator 	acc_end		= accounts.end();					// acc_end is now pointing to the last account of the "accounts" array

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );					// Gets the size required for allocating the array
	ints_t				deposits( d, d + d_size );							// Fill the array of int with the "d" values
	ints_t::iterator 	dep_begin	= deposits.begin();						// dep_begin is now pointing to the first deposit of the "deposits" array
	ints_t::iterator 	dep_end		= deposits.end();						// dep_end is now pointing to the last deposit of the "deposits" array

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );					// Gets the size required for allocating the array
	ints_t				withdrawals( w, w + w_size );						// Fill the array of int with the "w" values
	ints_t::iterator 	wit_begin	= withdrawals.begin();					// wit_begin is now pointing to the first withdrawal of the "withdrawals" array
	ints_t::iterator 	wit_end		= withdrawals.end();					// wit_end is now pointing to the last withdrawal of the "withdrawals" array

	Account::displayAccountsInfos();										// Method of the Account class outputing "accounts:8;total:20049;deposits:0;withdrawals:0"
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // Loop from acc_begin to acc_end and call Account::displayStatus on each element

	for ( acc_int_t it( acc_begin, dep_begin );								// Create an std::pair with a pointer to the first value of the accounts array
		  it.first != acc_end && it.second != dep_end;						// and a pointer to the first value of the deposits array
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );							// For each value of the arrays, I make a new deposit 
	}

	Account::displayAccountsInfos();										// Method of the Account class outputing "accounts:8;total:21524;deposits:8;withdrawals:0"
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // Loop from acc_begin to acc_end and call Account::displayStatus on each element

	for ( acc_int_t it( acc_begin, wit_begin );								// Create an std::pair with a pointer to the first value of the accounts array
		  it.first != acc_end && it.second != wit_end;						// and a pointer to the first value of the withdrawals array
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );						// For each value of the arrays, I make a new withdrawal 
	}

	Account::displayAccountsInfos();										// Method of the Account class outputing "accounts:8;total:12442;deposits:8;withdrawals:6"
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // Loop from acc_begin to acc_end and call Account::displayStatus on each element

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
