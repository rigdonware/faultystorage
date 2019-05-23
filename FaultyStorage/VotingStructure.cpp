#include "pch.h"
#include "VotingStructure.h"
#include <fstream>
#include <iostream>

VotingStructure::VotingStructure(std::string filename)
{
	m_FileName = filename;
}

void VotingStructure::Vote(NetworkHelper& network)
{
	LoadContents(network);
}

void VotingStructure::LoadContents(NetworkHelper& network)
{
	for (int i = 1; i <= 3; i++)
	{
		m_Contents[i].clear();
		if (i == 1)
			network.SendReadMessage(m_FileName, NULL);
		else
			network.SendReadMessage(m_FileName, ('0' + i));
	}
}