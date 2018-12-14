#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<time.h>

using namespace std;

class EncoderProgram
{
protected:
private:
	int finalVectorSize;
	int trellisStage ;
	int limit;
	int save;
	string outputFileName;
public:
	EncoderProgram();
	~EncoderProgram();
	void drawTrellis(vector<vector<int>> , vector<vector<int>>);
	void getSize(const int);
	void drawStates(vector<vector<int>>, const string);
	void createTrellisFile(vector <vector<int>>, vector <vector<int>>, const string);
	void fillTrellis();
};

