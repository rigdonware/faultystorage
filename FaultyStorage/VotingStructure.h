#pragma once
#include <vector>
#include "NetworkHelper.h"

class NetworkHelper;

class VotingStructure
{
public:
	VotingStructure(std::string filename);
	std::string m_FileName;
	std::map<int, std::vector<unsigned char>> m_Contents;
	std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile1;
	std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile2;
	std::tuple<std::string, std::vector<unsigned char>> m_ContentsFile3;
	bool doVoting = false;
	double votingElapsedTime = 0.0;
	void Vote(NetworkHelper& network);
	void LoadContents(NetworkHelper& network);
};
