//
// Created by benbash on 1/6/16.
//

#include "msgParser.h"




msg::Messages getMessageType (std::string s) {
    std::string token = s.substr(0, s.find(" "));

    if (token == "ASKTXT")
        return msg::ASKTXT;
    else if (token == "ASKCHOICES")
        return msg::ASKCHOICES;
    else if (token == "SYSMSG")
        return msg::SYSMSG;
    else if (token == "GAMEMSG")
        return msg::GAMEMSG;
    else if (token == "USRMSG")
        return msg::USRMSG;

    return msg::UNKNOWNMSG;
}

std::string getMessage(std::string s) {
    return s.substr(s.find(" ") + 1, s.length());
}

