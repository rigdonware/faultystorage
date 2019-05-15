#pragma once

class NetworkHelper
{
public:
	NetworkHelper();
	void ReceiveMessage();
	void SendReadMessage();
	void SendWriteMessage();
	void ReceiveDataMessage();
	void ReceiveAckMessage();

private:
	sf::IpAddress m_Ip;
	sf::UdpSocket m_Socket;
	sf::UdpSocket m_BulletSocket;

	unsigned short sendPort = 1982;
	unsigned short receivePort = 1983;
};