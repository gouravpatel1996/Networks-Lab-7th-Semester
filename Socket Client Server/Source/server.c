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
	int sockfd,newsockfd,len,port;
	FILE* fd;
	struct sockaddr_in serv,cli;
	char buffer[256],c[2000],cc[20000];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	// bzero((char*)&serv,sizeof(serv));
	port=atoi(argv[1]);
	serv.sin_port=htons(port);
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_family=AF_INET;
	printf(" Status: Setting up... \n ");
	if(bind(sockfd,(struct sockaddr*)&serv,sizeof(serv))<0){
		printf(" Error \n " );
		exit(0);
	}
	printf(" Status: Waiting for client... \n ");
	listen(sockfd,10);
	len=sizeof(cli);
	newsockfd=accept(sockfd,(struct sockaddr*) &cli , &len);
	printf(" Status: Client connected... \n ");
	bzero(buffer,255);
	read(newsockfd,buffer,255);
	printf(" Status: Sending data... \n ");
	if((fd=fopen(buffer,"r"))!=NULL){
		fgets(cc,2000,fd);
		while(!feof(fd)){
			fgets(c,2000,fd);
			strcat(cc,c);
		}
	}
	

	write(newsockfd,cc,strlen(cc));
	printf(" Status: Done. \n ");
}