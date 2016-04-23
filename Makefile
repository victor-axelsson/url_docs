CC=g++
INCLUDES=$(wildcard include/*.h)
SRC=main.cpp $(wildcard src/*.cpp)
FLAGS=-std=c++11 -Wall -g

all: 
	$(CC) $(SRC) -o url_docs -I include $(FLAGS)
	if [ ! -f "res/endpoints.txt" ]; then echo ";;;;;" > "res/endpoints.txt"; fi

clean:
	rm url_docs  
	rm documentation.pdf
	rm documentation.json
	rm res/endpoints.txt
	rm res/documentation.json
	rm res/documentation.tex

pdf:
	./url_docs pdf
	pdflatex ./res/documentation.tex
	pdflatex ./res/documentation.tex
	rm documentation.aux documentation.dvi documentation.log documentation.toc

json:
	./url_docs json
	cp ./res/documentation.json ./documentation.json