#/bin/bash

#It needs to be build twice for the table of contents to be added
pdflatex ./res/documentation.tex
pdflatex ./res/documentation.tex
rm documentation.aux documentation.dvi documentation.log documentation.toc