// Related Documentation at http://www.vtuwiki.org/Using_Message_Queues_or_FIFOs_as_IPC_channels,_write_a_client_–_server_program_to_make_the_client_send_the_file_name_and_to_make_the_server_send_back_the_contents_of_the_requested_file_if_present
// warnings maybe generated.Posix standard.not std c99.If warnings bother you, use --std=gnu89 flag or --std=c89.

// Generated for VtuWiki
// www.VtuWiki.org
// VtuWiki Foundation.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <strings.h>

#define fifo1 "/tmp/fifo1"
#define fifo2 "/tmp/fifo2"

int main(){
	int writer,reader,i;
	char p[100],c[1000],ch;
	printf(" Status: Waiting for Server... \n ");
	//client will write to fifo1 
	mknod(fifo1,S_IFIFO|777,0);
	//client will read from fifo2
	mknod(fifo2,S_IFIFO|777,0);	
	
 	writer=open(fifo1,O_WRONLY);
 	printf(" Status: Server seems to be active. \n ");
 	printf(" Enter file name to read from: ");
 	i=0;
 	while(1){
 		ch=getchar();
 		if(ch=='\n')
 			break;
 		p[i++]=ch;
 	}
 	p[i]='\0';

 	write(writer,p,strlen(p));
 	reader=open(fifo2,O_RDONLY);
 	read(reader,c,1000);
 	printf(" Status: Server Responded. \n ");
	printf(" Status: Displaying Contents... \n ");
	fputs(c,stdout);
	printf("\n\n");
	return 0;
}