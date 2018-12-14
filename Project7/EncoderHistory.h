#pragma once
#include"EncoderProgram.h"
#include<vector>
using namespace std;
class EncoderHistory
{
protected:
private:
	vector <vector<int>> stateHistory;
     vector<vector<int>> outputHistory;
	int CurrentStateNumber = 0;
	EncoderProgram Program; // composition
	
public:
	EncoderHistory();
	~EncoderHistory();
	void takeFileName(const string);
	void setHistory(const int [], const int [], const int);
	void takeSize(const int);
	
};

