#include <string>
#include <iostream>

class FileReader{
	std::string path = "res/endpoints.txt";  
	std::string texPath = "res/documentation.tex"; 
	std::string jsonPath = "res/documentation.json"; 
	std::string headerPath = "res/header.tex"; 
	int offset; 
	public:
		void readFiles(); 	
		std::string getNextEndpoint(); 
		void prepare(); 
		void prepareJson(); 
		void end(); 
		void endJson(); 
		void addToTexFile(std::string texmodel); 
		void addToJsonFile(std::string jsonmodel); 
}; 