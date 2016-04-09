#include "EndpointModel.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std; 

void EndpointModel::setEndpointData(std::string e){
	std::string input = e;
	std::istringstream ss(input);
	std::string token;

	int counter = 0; 

	while(std::getline(ss, token, ';')) {
		
		switch(counter){
		    case 0:
		    	endpoint = token; 
		       break;

		    case 1:
		    	title = token; 
		       break;

		    case 2:
		    	description = token; 
		       break;

		    case 3:
		    	expectedInput = token; 
		       break;

		    case 4:
		    	expectedOutput = token; 
		       break;

   		   	case 5:
		    	remarks = token; 
		       break;

		    default : 
		       break; 
		}

		counter++;
	}

}

std::string getIndentation(int depth){

	string indented = ""; 
	for(int i = 0; i < depth; i++){
		indented += "  "; 
	}

	return indented; 
}


std::string EndpointModel::prettyfy(std::string json){
	
	int depth = 0;
	string formatted = "";  


	for(int i = 0; i < json.length(); i++){

		bool skip = false; 

		if(json[i] == '{' || json[i] == '['){
			depth ++; 
			formatted += json[i]; 
			formatted += "\n"; 
			formatted += getIndentation(depth); 
			skip = true; 

		}else if(json[i] == ']' || json[i] == '}'){
			depth --; 
			formatted += "\n";
			formatted += getIndentation(depth); 
			formatted += json[i]; 
			skip = true; 
		}


		if(!skip && json[i] != ';'){
			formatted += json[i]; 
		}


		if(json[i] == ','){
			formatted += "\n"; 
			formatted += getIndentation(depth); 
		}
		

		

	}

	return formatted; 
}


std::string EndpointModel::toLatex(){
	string latex = "\\subsection{"+title+"} \n";

	latex +=  description + "\n";

	latex += "\\subsubsection{Endpoint} \n"; 
	latex += "\\begin{verbatim}\n"; 
	latex += endpoint + "\n";
	latex += "\\end{verbatim}"; 

	latex += "\\subsubsection{Remarks} \n"; 
	latex += remarks + "\n";

	latex += "\\subsubsection{Expected input} \n";
	latex += "\\begin{lstlisting}[language=json,firstnumber=1] \n";
	latex += prettyfy(expectedInput) + "\n";  
	latex += "\\end{lstlisting} \n";  

	latex += "\\subsubsection{Expected output} \n";
	latex += "\\begin{lstlisting}[language=json,firstnumber=1] \n";
	latex += prettyfy(expectedOutput) + "\n";  
	latex += "\\end{lstlisting} \n";  

	return latex; 
}

std::string EndpointModel::toJson(bool isFirstOne){

	string inputPlaceholder = expectedInput; 
	string outputPlaceholder = expectedOutput; 

	if(expectedInput[0] == ';'){
		inputPlaceholder = "{}";
	}

	if(expectedOutput[0] == ';'){
		outputPlaceholder = "{}";
	}

	string json = ""; 

	if(!isFirstOne){
		json += ","; 
	}

	json += "{\"endpoint\":\""+endpoint+"\", \"title\": \"" + title + "\", \"description\":\"" + description + "\", \"remarks\": \"" + remarks + "\", "; 
	json += "\"expectedInput\": " + inputPlaceholder + ", \"expectedOutput\": " + outputPlaceholder + "}"; 

	return prettyfy(json); 
}

