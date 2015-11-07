// Related Documentation at http://www.vtuwiki.org/Using_TCP/IP_sockets,_write_a_client_–_server_program_to_make_the_client_send_the_file_name_and_to_make_the_server_send_back_the_contents_of_the_requested_file_if_present.
// Generated for VtuWiki 
// www.VtuWiki.org
// - VtuWiki foundation

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc,char * argv[]){
	int sockfd,newsockfd,len,fd;
	struct sockaddr_in serv,cli;
	char buffer[256],c[2000],cc[20000];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&serv,sizeof(serv));
	serv.sin_port=htons(atoi(argv[1]));
	serv.sin_family=AF_INET;
	printf(" Status: Attempting to connect to server\n ");
	connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	printf(" Status: Connected \n ");
	printf(" Enter file name: ");
	scanf("%s",buffer);
	write(sockfd,buffer,strlen(buffer));
	bzero(c,2000);
	printf(" Waiting for Server to respond.. \n \n");
	read(sockfd,c,1999);
	printf("%s",c);
	printf(" \n ");
	return 0;
}