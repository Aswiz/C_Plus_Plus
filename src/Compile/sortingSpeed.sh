#!/bin/sh
cd
clear
cd /home/aswis/Documents/C_Plus_Plus/src/Algor/
g++ sortingSpeed_v2.cpp -o Vlad
# ./Vlad 7 30 2 >> /home/aswiz/Documents/C++/HanoiPDF/result.txt

echo "coulumns    rings    numbersOfSteps"

for (( rings=50; rings <= 1500; rings=rings+50 ))
do
  ./Vlad $rings 2 >> /home/aswis/Documents/Web/SortingSpeed/app/data/speeds2.json
done
