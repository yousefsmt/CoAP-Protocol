#pragma once

#include <cstdint>

namespace coap
{
    /**
     * \enum Message::MessageType
     * \brief Represents the type of a CoAP message.
     *
     * This enumeration defines the possible types of CoAP messages, which determine
     * how the message should be handled by the recipient:
     * - CONFIRMABLE: Requires an acknowledgment from the recipient.
     * - NONCONFIRMABLE: Does not require an acknowledgment.
     * - ACKNOWLEDGEMENT: Sent in response to a confirmable message to confirm receipt.
     * - RESET: Indicates that a message was received but could not be processed.
     */
    enum class MessageType : uint8_t
    {
        CONFIRMABLE,
        NONCONFIRMABLE,
        ACKNOWLEDGEMENT,
        RESET
    };

    class Message
    {
    private:
        Message() :
            message_type(MessageType::CONFIRMABLE)
        {
        }
        ~Message() {}

        MessageType message_type;

    public:
        static Message& messageGetInstance();

        Message(const Message&)            = delete;
        Message& operator=(const Message&) = delete;

        int addVersionToHeader(uint32_t& header_msg, uint8_t version);

        int addTypeToHeader(uint32_t& header_msg, uint8_t type);

        int addTokenLengthToHeader(uint32_t& header_msg, uint8_t token_length);

        int addCodeToHeader(uint32_t& header_msg, uint8_t code);

        int addMessageIdToHeader(uint32_t& header_msg, uint16_t message_id);
    };

} // namespace coap