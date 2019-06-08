#include "huffcomstring.h"

HuffComString::HuffComString(const std::string &source_string)
    : HuffCom(source_string)
{

}

//HuffComString::~HuffComString() {

//}

std::string HuffComString::encode() {
    return m_msg_encode.encode(m_source_message);
}

std::string HuffComString::alternate_encode(const std::string &message) {
    return m_msg_encode.encode(message);
}

// We need to destroy in:code to decode.  Either pass by copy or create copy here.
std::string HuffComString::decode(const std::string &code) {
    return m_msg_decode.decode(code, m_root);
}
