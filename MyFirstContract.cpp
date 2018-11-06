#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include "MyFirstContract.hpp"

using namespace eosio;


void MyFirstContract::upsert(eosio::name user, uint16_t win_count, uint16_t lost_count, std::string note) {
	//For testing purposes I'll let anyone push data into this table 
	//require_auth( _self ); 
	users_table users(_self, user.value);
	
	auto iterator = users.find(user.value);  

	if( iterator == users.end() )
	{
		users.emplace(user, [&]( auto& row ) {
		row.user = user.value;
		row.win_count = win_count;
		row.lost_count = lost_count;
		});
	}
	else {
		users.modify(iterator, user, [&]( auto& row ) {
		row.user = user.value;
		row.win_count = win_count;
		row.lost_count = lost_count;
		});
	}

}

void MyFirstContract::echo(std::string message) {
	print("Echo: ", message);
}