#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT MyFirstContract : public eosio::contract {

  public:
    using contract::contract;
    MyFirstContract(name receiver, name code,  datastream<const char*> ds):contract(receiver, code, ds) {}
    ACTION upsert(name user, uint16_t win_count, uint16_t lost_count); 

  private:
    
    struct [[eosio::table]] user_info {
      name            key;
      uint16_t        win_count = 0;
      uint16_t        lost_count = 0;

      auto primary_key() const { return key; }
    };

    typedef eosio::multi_index<name("users"), user_info> users_table;

};

EOSIO_DISPATCH(MyFirstContract, (upsert))