//
// Created by benbash on 1/6/16.
//

#ifndef ASSIGMENT3_CLIENT_MSGPARSER_H
#define ASSIGMENT3_CLIENT_MSGPARSER_H

#include <string>

namespace msg {
    enum Messages { ASKTXT, ASKCHOICES, SYSMSG, GAMEMSG, USRMSG, UNKNOWNMSG };
}


msg::Messages getMessageType (std::string);
std::string getMessage(std::string s);

#endif //ASSIGMENT3_CLIENT_MSGPARSER_H
