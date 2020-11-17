/**
**RSA Key Pair Generation 
**Author: Sudhir G.N,The University of HULL,
**mailto: G.N.Sudhir@2007.hull.ac.uk
**Desc  : Generates a 2048 bit RSA keypair and
		writes all the components of the 
		keypar viz. (p,q,n,e,d) to 'rsakeypair.txt'.
**/

#include "stdafx.h"
#include <conio.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/x509.h>
#include <stdlib.h>
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	
	FILE* fp;
	RSA *myrsa;
	unsigned long e = RSA_3;
	BIO* out = NULL;

	printf("\nRSA Key Pair Generation -uses OpenSSL(www.openssl.org)");

	printf("\n\nGenerating 2048 bit RSA Key pair ..");
	printf("\nthis could take 20-30 secs,depending on your machine..");
		
	myrsa = RSA_generate_key(2048,e,NULL,NULL);

	out=BIO_new(BIO_s_file());
	

	if(myrsa==NULL){
		printf("Unknown erron in generating keypair..");
		printf("press any key to exit..");
		_getch();
	}
    
	fp=fopen("rsakeypair.txt","wb");
	//BIO_set_fp(out,fp,BIO_BIND_NORMAL);
	out = BIO_new_fp(fp,BIO_CLOSE);
	BIO_printf(out,"\n");
	RSA_print(out,myrsa,0);
	fclose(fp);
	
	printf("\nFinished generating RSA Keypair.., Opened 'rsakeypair.txt");
	system("write rsakeypair.txt");
	printf("\nPress any key to exit..");
	_getch();
		
return(0);


}

