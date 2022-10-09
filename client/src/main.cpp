#include <SFML/Network.hpp>
#include <iomanip>
#include <iostream>

void runTcpServer(unsigned short port)
{
    // Create a server socket to accept new connections
    sf::TcpListener listener;

    // Listen to the given port for incoming connections
    if (listener.listen(port) != sf::Socket::Status::Done)
        return;
    std::cout << "Server is listening to port " << port << ", waiting for connections... " << std::endl;

    // Wait for a connection
    sf::TcpSocket socket;
    if (listener.accept(socket) != sf::Socket::Status::Done)
        return;
    std::cout << "Client connected: " << socket.getRemoteAddress().toString() << std::endl;

    // Send a message to the connected client
    const char out[] = "Hi, I'm the server";
    if (socket.send(out, sizeof(out)) != sf::Socket::Status::Done)
        return;
    std::cout << "Message sent to the client: " << std::quoted(out) << std::endl;

    // Receive a message back from the client
    char in[128];
    std::size_t received;
    if (socket.receive(in, sizeof(in), received) != sf::Socket::Status::Done)
        return;
    std::cout << "Answer received from the client: " << std::quoted(in) << std::endl;
}

void runTcpClient(unsigned short port)
{
    sf::IpAddress server;
    do
    {
        std::cout << "Type the address or name of the server to connect to: ";
        std::cin >> server;
    } while (!server.toInteger());

    sf::TcpSocket socket;
    if (socket.connect(server, port) != sf::Socket::Status::Done)
        return;
    std::cout << "Connected to server " << server.toString() << std::endl;
    // Receive a message from the server
    char in[128];
    std::size_t received;
    if (socket.receive(in, sizeof(in), received) != sf::Socket::Status::Done)
        return;
    std::cout << "Message received from the server: " << std::quoted(in) << std::endl;

    // Send an answer to the server
    const char out[] = "Hi, I'm a client";
    if (socket.send(out, sizeof(out)) != sf::Socket::Status::Done)
        return;
    std::cout << "Message sent to the server: " << std::quoted(out) << std::endl;
}

int main()
{
    unsigned short port = 5000;
    char who;
    std::cout << "Enter what to run as s for server c for client " << std::endl;
    std::cin >> who;
    if (who == 's')
    {
        // server handler
        runTcpServer(port);
    }
    else
    {
        // client handler
        runTcpClient(port);
    }

    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(10000, '\n');
    std::cin.ignore(10000, '\n');
    return 0;
}
