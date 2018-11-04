#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT MyFirstContract : public eosio::contract {

  private:
    
    struct [[eosio::table]] user_info {
      name            name;
      uint16_t        win_count = 0;
      uint16_t        lost_count = 0;

      auto primary_key() const { return name; }
    };

    typedef eosio::multi_index<name("users"), user_info> users_table;

    users_table _users;

  public:
    using contract::contract;
    ACTION hi(name user);

};

EOSIO_DISPATCH(MyFirstContract, (hi))