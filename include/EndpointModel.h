#include <string>
#include <iostream>

class EndpointModel{
	std::string endpoint; 
	std::string title;
	std::string description; 
	std::string expectedInput;
	std::string expectedOutput; 
	std::string remarks; 

	public:
		void setEndpoint(std::string e){endpoint = e;}; 
		void setTitle(std::string e){title = e; };
		void setDescription(std::string e){description = e; };
		void setExpectedInput(std::string e){expectedInput = e; };
		void setExpectedOutput(std::string e){expectedOutput = e; };
		void setRemarks(std::string e){remarks = e; };

		std::string getEndpoint(){return endpoint; };
		std::string getTitle(){return title;};
		std::string getDescription(){return description;};
		std::string getExpectedInput(){return expectedInput;};
		std::string getExpectedOutput(){return expectedOutput;};
		std::string getRemarks(){return remarks; };

		std::string toLatex();
		void latexParse(std::string& subject); 
		void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace);
		std::string toJson(bool isFirstOne); 
		void setEndpointData(std::string e); 
		std::string prettyfy(std::string json); 
}; 