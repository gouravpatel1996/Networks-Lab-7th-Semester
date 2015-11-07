// Related Documentation at http://www.vtuwiki.org/Program_to_implement_error_detection_CRC-CCITT(16-bit)_procedure..

// Generated for VtuWiki 
// www.VtuWiki.org
// - VtuWiki foundation

#include<stdio.h> 
//r is for remainder.
char message[50],generator[50],r[50],quotient[50],temp[50]; 
void caltrans(int); 
void crc(int); 
void calram(); 
void shiftl(); 
int main() 
{ 	int n,i=0; 
	char ch,flag=0; 
	printf("Enter the frame bits:"); 
	while((ch=getc(stdin))!='\n')  
		message[i++]=ch;          
	n=i;                          
	for(i=0;i<16;i++)             
		message[n++]='0'; 
	message[n]='\0'; 
	printf("Message after appending 16 zeros:%s",message); 
	for(i=0;i<=16;i++) 
		generator[i]='0'; 
	generator[0]=generator[4]=generator[11]=generator[16]='1';generator[17]='\0'; 
	printf("\n generator:%s \n",generator); 
	crc(n); 
	printf("\n\n quotient:%s",quotient); 
	caltrans(n); 
	printf("\n transmitted frame:%s",message); 
	printf("\n Enter transmitted frame:"); 
	scanf("\n%s",message); 
	printf("CRC checking\n"); 
	crc(n); 
	printf("\n\n last r:%s",r); 
	for(i=0;i<16;i++) 
		if(r[i]!='0') 
			flag=1; 
		else 
			continue; 
		if(flag==1) 
			printf("Error during transmission"); 
		else 
			printf("\n\n Received frame is correct \n"); 
} 
 
void crc(int n) 
{ 
	int i,j; 
	for(i=0;i<n;i++)
		temp[i]=message[i]; 
	for(i=0;i<16;i++)
		r[i]=message[i]; 
	printf("\n Intermediate remainder\n");
	for(i=0;i<n-16;i++) 
	{ 
		if(r[0]=='1') 
		{ 
			quotient[i]='1'; 
			calram(); 
		} 
		else 
		{ 
			quotient[i]='0'; 
			shiftl(); 
		} 
		r[16]=message[17+i]; 
		r[17]='\0'; 
		printf("\nr %d:%s",i+1,r); 
		for(j=0;j<=17;j++) 
			temp[j]=r[j]; 
	} 
	quotient[n-16]='\0'; 
}
 
void calram() 
{ 
	int i,j; 
	for(i=1;i<=16;i++) {
		r[i-1]=((int)temp[i]-48)^((int)generator[i]-48)+48; 
				printf("\n %d = %d ^ %d \n",r[i-1],(int)temp[i]-48,(int)generator[i]-48);

	}
} 
 
void shiftl() 
{ 
	int i; 
	for(i=1;i<=16;i++) 
		r[i-1]=r[i]; 
} 
 
void caltrans(int n) 
{ 
	int i,k=0; 
	for(i=n-16;i<n;i++) 
		message[i]=((int)message[i]-48)^((int)r[k++]-48)+48;  //ascii value of 0 is 48 
	message[i]='\0'; 
}