#include "Encoder.h"



void Encoder::saveFile(const string fileName) {      //Receiving the file name and sending it to the EncoderHistory

	this->History.takeFileName(fileName);
}

Encoder::Encoder( const string input){             //The constructor recieves the final correct input and starts
	
	
	this->History.takeSize((int)input.size());            //to store it in the inputVector
	inputVector.resize(input.size());

	for (int i = 0; i < input.size(); i++) 
		inputVector[i] = input[i] - '0';
	
	for (int i = 0; i < input.size(); i++)
		setCurrentState(inputVector[i]);
}


void Encoder::setCurrentState( const int inputBit) {           //Setting the current state
	
	currentState[2] = currentState[1];
	currentState[1] = currentState[0];
	currentState[0] = inputBit;
	
	
	setCurrentOutput();
	
}

void Encoder::setCurrentOutput() {                         //Setting the output that matches the current state

	output[0] = currentState[1] xor currentState[2];
	output[1] = currentState[2];
	output[2] = currentState[0] xor currentState[1];
	
	this->History.setHistory(currentState, output,(int)inputVector.size());     //Sending the current state and output
	                                                                      //to be stored in the EncoderHistory
}

Encoder::Encoder() {

	

}

Encoder::~Encoder()
{
}
