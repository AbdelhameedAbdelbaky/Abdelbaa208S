#include "EncoderHistory.h"



EncoderHistory::EncoderHistory()
{
}


EncoderHistory::~EncoderHistory()
{
}

void EncoderHistory::takeFileName(const string name) {               //receiving the file name and sending it to the
	this->Program.createTrellisFile(outputHistory, stateHistory, name); // Encoder program
}

//Starting to store the states and the outputs in vectors and sending them to the EncoderProgram 
void EncoderHistory::setHistory(const int state[], const int output[], const int size ) { 
	CurrentStateNumber++;                             //Counter for every time the method is called
	const int stateBits = 3;
	stateHistory.resize(size);
	outputHistory.resize(size);

	for (int i = 0; i < stateBits; i++) 
		stateHistory[CurrentStateNumber-1].push_back(state[i]);
		
	for (int i = 0; i < stateBits; i++) 
		outputHistory[CurrentStateNumber - 1].push_back(output[i]);
	
	if(CurrentStateNumber == size)
	this->Program.drawTrellis(outputHistory, stateHistory);
}

void EncoderHistory::takeSize(const int size) {    //Receiving the size of the input vector and sending it to
	                                              //EncoderProgram so that the output and the
	                                              //state vectors aren't sent until both of them have been filled
	this->Program.getSize(size);                     //completely
	
}

