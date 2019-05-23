#include "pch.h"
#include "FaultTolerantHelper.h"
#include <fstream>
#include <iostream>

FaultTolerantHelper::FaultTolerantHelper()
{
	m_SmallTextFile.m_FileName = "SmallTextFile.txt";
	m_LargeTextFile.m_FileName = "LargeTextFile.txt";
	m_SmallBinaryFile.m_FileName = "SmallBinary.jpg";
	m_LargeBinaryFile.m_FileName = "LargeBinary.wav";
}

void FaultTolerantHelper::DoVoting(NetworkHelper& network)
{
	//LoadContents(m_SmallTextFile, network);
	//LoadContents(m_LargeTextFile, network);
	//LoadContents(m_SmallBinaryFile, network);
	//LoadContents(m_LargeBinaryFile, network);
}

void FaultTolerantHelper::LoadContents(VotingStructure whichStructure, NetworkHelper& network)
{
	for (int i = 1; i <= 3; i++)
	{
		whichStructure.m_Contents[i].clear();
		network.SendReadMessage(whichStructure.m_FileName, ('0' + i));
	}
}