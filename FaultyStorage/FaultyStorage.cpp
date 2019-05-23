// FaultyStorage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "NetworkHelper.h"
#include "Button.h"
#include "FaultTolerantHelper.h"
#include "VotingStructure.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 750), "Faulty Storage");
	Button writeSmallTextButton;
	writeSmallTextButton.InitButton(50, 50, 300, 40, "Write Small Text File");
	Button writeLargeTextButton;
	writeLargeTextButton.InitButton(50, 100, 300, 40, "Write Large Text File");
	Button writeSmallBinaryButton;
	writeSmallBinaryButton.InitButton(500, 50, 300, 40, "Write Small Binary File");
	Button writeLargeBinaryButton;
	writeLargeBinaryButton.InitButton(500, 100, 300, 40, "Write Large Binary File");

	Button readSmallTextButton;
	readSmallTextButton.InitButton(50, 150, 300, 40, "Read Small Text File");
	Button readLargeTextButton;
	readLargeTextButton.InitButton(50, 200, 300, 40, "Read Large Text File");
	Button readSmallBinaryButton;
	readSmallBinaryButton.InitButton(500, 150, 300, 40, "Read Small Binary File");
	Button readLargeBinaryButton;
	readLargeBinaryButton.InitButton(500, 200, 300, 40, "Read Lage Binary File");

	NetworkHelper network;
	VotingStructure* smallTextFile = new VotingStructure("SmallTextFile.txt");
	VotingStructure* largeTextFile = new VotingStructure("LargeTextFile.txt");
	network.m_SmallText = smallTextFile;
	network.m_LargeText = largeTextFile;

	std::vector<VotingStructure*> votingStructures;
	votingStructures.push_back(smallTextFile);
	votingStructures.push_back(largeTextFile);

	sf::Clock clock;
	double elapsedTime = 0.0;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		elapsedTime += elapsed.asSeconds();
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			if (writeSmallTextButton.IsButtonPressed(mousePos.x, mousePos.y))
			{
				network.SendWriteMessage("SmallTextFile.txt");
				smallTextFile->doVoting = true;
			}
			
			if(writeLargeTextButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendWriteMessage("LargeTextFile.txt");
			
			if(writeSmallBinaryButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendWriteMessage("SmallBinary.jpg");

			if(writeLargeBinaryButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendWriteMessage("LargeBinary.wav");

			if (readSmallTextButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendReadMessage("SmallTextFile.txt");
			
			if(readLargeTextButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendReadMessage("LargeTextFile.txt");
			
			if(readSmallBinaryButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendReadMessage("SmallBinary.jpg");
			
			if(readLargeBinaryButton.IsButtonPressed(mousePos.x, mousePos.y))
				network.SendReadMessage("LargeBinary.wav");
		}

		network.ReceiveMessage();

		//if (elapsedTime >= 5)
		//{
		//	faultTolerantHelper->DoVoting(network);
		//	elapsedTime = 0;
		//}

		for (auto& vote : votingStructures)
		{
			if (vote->doVoting)
			{
				vote->Vote(network);
			}
		}x

		window.clear();

		readSmallTextButton.Render(window);
		readLargeTextButton.Render(window);
		readSmallBinaryButton.Render(window);
		readLargeBinaryButton.Render(window);

		writeSmallTextButton.Render(window);
		writeLargeTextButton.Render(window);
		writeSmallBinaryButton.Render(window);
		writeLargeBinaryButton.Render(window);

		window.display();
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
