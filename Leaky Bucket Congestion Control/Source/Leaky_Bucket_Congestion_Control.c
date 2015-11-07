// Related Documentation at http://www.vtuwiki.org/Program_to_implement_the_Leaky_Bucket_Algorithm_for_Congestion_Control.
// warnings maybe generated.Posix standard.not std c99.If warnings bother you, use --std=gnu89 flag or --std=c89.

// Generated for VtuWiki 
// www.VtuWiki.org
// - VtuWiki foundation

#include<stdio.h> 

int rand(int a)
{
	//get a small random single digit.
	int m = (random() % 10)% a ;
	return m == 0 ? 1 : m; 
}

int main() {

	int packet_size[5], i, clk, bucket_size, output_rate, packet_size_remaining = 0, p_time; 
	
	//select random size for packets
	for(i = 0;i < 5; ++i)
		packet_size[i] = rand(5)*10; 

	//show the selected packet sizes(bytes) to the user 
	for(i = 0;i < 5; ++i)
		printf(" \n packet[%d]:%d bytes\t",i, packet_size[i]); 

	printf(" \n Enter the Output rate:");
	scanf("%d", &output_rate);

	printf(" Enter the Bucket Size: ");
	scanf("%d", &bucket_size); 

	//for each of the 5 packets.
	for(i = 0; i < 5; ++i)
	{
		//check broadly for bucket capacity (packet size + remaining size to process compared to size of bucket)	
		if((packet_size[i] + packet_size_remaining) > bucket_size) {
			//packet size is the culprit? 
			if(packet_size[i] > bucket_size)
				printf(" \n Incomming packet size (%d bytes) is Greater than bucketcapacity (%d bytes) -PACKET REJECTED \n ",packet_size[i],bucket_size); 
			//naah, we're overloaded!
			else
				printf(" \n Bucket capacity exceeded-REJECTED!! \n ");
		}
		//process them packets!
		else {
			
			//incoming and remaining packets
			packet_size_remaining += packet_size[i];
			printf(" \n \n Incomming Packet size: %d ",packet_size[i]); 
			printf(" \n Bytes remaining to Transmit: %d ",packet_size_remaining); 
			//select random time slice
			p_time = rand(4)*10;
			printf(" \n Time left for transmission: %d units ",p_time); 
			for(clk = 10; clk <= p_time; clk += 10)
			{
				//warning maybe generated. posix standard.not std c99. if warnings bother you, use --std=gnu89 flag.
				//This is just to make things look fancy.
				sleep(1); 
				//packets are still remaining? 
				if(packet_size_remaining) {
					//packet remaining can be handled immediately?
					if(packet_size_remaining <= output_rate)
						//handled.
						printf(" \n Packet of size %d Transmitted \n ",packet_size_remaining), packet_size_remaining = 0;
					else
						//handle some and keep rest for later.
						printf(" \n Packet of size %d Transmitted \n ",output_rate), packet_size_remaining -= output_rate;
					//alert user about packet remaining 
					printf(" ----Bytes Remaining after Transmission:%d \n ",packet_size_remaining); 
				}
				else
					printf(" \n No packets to transmit!! \n "); 
				printf(" Time Left: %d \n ",p_time-clk);
			}
		}
	}
}

