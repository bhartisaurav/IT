#!/bin/bash
for d in ./*/
do
(cd "$d"
g++ -std=c++11 -O2 -fopenmp -pg -g -c main.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g -c classify.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g main.o classify.o -o classify
for i in {1..10}; do taskset -c 0,1 ./classify rfile dfile 1009072 2 10 | awk '{if(NR==11) print $18}' >> out2Core.txt; done);
 done
exec bash
