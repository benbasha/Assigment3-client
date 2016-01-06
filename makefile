CFLAGS:=-c -Wall -Weffc++ -g
LDFLAGS:=-lboost_system -lboost_thread

all: Client
	g++ -o bin/client bin/connectionHandler.o bin/msgParser.o bin/listeners.o  bin/clientMain.o $(LDFLAGS)

Client: bin/connectionHandler.o bin/msgParser.o bin/listeners.o bin/clientMain.o
	
bin/connectionHandler.o: client/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o client/connectionHandler.cpp

bin/msgParser.o: protocol/msgParser.cpp
	g++ $(CFLAGS) -o bin/msgParser.o protocol/msgParser.cpp

bin/listeners.o: client/listeners.cpp
	g++ $(CFLAGS) -o bin/listeners.o client/listeners.cpp

bin/clientMain.o: client/clientMain.cpp
	g++ $(CFLAGS) -o bin/clientMain.o client/clientMain.cpp

	
.PHONY: clean
clean:
	rm -f bin/*
