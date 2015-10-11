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
		void setEndpoint(std::string e){endpoint = e; };
		void setTitle(std::string e){title = e; };
		void setDescription(std::string e){description = e; };
		void setExpectedInput(std::string e){expectedInput = e; };
		void setExpectedOutput(std::string e){expectedOutput = e; };
		void setRemarks(std::string e){remarks = e; };

		std::string getEndpoint(){return endpoint; };
		std::string setTitle(){return title;};
		std::string setDescription(){return description;};
		std::string setExpectedInput(){return expectedInput;};
		std::string setExpectedOutput(){return expectedOutput;};
		std::string setRemarks(){return remarks; };

		std::string toLatex(); 
}; 