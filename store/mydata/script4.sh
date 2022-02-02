#!/bin/bash
for d in ./*/
do
(cd "$d"
g++ -std=c++11 -O2 -fopenmp -pg -g -c main.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g -c classify.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g main.o classify.o -o classify
for i in {1..5}; do taskset -c 0,1,2,3 ./classify rfile dfile 1009072 4 4 | awk '{if(NR==5) print $18}' >> out4Core.txt; done); 
 done
exec bash
