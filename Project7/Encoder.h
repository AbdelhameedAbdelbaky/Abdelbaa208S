#pragma once
#ifndef ENCODER_H
#define ENCODER_H
#include"EncoderHistory.h"
#include<string>
class Encoder
{

protected:
private:
    int currentState[3] = { 0 , 0 , 0 };
	int output[3] = { 0 , 0 , 0 };
	vector<bool>inputVector;
	EncoderHistory History;// composition
public:
	Encoder();
	~Encoder();
	void saveFile(const string);
	Encoder(const string);
	void setCurrentState( const int input);
	void setCurrentOutput();
};
#endif
