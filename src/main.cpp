#include <bitset>
#include <iostream>
#include <unordered_map>

#include "messages.hpp"

using namespace coap;

typedef struct
{
    uint8_t  version;
    uint8_t  type;
    uint8_t  token_length;
    uint8_t  code;
    uint8_t  message_id;
    uint32_t header_msg;
} HeaderMessage;

std::unordered_map<CoapStatus, std::string> test = {{CoapStatus::FORMAT_ERROR, "FORMAT_ERROR"},
                                                    {CoapStatus::SUCCESS, "SUCCESS"}};

int main()
{
    HeaderMessage header_options{};
    CoapStatus    status_func{};
    // Logger        log_file {};

    header_options.header_msg   = 0U;
    header_options.version      = 1U;
    header_options.type         = 3U;
    header_options.token_length = 5U;
    header_options.code         = 2U;

    Message& instance = Message::messageGetInstance();

    status_func = instance.addTypeToHeader(header_options.header_msg, header_options.type);
    std::cout << "state addTypeToHeader: " << test[status_func] << '\n';

    status_func = instance.addVersionToHeader(header_options.header_msg, header_options.version);
    std::cout << "state addVersionToHeader: " << test[status_func] << '\n';

    status_func =
        instance.addTokenLengthToHeader(header_options.header_msg, header_options.token_length);
    std::cout << "state addTokenLengthToHeader: " << test[status_func] << '\n';

    status_func = instance.addCodeToHeader(header_options.header_msg, header_options.code);
    std::cout << "state addCodeToHeader: " << test[status_func] << '\n';

    // instance.addMessageIdToHeader(header_msg, message_id);

    return 0;
}