#!/bin/bash
for d in ./*/
do
(cd "$d"
(awk '{s+=$1}END{print s/NR}' out4Core.txt | tr '\n' '\t'; (ls | egrep '\.zip$'))  
);
done
 exec bash
