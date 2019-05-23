#pragma once
#include <vector>
#include "NetworkHelper.h"

class NetworkHelper;

class FaultTolerantHelper
{
public:
	struct VotingStructure
	{
		std::string m_FileName;
		std::map<int, std::vector<unsigned char>> m_Contents;
		std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile1;
		std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile2;
		std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile3;
		bool doVoting = false;
	};

	FaultTolerantHelper();
	void DoVoting(NetworkHelper& network);
	void LoadContents(VotingStructure whichStructure, NetworkHelper& network);

	std::vector<VotingStructure> m_VotingStructures;

	VotingStructure m_SmallTextFile;
	VotingStructure m_LargeTextFile;
	VotingStructure m_SmallBinaryFile;
	VotingStructure m_LargeBinaryFile;
};
