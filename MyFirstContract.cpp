#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include "MyFirstContract.hpp"

using namespace eosio;

//https://developers.eos.io/eosio-home/docs/data-persistence#section-step-6-the-constructor
void MyFirstContract::upsert(eosio::name user, uint16_t win_count, uint16_t lost_count) {
	require_auth( user );
	users_table addresses(_code, _code.value);
	
	//auto iterator = addresses.find(user.value);  << This causes a problem

/*	
	if( iterator == addresses.end() )
	{
		addresses.emplace(user, [&]( auto& row ) {
		row.name = user;
		row.win_count = win_count;
		row.lost_count = lost_count;
		});
	}
	else {
		std::string changes;
		addresses.modify(iterator, user, [&]( auto& row ) {
		row.name = user;
		row.win_count = win_count;
		row.lost_count = lost_count;
		});
	}
*/
}