#include <bitset>
#include <iostream>

#include "messages.hpp"

using namespace coap;

int main()
{
    uint32_t header_msg{0};
    // uint8_t  message_id{95};
    uint8_t version{1};
    uint8_t type{3};
    uint8_t token_length{5};
    uint8_t code{255};

    Message& instance = Message::messageGetInstance();

    std::cout << "Start generation header\n";
    instance.addTypeToHeader(header_msg, type);
    std::cout << "Add type to header: " << std::bitset<32>(header_msg) << std::endl;

    instance.addVersionToHeader(header_msg, version);
    std::cout << "Add version to header: " << std::bitset<32>(header_msg) << std::endl;

    instance.addTokenLengthToHeader(header_msg, token_length);
    std::cout << "Add token length to header: " << std::bitset<32>(header_msg) << std::endl;

    instance.addCodeToHeader(header_msg, code);
    std::cout << "Add code to header: " << std::bitset<32>(header_msg) << std::endl;

    // instance.addMessageIdToHeader(header_msg, message_id);
    // std::cout << "Add message ID to header: " << std::bitset<32>(header_msg) << std::endl;

    return 0;
}