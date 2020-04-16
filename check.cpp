#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
	char s[100]="MOT HAI  BA   NAM";
	int i,n,j,dem,lap=0;
	//gets(s);
	dem=0;
	n=strlen(s);
	//do
	//{
		for(i=0;i<n;i++)
		{
			if((s[i]==' ')&&(s[i+1]==' '))
			{
				//dem++;
				for(j=i;j<n;j++)
				{
					s[j]=s[j+1];
				}
				n--;	//so ki tu cua chuoi giam xuong
				i--;	//sau buoc nay thi i se tang (vong for) nen ta se giam no xuong
			}
		}
		lap++;
	//}
	//while(dem==0);
	printf("Chuoi sau khi cat:\n");
	//for(i=0;i<(n-dem);i++)
	for (i=0;i<n;i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}
