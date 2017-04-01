//for all the queries roll no is 15ucs001-15ucs007 and password is also roll no

#include<stdio.h>
#include<curses.h>
#include<string.h>

struct student{
                char std_id[20];
		char password[20];
                char firstname[20];
                char lastname[20];
                char gender[10];
		int sem;
		int year;
		};
typedef struct student student;


struct course{
		char std_id[20];
		char course_name[20];
		char grade[3];
		int credits;
		int sem;  // in which semester they did
		};
typedef struct course course;

/* To create new student account
 it will store details of students in file stud.dat*/

void new_account()
{
	student stud;
	FILE* fp2;
	fp2=fopen("stud.dat","a");
	if(fp2==NULL)
		printf("can't open file\n");
	else
	{


			printf("ENTER ROLL NO:");
			scanf("%s",stud.std_id);
			printf("ENTER PASSWORD:");
			scanf("%s",stud.password);
			printf("ENTER FIRSTNAME:");
                        scanf("%s",stud.firstname);
			printf("ENTER LASTNAME:");
                        scanf("%s",stud.lastname);
			printf("ENTER GENDER:");
                        scanf("%s",stud.gender);
			stud.sem=1;  //when we create new account student enter in first semester and first year I will change it later in update account query
			stud.year=1;
		
			fwrite(&stud,sizeof(stud),1,fp2);


		fclose(fp2);
	}
		
}

/* student have to enter their username and password to see their details. they can see only their details*/

void student_details()
{
	char rollno[20];
	char password[20];
	printf("ENTER ROLL NO:");
	scanf("%s",rollno);
	printf("ENTER PASSWORD:");
	scanf("%s",password);
	student stud;
	int flag=0;

	FILE* fp2;
	fp2=fopen("stud.dat","r");
        if(fp2==NULL)
                printf("can't open file\n");
        else
        {

		while(fread(&stud,sizeof(stud),1,fp2))
		{

			if(strcmp(rollno,stud.std_id)==0 && strcmp(password,stud.password)==0)
			{
				flag=1;
				 system("clear");
		                 printf("\t\t----------------------------------------STUDENT INFORMATION---------------------------------------------\n");


				printf("\n\n\t\t\t  ROLL NO: %s\n\n\n\t\t\t FIRSTNAME: %s \t\t\t LASTNAME: %s\n\n\n\t\t\t GENDER: %s\n\n\n\t\t\t SEMESTER: %d\t\t\t\t YEAR: %d\n\n\n",stud.std_id,stud.firstname,stud.lastname,stud.gender,stud.sem,stud.year);
				break;
			}

		}
		
		if(!flag)
			printf("ENTER CORRECT ROLL NO OR PASSWORD\n");
		fclose(fp2);
	}	

}

//this function will store their grades according to courses they have done  and senester , credits also

void new_grades()
{
	course sub;
        FILE* fp1;
        fp1=fopen("stud1.dat","a");
        if(fp1==NULL)
                printf("can't open file\n");
        else
        {
                int choice=1;
		system("clear");
              
              	while(choice)
              	{
			printf("ENTER ROLL NO:");
                        scanf("%s",sub.std_id);
                        printf("ENTER COURSE NAME:");
                        scanf("%s",sub.course_name);
                        printf("ENTER GRADE IN COURSE %s:",sub.course_name);
                        scanf("%s",sub.grade);
                        printf("ENTER CREDITS:");
                        scanf("%d",&sub.credits);
                        printf("ENTER SEMESTER:");
                        scanf("%d",&sub.sem);
                      
                         fwrite(&sub,sizeof(sub),1,fp1);
			 printf("\n\nWant to add more record:");
		         scanf("%d",&choice);
                }
              fclose(fp1);
        }


}

// student can see their overall cgpa	
void student_result()
{
	char rollno[20],password[20],name[40];
        printf("ENTER ROLL NO:");
        scanf("%s",rollno);
	printf("ENTER PASSWORD:");
        scanf("%s",password);
        course sub;
	int flag=0;
	student stud;

        FILE* fp2;
        fp2=fopen("stud.dat","r");
        if(fp2==NULL)
                printf("can't open file\n");
        else
        {
		
                while(fread(&stud,sizeof(stud),1,fp2))
                {
                        if(strcmp(rollno,stud.std_id)==0)
			{
				if( strcmp(password,stud.password)==0 )
	                        {
					flag=1;
        	                        strcpy(name,stud.firstname);
					strcat(name," ");
					strcat(name,stud.lastname);
                	        }
             				break;
			}

                }
	}

	if(flag)
	{
        	FILE* fp1;
      		  fp1=fopen("stud1.dat","r");
        	if(fp1==NULL)
                	printf("can't open file\n");
      		  else
       		 {

			system("clear");
			float sum=0;
			int credit=0,flag=0;
			while(fread(&sub,sizeof(sub),1,fp1))
			{
			
				if(strcmp(rollno,sub.std_id)==0)
				{
					credit+=sub.credits;
					sum+=sub.credits*grade(sub.grade);
				}
			}
			printf("\n\n\t\tHELLO %s YOUR CGPA IS : %.2f\n\n",name,sum/credit);
		
			fclose(fp1);
		}
	}
	else
		printf("ENTER CORRECT ROLL NO OR PASSWORD\n");
}

int grade(char c[3])
{
	if(c[0]=='A' && c[1]=='B')
		return 9;
	else if(c[0]=='A')
		return 10;
	else if(c[0]=='B' && c[1]=='C')        
                return 7;
	else if(c[0]=='B')        
                return 8;
	else if(c[0]=='C' && c[1]=='D')        
                return 5;
	else if(c[0]=='C')        
                return 6;
	else if(c[0]=='D')        
                return 4;
	else if(c[0]=='F')        
                return 0;
}		

// Student history in all courses that he has done
 		
void student_history()
{

	char rollno[20],password[20];
        printf("ENTER ROLL NO:");
        scanf("%s",rollno);
	printf("ENTER PASSWORD:");
	scanf("%s",password);
        course sub;

	int flag=0;
	 student stud;

        FILE* fp2;
        fp2=fopen("stud.dat","r");
        if(fp2==NULL)
                printf("can't open file\n");
        else
        {

                while(fread(&stud,sizeof(stud),1,fp2))
                {
                        if(strcmp(rollno,stud.std_id)==0)
                        {
                                if( strcmp(password,stud.password)==0 )
                                {
                                        flag=1;
                              
                                }
                              
                                break;
                        }

                }
        }

        if(flag)
        {

       		 FILE* fp1;
      		  fp1=fopen("stud1.dat","r");
       		 if(fp1==NULL)
                printf("can't open file\n");
      		  else
        	  {
               
			system("clear");
			printf("------------------------------------------STUDENT HISTORY----------------------------------------\n\n");
			printf("\nCOURSE-NAME\t COURSE-CREDITS\t\t\t COURSE-GRADE\t SEM\n");

              		  while(fread(&sub,sizeof(sub),1,fp1))
               		 {

                        	if(strcmp(rollno,sub.std_id)==0)
                       		 {
					printf("%s\t\t\t %d\t\t\t %s\t\t %d\n\n",sub.course_name,sub.credits,sub.grade,sub.sem);
                              
                       		 }
               		 }

             		   fclose(fp1);
		}
        }
	else
		printf("ENTER CORRECT ROLL NO OR PASSWORD\n");

}	

// Semester wise result

void semester_result()
{
	char rollno[20];
	char password[20];
	int sem;
        printf("ENTER ROLL NO:");
        scanf("%s",rollno);
	printf("ENTER PASSWORD:");
        scanf("%s",password);

        course sub;
	int flag=0;
	 student stud;

        FILE* fp2;
        fp2=fopen("stud.dat","r");
        if(fp2==NULL)
                printf("can't open file\n");
        else
        {
            
                while(fread(&stud,sizeof(stud),1,fp2))
                {
                        if(strcmp(rollno,stud.std_id)==0)
                        {
                                if( strcmp(password,stud.password)==0 )
                                {
                                        flag=1;
                                       
                                }
                            
                                break;
                        }

                }
        }

        if(flag)
        {

		printf("ENTER SEMESTER:");
		scanf("%d",&sem);
	        FILE* fp1;
        	fp1=fopen("stud1.dat","r");
        	if(fp1==NULL)
                	printf("can't open file\n");
        	else
        	{
                	float sum=0;
               		 int credit=0;
			system("clear");

               		 printf("----------------------------------SEMESTER %d RESULT----------------------------------\n",sem);
                	printf("\tCOURSE-NAME\t\t COURSE-CREDITS\t\t\t COURSE-GRADE\n");

             		   while(fread(&sub,sizeof(sub),1,fp1))
                	  {

                       		 if(strcmp(rollno,sub.std_id)==0 && sem==sub.sem)
                        	{
                                	printf("\n\n\t%s\t\t\t\t %d\t\t\t\t %s\n",sub.course_name,sub.credits,sub.grade);
                               		 credit+=sub.credits;
                            	         sum+=sub.credits*grade(sub.grade);
                       		 }
               		 }

               		 printf("\n\n\tSGPA :%.2f\n\n",sum/credit);
              		  fclose(fp1);
       	 	}
	}
	else
		printf("ENTER CORRECT ROLL NO OR PASSWORD\n");
}

//in particular subject how many students got particluar grade

void subject_grade_analysis()
{
	
	char course_name[20];
	char grade[3];

	printf("ENTER COURSE NAME:");
	scanf("%s",course_name);

	printf("ENTER GRADE:");
	scanf("%s",grade);

	course sub;
	
	FILE* fp1;
	fp1=fopen("stud1.dat","r");
	int i=0;
	system("clear");
	printf("\t\t\t============================================LIST OF STUDENTS==================================================\n\n\n");
	while(fread(&sub,sizeof(sub),1,fp1))
        {

              if(strcmp(course_name,sub.course_name)==0 && strcmp(grade,sub.grade)==0)
              {
                        printf("\n\n\t\t\t %d\t%s\t\t\t",++i,sub.std_id);

              }
        }

	printf("\n\nTOTAL %d STUDENTS GOT GRADE %s IN COURSE %s\n\n",i,grade,course_name);
       fclose(fp1);
	
	
}

//introduction of project

void intro()
{
	system("clear");
	printf("\n\n\n\n\n\n\t\t\t\t\t  STUDENT DATABASE MANAGEMENT PROJECT");
	printf("\n\n\n\n\t\tStudent can see their Semester Wise Result,their grades in all subjects etc.");  
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\tMADE BY : PRIYANKA SHARMA \n\t\t\t\t15UCS170");
	
}


int main()
{
	intro();
	printf("\n\n\n\t\tENTER ANY KEY TO CONTINUE:");
	
	if(getchar())
	{
		system("clear");
		printf("\n\n\n=================================================================STUDENT - SECTION===========================================================\n\n\n\n");
		printf("--------------------------------------------------------------------------MENU-----------------------------------------------------------------\n\n\n");
		printf("\n\n\t\t\t\t\t1.STUDENT PERSONAL DETAILS\n\n\t\t\t\t\t 2.CREATE STUDENT NEW ACCOUNT\n\n\t\t\t\t\t 3.STUDENT OVERALL RESULT\n\n\t\t\t\t\t 4.STUDENT HISTORY\n\n\t\t\t\t\t 5.GRADE SUBMISSION\n\n\t\t\t\t\t6.PREVIOUS RESULT\n\n\t\t\t\t\t7.TO SEE IN PARTICULAR SUBJECT HOW MANY STUDENTS GOT PARTICULAR GRADE\n\n\n");

		int choice;
		printf("\n\nENTER YOUR QUERY:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:student_details();
				break;
			case 2:new_account();
				break;
			case 3:student_result();
				break;
			case 4:student_history();
				break;
			case 5:new_grades();
				break;
			case 6:semester_result();
				break;
			case 7:subject_grade_analysis();
				break;
		}
	}
	 

return 0;
}			
