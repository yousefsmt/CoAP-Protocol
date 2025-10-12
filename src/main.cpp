#include <bitset>
#include <iostream>

#include "messages.hpp"

using namespace coap;

int main()
{
    uint32_t header_msg{0};
    uint8_t  version{1};
    uint8_t  type{3};

    Message& instance = Message::MessageGetInstance();

    instance.AddTypeToHeader(header_msg, type);
    std::cout << std::bitset<32>(header_msg) << std::endl;

    instance.AddVersionToHeader(header_msg, version);
    std::cout << std::bitset<32>(header_msg) << std::endl;

    // instance.AddCodeToHeader();
    // instance.AddTokenLengthToHeader();
    // instance.AddVersionToHeader();
    // instance.CombineHeaderField();

    return 0;
}