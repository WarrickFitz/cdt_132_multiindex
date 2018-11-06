#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT MyFirstContract : public eosio::contract {

  public:
    using contract::contract;
    //https://developers.eos.io/eosio-home/docs/data-persistence#section-step-6-the-constructor
    MyFirstContract(name receiver, name code,  datastream<const char*> ds):contract(receiver, code, ds) {}
    ACTION upsert(name user, uint16_t win_count, uint16_t lost_count, std::string note); 
    ACTION echo(std::string message); 

  private:
    
    TABLE user_info {
      uint64_t        user;
      uint16_t        win_count = 0;
      uint16_t        lost_count = 0;

      auto primary_key() const { return user; }
    };

    typedef eosio::multi_index<name("users"), user_info> users_table;

};

EOSIO_DISPATCH(MyFirstContract, (upsert)(echo))