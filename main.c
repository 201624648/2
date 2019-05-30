#include<stdio.h>
#include"string.h"
#define MAX 50
int service;
int length;
struct information{
		char name[10];
		char number[15];
		};
struct information a[]={
	{"naTahi","010-5228-7889"},
	{"yuHionbo","010-5211-1472"},
	{"naWobin","010-1235-8765"},
	{"muGening","010-8282-8282"},
	{"soJibo","010-5165-3483"}};

void register1(){
	char a[10]="qwer1234";
	char b[10];
	
        static  int times=1;
	printf("input your password:");
	scanf("%s",b);
	do
	{
		if(strcmp(a,b)==0)
			{
				times=1;
				printf("login name:soJibo\nphoneNumber:010-5165-3483\nlogin successful\n");
				break;
			}
		else {
			
			if(times<3){
			printf("password %d times error:",times);
			scanf("%s",b);}
			times++;
			}
	}
	while(times<=3);	
	if(times==4)
	{
                printf("password 3 times error,program shutdown...\n");
    		service=5;
	}

}

void personalprint(){
	
	char ne[15];
	printf("\nyou want find name:\n");
	scanf("%s",ne);
	
	for(int i=0;i<=length;i++){
		if(strcmp(a[i].name,ne)==0){
			printf("\n%s,%s\n",a[i].name,a[i].number);
		}
	}

}

void allprint()
{
	
	printf("\n<<phonNumber list>>\n");
	for(int i=0;i<length;++i)
	{
		if(a[i].name==0) break;
		printf("%s %s\n",a[i].name,a[i].number);
	}
}

void delete()
{
	int i;
	char na_delete[10];
	printf("input you want delete name:\n");
	scanf("%s",na_delete);
	for(i=0;i<=sizeof(a)/sizeof(struct information);i++){
		if(strcmp(a[i].name,na_delete)==0)
			break;	
	}

	if(i<sizeof(a)/sizeof(struct information)){
		printf("you want delect:%s",a[i].name);
	
		for(int star=i;star<sizeof(a)/sizeof(struct information);star++)
		{
			*(a[star].name)=*(a[star+1].name);
			*(a[star].number)=*(a[star+1].number);
		} 
		printf("\n delect sucesful!\n");
		length=sizeof(a)/sizeof(struct information)-1;
	}	
	else{
		printf("the name %s is not find!\n",na_delete);
	}
}

int main(void){
	length=sizeof(a)/sizeof(struct information);
	do
	{
		printf("\n<<<1.Login 2.allprint 3.personalprint 4.delete 5.exit >>>\n");
	printf("input your want to ....");
	scanf("%d",&service);
	switch(service){
		case 1:
			register1();
			break; 
		case 2:
			allprint();
			break;
		case 3:
			personalprint();
			break;
		case 4:
			delete();
			break;
		case 5:
			printf("you will exit...");
			break;
		default:
			printf("please input 1~4\n");
			break;
		}

}while(service !=5);

return 0;

}	

		
		
		
		
		
