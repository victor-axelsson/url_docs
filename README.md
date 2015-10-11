# url_docs
Create autogenerated documentation with information needed for the consumer. Super easy to use.

##Express description
* Build with Makefile
* Define endpoints in `res/endpoints.txt`
* Run program
* Compile latex with `create_pdf.sh`

##Build
in order to use the application you need to build it with the makefile. Just type make in the directory of the Makefile.

`make`

##Setup
In the res folder you create a file called `endpoints.txt` and if you need to have notes and temporary stuff you can put them in `tmp.txt`. 
In `endpoints.txt` you put all your endpoints that should be documented. Example: 

```
GET /v1/user
GET /v1/user/{id}
POST /v1/user
GET /v1/article
GET /v1/article/{id}
POST /v1/article
```

All endpoint is sepparated by newline, so make sure you **don't have any trailng empty lines** after the enpoints.

##Run
Run the program from the terminal. You may need to give the right permissions and ownership as always. Example with bash: 

```
sudo chmod 775 url_docs
./url_docs
```

You will be asked 6 questions on each endpoint:

* Skip. if you want to skip the endpoint. Skipped endpoints will not be in the documentation. 
* Title for the endpoint
* A description of what the endpoint actually does
* The expected input. You can paste whatever you like here but it will be treated as code so a good practice is to pase a JSON example. **In order to terminate the input you create a newline with a semiolon.**
* The expected output. This wll be treated exactly as the `expected input`. **In order to terminate the input you create a newline with a semiolon.**
* Remarks. If you want to comment something about the endpoint.

All fields are optional. If you don't want to enter anything just press enter or semicolon (on expected input/output).

###Example of expected input/output
![Alt text](expected_output.png?raw=true "Example of expected output/input")
Note how the input is terminated with semicolon

##Build PDF
If you are on a system that has bash terminal(MacOS, most linux like Debian, Ubuntu etc) you can run the script `create_pdf.sh` from you terminal. 

```
./create_pdf.sh
```
If everything went fine you should have your `documentation.pdf` ready in the root folder.

###I'm on windows
If you are on windows you need to compile the latex manually. I suggest you [download texmaker](http://www.xm1math.net/texmaker/download.html), paste the content
from `/res/documentation.tex` and build it manually. 

##If you terminate 
If you terminate the program half way through the latex in `res/documentation.tex` will be created up to that point. But 
you need to put `\end{document}` at the end in order for it to be valid latex (and compilable).