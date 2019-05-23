#pragma once
#include "SFML/Network.hpp"
#include "VotingStructure.h"

class VotingStructure;

class NetworkHelper
{
public:
	NetworkHelper();
	void ReceiveMessage();
	void SendReadMessage(std::string fileToRead, char fileNum = NULL);
	void SendReadRetryMessage(std::vector<unsigned char> bits);
	void SendWriteMessage(std::string fileToWrite, char fileNum = NULL);
	void SendWriteRetryMessage(std::vector<unsigned char> bits);
	void ReceiveDataMessage(std::vector<unsigned char> bits);
	void ReceiveAckMessage(std::vector<unsigned char> bits);
	VotingStructure* m_SmallText;
	VotingStructure* m_LargeText;
private:
	sf::IpAddress m_Ip;
	sf::UdpSocket m_Socket;

	unsigned short sendPort = 1982;
};