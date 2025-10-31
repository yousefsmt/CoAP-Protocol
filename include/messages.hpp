#pragma once

#include <cstdint>

namespace coap
{
    /**
     * \enum Message::MessageType
     * \brief Represents the CoAP message type (the "Type" field in the CoAP header).
     *
     * This enumeration defines the four possible CoAP message types as specified in RFC 7252.
     * The message type determines the reliability mechanism and how the recipient
     * should handle or respond to the message.
     *
     * - CONFIRMABLE:     A reliable message that requires an acknowledgment (ACK) from the
     * recipient. If no ACK is received, the sender retransmits the message.
     * - NON_CONFIRMABLE: An unreliable message that does not require an acknowledgment.
     *                    Used when occasional message loss is acceptable.
     * - ACKNOWLEDGEMENT: Sent in response to a Confirmable message to acknowledge its receipt.
     *                    May optionally contain a response payload.
     * - RESET:           Sent when a message was received but could not be processed
     *                    (e.g., due to missing context or invalid state).
     *
     * \note The Message Type is distinct from the Code field.
     *       MessageType controls transport reliability, while Code identifies
     *       the request method or response status.
     */
    enum class MessageType : uint8_t
    {
        CONFIRMABLE     = 0U, ///< Reliable message that requires an ACK.
        NON_CONFIRMABLE = 1U, ///< Unreliable message; no ACK expected.
        ACKNOWLEDGEMENT = 2U, ///< ACK confirming receipt of a Confirmable message.
        RESET           = 3U  ///< Indicates a message could not be processed.
    };

    /**
     * \enum Message::ClassType
     * \brief Represents the CoAP message code class (high-order 3 bits of the Code field).
     *
     * This enumeration defines the main categories (classes) of CoAP message codes
     * as specified in RFC 7252. The Code field in a CoAP message is an 8-bit value
     * split into:
     * - A 3-bit class (represented by this enum), and
     * - A 5-bit detail value.
     *
     * The class determines the general purpose of the message:
     * - REQUEST:      Indicates a request method such as GET, POST, PUT, or DELETE.
     * - SUCCESS_RESPONSE: Indicates a successful response (e.g., 2.01 Created, 2.05 Content).
     * - CLIENT_ERROR_RESPONSE: Indicates a client-side error (e.g., 4.00 Bad Request, 4.04 Not
     * Found).
     * - SERVER_ERROR_RESPONSE: Indicates a server-side error (e.g., 5.00 Internal Server Error).
     *
     * Other class values (1, 3, 6, 7) are reserved for future use.
     */
    enum class ClassType : uint8_t
    {
        REQUEST               = 0U, ///< Request messages (e.g., GET, POST)
        SUCCESS_RESPONSE      = 2U, ///< Successful responses (2.xx)
        CLIENT_ERROR_RESPONSE = 4U, ///< Client error responses (4.xx)
        SERVER_ERROR_RESPONSE = 5U  ///< Server error responses (5.xx)
    };

    /**
     * \enum Message::CoapStatus
     * \brief Represents the status of CoAP message processing.
     *
     * This enumeration indicates whether a CoAP message was processed successfully
     * or an error occurred during parsing, validation, or interpretation.
     *
     * The status is not part of the CoAP protocol itself — it is used internally
     * to represent the result of message handling in the implementation.
     *
     * - SUCCESS:       The message is valid and was processed successfully.
     * - FORMAT_ERROR:  The message format is invalid or violates CoAP specification.
     */
    enum class CoapStatus : uint8_t
    {
        SUCCESS      = 0U, ///< The message was valid and processed successfully.
        FORMAT_ERROR = 1U  ///< The message was malformed or invalid.
    };

    class Message
    {
    private:
        Message() :
            m_message_type(MessageType::CONFIRMABLE),
            m_class_type(ClassType::REQUEST)
        {
        }
        ~Message() {}

        MessageType m_message_type;
        ClassType   m_class_type;

    public:
        static Message& messageGetInstance();

        Message(const Message&)            = delete;
        Message& operator=(const Message&) = delete;

        CoapStatus addVersionToHeader(uint32_t& header_msg, uint8_t version);

        CoapStatus addTypeToHeader(uint32_t& header_msg, uint8_t type);

        CoapStatus addTokenLengthToHeader(uint32_t& header_msg, uint8_t token_length);

        CoapStatus addCodeToHeader(uint32_t& header_msg, uint8_t code);

        CoapStatus addMessageIdToHeader(uint32_t& header_msg, uint16_t message_id);
    };

} // namespace coap