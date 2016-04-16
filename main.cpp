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

	if(argv[1][0] == 'j'){
		fileReader->prepareJson(); 
	}else if(argv[1][0] == 'p'){
		fileReader->prepare(); 
	}

	bool endpointsLeft = true; 
	bool firstOne = true; 
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
			model->setEndpointData(endpoint); 
			
			if(model->getEndpoint().length() <= 0){
				cout << "Endpoint url: "; 
				string url; 
				getline(cin, url);
				model->setEndpoint(url); 
				cout <<endl; 
			}

			if(model->getTitle().length() <= 0){
				cout << "Title: "; 
				string title; 
				getline(cin, title);
				model->setTitle(title); 
				cout <<endl; 
			}


			if(model->getDescription().length() <= 0){
				cout << "Description: "; 
				string description; 
				getline(cin, description);
				model->setDescription(description); 
				cout <<endl; 
			}

			string subData; 
			if(model->getExpectedInput().length() <= 0){
				cout << "Expected Input (paste JSON example, terminate with a semicolon): "; 
				string expectedInput; 	
				while (getline(cin, subData))
				{	
				    expectedInput += subData + "\n"; 
				    if(subData == ";"){
				    	break; 
				    }
				}
				model->setExpectedInput(expectedInput); 
				cout <<endl; 
			}


			if(model->getExpectedOutput().length() <= 0){
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
			}

			if(model->getRemarks().length() <= 0){
				cout << "Remarks: "; 
				string remarks; 
				getline(cin, remarks);
				model->setRemarks(remarks); 
				cout <<endl; 
			}

			if(argv[1][0] == 'p'){
				string latex = model->toLatex(); 
				fileReader->addToTexFile(latex); 
			}else if(argv[1][0] == 'j'){
				string json = model->toJson(firstOne); 
				fileReader->addToJsonFile(json);
			}

			firstOne = false; 

		}else{
			endpointsLeft = false; 
		}
	}

	if(argv[1][0] == 'j'){
		fileReader->endJson(); 
	}else if(argv[1][0] == 'p'){
		fileReader->end(); 
	}

	return 0; 
}