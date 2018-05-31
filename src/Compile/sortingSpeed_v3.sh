#!/bin/sh
cd
clear
cd /home/aswis/Documents/C_Plus_Plus/src/Algor/
g++ sortingSpeed_v3.cpp -o Vlad1
g++ sortingSpeed_2_v3.cpp -o Vlad2
g++ sortingSpeed_3_v3.cpp -o Vlad3

# typeSorting:  1 - InsertionSort
# 							2 - SelectionSort
# 							3 - BubbleSort
# 							4 - QuickSort
# 							5 - BubbleSortFlag
typeSorting=5

step=1000
maxNumbers=100000

./Vlad3 $typeSorting >> /home/aswis/Documents/Web/SortingSpeed/app/data/BubbleSortFlag3.json

	for (( rings=0; rings <= $maxNumbers; rings=rings+$step )) do
		./Vlad2 $rings 3 >> /home/aswis/Documents/Web/SortingSpeed/app/data/BubbleSortFlag3.json
		for (( i = 1; i <= 3; i++ )); do
			./Vlad1 $rings $typeSorting $i >> /home/aswis/Documents/Web/SortingSpeed/app/data/BubbleSortFlag3.json
		done
done
