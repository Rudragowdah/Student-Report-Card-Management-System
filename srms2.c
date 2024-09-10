#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
typedef struct student
{
    char name[20];
    int rollno;
    char usn[10];
    int english;
    int kannada;
    int hindi;
    int maths;
    int science;
    int social;
    float percentage;
}stud;
FILE *fp;
//stud read();
void modify();
void display_one(stud*);
void create();
stud* read();
void delet();
void display_all();
int validate_rollno(stud*);
int validate_usn(stud*);
int main()
{
	fp=fopen("student.dat","a+");
	//fread(first,sizeof(stud),1,fp);
	fseek(fp,0,SEEK_SET);
	int ch,rollno,flag=0;
	stud s;
	
	//while(1)
	do
	{
	    //system("cls");
		//fflush(stdin);
		printf("\n-----MENU-----\n");
		printf("\n1.create a new record\n");
		printf("2.display all records\n");
		printf("3.display an existing record\n");
		printf("4.modify an existing record\n");
		printf("5.delete a existing record\n");
		printf("6.exit \n");
		printf("enter your choice\n");
		fflush(stdin);
		scanf("%d",&ch);
		//fflush(stdin);
		switch(ch)
		{
			case 1 : //fflush(stdin);
					 create();
					 break;
			case 2 :
					 display_all();
					 break;
			case 3 : flag=0;
			         printf("enter the roll number \n");
					 fflush(stdin);
					 scanf("%d",&rollno);
					 fp=fopen("student.dat","a+");
					 fseek(fp,0,SEEK_SET);
					 while(fread(&s,sizeof(stud),1,fp))
					 {
					 	if(rollno==s.rollno)
					 	{
					 	     printf("\tname\t\trollno\tusn\tenglish\tkannada\thindi\tmaths\tscience\tsocial\tpercentage\n");
                    	     printf("-----------------------------------------------------------------------------------------\n");
					   	     display_one(&s);
					   	     flag=1;
					 	}
					 }
					 if(flag==0)
			         printf("RECORD DOES NOT EXIST\n");
					 break;
			case 4 : 
					 modify();
					 break;
			case 5 : 
					 delet();
					 break;
			case 6 : exit(0);
			
			default : printf("invalid choice \n");
		}
	}while(ch!=6);
	fclose(fp);
    return 0;
}
void create()
{
	stud *s;
	int flag,flag2;
	fp=fopen("student.dat","a");
	fseek(fp,sizeof(stud),SEEK_END);
	s=(stud *)malloc(sizeof(stud));
	s=read();
	flag=validate_rollno(s);
	flag2=validate_usn(s);
	if(flag==0 && flag2==0)
	{
		fseek(fp,0,SEEK_END);
		fwrite(s,sizeof(stud),1,fp);
	}
	//fseek(fp,0,SEEK_END);
	//fwrite(s,sizeof(stud),1,fp);
	fclose(fp);
	//getch();
}

int validate_rollno(stud *sp)
{
	FILE *fp2;
	stud *temp;
	stud *s;
	temp=(stud *)malloc(sizeof(stud));
	s=(stud *)malloc(sizeof(stud));
	s=sp;
	fp2=fopen("student.dat","r");
	while(fread(temp,sizeof(stud),1,fp2))
	{
		if(s->rollno==temp->rollno)
		{
			printf("ROLL NUMBER MUST BE UNIQUE \n");
			fclose(fp2);
			return 1;
		}
	}
	fclose(fp2);
	return 0;
}

int validate_usn(stud *sp)
{
	int flag=0,i;
	FILE *fp2;
	stud *temp;
	stud *s;
	temp=(stud *)malloc(sizeof(stud));
	s=(stud *)malloc(sizeof(stud));
	s=sp;
	fp2=fopen("student.dat","r");
	while(fread(temp,sizeof(stud),1,fp2))
	{
		i=0;
		while(s->usn[i]!='\0')
		{
			if(s->usn[i]!=temp->usn[i])
			{
				break;
			}
			i++;
			if(s->usn[i]=='\0')
			{
				flag=1;
			}
		}
	}
	fclose(fp2);
	if(flag==0)
	{
		return 0;
	}
	else
	{
		printf("USN MUST BE UNIQUE \n");
		return 1;
	}
}

stud* read()
{
    stud* s;
    s=(stud *)malloc(sizeof(stud));
	int flag=0;
    int i=0;
    //char temp;
    printf("name : \n");
    fflush(stdin);
    //scanf("%c",&temp);
    scanf("%[^\n]s",s->name);
    //gets(s->name);
    //s->name[i]='\0';
    printf("rollno : \n");
    //fflush(stdin);
    scanf("%d",&s->rollno);
    printf("usn : \n");
    fflush(stdin);
    scanf("%s",s->usn);
    printf("enter your marks\n");
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("maths : ");
        fflush(stdin);
		scanf("%d",&s->maths);
        flag=1;
        //fflush(stdin);
    }while(s->maths>100);
    flag=0;
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("science : ");
        fflush(stdin);
		scanf("%d",&s->science);
        flag=1;
    }while(s->science>100);
    flag=0;
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("social : ");
        fflush(stdin);
        scanf("%d",&s->social);
        flag=1;
    }while(s->social>100);
    flag=0;
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("english : ");
        fflush(stdin);
        scanf("%d",&s->english);
        flag=1;
    }while(s->english>100);
    flag=0;
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("kannada : ");
        fflush(stdin);
        scanf("%d",&s->kannada);
        flag=1;
    }while(s->kannada>100);
    flag=0;
    do
    {
    	if(flag==1)
    	{
    		printf("marks should not be more than 100\n");
		}
        printf("hindi : ");
        fflush(stdin);
        scanf("%d",&s->hindi);
        flag=1;
    }while(s->hindi>100);
	s->percentage=(s->english+s->kannada+s->hindi+s->maths+s->science+s->social)/6;
	return s;
}

void display_all()
{
    int flag=0;
	fp=fopen("student.dat","a+");
	stud s;
	while(fread(&s,sizeof(stud),1,fp))
	{
	    if(flag==0)
	    {
	        printf("\tname\t\trollno\tusn\t    english   kannada   hindi\tmaths\tscience\tsocial\tpercentage\n");
	        printf("----------------------------------------------------------------------------------------------------\n");
	        flag=1;
	    }
		display_one(&s);
	}
	if(flag==0)
	{
	    printf(" NO RECORD EXIST IN THE DATABASE\n");
	}
	fclose(fp);
}

void display_one(stud *s)
{
	int i;
    //printf("\n the student details are : \n");
    int namelen=strlen(s->name);
    printf("%s",s->name);
    for(i=0;i<24-namelen;i++)
    {
        printf(" ");
    }
    printf("  %d\t",s->rollno);
    printf("%s\t",s->usn);
    printf("%d  \t",s->english);
    printf("  %d  \t",s->kannada);
    printf(" %d \t",s->hindi);
    printf(" %d \t",s->maths);
    printf(" %d \t",s->science);
    printf(" %d \t",s->social);
    printf("   %.2f\n",s->percentage);
}

void modify()
{
    int rollno,flag=0;
    stud s;
    //stud new;
	printf("enter the roll number :\n");
	scanf("%d",&rollno);
	fp=fopen("student.dat","a+");
	FILE *fp2;
	fp2=fopen("temp.dat","w+");
	while(fread(&s,sizeof(stud),1,fp))
	{
	    if(s.rollno==rollno)
	    {
	        flag=1;
	        printf("enter the updated values \n");
	       stud *temp;
	       temp=read();
	       fwrite(temp,sizeof(stud),1,fp2);
	    }
	    else
	    {
	        fwrite(&s,sizeof(stud),1,fp2);
	    }
	}
	if(flag==0)
    {
        printf("RECORD DOES NOT EXIST\n");
    }
	//rewind(fp);
	rewind(fp2);
	//fflush(fp);
	fp=fopen("student.dat","w");
	while(fread(&s,sizeof(stud),1,fp2))
	{
	    fwrite(&s,sizeof(stud),1,fp);
	}
	fclose(fp);
	fclose(fp2);
}

void delet()
{
	stud s;
	int rollno,flag=0;
	printf("enter the roll number \n");
	scanf("%d",&rollno);
	fp=fopen("student.dat","a+");
	FILE *fp2;
	fp2=fopen("temp.dat","w+");
	while(fread(&s,sizeof(stud),1,fp))
	{
	    if(s.rollno==rollno)
	    {
	        flag=1;
	    }
	    else
	    {
	       fwrite(&s,sizeof(stud),1,fp2);
	        //fwrite(&s,sizeof(stud),1,fp2);
	    }
	}
	rewind(fp2);
	fp=fopen("student.dat","w");
	while(fread(&s,sizeof(stud),1,fp2))
	{
		fwrite(&s,sizeof(stud),1,fp);
	}
	if(flag==0)
    {
        printf("RECORD DOES NOT EXIST\n");
    }
    else
    {
    	printf("RECORD DELETED SUCCESSFULLY\n");
	}
	fclose(fp);
	fclose(fp2);
}

