#!/bin/bash
g++ -std=c++11 -O2 -fopenmp -pg -g -c main.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g -c classify.cpp
g++ -std=c++11 -O2 -fopenmp -pg -g main.o classify.o -o classify
for i in {1..5}; do taskset -c 1,2,3,4 ./classify rfile dfile 100 1 4 | awk '{if(NR==5) print $18}' >> output_4_core1.txt; done
exec bash
