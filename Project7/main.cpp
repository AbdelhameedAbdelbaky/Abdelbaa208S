#include <iostream>
#include"Encoder.h"
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include"EncoderHistory.h"
using namespace std;

int main() {
	cout.width(10);
	cout << char(186) << setw(45) << "Convolutional Encoder Program" << setw(13) << char(186) << endl;
	cout.width(10);
	cout << char(186) << "Name: Abdelhameed Abdelbaky" << setw(30) << "SID: 8568906" << char(186) <<endl;
	cout.width(10);
	cout << char(186) << " Output A = (011), Output B = (001), Output C = (110) "<<setw(4) << char(186) << endl;
	cout <<setw(10)<<char(200)<< setfill(char(205)) << setw(58) << char(188) << endl;
	cout << setfill(char(NULL));

	char repeat = 'y';            //Definning variables used in main
	string userInput, inputFileName;
	char nextLine[10000], save;
	ifstream wrongInput("Wrong input.txt");     

	//Starting to receive and analysing the input in the main
	
	do {
		

		cout << "Please enter the input filename or type in the input\nsequence from the keyboard:\n\n";
		
		cin >> userInput;                                 //Receive input from user
		
		inputFileName = userInput;
		ifstream inputFile;
		inputFile.open(userInput);                        //Check if there's a file that matches the user input
		if (inputFile.good()) {
			userInput.clear();                           //clearing the userinput string to start filling it with
			                                             //input from input file
			char inputChar;
			while (!inputFile.fail()) {

				inputChar = inputFile.get();
				if ((inputChar != '1') xor (inputChar != '0'))
					userInput.push_back(inputChar);
			}
			

			inputFile.close();
			cout << endl << "File " << inputFileName << " read successfully...";

		}

		if (userInput.find(".txt") != string::npos) {         //Check if the user might have entered a wrong file name
			cout << "\nThere's no file with such a name, please enter a valid file name.\n\n";
			continue;
		}


		if(userInput.find_first_not_of("10") != string:: npos){    //Check if the user input is only 0's and 1's
				
				if (!wrongInput.fail()) {
					wrongInput.getline(nextLine, 10000);
					cout << endl << nextLine << endl;

					if (wrongInput.eof())
						return 0;
					
					cout << endl;
					continue;
				}
		}

		Encoder Encode(userInput); //Constructing an Encoder object
		
		cout << "Please type 'Y' or 'y' to output trellis to text file...";
		cin >> save;
		cin.seekg(0, cin.beg);                             //moving the iterator of cin stream to the beginning
		                                                   //to stop it from moving to the  next char in the stream
		if (save == 'y' or save == 'Y') {
			cout << "\nEnter the name of the output file...";

			string outputFileName;
			cin >> outputFileName;
			Encode.saveFile(outputFileName);             //Sending the file name to the Encoder
		
			cout << "\nThe output sequence has been saved as " << outputFileName << ".txt\n";
		}
		cout << endl;
		cout << "Please type 'Y' or 'y' to run again...";
		cin>>repeat;
		
		wrongInput.seekg(0,wrongInput.beg);             //returning the iterator to the beginning of the Wrong Input
														//text file stream
		cin.seekg(0, cin.beg);                                              

		cout << endl;
	} while ((repeat == 'y') xor (repeat == 'Y'));

	cout << "Thank you for using the convolutional encoder program.\nGoodbye!\n";
	
	wrongInput.close();

		return 0;
}