// Related Documentation at http://www.vtuwiki.org/Using_Message_Queues_or_FIFOs_as_IPC_channels,_write_a_client_–_server_program_to_make_the_client_send_the_file_name_and_to_make_the_server_send_back_the_contents_of_the_requested_file_if_present.
// warnings maybe generated.Posix standard.not std c99.If warnings bother you, use --std=gnu89 flag or --std=c89.

// Generated for VtuWiki
// www.VtuWiki.org
// VtuWiki Foundation.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <strings.h>

//set the fifo file paths
#define fifo1 "/tmp/fifo1"
#define fifo2 "/tmp/fifo2"

int main(){
	int reader,writer,fd,i;
	char p[100],c[1000];
	for(i=0;i<100;i++)
    c[i]=p[i]='\0';
	mknod(fifo1,S_IFIFO|777,0);
	mknod(fifo2,S_IFIFO|777,0);
	printf(" Status: Waiting for client... \n ");
 	reader=open(fifo1,O_RDONLY);
 	read(reader,p,100);
 	printf(" Status: Recieved Request from client. \n");
 	printf("%s",p);
 	if((fd=open(p,O_RDONLY))<0){
 		writer=open(fifo2,O_WRONLY);
 		write(writer,"404 file not found.",20);
 		exit(0);
 	}
 	  read(fd,c,1000);
 	  printf(" server:%s found! \n transfering the content \n ",p);
 	writer=open(fifo2,O_WRONLY);
 	write(writer,c,strlen(c));
	printf("Server:transfer completed\n");
	return 0;
}