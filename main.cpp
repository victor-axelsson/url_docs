#include <stdio.h>
#include <iostream>
#include "fileReader.h"
#include "EndpointModel.h"
#include <memory>

using namespace std; 

int main(int argc, const char* argv[])
{

	std::unique_ptr<FileReader> fileReader(new FileReader());
	fileReader->readFiles(); 
	fileReader->prepare(); 
	bool endpointsLeft = true; 
	string prevEndpoint; 

	while(endpointsLeft){

		string endpoint = fileReader->getNextEndpoint(); 

		if(endpoint != prevEndpoint){

			prevEndpoint = endpoint; 
			cout << "==================" <<endl;
			cout << endpoint <<endl; 
			

			
			//Skip endpoint
			cout << "Skip endpoint? (y/n)";
			string skip; 
			getline(cin, skip);
			if(skip == "y" || skip == "Y"){
				continue; 
			}  
			cout <<endl; 


			std::unique_ptr<EndpointModel> model(new EndpointModel());
			model->setEndpoint(endpoint); 
			
			cout << "Title: "; 
			string title; 
			getline(cin, title);
			model->setTitle(title); 
			cout <<endl; 

			
			cout << "Description: "; 
			string description; 
			getline(cin, description);
			model->setDescription(description); 
			cout <<endl; 

			cout << "Expected Input (paste JSON example, terminate with a semicolon): "; 
			string expectedInput; 
			string subData; 
			while (getline(cin, subData))
			{	
			    expectedInput += subData + "\n"; 
			    if(subData == ";"){
			    	break; 
			    }
			}
			model->setExpectedInput(expectedInput); 
			cout <<endl; 

			cout << "Expected Output (paste JSON example terminate with a semicolon): "; 
			string expectedOutput; 
			subData = ""; 
			while (getline(cin, subData))
			{	
			    expectedOutput += subData + "\n"; 
			    if(subData == ";"){
			    	break; 
			    }
			}
			model->setExpectedOutput(expectedOutput); 
			cout <<endl; 

			cout << "Remarks: "; 
			string remarks; 
			getline(cin, remarks);
			model->setRemarks(remarks); 
			cout <<endl; 
			
			string latex = model->toLatex(); 
			fileReader->addToTexFile(latex); 
		}else{
			endpointsLeft = false; 
		}
	}

	fileReader->end(); 


	return 0; 
}