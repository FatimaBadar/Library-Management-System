#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size_username 30
#define size_password 20

#define size_bookID 10
#define size_bookName 50
#define size_authorName 50
#define size_studentName 50

#define size_FileH sizeof(FileH)
#define size_student sizeof(student)

struct DATE
{
    int yyyy;
    int mm;
    int dd;
}Date;

struct STUDENT
{
	char student_name[size_studentName];
	char student_user[size_username];
	char student_pass[size_password];	
} student;

struct FileHeader
{
    char admin_user[size_username];
    char admin_pass[size_password];
} FileH;


struct BooksInfo 
{
    unsigned int books_id; 
    char bookName[size_bookName];
	char authorName[size_authorName];
    char studentName[size_studentName];
    struct DATE  bookIssueDate;
} BkInfo;

int main()
{
	int registration, login, student, identity;
	system("color 80");
	
	message();
do
{   	
	printf("\n\t\t\t\t\tAre you the librarian or a student?");
	printf("\n\t\t\t\t\tEnter 1 for login as a librarian, \n\t\t\t\t\t2 to register a student, \n\t\t\t\t\t3 to login as a student and \n\t\t\t\t\t4 to go to menu: ");
	scanf("%d",&identity);

	switch(identity){
		case 1:
			FileExists();
			librarian(login);
			break;
			
		case 2:
			admin(registration);
			break;
			
		case 3:
			studentu(login);
			break;
			
		case 4:
			choice();
			break;
	}
}
while(identity!=0);

}

int choice()
{
	
	int options;
	do
    {
    	system("cls");
        printf("\n\t\t\t\t\t\t\tHOME PAGE\n");
        printf("\n\t\t\t\t\t\t1. ADD BOOKS");
        printf("\n\t\t\t\t\t\t2. SEARCH BOOKS");
        printf("\n\t\t\t\t\t\t3. VIEW BOOKS");
        printf("\n\t\t\t\t\t\t4. DELETE BOOKS");
        printf("\n\t\t\t\t\t\t5. MODIFY BOOKS");
        printf("\n\t\t\t\t\t\t6. EXIT");
        printf("\n\n\t\t\t\t\t\tEnter choice: ");
        scanf("%d",&options);
        switch(options)
        {
        case 1:
            Add_books();
            break;
            
        case 2:
            searchBooks();
            break;
            
        case 3:
            viewBooks();
            break;
            
        case 4:
            deleteBooks();
            break;
            
        case 5:
            modify();
            break;
            
        case 6:
            printf("\n\t\t\t\t\t\t\t\tTHE END\n");
            getch();
            break;
            
        default:
            printf("\n\t\t\tINVALID INPUT");
        }           
    }
    while(options!=0);
}

int dateValidity(struct DATE *Date)
{
	int date, t_days_per_year, execution, leap;
 	    
 	   if(Date->mm >=1 && Date->mm <=12)
		{
	         if((Date->dd >=1 && Date->dd <=31) && (Date->mm ==1 || Date->mm ==3 || Date->mm ==5 || Date->mm ==7 || Date->mm ==8 || Date->mm ==10 || Date->mm ==12))
 	   	      printf("\nThe date is valid");
 	   	
 	         else if((Date->dd >=1 && Date->dd <=30) && (Date->mm ==4 || Date->mm ==6 || Date->mm ==9 || Date->mm ==11))
 	   	   	   printf("\nThe date is valid");
 	   	   	   
 	   	   	else if((Date->dd >=1 && Date->dd <=28) && (Date->mm ==2))
 	   	   		printf("\nThe date is valid");	
 	         
			else if((Date->dd >=1 && Date->dd <=29) && (Date->mm ==2))
 	  	 	
 	  	 	   { if((Date->dd ==29) && (Date->mm ==2) && (Date->yyyy %4==0))
 	  	 		printf("\nThe date is valid");
 	 
                else
 	  	 		printf("\nThe date is not valid");
				}
	             	   	   
 	         else 
 	  	     printf("\nThe date is not valid"); 	  
	    }
	    
	    if(Date->yyyy %4==0)
 	    printf("\nIt is a leap year");
 	    
		else
 	    {printf("\nIt is not a leap year");}
	    
}

int FileExists()
{
	char admin_user[]="lib.admin@nu.edu.pk";
	char admin_pass[]= "lib.admin123";
	
    FILE *fp1;
    
     fp1 = fopen ("Admin.txt", "w");
	  if(fp1 == NULL)
	  {
	  	printf("\n\t\t\tUnable to open");
	  	exit(0);
	  }
	  
	  else{

        strcpy(FileH.admin_user, admin_user);
        strcpy(FileH.admin_pass, admin_pass);
          
        fprintf(fp1, "Admin username: %s\nAdmin password: %s", FileH.admin_user, FileH.admin_pass);
		      
    //    fwrite(&FileH, size_FileH, 1, fp1);   
		}
		
		fclose(fp1);
}
   
int librarian(int login)
{
	m("LOGIN");

	char username[50], password[50];
	
	FILE *fp1;
    
    fp1 = fopen ("Admin.txt", "r");
     if(fp1 == NULL)
     {
     	printf("\n\t\t\tUnable to open");
     	exit(0);
     }
       
do{
    
	printf("\n\t\t\tEnter your valid username: ");
	scanf(" %s",&username);
  }
  while(strcmp(username, FileH.admin_user)!=0);

do{
	printf("\n\t\t\tEnter the correct password: ");
//	scanf(" %s", &password);
	//PASSWORD:
	int i;
	char a;
	 for ( i = 0 ; i<100 ; i++ )
    {

        fflush(stdin);
        a = getch();
        password[i] = a;
        if ( password[i] == '\b')
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        if ( password[i] == ' ' || password[i] == '\r' )
            printf(" ");
        else
            printf("*");
        if ( password[i]=='\r')
            break;
    }
    password[i]='\0';
	
}
 while(strcmp(password, FileH.admin_pass)!=0);

	printf("\n\n\t\t\t\t\tYou have successfully logged in");
	printf("\n\n\t\t\t\t\t\tPress any key to continue");
	
	getch();
	system("cls");
	fclose(fp1);
}

int admin(registration)
	{
		m("REGISTRATION");
	//printf("\n\t\t\t\t\t\t\tREGISTRATION\n");
	
	char username[size_username];
	char password[size_password];
	char name[size_studentName];
	
	printf("\n\t\t\tEnter name: ");
	scanf("%s", &student.student_name);
	
	printf("\n\t\t\tEnter username: ");
	scanf("%s", &student.student_user);
	
	printf("\n\t\t\tEnter password: ");
	scanf("%s", &student.student_pass);
	
	FILE *fp2;
    
     fp2 = fopen ("Student.txt", "w");
	  if(fp2 == NULL)
	  {
	  	printf("\n\t\t\tUnable to open");
	  }
	  else{
	  	
  //      strcpy(student.student_name, name);
    //    strcpy(student.student_user, username);
      //  strcpy(student.student_pass, password);
              
        //fprintf(fp2, "Student name: %s\nStudent username: %s\nStudent password: %s", student.student_name, student.student_user, student.student_pass);      
    fwrite(&student, size_student, 1, fp2);   
		}
	
	printf("\n\t\t\t\t\t\tPress any key to continue");
	getch();
	
	system("cls");
	fclose(fp2);
}

int studentu(int login)
{
	m("STUDENT LOGIN");
	
	char student_username[50];
	char student_password[50];

		FILE *fp2;
    
    fp2 = fopen ("Student.txt", "r");
     if(fp2 == NULL)
     {
     	printf("\n\t\t\tUnable to open");
     	exit(0);
     }
   

    fread(&student, sizeof(student), 1, fp2); 
	//USERNAME: 

do{
		
    printf("\n\t\t\tEnter your valid username: ");
  //  fflush(stdin);
//    gets(student_user);
	scanf("%s",&student_username);
    }
  while(strcmp(student_username, student.student_user)!=0);
 
	//PASSWORD:
do{	
	printf("\n\t\t\tEnter the correct password: ");

	int i;
	char a;

	 for ( i = 0 ; i<100 ; i++ )
    {
        fflush(stdin);
        a = getch();
        student_password[i] = a;
        if ( student_password[i] == '\b')
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        if ( student_password[i] == ' ' || student_password[i] == '\r' )
            printf(" ");
        else
            printf("*");
        if ( student_password[i]=='\r')
            break;
    }
    student_password[i]='\0';

//	fflush(stdin);
//	gets(student_pass);
    }
while(strcmp(student_password, student.student_pass)!=0);

	printf("\n\n\t\t\tYou have successfully logged in");
	printf("\n\t\t\t\t\t\tPress any key to continue");
	
	getch();
	system("cls");
	fclose(fp2);
}
	
int Add_books(){
	
	m("ADD BOOKS");
		
	int bookID;
	char authorName[20], bookName[20], student_user[30];
	
	FILE *fp;
    
    fp = fopen ("LMS.txt", "a+");
     if(fp == NULL)
     {
     	printf("\n\t\t\tUnable to open");
     	exit(0);
     }    

	printf("\n\t\t\t\t\tStudent Name: ");
	fflush(stdin);
	fgets(BkInfo.studentName,size_studentName,stdin);
	//scanf("%s",&BkInfo.studentName);
	
	printf("\n\t\t\t\t\tBook ID: ");
	fflush(stdin);
	//fgets(BkInfo.books_id,size_bookID,stdin);
    scanf("%u",&BkInfo.books_id);

	
	printf("\n\t\t\t\t\tBook name: ");
	fflush(stdin);
	fgets(BkInfo.studentName,size_studentName,stdin);
//	scanf("%s",&BkInfo.bookName);

	
	printf("\n\t\t\t\t\tAuthor name: ");
		fflush(stdin);
	fgets(BkInfo.authorName,size_authorName,stdin);
//	scanf("%s",&BkInfo.authorName);

		
    printf("\n\t\t\t\t\tEnter date in format (day/month/year): ");
    scanf("%d/%d/%d",&BkInfo.bookIssueDate.dd, &BkInfo.bookIssueDate.mm, &BkInfo.bookIssueDate.yyyy);
//	fprintf(fp,"\nDate: %d/%d/%d", BkInfo.bookIssueDate.dd, BkInfo.bookIssueDate.mm, BkInfo.bookIssueDate.yyyy);

    fwrite(&BkInfo, sizeof(BkInfo), 1, fp);
    
    fclose(fp);
  //  printf("\n\t\t\t\t\t\tPress any key to continue");
	getch();
}

int searchBooks()
{
	m("SEARCH BOOKS");
		
	int bookID, found;
	char authorName[20], bookName[20];
	
	FILE *fp;
    
    fp = fopen ("LMS.txt", "r");
    
	if(fp == NULL)
    {
     	printf("\n\t\t\t\t\tUnable to open");
     	exit(0);
    }

    if (fseek(fp,size_FileH,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\t\t\tFacing issue while reading file\n");
    }
//  char c;  
    printf("\n\t\t\t\t\tEnter Book Name to search:");
	scanf("%s",&bookName);
//    while(c!=EOF){
//    c=fgetc(fp);
//    }
	//fgets(BkInfo.bookName, size_bookName, stdin);
	
    while(fread (&BkInfo, sizeof(BkInfo), 1, fp))
    {
        if(!strcmp(BkInfo.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    
	if(!found)
    {
        printf("\n\t\t\t\t\tBook id: %u", BkInfo.books_id);
        printf("\n\t\t\t\t\tBook name: %s", BkInfo.bookName);
        printf("\n\t\t\t\t\tAuthor name: %s", BkInfo.authorName);
        printf("\n\t\t\t\t\tIssue date: %d/%d/%d", BkInfo.bookIssueDate.dd, BkInfo.bookIssueDate.mm, BkInfo.bookIssueDate.yyyy);
    }
    
	else
    {
        printf("\n\t\t\t\t\tNo Record");
    }
     fclose(fp);
     //printf("\n\t\t\t\t\t\tPress any key to continue");
     
     getch();
 }
 
int viewBooks()
{
	int found=0, countBook=1;
    char bookName[size_bookName];
    
    m("VIEW BOOKS");
    
    FILE *fp;
    
    fp = fopen ("LMS.txt", "r");

do{
	printf("\n\t\t\t\t\tEnter book name: ");
	scanf("%s", &BkInfo.bookName);
	
    if (fseek(fp, size_bookName, SEEK_SET) != 0) //seek_Set=end position or 0
    {
    	printf("\n\t\t\t\t\tUnable to open");
    	fclose(fp);
    }

    else
	{
    fread (&BkInfo, sizeof(BkInfo), 1, fp);

        printf("\n\t\t\t\t\tBook Count = %u",countBook);
        printf("\n\t\t\t\t\tBook id = %d",BkInfo.books_id);
        printf("\n\t\t\t\t\tBook name = %s",BkInfo.bookName);
        printf("\n\t\t\t\t\tBook authorName = %s",BkInfo.authorName);
        printf("\n\t\t\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",BkInfo.bookIssueDate.dd, BkInfo.bookIssueDate.mm, BkInfo.bookIssueDate.yyyy);
        found = 1;
        countBook++;
    }
}
while(!found);
    fclose(fp);
    //printf("\n\t\t\t\t\t\tPress any key to continue");
	getch();
}

int deleteBooks()
{
	m("DELETE BOOKS");
	
	int found;
	char bookName[20], bookDelete[20];
	
	FILE *fp;
	
    fp = fopen ("LMS.txt", "a+");

     if(fp == NULL)
     {
     	printf("\n\t\t\t\t\tUnable to open");
     	exit(0);
     }

    FILE *del;
	del = fopen("del.txt","w");

    if(del == NULL)
    {
        fclose(fp);
        printf("\n\t\t\t\t\tUnable to open");
    }

    fread (&FileH,size_FileH, 1, fp);
    fwrite(&FileH,size_FileH, 1, del);
    
	printf("\n\t\t\t\t\tEnter book name for delete : ");
	scanf("%s",bookDelete);

    while(fread (&BkInfo, sizeof(BkInfo), 1, fp))
    {
    	if(BkInfo.bookName != bookDelete)
        {
        fwrite(&BkInfo,sizeof(BkInfo), 1, del);
        }
        else
            found = 1;
}
    if(!found){
	printf("\n\t\t\t\t\tRecord deleted successfully");
 }
	else
	{
	printf("\n\t\t\t\t\tRecord not found");
 } 
 
    fclose(fp);
    fclose(del);
    remove("LMS.txt");
    rename("del.txt","LMS.txt");
    
	//printf("\n\t\t\t\t\t\tPress any key to continue");
	getch();
}

int modify()
{
	FILE *fp;
	
	m("MODIFY");
	
	fp = fopen("LMS.txt","a+");
    if(fp == NULL)
    {
        printf("\n\t\t\t\t\tUnable to open");
        exit(0);
    }

    fread (&FileH,size_FileH, 1, fp);

   	printf("\n\t\t\t\t\tBook ID: ");
	scanf("%u",& BkInfo.books_id);
//	fprintf(fp,"\nBook ID: %d", BkInfo.books_id);
		
	printf("\n\t\t\t\t\tBook name: ");
	fflush(stdin);
	fgets(BkInfo.bookName,size_bookName,stdin);
//	scanf("%s",& BkInfo.bookName);
		
	printf("\n\t\t\t\t\tAuthor name: ");
	fflush(stdin);
	fgets(BkInfo.authorName,size_authorName,stdin);
//	scanf("%s",& BkInfo.authorName);
	
    printf("\n\t\t\t\t\tEnter date in format (day/month/year): ");
    scanf("%d/%d/%d",&BkInfo.bookIssueDate.dd, &BkInfo.bookIssueDate.mm, &BkInfo.bookIssueDate.yyyy);
//	fprintf(fp,"\nDate: %d/%d/%d", BkInfo.bookIssueDate.dd, BkInfo.bookIssueDate.mm, BkInfo.bookIssueDate.yyyy);
	
    fwrite(&FileH,size_FileH, 1, fp);
    fclose(fp);
    
    //printf("\n\t\t\t\t\t\tPress any key to continue");
	getch();    
}

int message()
{
	int i, j;
	for(i=1;i<=3;i++)
	{
		for(j=1; j<=120; j++)
		{
		    if(i==2 && j==2)
		    {
		        printf("\t\t\t\t\t\t LIBRARY MANAGEMENT SYSTEM  ");
		        continue;
		    }
		    
			else if(i==2 && j>=2 || i == 2 && j<=2)
		    printf(" ");
		    
			else
		    printf("*");
	
		}
		printf("\n");
	}
}
int m(const char* n)
{
	int i, j;
	for(i=1;i<=3;i++)
	{
		for(j=1; j<=100; j++)
		{
		    if((j>=45 && i==1 && j<=80) || (i == 3 && j>=45 && j<=80))
		    printf("*");
			
			else if(i==2 && j==30)
			printf("\t\t\t\t  %s \t\t\t\t  ",n);
	
			else
			printf(" ");
	
		}
		printf("\n");
	}
}
