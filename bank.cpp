#include<stdio.h>
#include<time.h>
#include<string.h>
struct customer
{
	char n[50] ;
	int accountno,pin;
	float bal;
	long long int num;
	
	
}c1,c2,c3;
struct ti
{

int j,lt,acc;	
char  t1[26];	
}time1,time2;

int main()
{  
	int o,i,pin1,K,a,x,y,z,amount,accountno1,q,b,sh=0;
	FILE *p,*tim;
	time_t t;  
    p=fopen("customer.txt","r+");
   	tim=fopen("last transaction.txt","r+");

	char c;
		printf("\n  WELCOME TO  BANK \n");
		
	 do
	  {
		
	printf("\n 1.CREATE ACCOUNT\t 2.CHANGE PIN \n 3.CASH WITHDRAWL\t 4.LAST TRANSACTION DETALIS \n 5.BALANCE ENQUIRY\t 6.CASH DEPOSIT\n");
	scanf("%d",&o);
	
	switch(o)
	{
	    case 5:
	    	
	    	printf("\n ENTER YOUR ACCOUNT NUMBER\n");
	    	scanf("%d",&accountno1);
	    
	    	rewind(p);
	    	while(!feof(p))
	    	{
			fread(&c1,sizeof(c1),1,p);
	    	if(c1.accountno==accountno1)
		    {
			printf("\n ENTER YOUR PIN\n");
		    scanf("%d",&pin1);
		    break;
			}
			}
	    	
		    if(pin1==c1.pin)
		    {
			
		   	
	        printf("ACCOUNT BALANCE = %.2f",c1.bal);
	         printf(" \n SUCCESSFUL \n\n");
	         a=1;
	         }
	       	         
	        
	        
	    
	    else
	    {
		
	    printf("\n ENTER VALID  ACCOUNT NUMBER OR PIN \n");
	    a=1;
	    }
	
	    break;
	    
	    case 2:
	    
	    	printf("\n ENTER YOUR ACCOUNT NUMBER\n");
	    	scanf("%d",&accountno1);
	    
	    	rewind(p);
	    	while(!feof(p))
	    	{
			fread(&c3,sizeof(c1),1,p);
		
			
	    	if(c3.accountno==accountno1){
		w:	
	    printf("\n PLEASE ENTER CURRENT PIN \n");	
	    scanf("%d",&pin1);
	    q=ftell(p);	
		break;
	}}
	    if(pin1==c3.pin)
	    {
	    printf("\n PLEASE ENTER NEW PIN \n");
		scanf("%d",&c3.pin);
		  
	
		
		
		printf("\n DO YOU WANT TO CHANGE NAME or NUMBER  ENTER y/n \n");
		scanf("\n%c",&c);
		if(c=='y')
		{
		printf("\n DO YOU WANT TO CHANGE ENTER 1.NAME \t 2.NUMBER   \n");
		scanf("%d",&K);
     	}
     	else
   	goto b;
     
	
		if(K==1)
		{
		printf("\n ENTER NEW NAME\n");
		scanf("%s",c3.n);
		}
		else if(K==2)
		{
		printf("\n ENTER NEW NUMBER\n");
		scanf("%lld",&c3.num);
	}
	
		
		b:
	
	
	     
	  	fseek(p,q-sizeof(c1),SEEK_SET);
	    
		fwrite(&c3,sizeof(c3),1,p);
		

		
		
	    printf("\n  CHANGED SUCESSFULLY \n\n");
	    
		a=1;	
		}
		else
		{
		goto w;
		printf("\n  ENTER CORRECT PIN \n");
      	}
		
	    break;
	    
	    
	    
	    
	  case 3:
	  	 
	   printf("\n ENTER YOUR ACCOUNT NUMBER\n");
	    	scanf("%d",&accountno1);
	    
	    	rewind(p);
	    	while(!feof(p))
	    	{
			fread(&c3,sizeof(c1),1,p);
		
			
	    	if(c3.accountno==accountno1&&(c3.bal>=500)){
			
	    printf("\n PLEASE ENTER  PIN \n");	
	    scanf("%d",&pin1);
	    q=ftell(p);	
		break;
	}

	}
	    if(pin1==c3.pin)
	    {
	    	
	    printf(" PLEASE ENTER REQURIED AMOUNT OF MONEY IN 500  \n");
		scanf("%d",&amount);
		
		   
          
         z=c3.bal-amount;
		  if(z>=500)
		  c3.bal=z;
		  else
		  {
		  
		  printf(" \n YOU DONT HAVE SUFFICIENT MONEY TO MAKE TRANSACTION  \n");
		  
		  goto x;
        	}
		  
	  printf(" PLEASE TAKE %d 500 NOTES  \n",amount/500);
		printf("\n  TRANSACTION SUCCESSFULL \n\n");
    	    
        fseek(p,q-sizeof(c1),SEEK_SET);
	    
		fwrite(&c3,sizeof(c3),1,p);
        time(&t);
			time2.acc=c3.accountno;
		    time2.j++;
			time2.lt=amount;
			time(&t);
				struct tm* tm_info;
				tm_info = localtime(&t);
	      
	     strftime(time2.t1, 26, "%d-%m-%y %H:%M:%S", tm_info);
	fseek(tim,0,SEEK_END);
	
	 fwrite(&time2,sizeof(ti),1,tim);
	
          	
		  
			
        	
	 
	
	    
	 
	   
		
     
	  x:
	 a=1;	
		}
		else{
		
		printf("\n  ENTER VALID PIN OR ACCOUNT NUMBER\n");
		a=1;
		}
		
	    break;
	    
		case 1:
      	{
					
	//	struct customer c1={"shashi","0",10000,1234,0,0,0,8185812335};	
	
     //  fwrite(&c1,sizeof(c1),1,p);
         
  fseek(p,-sizeof(c1),SEEK_END);
  
  fread(&c2,sizeof(c2),1,p);
  fread(&c1,sizeof(c1),1,p);
  
  c1.accountno=c2.accountno+1;
  
  
  
  printf(" \nENTER NAME,  PIN ,PHONE NUMBER\n");
  scanf("\n%s\n%d",&c1.n,&c1.pin);
 
  scanf("\n%lld",&c1.num);
  
  fseek(p,0,SEEK_END);
  
  fwrite(&c1,sizeof(c1),1,p);
  
  fseek(p,-sizeof(c1),SEEK_END);
  
  fread(&c2,sizeof(c2),1,p);
  
  printf("\n NAME =%s\n ACCOUNT NUMBER=%d \n PHONE NUMBER = %lld\n\n",c2.n,c2.accountno,c2.num);
		
  printf("\n ACCOUNT CREATED SUCCESSFULLY\n");
  a=1;
	break;	
     }
         
	   case 6:
	   printf("\n ENTER YOUR ACCOUNT NUMBER\n");
	    	scanf("%d",&accountno1);
	    
	    	rewind(p);
	    	while(!feof(p))
	    	{
			fread(&c3,sizeof(c1),1,p);
		
			
	    	if(c3.accountno==accountno1){
			
	    printf("\n PLEASE ENTER  PIN \n");	
	    scanf("%d",&pin1);
	    q=ftell(p);	
		break;
	}
	
	}
	    if(pin1==c3.pin)
	    {
	    printf("\n PLEASE ENTER  AMOUNT OF MONEY DEPOSIT   \n");
		scanf("%d",&amount);
		  c3.bal=c3.bal+amount;
	 
		printf(" \n CASH CREDITED SUCCESFULLY\n\n");
		
		
	
		
		
	     
	  	fseek(p,q-sizeof(c1),SEEK_SET);
	    
		fwrite(&c3,sizeof(c3),1,p);
		
	fseek(p,-(sizeof(c1)),SEEK_CUR);
		fread(&c3,sizeof(c3),1,p);
		
		printf("\n PLEASE ENTER 1.CHECK BALANCE 2.EXIT \n");
		scanf("%d",&K);
		if(K==1)
	    printf("BALANCE=%.2f\n\n",c3.bal);
	    else
	  	a=1;
	    
		a=1;	
		}
		else
		printf("\n  ENTER VALID  ACCOUNT NUMBER OR PIN \n");
		
	    break;
	    case 4:
	   printf("\n ENTER YOUR ACCOUNT NUMBER\n");
	    	scanf("%d",&accountno1);
	   //	tim=fopen("last transaction.txt","r+");
	    	rewind(p);
	    	while(!feof(p))
	    	{
	    		
	    	
			fread(&c2,sizeof(c1),1,p);
		    	
			
	    	if(c2.accountno==accountno1){
	    	rewind(tim);
	    	while(!feof(tim))
	    	{
		   
		     fread(&time1,sizeof(time1),1,tim);
	    		if(time1.acc==accountno1)
			{
			
	    printf(" \n NAME = %s \n ACCOUNT NUMBER = %d  \n  TRANSACTION MONEY = %d \n  TIME = %s \n\n",c2.n,c2.accountno,time1.lt,time1.t1);	
	    a=1;
		
	}	}}
	
	}
	    
	    break;
	    default :
	    	printf("\nENTER CORRECT OPTION\n");
	    	a=1;
	    	break;
    }
	
	
}while(a==1);
	
}
