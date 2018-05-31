#!/bin/sh
cd
clear
cd /home/aswis/Documents/C_Plus_Plus/src/Algor/
g++ sortingSpeed_v3.cpp -o Vlad1
g++ sortingSpeed_2_v3.cpp -o Vlad2
# ./Vlad 7 30 2 >> /home/aswiz/Documents/C++/HanoiPDF/result.txt

echo "coulumns    rings    numbersOfSteps"

for (( rings=50; rings <= 100000; rings=rings+1000 ))
do
  ./Vlad2 $rings 3 >> /home/aswis/Documents/Web/SortingSpeed/app/data/speeds3.json
  ./Vlad1 $rings 3 >> /home/aswis/Documents/Web/SortingSpeed/app/data/speeds3.json
done
