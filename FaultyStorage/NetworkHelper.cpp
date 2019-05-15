#include "pch.h"
#include "NetworkHelper.h"
#include "SFML/Network.hpp"
#include <sstream>
#include <iostream>

NetworkHelper::NetworkHelper()
{
	m_Ip = sf::IpAddress::LocalHost;
	m_Socket.setBlocking(false);
	//InitializeNetwork();
}

void NetworkHelper::SendReadMessage()
{
	unsigned char* packetContents[48];

	sf::Packet packet;
	packet << "R"; //opcode
	packet << "hello.txt"; //filename
	packet << "location"; //location to read

	if (m_Socket.send(packet, m_Ip, sendPort) != sf::Socket::Done)
	{
		std::cout << "Failed to send packet" << std::endl;
		std::cout << "Error: " << m_Socket.Error << std::endl;
	}
}

void NetworkHelper::SendWriteMessage()
{
	unsigned char* packetContents[48];
	
	sf::Packet packet;
	packet << "R"; //opcode
	packet << "hello.txt"; //filename
	packet << "location"; //location to read

	if (m_Socket.send(packet, m_Ip, sendPort) != sf::Socket::Done)
	{
		std::cout << "Failed to send packet" << std::endl;
		std::cout << "Error: " << m_Socket.Error << std::endl;
	}
}



void NetworkHelper::ReceiveMessage()
{
	char buffer[512];      // The buffer to store raw response data in
	sf::IpAddress respIP;  // The ip address where the response came from
	size_t respSize;     // The amount of data actually written to buffer

	// Now receive a response.  This is a blocking call, meaning your program
	// will hang until a response is received.
	m_Socket.receive(buffer, 512, respSize, respIP, receivePort);

	std::string respString(buffer, respSize);

	if (respSize == 0)
		return;

	// Now lets turn the string back into JSON
	//JSONValue * response = JSON::Parse(respString.c_str());

	//if (!response->IsObject())
	//{
	//	std::cout << "Something went wrong, not good.";
	//	return;
	//}

	//delete response;
}

void NetworkHelper::ReceiveAckMessage()
{
	unsigned char* byteArray[48]; //48 byte array
}

void NetworkHelper::ReceiveDataMessage()
{

}
