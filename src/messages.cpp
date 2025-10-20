#include "messages.hpp"

#include <iostream>

namespace coap
{
    Message& Message::messageGetInstance()
    {
        static Message make_instance;

        return make_instance;
    }

    int Message::addVersionToHeader(uint32_t& header_msg, uint8_t version)
    {
        if (version != 1U)
        {
            return -1;
        }

        header_msg |= (static_cast<uint32_t>(version & 0x3) << 30U);

        return 0;
    }

    int Message::addTypeToHeader(uint32_t& header_msg, uint8_t type)
    {
        switch (type)
        {
            case 0U:
                message_type = MessageType::CONFIRMABLE;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 1U:
                message_type = MessageType::NON_CONFIRMABLE;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 2U:
                message_type = MessageType::ACKNOWLEDGEMENT;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 3U:
                message_type = MessageType::RESET;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            default:
                std::cerr << "ERROR: cannot allocate type message\n";
                return -1;
                break;
        }

        return 0;
    }

    int Message::addTokenLengthToHeader(uint32_t& header_msg, uint8_t token_length)
    {
        if (token_length > 8U)
        {
            std::cerr << "ERROR: message format does not true\n";
            return -1;
        }

        header_msg |= (static_cast<uint32_t>(token_length) << 24U);

        return 0;
    }

    int Message::addClassToCode(uint8_t& code, uint8_t three_bit_class)
    {
        
        return 0;
    }

    int Message::addDetailToCode(uint8_t& code, uint8_t five_bit_detail)
    {

        return 0;
    }

    int Message::addCodeToHeader(uint32_t& header_msg, uint8_t code)
    {
        return 0;
    }

    int Message::addMessageIdToHeader(uint32_t& header_msg, uint16_t message_id)
    {

        return 0;
    }

} // namespace coap