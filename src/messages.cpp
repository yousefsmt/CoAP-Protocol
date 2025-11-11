#include "messages.hpp"

#include <fcntl.h>
#include <unistd.h>

#include <cstdlib>
#include <iostream>

namespace coap
{
    Message& Message::messageGetInstance()
    {
        static Message make_instance;

        return make_instance;
    }

    CoapStatus Message::addVersionToHeader(uint32_t& header_msg, uint8_t version)
    {
        if (version != 1U)
        {
            return CoapStatus::FORMAT_ERROR;
        }

        header_msg |= (static_cast<uint32_t>(version & 0x3) << 30U);

        return CoapStatus::SUCCESS;
    }

    CoapStatus Message::addTypeToHeader(uint32_t& header_msg, uint8_t type)
    {
        switch (type)
        {
            case 0U:
                m_message_type = MessageType::CONFIRMABLE;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 1U:
                m_message_type = MessageType::NON_CONFIRMABLE;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 2U:
                m_message_type = MessageType::ACKNOWLEDGEMENT;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            case 3U:
                m_message_type = MessageType::RESET;
                header_msg |= (static_cast<uint32_t>(type) << 28U);
                break;
            default:
                return CoapStatus::FORMAT_ERROR;
                break;
        }

        return CoapStatus::SUCCESS;
    }

    CoapStatus Message::addTokenLengthToHeader(uint32_t& header_msg, uint8_t token_length)
    {
        if (token_length > 8U)
        {
            return CoapStatus::FORMAT_ERROR;
        }

        header_msg |= (static_cast<uint32_t>(token_length) << 24U);

        return CoapStatus::SUCCESS;
    }

    CoapStatus Message::addCodeToHeader(uint32_t& header_msg, uint8_t code)
    {
        if (code == 0)
        {
            return CoapStatus::SUCCESS;
        }

        uint8_t class_msg = (code & (0xE0)) >> 5U;
        switch (class_msg)
        {
            case 0U:
                m_class_type = ClassType::REQUEST;
                break;
            case 2U:
                m_class_type = ClassType::SUCCESS_RESPONSE;
                break;
            case 4U:
                m_class_type = ClassType::CLIENT_ERROR_RESPONSE;
                break;
            case 5U:
                m_class_type = ClassType::SERVER_ERROR_RESPONSE;
                break;
            default:
                return CoapStatus::FORMAT_ERROR;
                break;
        }

        uint8_t detail_msg = code & (0x1F);

        header_msg |= (static_cast<uint32_t>(class_msg) << 21U);
        header_msg |= (static_cast<uint32_t>(detail_msg) << 16U);

        return CoapStatus::SUCCESS;
    }

    // CoapStatus Message::addMessageIdToHeader(uint32_t& header_msg, uint16_t message_id)
    // {

    //     return CoapStatus::SUCCESS;
    // }

    CoapStatus addToken(uint64_t& token, uint8_t token_length)
    {
        ssize_t is_correct{};
        int     file_descriptor{};

        file_descriptor = open("/dev/urandom", O_RDONLY);
        is_correct      = read(file_descriptor, &token, token_length);
        if (is_correct < 0)
        {
            return CoapStatus::FORMAT_ERROR;
        }
        close(file_descriptor);

        return CoapStatus::SUCCESS;
    }

    // CoapStatus addOptions(uint32_t& options)
    // {

    //     return CoapStatus::SUCCESS;
    // }

    // CoapStatus addPayload(uint32_t& payload)
    // {

    //     return CoapStatus::SUCCESS;
    // }

} // namespace coap