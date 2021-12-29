/*
 * Copyright (C) 2018-2021 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream> 
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>

#include "radix.h"
#include "helper.h"


RadixServer::RadixServer(const int port, const unsigned int cores) {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) exit(-1);
	
	struct sockaddr_in server_addr;
	bzero((char *) &server_addr, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	if(bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
		exit(-1);
	}
	
	listen(sockfd, 5);
	char buffer[256];

	for(;;) {
		struct sockaddr_in client_addr;
		socklen_t len = sizeof(client_addr);

		int newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &len);
		if(newsockfd < 0){
			exit(-1);
		}

		bzero(buffer,256);
		int n = recv(newsockfd, buffer, 255, 0);
		if(n<0){
			exit(-1);
		}

		n=write(newsockfd,buffer,strlen(buffer));
		if(n<0){
			exit(-1);
		}
		close(newsockfd);
	}
	close(sockfd);
}

void RadixClient::msd(const char *hostname, const int port, std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists) { 
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct hostent *server = gethostbyname(hostname);

	struct sockaddr_in serv_addr;
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

	serv_addr.sin_port = htons(port);

	char buffer[256];
	bzero(buffer,256);
	
	for(std::vector<unsigned int> &i : lists){
		unsigned int solution[i.size()];
		for(unsigned int q = 0; q < i.size(); q++){
			solution[q] = (unsigned int)(0);
		}
		unsigned int counter = 0;
		for(unsigned int r : i){
			solution[counter] = r;
			counter++;
		}
		std::sort(solution, solution + i.size(), helper::compareFunction);
		for(unsigned int w = 0; w < i.size(); w++){
			i[w] = solution[w];
		}
		counter = 0;
		for(unsigned int o : i){
			o = solution[counter];
			counter++;
			o+=0;
		}
//		for(unsigned int e : i){
//			std::cout << e << counter << "\n";
//		}
	}
	close(sockfd);
}

bool helper::compareFunction(unsigned int first, unsigned int second){
	unsigned int exponent = 1;
	unsigned int counter1 = 0;
	unsigned int counter2 = 0;
      	do{
		counter1++;
               	exponent = exponent * 10;
        }
	while(first/exponent > 0 && (exponent % 10 == 0 || exponent == 1));
	exponent = 1;
      	do{
		counter2++;
               	exponent = exponent * 10;
        }
	while(second/exponent > 0 && (exponent % 10 == 0 || exponent == 1));
	if(counter1 == counter2){
		if(first < second){
			return true;
		}
		else{
			return false;
		}
	}
	else if(first/10 == second){
		return false;
	}
	else if(first == second/10){
		return true;
	}
	else if(counter1 > counter2){
		return compareFunction(first/10, second);
	}
	else{
		return compareFunction(first, second/10);
	}
}
