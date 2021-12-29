/*
 * Copyright (C) 20182-2021 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <iostream>
#include <cmath>

#include "radix.h"

//https://www.geeksforgeeks.org/c-program-find-largest-element-array/
//https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
//https://www.codingeek.com/algorithms/radix-sort-explanation-pseudocode-and-implementation/

void RadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, const unsigned int cores) { 
	for(std::vector<unsigned int> i : lists){
		unsigned int max = 0;
		for(unsigned int x : i){
			if(x > max){
				max = x;
			}
		}

		unsigned int exponent = 1;	
		while(max/exponent > 1 && (exponent % 10 == 0 || exponent == 1)){
        		unsigned int count[10] = {0};
			unsigned int output[i.size()];
        		for (unsigned int p : i)
            				count[(p/exponent)%10 ] = count[(p/exponent)%10 ] + 1;
        		for (unsigned int x = 1; x < 10; x++)
            			count[x] = count[x] + count[x - 1];
        		for (unsigned int x = i.size() - 1; x > 0; x--)
        		{
				if(i[x] != 0){
            				output[count[ (i[x]/exponent)%10 ] - 1] = i[x];
				}
            			count[ (i[x]/exponent)%10 ] = count[ (i[x]/exponent)%10 ] - 1;
       			 }
        		for (unsigned int x = 0; x < i.size(); x++){
           		 	i[x] = output[x];
			}
            // Move to next digit place
            		exponent = exponent * 10;
		}
	}
	
}
		/*for(unsigned int exponent = 1; (max / exponent) > 1 && (exponent % 10 == 0 || exponent == 1); exponent = exponent * (unsigned int)(10)){
			std::vector<unsigned int> output;
			unsigned int count[10];
			unsigned int temp[i.size()];
			unsigned int iter = 0;
			for(unsigned int p : i){
				std::cout << count[(p / exponent) % 10] << "\n";
				count[(p / exponent) % 10]++;
				temp[iter] = p;
				iter++;
			}

			for(unsigned int e = 1; e < 10; e++){
				count[e] += count[e-1];
			}
			
			for(unsigned int r = i.size() + 1; r > 0; r = r-1){
				std::cout << count[(temp[r] / exponent) % 10] - 1 << "\n";
				output[count[temp[r] / exponent % 10] - 1] = temp[r];
				count[(temp[r] / exponent) % 10]--; 
			
			}
			for(unsigned int f : i){
				i[iter] = output[iter];
				std::cout << i[iter] << "/n";
				iter++;
				f--;	
				f++;
			}
		}*/
