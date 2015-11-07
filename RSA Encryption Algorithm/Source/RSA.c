// Related Documentation at http://www.vtuwiki.org/Program_to_implement_the_RSA_Algorithm_for_simple_encryption_and_decryption_of_data.
// Standard compilation procedure
// compile using gcc/cc
// gcc RSA.c; ./a.out;

// Generated for VtuWiki 
// www.VtuWiki.org
// - VtuWiki foundation

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
//(Msg)^e mod N
unsigned long modexp(unsigned long msg, unsigned long exp, unsigned long n) {
 
	unsigned long i, k = 1; 
	for(i = 0;i < exp; i++)
		k = ( k * msg ) % n; 
	return k;
 
}
 
int main( ) {
 
	unsigned long p, q, e, d, n, phi, i, C, M; 
	int len;
	char data[100];
	system(" clear ");
	printf(" Enter the value of P and Q (such that p * q > 255, say 31 and 37 and p not equal to q) \n "); 
	scanf("%lu%lu", &p, &q);
	n = p * q;
	//Eulers phi function.  phi(n)
	phi = (p - 1) * (q - 1);
	printf(" phi(n) is %lu ",phi);
 
	//calculate e. e should not share a factor with phi(n)
	for(i = 1;i < phi; i++) {
		if( (phi % i ) == 0) 
			continue;
		else
			break;
	}
	e = i;
	printf(" \n Encryption key is : %lu ",e); 
 
	//calculate d. d=k*phi(n)+1/e or e*i-1 mod phi(n)
	for(i = 1;i < phi; i++)
		if(((e * i - 1 ) % phi) == 0)
			break; 
		d = i;
	printf( " \n decryption key is : %lu ",d); 
 
	//Lets get the message to encrypt and decrypt.
	printf( " \n pls enter the message : " ); 
	scanf( "%s" , data );
 
	//calculate the length of the data. we will do encryption and decryption of one character at a time.
	len = strlen( data );
	for( i = 0;i < len; i++) {
		M = ( unsigned long )data[i];
		C = modexp ( M , e , n );
		printf( " \n encrypted value and its char representation: %lu \t %c \n " , C ,  (char)C ); 
		M = modexp ( C , d , n );
		printf( " \n decrypted value and its char representation: %lu \t %c \n " , M , (char)M );
	}
 
	return 0;
}