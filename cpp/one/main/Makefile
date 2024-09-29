
all: server client

server:
	g++ -I. Server.cpp -o server.exe -lws2_32

client:
	g++ -I. Client.cpp -o client.exe -lws2_32

clean:
	del -f *.exe