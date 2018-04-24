#!/bin/sh
cd
clear
cd /home/aswiz/Documents/C++/Algor
g++ hanoiTower_v4_forTesting.cpp -o Vlad
# ./Vlad 7 30 2 >> /home/aswiz/Documents/C++/HanoiPDF/result.txt

echo "coulumns    rings    numbersOfSteps"
for (( coulumns=9; coulumns <= 9; coulumns++ ))
do
  for (( rings=7; rings <= 30; rings++ ))
  do
    ./Vlad $coulumns $rings 2 >> /home/aswiz/Documents/C++/HanoiPDF/result_9_numbersOfSteps.txt
  done
done
