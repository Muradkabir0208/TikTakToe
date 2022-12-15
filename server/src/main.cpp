#include <netinet/ip.h>
int main()
{
	unsigned short port = 5000;

	// buffer to input data from client
	char in[128];

	// setup socket connection tools
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
}
