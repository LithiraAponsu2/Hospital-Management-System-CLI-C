/* 
Course : CO253
Title : Hosptal Maagement System
*/

// headers
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct patient // varibles of patient  
{
    int NIC, age;
    char fullName[100], gender[10], admissionDate[20];
};

// global varibles
int patientCount = 0; 
struct patient patients[100]; // list of patients (max 100)

// function decleration
void WelcomeScreen(void);
void Header(void);
void MainMenu(void);
void quit_(void);
void add_rec(void);
void one_rec(void);
void all_rec(void);
void del_rec(void);

// oordinate for pointing a position
void gotoxy(short x, short y) 
{
    COORD position = {x, y};  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// start of programme 
void main()
{
    WelcomeScreen();
    Header();
    MainMenu();
}

// welcome screen
void WelcomeScreen(void)
{	
    printf("\033[0;35m");  // purple
    printf("\n\n\n\n\n\n\n");

    printf("\t\t                                                             WELCOME TO                                                             \n\n\n\n");
    printf("\t\t ######  ##     ##    ###    ##    ##    ###    ##     ##    ##     ##  #######   ######  ########  #### ########    ###    ##      \n"); 
    printf("\t\t##    ## ##     ##   ## ##   ###   ##   ## ##    ##   ##     ##     ## ##     ## ##    ## ##     ##  ##     ##      ## ##   ##      \n"); 
    printf("\t\t##       ##     ##  ##   ##  ####  ##  ##   ##    ## ##      ##     ## ##     ## ##       ##     ##  ##     ##     ##   ##  ##      \n"); 
    printf("\t\t##       ######### ##     ## ## ## ## ##     ##    ###       ######### ##     ##  ######  ########   ##     ##    ##     ## ##      \n"); 
    printf("\t\t##       ##     ## ######### ##  #### #########   ## ##      ##     ## ##     ##       ## ##         ##     ##    ######### ##      \n"); 
    printf("\t\t##    ## ##     ## ##     ## ##   ### ##     ##  ##   ##     ##     ## ##     ## ##    ## ##         ##     ##    ##     ## ##      \n"); 
    printf("\t\t ######  ##     ## ##     ## ##    ## ##     ## ##     ##    ##     ##  #######   ######  ##        ####    ##    ##     ## ########\n"); 
	
    printf("\n\n\n\n\n Press any key to continue......\n");
    printf("\033[0m");  // reset
	getch(); // pause until key is pressed 
	system("cls");  // clear screen  	
}

// header for every option
void Header(void)
{
    printf("\033[0;35m");  // purple

	printf("\n\n\t\t\t------------------------------------------------------------------------------------");
	printf("\n\t\t\t                COVID-19 PATIENT MANAGEMENT SYSTEM - CHANAX HOSPITAL                ");
	printf("\n\t\t\t------------------------------------------------------------------------------------");

    printf("\033[0m");  // reset
}

// funtion for selecting options
void MainMenu(void)
{
	system("cls"); // clear screen
	Header();// call Header function

    printf("\033[0;32m");  // green

    printf("\n\n\n\n\n\t\t\t\t0. Quit\n");
	printf("\n\t\t\t\t1. Add a Patients Record\n");
	printf("\n\t\t\t\t2. Print a Patient Record\n");
	printf("\n\t\t\t\t3. Print all Patients Records\n");
	printf("\n\t\t\t\t4. Delete a Patient Record\n");
	printf("\n\n\t\t\t\tEnter Option [0-4]: ");

    printf("\033[0m");  // reset

    int option;
	scanf("%i", &option);
	
	switch(option)//switch to differeht case
	{
        case 0:
            quit_();  //quit_ function is called
            break;
        case 1:
            add_rec();//add_rec function is called
            break;
        case 2:
            one_rec();//one_rec function is call
            break;
        case 3:
            all_rec();//all_rec function is call
            break;
        case 4:
            del_rec();//del_rec function is call
            break;
        default:
            printf("\033[0;31m");  // red
            printf("\n\n\t\t\tInvalid entry!. Please enter right option");
            printf("\033[0m");  // reset
            printf("\033[0;32m");  // green
            printf("\n\nPress any key to continue......\n");
            printf("\033[0m");  // reset
            getch(); // pause until key is pressed 
            system("cls");  // clear screen  
	}

    Header();  // call Header function
    MainMenu();  // call Mainenu function
}

// function for quit the programme
void quit_(void)//function to quit
{
	system("cls");  // clear screen
    printf("\033[0;35m");  // purple
    printf("\n\n\t\t\t------------------------------------------------------------------------------------");
	printf("\n\t\t\t                                     THANK YOU!                                     ");
	printf("\n\t\t\t                                CHANAX INTERNATIONAL                                ");
	printf("\n\t\t\t------------------------------------------------------------------------------------");

    printf("\033[0m");  // reset
    getch();  // pause until key is pressed
}

// function for add a new record
void add_rec(void)
{
    system("cls"); // clear screen
	Header();// call Header function

    printf("\033[0;32m");  // green
    printf("\n\n");
	printf("\n\t\t\t                                  ADD NEW PATIENT                                  ");
    printf("\n\t\t\t------------------------------------------------------------------------------------");

    patientCount++;  // new record saved. then patient count is increased

    printf("\n\t\t\tNIC[without 'V']: ");
    printf("\033[0m");  // reset
    scanf("%i",&patients[patientCount].NIC);  // store NIC
     

    printf("\033[0;32m");  // green
    printf("\n\t\t\tFirst Name[Without spaces]: ");
    printf("\033[0m");  // reset
    char temp_first[25];  // temp varible to store first name
    scanf("%s", temp_first);
    printf("\033[0;32m");  // green
    printf("\n\t\t\tLast Name: ");
    printf("\033[0m");  // reset
    char temp_last[25];  // temp varible to store last name
    scanf("%s", temp_last);
    sprintf(patients[patientCount].fullName, "%s %s", temp_first, temp_last);  // cocatenate first last names and store in full name 

    printf("\033[0;32m");  // green
    printf("\n\t\t\tAge[Years]: ");
    printf("\033[0m");  // reset
    scanf("%i", &patients[patientCount].age);  // store age

    printf("\033[0;32m");  // green
    printf("\n\t\t\tGender[M/m/F/f]: ");
    printf("\033[0m");  // reset
    scanf("%s",&patients[patientCount].gender);  // store gender

    printf("\033[0;32m");  // green
    printf("\n\t\t\tAddmission Date[DD/MM/YYYY]: ");
    printf("\033[0m");  // reset
    scanf("%s", &patients[patientCount].admissionDate);  // store admission date

    printf("\033[0;32m");  // green
    printf("\n\n\t\t\t.... Information Record Successful ....");
    printf("\n\n\n\n\n Press any key to continue......\n");
    printf("\033[0m");  // reset
    
	getch();   // pause until key is pressed 
	system("cls"); // clear screen

}

// function for print a record by IC number
void one_rec(void)
{
    system("cls"); // clear screen
	Header();// call Header function

    printf("\033[0;32m");  // green
    printf("\n\n");
	printf("\n\t\t\t                                  PATIENT RECORD                                  ");
    printf("\n\t\t\t------------------------------------------------------------------------------------");
    printf("\033[0m");  // reset

    printf("\033[0;32m");  // green
    printf("\n\t\t\tNIC[without 'V']: ");
    printf("\033[0m");  // reset
    int temp_NIC;  // store NIC number to compare
    scanf("%i",&temp_NIC);

    printf("\033[0;32m");  // green

    gotoxy(22, 15);
    printf("NIC");
    gotoxy(36, 15);
    printf("Full Name");
    gotoxy(86, 15);
    printf("Age");
    gotoxy(91, 15);
    printf("Gender");
    gotoxy(99, 15);
    printf("Admission Date");
    printf("\n\t\t    ===============================================================================================");

    for(int temp_count = 0; temp_count <= patientCount; temp_count++)  // loop through patients
    {
        if(temp_NIC == patients[temp_count].NIC)  // same NIC found 
        {
            gotoxy(22, 17);
            printf("%i", patients[temp_count].NIC);
            gotoxy(36, 17);
            printf("%s", patients[temp_count].fullName);
            gotoxy(86, 17);
            printf("%i", patients[temp_count].age);
            gotoxy(91, 17);
            printf("%s", patients[temp_count].gender);
            gotoxy(99, 17);
            printf("%s", patients[temp_count].admissionDate);
            break;
        }
    }

    printf("\n\n\n\n\n Press any key to continue......\n");
    printf("\033[0m");  // reset
	getch(); // pause until key is pressed 
	system("cls"); // clear screen

}

// fumction for print patient list
void all_rec(void)
{
    system("cls"); // clear screen
	Header();// call Header function

    printf("\033[0;32m");  // green
    printf("\n\t\t\t                                 ALL PATIENT RECORDS                                ");
    printf("\n\t\t\t------------------------------------------------------------------------------------");

    gotoxy(22, 15);
    printf("NIC");
    gotoxy(36, 15);
    printf("Full Name");
    gotoxy(86, 15);
    printf("Age");
    gotoxy(91, 15);
    printf("Gender");
    gotoxy(99, 15);
    printf("Admission Date");
    printf("\n\t\t    ===============================================================================================");

    for(int temp_count = 1; temp_count <= patientCount; temp_count++)
    {
        gotoxy(22, 17+temp_count);
        printf("%i", patients[temp_count].NIC);
        gotoxy(36, 17+temp_count);
        printf("%s", patients[temp_count].fullName);
        gotoxy(86, 17+temp_count);
        printf("%i", patients[temp_count].age);
        gotoxy(91, 17+temp_count);
        printf("%s", patients[temp_count].gender);
        gotoxy(99, 17+temp_count);
        printf("%s", patients[temp_count].admissionDate);     
    }
    printf("\n\n\n\n\n Press any key to continue......\n");
    printf("\033[0m");  // reset
	getch(); // pause until key is pressed 
	system("cls");  // clear screen
}

// delete a patient record
void del_rec(void)
{
    printf("\033[0;32m");  // green
    printf("\n\t\t\t                               DELETE PATIENT RECORD                                ");
    printf("\n\t\t\t------------------------------------------------------------------------------------");

    printf("\n\t\t\tNIC[without 'V']: ");
    printf("\033[0m");  // reset
    int temp_NIC;
    scanf("%i",&temp_NIC);

    printf("\033[0;32m");  // green
    for(int temp_count = 0; temp_count <= patientCount; temp_count++)
    {
        if(temp_NIC == patients[temp_count].NIC)
        {
            printf("\n\t\t\tNIC: %i", patients[temp_count].NIC);
            printf("\n\t\t\tFull Name: %s", patients[temp_count].fullName);
            printf("\n\t\t\tAge: %i", patients[temp_count].age);
            printf("\n\t\t\tGender[M/F]: %s", patients[temp_count].gender);
            printf("\n\t\t\tAddmission Date: %s", patients[temp_count].admissionDate);
            
            for(int temp_count2 = temp_count; temp_count2 < patientCount; temp_count2++)
            {   
                patients[temp_count2].NIC = patients[temp_count2+1].NIC;
                strcpy(patients[temp_count2].fullName, patients[temp_count2+1].fullName);
                patients[temp_count2].age = patients[temp_count2+1].age;
                strcpy(patients[temp_count2].gender, patients[temp_count2+1].gender);
                strcpy(patients[temp_count2].admissionDate, patients[temp_count2+1].admissionDate);    
            }
            patientCount -= 1;
            break;
        } 
    }
    printf("\n\n\t\t\t.... Record Delete Successful ....");
    printf("\n\n\n\n\n Press any key to continue......\n");
    printf("\033[0m");  // reset
	getch(); // pause until key is pressed 
	system("cls"); // clear screen
}
