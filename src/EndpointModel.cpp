#include "EndpointModel.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

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
	latex += expectedInput + "\n";  
	latex += "\\end{lstlisting} \n";  

	latex += "\\subsubsection{Expected output} \n";
	latex += "\\begin{lstlisting}[language=json,firstnumber=1] \n";
	latex += expectedOutput + "\n";  
	latex += "\\end{lstlisting} \n";  

	return latex; 
}

