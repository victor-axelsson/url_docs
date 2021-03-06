# url_docs
Create autogenerated documentation with information needed for the consumer. Super easy to use.

## Express description
* Build with Makefile
* Define endpoints in `res/endpoints.txt`
* Run program 

## Build
in order to use the application you need to build it with the makefile. Just type make in the directory of the Makefile.

`make`

## Setup
In the res folder you create a file called `endpoints.txt` and if you need to have notes and temporary stuff you can put them in `tmp.txt`. 
In `endpoints.txt` you put all your endpoints that should be documented. It's IMPORTANT that you keep each endpoint on one line only. 

Each line is sepparated into 5 fields sepparated by semicolor. You can prefill the columns if you like or keep them empty. If any column is empty the program will prompt for input, otherwise it will use the provided value for the field. One line without any predefined values will look like this: 

```
;;;;;
```

More examples:
```
GET /v1/user;;;;
GET /v1/user/{id};My title;;;;
POST /v1/user;My title; Creates a new user; {"username": "as@s.com"};{"status":"success"};No remarks
GET /v1/article;;;;;
GET /v1/article/{id};;;;;This is my remark
POST /v1/article;;;;;
```
 
The fields maps like so:
```
[endpoint];[title];[description];[expected input];[expected output];[remarks]
```

All endpoint is sepparated by newline, so make sure you **don't have any trailng empty lines** after the enpoints.

## Run
Run the program from the terminal. You may need to give the right permissions and ownership as always. Example with bash: 

```
sudo chmod 775 url_docs
./url_docs
```

You can be asked up to 6 questions on each endpoint:

* Skip. if you want to skip the endpoint. Skipped endpoints will not be in the documentation. 
* Title for the endpoint (if missing)
* A description of what the endpoint actually does (if missing)
* The expected input in json. (if missing)  **In order to terminate the input you type a semiolon.** 
* The expected output in json. This wll be treated exactly as the `expected input`. **In order to terminate the input you type a semiolon.** 
* Remarks. If you want to comment something about the endpoint. (if missing)

All fields are optional. If you don't want to enter anything just press enter or semicolon (on expected input/output).

### Example of expected input/output
![Alt text](expected_output.png?raw=true "Example of expected output/input")
Note how the input is terminated with semicolon

## Build PDF
In order to create a pdf documentation you just type: 
```
make pdf
```
If everything went fine you should have your `documentation.pdf` ready in the root folder.

## Build JSON
In order to create a json documentation you just type: 
```
make json
```
If everything went fine you should have your `documentation.json` ready in the root folder.

### I'm on windows
If you are on windows you need to compile the latex manually. I suggest you [download texmaker](http://www.xm1math.net/texmaker/download.html), paste the content
from `/res/documentation.tex` and build it manually. You will also need to do some modifications to the Makefile in order to use it. It's really simple and you should be able to figure out what to replace the UNIX specific stuff with.

## If you terminate 
If you terminate the program half way through the latex in `res/documentation.tex` will be created up to that point. But 
you need to put `\end{document}` at the end in order for it to be valid latex (and compilable). The JSON will work in the same way, so you will have trailing commas and missing ] tag in the end. 
