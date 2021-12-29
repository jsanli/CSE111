/*
 * Copyright (C) 2018-2021 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>
#include "cracker.h"

int main(int argc, char *argv[]) {
//	Message msg;
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	/*struct hostent *server = gethostbyname("thor");
	if(server == NULL) exit(-1);*/

	struct sockaddr_in server_addr;
	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(get_multicast_port());

	if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
		exit(-1);
	struct ip_mreq multicastRequest;
	multicastRequest.imr_multiaddr.s_addr = get_multicast_address();
	multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);
	if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP,(void *) &multicastRequest, sizeof(multicastRequest)) < 0){
		exit(-1);
	}
//	close(sockfd);

//	int socktcp = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in tcpaddr;
	bzero((char *) &tcpaddr, sizeof(tcpaddr));
	tcpaddr.sin_family = AF_INET;
	tcpaddr.sin_addr.s_addr = AF_INET;
	tcpaddr.sin_port = htons(get_unicast_port());
	//if (bind(socktcp, (struct sockaddr *) &tcpaddr, sizeof(tcpaddr)) < 0)
	//	perror("tcp\n");
	//char password[4];
	//if(n == -1){
	//	perror("n<0\n");
	//	exit(-1);
	//} 
	/*int n = 1;
	while(n > 0){
		n = recvfrom(sockfd, &msg, sizeof(msg), 0, (sockaddr*)&server_addr, (socklen_t *)sizeof(server_addr));
		std::cout << n << "\n";
	}*/
	//for(unsigned int x = 0; x <  msg.num_passwds; x++){*/
		//crack(msg.alphabet, "WuxaoJbgzwuwQ", password);
	//}
	//std::cout << password[0] << "\n";
	
}
