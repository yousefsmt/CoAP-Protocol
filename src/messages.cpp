#include "messages.hpp"

#include <iostream>

namespace coap
{
    Message& Message::MessageGetInstance()
    {
        static Message make_instance;

        return make_instance;
    }

    int Message::AddVersionToHeader(uint32_t& header_msg, uint8_t version)
    {
        if (version != 1)
        {
            return -1;
        }

        header_msg |= (static_cast<uint32_t>(version & 0x3) << 30);

        return 0;
    }

    int Message::AddTypeToHeader(uint32_t& header_msg, uint8_t type)
    {
        auto convert_8_to_32_bit = static_cast<uint32_t>(type);

        switch (type)
        {
            case 0U:
                message_type = MessageType::CONFIRMABLE;
                header_msg |= (convert_8_to_32_bit << 28);
                break;
            case 1U:
                message_type = MessageType::NONCONFIRMABLE;
                header_msg |= (convert_8_to_32_bit << 28);
                break;
            case 2U:
                message_type = MessageType::ACKNOWLEDGEMENT;
                header_msg |= (convert_8_to_32_bit << 28);
                break;
            case 3U:
                message_type = MessageType::RESET;
                header_msg |= (convert_8_to_32_bit << 28);
                break;
            default:
                std::cerr << "ERROR: cannot allocate type message\n";
                return -1;
                break;
        }

        return 0;
    }

    int Message::AddTokenLengthToHeader(uint32_t& header_msg)
    {
        return 0;
    }

    int Message::AddCodeToHeader(uint32_t& header_msg)
    {
        return 0;
    }

} // namespace coap