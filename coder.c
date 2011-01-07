/********************************************************
Encryption/decryption program v1.0 

by Satya <http://satyaonline.cjb.net>

Compile: `gcc coder.c -o coder`. Probably platform independant, only
tested on Linux RedHat 6.0.

Use at own risk. Freeware. Please keep these comments intact. Inform me of
changes and redistribution. Give me credit if used anywhere. Standard
disclaimers apply.

This method is not secure! Do not use for encrypting sensitive material!
Remember the passwords, if you forget a password I know no way of
recovering original file!

Takes two arguments: input file, and output file. Output file will be
clobbered if it exists. Will ask for password of maximum length KEYLEN
characters (letters (case sensitive), numbers, some special characters).
Stick with letters and numbers.

********************************************************/

#include <stdio.h>

#define KEYLEN 20

int main(int argc, char *argv[])	{

char ch;
int i=1;
char pass[KEYLEN];
FILE *in,*out;

if (argc<3)	{
	fprintf(stderr,"usage:\n\t%s input_file output_file\n",argv[0]);
	exit(1);
}


if ( (in=fopen(argv[1],"rb")) == NULL )	{
	fprintf(stderr,"%s: failed to open %s\n",argv[0],argv[1]);
	exit(2);
}

if ( (out=fopen(argv[2],"wb")) == NULL )	{
	fprintf(stderr,"%s: failed to open %s\n",argv[0],argv[2]);
	exit(2);
}

printf("Enter password (upto %d characters, no spaces):",KEYLEN);
for (i=0;(pass[i]=getchar())!='\n' && i<KEYLEN;i++);

i=1;
while (fscanf(in,"%c",&ch)!=EOF)	{
	ch=pass[i] ^ (~(ch));
	i++;
	if (i>strlen(pass)) i=1;
	fprintf(out,"%c",ch);
}

fclose(in);
fclose(out);

return 0;
}

/*EOF*/
