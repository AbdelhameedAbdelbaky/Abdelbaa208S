

#include "EncoderProgram.h"
using namespace std;


EncoderProgram::EncoderProgram() {   
	outputFileName = "";             //setting the file name to null so that no file is created at the beginning
	 
}
void EncoderProgram::getSize(const int size) {    //receiving the input vector size
	
	finalVectorSize = size;
}


EncoderProgram::~EncoderProgram()
{
}

void EncoderProgram::fillTrellis() { //Filling the empty spaces in the trilles diagram
	if (limit < 13) cout << setfill(char(178)) << setw((trellisStage == 0) ? (13 - limit) * 5 + 2 : (13 - limit) * 5 + 7) << "";
	cout << setfill(char(NULL));
}

void EncoderProgram::createTrellisFile(vector<vector<int>> receivedVector1, vector<vector<int>>receivedSVector2,
	const string name) {                 //Receiving the preferred user output file name and signalling 
	outputFileName = name + ".txt";      //the beginning of saving the file
	save++;
	drawTrellis(receivedVector1, receivedSVector2);
}

void EncoderProgram::drawTrellis(vector<vector<int>> receivedOutputVector, vector<vector<int>> receivedStateVector) {
	
	time_t timer;                      //Just setting the time for no reason
	time(&timer);
	struct tm timerFormat ;
	localtime_s(&timerFormat, &timer);
	char s[26];
	asctime_s(s,26,&timerFormat);
	string O = "Trellis Diagram\n";
	
	limit = (int) receivedStateVector.size(); //Setting limit of the diagram to keep looping
	trellisStage = 0;                         // Determining when to move down so not to exceed the console limit
	const int consoleLimit = 12;
	streambuf *backup, *filebuf;             //creating streambuf objects
	backup = cout.rdbuf();                   //getting cout buffer (for backup)
	ofstream outputFile(outputFileName , ios::app);
	filebuf = outputFile.rdbuf();            // getting outputFile buffer
	
	if (save > 0) 	
			cout.rdbuf(filebuf);            //redirecting cout streambuf to outputFile buffer (to save the diagram
		                                    //to outputFile)

		//starting to draw the diagram-----------------------------------------------------
	    O.insert(16, s);
	    cout << O << endl;
    	cout << "Trellis diagram showing the state changes:"<< endl;
		cout << setfill(char(205)) << setw(79) << char(187) << endl;

		while (limit>0) {      
			cout << setfill(char(NULL));//resting setfill to prevent any unwanted filling
			if (trellisStage == 0)cout << "Input : n/a,"; else cout <<endl<< "Input :"; //drawing input line
			for ( int i = trellisStage ; i < receivedStateVector.size(); i++) {

				cout << setw(4) << receivedStateVector[i][0];
				if (i == receivedStateVector.size() - 1) cout<<" "; else cout << ",";
				if ((i == consoleLimit) or( i == trellisStage + consoleLimit+1)) {
					cout << " "<<char(186);
					break;
				}
				
			}
			fillTrellis();
		
			if (trellisStage == 0)cout << endl << "Output: n/a,"; else cout<< endl<<"Output:"; //drawing output line
			for ( int i = trellisStage; i < receivedOutputVector.size(); i++) {
				cout << setw(2);
				for (int j = 0; j < 3; j++)
					cout << receivedOutputVector[i][j];
				if (i == receivedOutputVector.size() - 1)cout << " "; else cout << ",";
				
				if ((i == consoleLimit) or (i == trellisStage + consoleLimit + 1)) {
					cout << " "<<char(186);
					break;
				}
				
			}
			fillTrellis();
			cout << endl;
			(trellisStage == 0)?                                           //drawing the dash line
			cout << "Current State-----":cout << "Current State";
			for ( int i = trellisStage; i <(signed) receivedStateVector.size()-2; i++) {
				cout << setfill('-') << setw(5) << "";
				if ((i == consoleLimit-2) or (i == trellisStage + consoleLimit-1)) {
					cout <<"-----"<< char(186);
					break;
				}
				if ((receivedStateVector.size() - trellisStage != 1) and (i == receivedStateVector.size()-3))
					cout << "----";
			}
			
			fillTrellis();
			drawStates(receivedStateVector, "000(0)");      //drawing states lines 
			drawStates(receivedStateVector, "001(1)");
			drawStates(receivedStateVector, "010(2)");
			drawStates(receivedStateVector, "011(3)");
			drawStates(receivedStateVector, "100(4)");
			drawStates(receivedStateVector, "101(5)");
			drawStates(receivedStateVector, "110(6)");
			drawStates(receivedStateVector, "111(7)");
			cout << endl;
			cout<<setfill(char(205));
			cout<<setw(79);
			
			if (limit == receivedStateVector.size()) { trellisStage += 13; limit -= 13; }  
			else {
				trellisStage += 14; limit -= 14;
		
			}
			
			if(limit<0) cout << char(188);
			else cout << char(185);
        }
		
	cout << endl;
	cout.rdbuf(backup);               //returning cout to its original streambuf
	
}
		
void EncoderProgram::drawStates(vector<vector<int>>vectordraw, string label) {  //drawing states
	const int consoleLimit = 12;
	if (trellisStage == 0) {
		cout << endl << label << ": "; (label[0] == '0'&&label[1] == '0' && label[2] == '0') ?
			cout << char(17) : cout << " ";
		cout << "  :";
	}
	else cout << endl << label<<":";
	for ( int i = trellisStage; i < vectordraw.size(); i++) {
		
		cout << setw(2);
		if ((vectordraw[i][0] == label[0]-'0') and (vectordraw[i][1] == label[1] - '0')
			and (vectordraw[i][2] == label[2] - '0'))
			cout << char(17);
		else cout << " ";

		cout << "  :";
		
		if ((i == consoleLimit) or (i == trellisStage + consoleLimit + 1)) {
			 
		     cout << " "<<char(186);
			break;
		}
		
	}

	fillTrellis();
	
}

