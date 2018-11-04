cmake_minimum_required(VERSION 3.5)
project(MyFirstContract_example VERSION 1.0.0)

find_package(eosio.cdt)

### Only generate the wasm
#add_executable( MyFirstContract.wasm MyFirstContract.cpp )

### Generate the wasm and abi
add_contract( MyFirstContract MyFirstContract MyFirstContract.cpp )
