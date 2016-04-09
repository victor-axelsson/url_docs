#include "fileReader.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

void FileReader::readFiles(){
	offset = 0; 
}

std::string FileReader::getNextEndpoint(){

	string line;
	ifstream myfile(path);
	int counter = 0; 

	if (myfile.is_open()){

		while (!myfile.eof() && counter <= offset){
			getline (myfile,line);
			
			counter ++; 
		} 

		myfile.close();
		offset++; 
	}else{
		cout << "Unable to open file"; 
	} 
	return line; 
}

void FileReader::prepare(){
	ifstream s(headerPath); 
	string line; 
	string contents; 

	if (s.is_open()){

		while (!s.eof()){
			getline (s,line);
			contents += line; 
		} 

		s.close();
	}else{
		cout << "Unable to open file"; 
	} 

	std::ofstream outfile;

	outfile.open(texPath);
	outfile << contents; 
	outfile.close(); 
}


void FileReader::prepareJson(){
	std::ofstream outfile;
	outfile.open(jsonPath);
	outfile << "["; 
	outfile.close(); 
}

void FileReader::end(){
	std::ofstream outfile;
	outfile.open(texPath, ios::out | ios::app);
	outfile << "\\end{document}"; 
	outfile.close(); 
}

void FileReader::endJson(){
	std::ofstream outfile;
	outfile.open(jsonPath, ios::out | ios::app);
	outfile << "]"; 
	outfile.close(); 
}

void FileReader::addToTexFile(string texmodel){
	std::ofstream outfile;

	outfile.open(texPath, ios::out | ios::app);
	outfile << texmodel; 
	outfile.close(); 
} 

void FileReader::addToJsonFile(std::string jsonmodel){
	std::ofstream outfile;

	outfile.open(jsonPath, ios::out | ios::app);
	outfile << jsonmodel; 
	outfile.close(); 
}