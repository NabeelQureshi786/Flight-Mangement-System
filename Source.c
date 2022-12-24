//there will be 3 flights and 9 files each file containing data of one class of each flight
//ie: flight#1_buisnessclass.txt
//there will be 30 buisness,40 economy and 15 Vip seats in each flight
//once the given number of seats are booked in given class more seats cant be booked
#include<stdio.h>
#include<conio.h>//to clear screen after every choice
#include<strings.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct Customer_details
{
	char CNIC[40];
	char name[30];
	char phone_number[30];
	int age; //input validation age cant be negative or less than 18
}Customer; 
typedef struct Flight
{
	int flight_no;
	int totalseats;
	char destination[30];
	char flightday[30];
	char where_from[30];//city from which flight will take off
	char flight_time[15]; //8:00am or pm
	char flight_date[20];  //dd-mm-yy
}Flight;
typedef struct userDetails{
	int seatno;
	int flight_no;
	char class_Name[30];
	char cnic[30];
	char name[30];
	char destination[30];
	char where_from[30];//city from which flight will take off
	char flight_time[15]; //8:00am or pm
	char flight_date[20]; 
	char flight_day[30];
	
	
}user;
//this function will ask for customer details in a sutructure 
//and write this data into a file named Customer_data.txt
void Customer_details(struct Customer_details a)
{
	int k=0;
	char ch;
	FILE *fp;
	fp=fopen("CustomerInfo.txt","a");
	printf("Enter Your Name\n");
	scanf("%c",&ch);
	scanf("%[^\n]s",&a.name);
	do
	{
		//clrscr();
	printf("Enter your Cnic\n");
		scanf("%c",&ch);
	scanf("%[^\n]s",&a.CNIC);
	k=cnic_validate(a.CNIC);
	if(k!=-1)
	{
	printf("Invalid this Cnic no already exist.Try again\n");
    }
	
}while(k!=-1);
	printf("Enter your phone no\n");
		scanf("%c",&ch);
	scanf("%[^\n]s",&a.phone_number);
	printf("Enter your Age\n");
	scanf("%d",&a.age);
	fwrite(&a,sizeof(Customer),1,fp);
	printf("Your data has been recorded\n");
	fclose(fp);
}
void Fare_details()
{
	printf("Flight Class            flight Destination            Fare\n");
	printf("Business                 Lahore to karachi              4500$\n");
	printf("Business                 Lahore ti Dubai               4000$\n");
	printf("Business                 karachi to CANDA              5500$\n");
	printf("---------------------------------------------------------------\n");
	printf("Flight Class            flight Destination            Fare\n");
	printf("Economy                 Lahore to karachi              2500$\n");
	printf("Economy                 Lahore ti Dubai               3000$\n");
	printf("Economy                 karachi to CANDA              4500$\n");
	printf("---------------------------------------------------------------\n");
	printf("Flight Class            flight Destination            Fare\n");
	printf("Regular                 Lahore to karachi              3000$\n");
	printf("Regular                 Lahore ti Dubai               3600$\n");
	printf("Regular                 karachi to CANDA              4800$\n");
	printf("---------------------------------------------------------------\n");
}
//this function will read details of different flights into flight details from file flight.txt hardcoded by admin
void flight_details()
{
	FILE*fp;
	int seat;
	Flight a;
	printf("WHICH CLASS YOU WANNT TO CHECK\n");
	printf("1-BUISNESS cLASS\n");
	printf("2-Economy class\n");
	printf("3-Regular class\n");
	scanf("%d",&seat);
	switch(seat)
	{
		case 1:
		
		 	printf("Avaible flights are:\n");
			fp=fopen("Buiness1.txt","r");
			while(fread(&a,sizeof(Flight),1,fp))
			{
				
		        printf("Flight number is : %d\n:",a.flight_no);
		        printf("Flight Date is :  %s\n:",a.flight_date);
		        printf("Flight Day is :   %s\n:",a.flightday);
		        printf("Flight time is :  %s\n:",a.flight_time);
		        printf("Flight where from : %s\n:",a.where_from);
		        printf("Flight Destination is :  %s\n",a.destination);
		        printf("Total seats avaible are : %d\n",a.totalseats);
		        printf("-------------------------------------\n");
			}
			break;
			case 2:
			printf("Avaible flights are:\n");
			fp=fopen("Economy.txt","r");
			while(fread(&a,sizeof(Flight),1,fp))
			{
				
		        printf("Flight number is :  %d\n",a.flight_no);
		        printf("Flight Date is   :   %s\n",a.flight_date);
		        printf("Flight Day is    :    %s\n",a.flightday);
		        printf("Flight time is   :     %s\n",a.flight_time);
		        printf("Flight where from  :  %s\n",a.where_from);
		        printf("Flight Destination is :  %s\n",a.destination);
		        printf("Total seats avaible are :  %d\n",a.totalseats);
		        printf("-------------------------------------\n");
			}
				break;
				case 3:
				printf("Avaible flights are:\n");
			fp=fopen("Regular.txt","r");
			while(fread(&a,sizeof(Flight),1,fp))
			{
				
		        printf("Flight nomber is : %d\n:",a.flight_no);
		        printf("Flight Date is : %s\n",a.flight_date);
		        printf("Flight Day is : %s\n",a.flightday);
		        printf("Flight time is : %s\n",a.flight_time);
		        printf("Flight where from : %s\n",a.where_from);
		        printf("Flight Destination is : %s\n",a.destination);
		        printf("Total seats avaible are : %d\n",a.totalseats);
		        printf("-------------------------------------\n");
			}
					break;
	}
}
int cnic_validate(char cnic[])
{
	FILE *fp;
	Customer s1;
	fp=fopen("CustomerInfo.txt","r");
	if(fp==NULL)
	{
		printf("File NOt open\n");
	}
	while(fread(&s1,sizeof(Customer),1,fp))
	{
		if(strcmp(s1.CNIC,cnic)==0)
		{
			
			fclose(fp);
			return 1;
			break;
		}
	}
	fclose(fp);
	return -1;
}
//this function will ask user seat number ,class and cnic,and flight number and search for if(t in that class file of that flight if this is present than cancel the seat
//otherwise display relevant



void cancel_a_ticket()
{
	FILE *fp,*fp2;
	char cnic[30];
	int flightno;
	char filename[30];
	int flag=0;
	char ch;
	user a;
	fp2=fopen("temp.txt","w");
	printf("Enter your Cnic\n");
	scanf("%c",&ch);
	scanf("%[^\n]s",cnic);
	printf("Enter your flight no\n");
	scanf("%d",&flightno);
	fp=fopen("userFlightDetails4.txt","r");
	while(fread(&a,sizeof(user),1,fp))
	{
		
		if((strcmp(a.cnic,cnic)==0) && a.flight_no==flightno)
		{
			strcpy(filename,a.class_Name);
			flag=1;
		}
		else
		{
			fwrite(&a,sizeof(user),1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	
	


	if(flag==1)
	{
		fp=fopen("userFlightDetails4.txt","w");
		fp2=fopen("temp.txt","r");
		while(fread(&a,sizeof(user),1,fp2))
		{
			fwrite(&a,sizeof(user),1,fp);
			
		}
	}
	else
	{
		printf("No record found\n");
	}
	fclose(fp);
	fclose(fp2);
	//increment a ticket
	
				FILE *temp;
				FILE *temp2;
			Flight b;
			temp=fopen("temp.txt","w");
			if((strcmp(filename,"Buiness")==0))
		{
			   temp2=fopen("Buiness1.txt","r");
			   
		}
		else if((strcmp(filename,"Economy")==0))
		{
			temp2=fopen("Economy.txt","r");
			
		}
		else if((strcmp(filename,"Regular")==0))
		{
			temp2=fopen("Regular.txt","r");

		}
			 flag=0;
			 
    	while(fread(&b,sizeof(Flight),1,temp2))
     	{
			
		if(b.flight_no==flightno)
		{
//		
		
			flag=1;
			b.totalseats+=1;
			fwrite(&b,sizeof(Flight),1,temp);
		}
		else
		{
			fwrite(&b,sizeof(Flight),1,temp);
		}
	}
	fclose(temp2);
	fclose(temp);
	
	//hardcore flight details


	if(flag==1)
	{
			if(strcmp(filename,"Buiness")==0)
			{
			   temp2=fopen("Buiness1.txt","w");
			   
		}
		else if(strcmp(filename,"Economy")==0)
		{
			temp2=fopen("Economy.txt","w");
		}
		else if(strcmp(filename,"Regular")==0)
		{
			temp2=fopen("Regular.txt","w");
		}
		temp=fopen("temp.txt","r");
		while(fread(&b,sizeof(Flight),1,temp))
		{
			fwrite(&b,sizeof(Flight),1,temp2);
			
		}
		printf("Record is delete sucessfully\n");
			fclose(temp2);
	fclose(temp);
	}
		
	fclose(fp);
	fclose(temp);
	
	
}

//{
//first this function will ask for user cnic than search for that cnic in customer.txt and if it is not present ask the user to first register than book a ticket
//than if cnic is present ask user for class and flight number if seat in that class is available book it and if it is not present display apropriate message

//}




void display_menu() 
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    printf("%50s", "1-Register yourself\n");
    printf("%50s", "2-View fare details\n");
    printf("%66s", "3-View details of different flights\n");
    printf("%46s", "4-Book a ticket\n");
    printf("%48s", "5-Cancle a ticket\n");
    printf("%57s", "6-View your ticket details\n");
    printf("%47s", "7-Quit\n");

    SetConsoleTextAttribute(h, 7);


}


void search()
{
	user a;
	FILE *fp;
	char ch;
	int flag=0;
	fp=fopen("userFlightDetails4.txt","r");
	if(fp==NULL)
	{
		printf("File not open\n");
	}
	
	char cnic[30];
	int flight,seatno;
	printf("Enter your Cnic\n");
	scanf("%c",&ch);
	scanf("%[^\n]s",cnic);
	printf("Enter your flight no\n");
	scanf("%d",&flight);
	while(fread(&a,sizeof(user),1,fp))
	{
	
		
		if(strcmp(cnic,a.cnic)==0)
		{
//			printf("a.flightno and flight no %d %d\n",a.flight_no,flight);
			if(a.flight_no==flight)
			{
				printf("Name :%s\n",a.name);
				printf("Flight class is : %s\n",a.class_Name);
				printf("Your flight no is %d\n",a.flight_no);
				printf("Your flight Date id %s\n",a.flight_date);
				printf("Flight arived from %s\n",a.where_from);
				printf("Flight destination is %s\n",a.destination);
				printf("Flight seatis %d\n",a.seatno);
				flag=1;
				break;
			}
		}
	}
	if(flag!=1)
	{
		printf("Record Not Found\n");
	}
}
void show_ticket_details(){
	search();
}




///////////////////////////////////////////////
//reverse ticket sub program
void ticketreservation_sub(char filename[],char cnic[])
{
	FILE *fp;
	   Flight a;
       user s1;
       int flightno;
       int seatno;
       char ch;
		printf("Avaible flights are:\n");
			fp=fopen(filename,"r");
			
			while(fread(&a,sizeof(Flight),1,fp))
			{
				
		        printf("Flight nomber is %d\n:",a.flight_no);
		        printf("Flight Date is %s\n:",a.flight_date);
		        printf("Flight Day is %s\n:",a.flightday);
		        printf("Flight time is %s\n:",a.flight_time);
		        printf("Flight where from %s\n :",a.where_from);
		        printf("Flight Destination is %s",a.destination);
		        printf("Total seats avaible are %d\n:",a.totalseats);
		        printf("-------------------------------------\n");
			}
			printf("Enter flight number you want to book\n");
			scanf("%d",&flightno);
			printf("Entre your Name \n");
			scanf("%c",&ch);
			scanf("%[^\n]s",s1.name);
			
			fclose(fp);
				FILE *fp2;
			fp2=fopen("userFlightDetails4.txt","r");
			while(fread(&s1,sizeof(user),1,fp2))
			{
				if(s1.flight_no==flightno)
			        ++seatno;
			}
			++seatno;
			
			s1.seatno=seatno;
			fclose(fp2);
			if(seatno!=0)
			{
			
			printf("Your seat no is A_L-0%d\n",seatno);
		}
		else
		{
			printf("Seats are full\n");
		}
			
			//searching for select flight no;
			fp2=fopen("userFlightDetails4.txt","a");
			if(fp2==NULL)
			{
				printf("file not open\n");
			}
			fp=fopen(filename,"r");
			
			
			while(fread(&a,sizeof(Flight),1,fp))
			{
				
				if(flightno==a.flight_no)
				{
					
					s1.flight_no=a.flight_no;
					strcpy(s1.cnic,cnic);
					strcpy(s1.class_Name,"Buiness");
					strcpy(s1.flight_date,a.flight_date);
					strcpy(s1.flight_day,a.flightday);
					strcpy(s1.where_from,a.where_from);
					strcpy(s1.destination,a.destination);
					strcpy(s1.flight_time,a.flight_time);
					a.totalseats-=1;
					fwrite(&s1,sizeof(user),1,fp2);
					printf("Your ticket has been reserved sucessfully\n");
					fclose(fp);
			        fclose(fp2);
					break;
				}
				
			}
				fclose(fp);
			    fclose(fp2);
			//updating records
			FILE *temp;
			temp=fopen("temp.txt","w");
			fp=fopen(filename,"r");
			int flag=0;
	while(fread(&a,sizeof(Flight),1,fp))
	{
		if(a.flight_no==flightno)
		{
			flag=1;
			a.totalseats-=1;
			fwrite(&a,sizeof(Flight),1,temp);
		}
		else
		{
			fwrite(&a,sizeof(Flight),1,temp);
		}
	}
	fclose(fp);
	fclose(temp);
	
	//hardcore flight details


	if(flag==1)
	{
		fp=fopen(filename,"w");
		temp=fopen("temp.txt","r");
		while(fread(&a,sizeof(Flight),1,temp))
		{
			fwrite(&a,sizeof(Flight),1,fp);
		}
	fclose(fp);
	fclose(temp);
	}
		

					

}




void book_a_ticket()
{

//this function ask for user class ,cnic and flight number and show tickets details to h
Customer s;
FILE *fp;
char ch;
int flag=0,seat;
fp=fopen("CustomerInfo.txt","r");
char cnic[20],name[30];
printf("ENTER YOUR CNIC NO\n");
scanf("%c",&ch);
scanf("%[^\n]s",cnic);
while(fread(&s,sizeof(Customer),1,fp))
{
//	printf("a.cnic  %d an dcnic %d",s.CNIC,cnic);
	if(strcmp(cnic,s.CNIC)==0)
	{
		flag=1;
		break;
	}
}
if(flag!=1)
{
	printf("Your are not register yet\n");
	
}
else
{
	printf("WHICH CLASS Y0U WANT TO BOOK\n");
	printf("1-BUISNESS cLASS\n");
	printf("2-Economy class\n");
	printf("3-Regular class\n");
	scanf("%d",&seat);
	switch(seat)
	{
		case 1:
		
			ticketreservation_sub("Buiness1.txt",cnic);
			//storing user flight details
				fclose(fp);
			break;
		
			case 2:
				ticketreservation_sub("Economy.txt",cnic);
					fclose(fp);
				break;
				
				case 3:
					ticketreservation_sub("Regular.txt",cnic);
						fclose(fp);
					break;
					
	}
	
	
}
	fclose(fp);
}
















int main() 
{
	FILE *fp=fopen("CustomerInfo.txt","r");
	struct Customer_details a;
	struct Flight b;
	  HANDLE h;
	    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 1);
	 printf("%68s", "Welcome to flight management system \n\n");
	int choice;
//	while(fread(&a,sizeof(Customer),1,fp))
//	{
//	      printf("Nma e: %s\n",a.name);
//		  printf("Cinc %s\n",a.CNIC);
//		  printf("PHON NO %s\n",a.phone_number);
//		  printf("Age : %d\n",a.age);	
//	}
//	fclose(fp);
//		Flight s1;
//	FILE *fp2 ,*fp3,*fp4;
//		fp2=fopen("Buiness1.txt","a");
//		fp3=fopen("Economy.txt","a");
//		fp4=fopen("Regular.txt","a");
//		if(fp3==NULL || fp4==NULL)
//		{
//			printf("fILE NOT OPEN\n");
//		}
//         printf("This is runiing\n");
//		s1.flight_no=1851;
//		strcpy(s1.destination,"London");
//		strcpy(s1.flightday,"Wednesday");
//		strcpy(s1.where_from,"Lahore");
//		strcpy(s1.flight_date,"14-January-2023");
//		s1.totalseats=20;
//		strcpy(s1.flight_time,"11:00 AM");
//		fwrite(&s1,sizeof(Flight),1,fp2);
//	     fwrite(&s1,sizeof(Flight),1,fp3);
//	     fwrite(&s1,sizeof(Flight),1,fp4);
//	fclose(fp2);
//	fclose(fp3);
//	fclose(fp4);
//
//
//  fclose(fp2);


	do 
	{
	
		display_menu();
		printf("Enter your choice ");
		scanf("%d", &choice);
		while (choice < 1 || choice>7) 
		{
			printf("Enter valid choice (1-7)");
			scanf("%d", &choice);
		}
			switch (choice) 
			{
				
			 case 1:
			 		system("cls");
				 Customer_details(a);
				 break;
			 case 2:
			 		system("cls");
				 Fare_details();
				 break;
			 case 3:
			 		system("cls");
				 flight_details( );
				 break;
			 case 4:
			 		system("cls");
				 book_a_ticket();
				 break;
			 case 5:
			 		system("cls");
				 cancel_a_ticket();
				 break;
			 case 6:
			 		system("cls");
				 show_ticket_details();
				 break;
			}
//			system("pause");
			
		}
	 while (choice != 7);
}
