#include  "mystring.h"

int len(const char *string)
{
for(index1=0;string[index1]!='\0';index1++);
return index1;
}


int cmp (const char *string1,const char *string2)
{
	if((len(string1))==len(string2))
	{
	for(index1=0;string2[index1]!='\0';index1++)
	{
	 if(string1[index1]==string2[index1])
     continue;
	 else
	 return string1[index1]-string2[index1];
	}
	return 0;
	}
	else
		return (len(string1)>len(string2))?1:-1;
}



char * cat ( char * string1, const char * string2 ){
	
	index1=len(string1);
	for(index2=0;string2[index2]!='\0';index2++, index1++)
	{string1[index1]=string2[index2];
	}
	string1[index1]='\0';
	
	return string1;
}



char* cpy (char* dest, const char* source)
{
	for(index1=0;source[index1]!='\0';index1++){
		dest[index1]=source[index1];
	}
	dest[index1]='\0';
	return dest;
}


