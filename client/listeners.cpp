//
// Created by benbash on 1/6/16.
//
#include <iostream>
#include <string>
#include "listeners.h"

bool shouldIQuit (std::string s);

bool terminate = false;

void listenToInput (ConnectionHandler *connectionHandler) {
    while (!terminate) {
        const short bufsize = 1024;

        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        if (!connectionHandler->sendLine(line)) {
            std::cout << "Disconnected. Exit12427ing...\n" << std::endl;
            terminate = true;
            break;
        }


        // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        //std::cout << "Sent " << len + 1 << " bytes to server" << std::endl;
    }
}

void listenToServer (ConnectionHandler *connectionHandler) {
    while (!terminate) {
        std::string answer;
        int len;

        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler->getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            terminate = true;
            break;
        }

        len=answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);

                msg::Messages msgType = getMessageType(answer);

        std::string ans;

        switch (msgType) {
            case msg::ASKTXT :
                std::cout << "Recived new question: " << getMessage(answer) << " use TXTRESP <msg> to respond with your answer" << std::endl;
                break;
            case msg::ASKCHOICES :
                std::cout << "Please choose an answer: " << getMessage(answer) << " use SELECTRESP <answer number> to respond" << std::endl;
                break;
            case msg::SYSMSG : {
                std::string ans = getMessage(answer);
                std::cout << "System msg recived: " << ans << std::endl;
                if (shouldIQuit(ans)) {
                    return;
                }
                break;
            }
            case msg::GAMEMSG :
                std::cout << getMessage(answer) << std::endl;
                break;
            case msg::USRMSG :
                std::cout << "Chat message recived: " << getMessage(answer) << " use MSG <msg> to respond" << std::endl;
                break;
            case msg::UNKNOWNMSG :
                std::cout << "Unknown message recived, consider of sending a message to ask for explanation" << std::endl;
                break;
        }

        std::cout << std::endl;
    }
}

bool shouldIQuit (std::string s) {
    if (s.substr(0, s.find(" ")) == "QUIT" && s.substr(s.find(" ") + 1, s.length()) == "ACCEPTED")
        return true;

    return false;
}