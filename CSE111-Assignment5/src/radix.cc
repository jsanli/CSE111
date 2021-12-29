/*
 * Copyright (C) 2018-2021 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include "iostream"
#include "radix.h"

//borrows from other assignment

void ParallelRadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, unsigned int cores) { 
        for(std::vector<unsigned int> i : lists){
                unsigned int max = 0;
                for(unsigned int x : i){
                        if(x > max){
                                max = x;
                        }
                }

                unsigned int exponent = 1;
                while(max/exponent > 0 && (exponent % 10 == 0 || exponent == 1)){
                        unsigned int count[10] = {0,0,0,0,0,0,0,0,0,0};
                        unsigned int output[i.size()];
                        for (unsigned int p : i){
                                        count[(p/exponent) % 10 ] = (count[(p/exponent)% 10 ]) + 1;
			}
                        for (unsigned int x = 1; x < 10; x=x+1){
                                count[x] = count[x] + count[x - 1];
			}
                        for (unsigned int x = i.size() - 1; x >= 0 && x <= i.size(); x=x-1)
                        {
                                output[count[ (i[x]/exponent)%10 ] - 1] = i[x];
                                count[ (i[x]/exponent)%10 ] = count[ (i[x]/exponent)%10 ] - 1 ;
                         }
                        for (unsigned int x = 0; x < i.size(); x=x+1){
                                i[x] = output[x];
                        }
                        exponent = exponent * 10;
                }
        }
}

