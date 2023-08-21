#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#define lli long long int
#define ss(aza) scanf("%lld",&aza)
#define pp(aza) printf("%lld",aza)
#define FOR(i,a,b,c) for (int i = (a); i < (b); i=i+(c))
#define ROF(i,a,b,c) for (int i = (a); i > (b); i=i-(c))
const int MOD = 1e9+7;
#define TEST         int zz,zzz; scanf("%d",zz); FOR(zzz,0,zz,1)
#define sp           " "



struct String{
    char sss[20];

};



struct student{
char first_name[100];
char last_name[100];
char roll[100];
char password[100];
char department[100];
char batch[100];

};


struct teacher{
char first_name[100];
char last_name[100];
char password[100];
char department[100];
char designation[100];
char teachers_id[100];
};


struct teacher_with_course{
char first_name[100];
char department[100];
int number_of_courses;
struct String courses[50];
char teachers_id[100];
};


struct result{
char roll[100];
char course[100];
char  mark[100];
};


//fixing output position in console
void goto_position_xy(int x,int y);

//This function prints n characters
void print_n_Character(char ch,int n);


//welcome function
void welcome(){

 printf(" \n\n\n\n\n\t\t\t\t        *  *  *  *  *  *  *   *   *  *  *  *  *  *");
		printf("\n\n\t\t\t\t        *                                        *");
		printf("\n\n\t\t\t\t        *                 Welcome                *");
		printf("\n\n\t\t\t\t        *                    To                  *");
		printf("\n\n\t\t\t\t        *       University Management System     *");
		printf("\n\n\t\t\t\t        *                                        *");
		printf("\n\n\t\t\t\t        *  *  *  *  *  *  *   *   *  *  *  *  *  *");
  printf("\n\n\n\n\n\t\t\t\t\t Press any key to continue...... ");
		getch(); //reads a single character

}


//This function shows marks to students
void class_test_mark(char tempRoll[100]){
    system("cls");    //clears screen
    FILE *f1;
    f1=fopen("result.dat","r");  //opens file in reading mode

    struct result r;
    int t=0;


    goto_position_xy(30,3);      //prints at position x,y;
    fflush(stdin);
        printf(" Your Roll Number : %s",tempRoll);
        goto_position_xy(20,4);
        print_n_Character('=',45);  //prints 45 "=";


    while((fread(&r,sizeof(r),1,f1))==1)   //searches and shows course and mark for temproll
    {

        if(strcmp(tempRoll,r.roll) == 0)   //compares 2 strings ;
        {
            t=t+2;
            goto_position_xy(30,(6+t));
            printf("Course: %s    Mark:%s",r.course,r.mark);

        }

    }


    fclose(f1);   //closes file

    t=t+2;

    goto_position_xy(30,(8+t));
    printf("Press any key to continue.");
    getch();
    student_pannel_main();

}


//This function assigns marks
void insert_classtest_mark(){

     system ("cls"); //clears screen

    goto_position_xy(40,2);
    printf(" Enter Students info : ");

    goto_position_xy(20,3);
    print_n_Character('=',65);//prints 65 "="

    FILE *f1;
    f1=fopen("result.dat","a+");//opens file in append+ mode;

    struct result tt;

    fflush(stdin);  //flushes input buffer

    goto_position_xy(30,6);
    printf("Enter Roll   :");
    gets(tt.roll);

    goto_position_xy(30,8);
    printf("Enter Course :");
    gets(tt.course);

    goto_position_xy(30,10);
    printf("Enter Mark   :");
    gets(tt.mark);

    //fflush(stdin);


    fwrite(&tt,sizeof(tt),1,f1);  //writes tt info  in file
    fflush(stdin);

    fclose(f1); //closes file f1

    goto_position_xy(30,16);


    char another ;
    printf("Want To Insert Another Mark? (Y/N)?");
    fflush(stdin);  //flushes input buffer
    another=getchar();

    if(another=='y'||another=='Y'){
        insert_classtest_mark();
    }
    else{
        teachers_pannel_main();
    }

}


//This function finds students
void Find_a_student(){

    system("cls"); //clears full screen
    FILE *f1;
    f1=fopen("student info.dat","r"); //opens file in reading mode

    struct student r;
    int t=0;
    char firstname[100];

    goto_position_xy(40,1);
    printf("---Find A Student---");
    goto_position_xy(20,2);
    print_n_Character('=',65);//prints 65 "="


    goto_position_xy(25,4);
    fflush(stdin);
    printf("Enter The First Name Of A Student To Find : ");
    scanf("%s",&firstname);

    while((fread(&r,sizeof(r),1,f1))==1)
    {

        if(strcmp(firstname,r.first_name) == 0)//compares firstname and shows student info
        {
            t=t+2;

            goto_position_xy(30,(8+t));
            printf("Full Name :%s  %s",r.first_name,r.last_name);
            t++;

            goto_position_xy(30,(8+t));
            printf("Roll      :%s",r.roll);
            t++;

            goto_position_xy(30,(8+t));
            printf("Department:%s",r.department);
            t++;


            goto_position_xy(30,(8+t));
            printf("Batch     :%s",r.batch);
            t++;



        }

    }


    fclose(f1);//closes  file

    goto_position_xy(30,(8+t+1));

    char another ;
    printf("Find Another Student? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        Find_a_student();
    }
    else{
        teachers_pannel_main();
    }



}


//This function counts number of students
void count_students(){

    system("cls");//clears conlsole
    FILE *f1;
    f1=fopen("student info.dat","r"); //opens  file in reading mode

    struct student stud;
    int total=0;

    char proll[100]={};

    while((fread(&stud,sizeof(stud),1,f1))==1)  //reads the total info of students
    {

    total++;

    }


    goto_position_xy(20,4);
    printf("The Number Of Total Student :%d",total);


    goto_position_xy(20,10);
    char another ;
    printf("Want To Back? (Y/N)? :");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        teachers_pannel_main();
    }
    else{
       return 0;
    }


}


//This function allows teachers to work after sign in
void teachers_pannel_main()
{
    system("cls");   //clears console
    system("color 4f"); //fixes the consoles color to red

    goto_position_xy(30,3);
    printf(" Welcome To Teacher's Pannel  ");

    goto_position_xy(20,4);
    print_n_Character('=',45);

    goto_position_xy(30,6);
    printf(" 1.Insert class test mark ");

    goto_position_xy(30,8);
    printf(" 2.Find a student ");

    goto_position_xy(30,10);
    printf(" 3.count student ");

    goto_position_xy(30,12);
    printf(" 4.EXIT ");


    goto_position_xy(20,15);
    print_n_Character('=',45);


    goto_position_xy(20,18);
    printf(" Enter Your Option:  ");

     int a;
    scanf("%d",&a);
///////////////////////
    switch(a)  //switches next action with the value of a;
    {
    case 1:
        insert_classtest_mark();
        break;
    case 2:
        Find_a_student();
        break;
    case 3:
        count_students();
        break;
    case 4:
        first();
        break;
//////////////////////



}
}


//This function allows students to work after sign in
void student_pannel_main(char roll[100])
{
    system("cls");//clears the console

    system("color 4f");//colors the console to red

     goto_position_xy(30,3);
    printf(" Welcome To Student Pannel  ");

     goto_position_xy(20,4);
    print_n_Character('=',45);

    goto_position_xy(30,7);
    printf(" 1.Check class test mark    ");

     goto_position_xy(30,9);
    printf(" 2.EXIT    ");

     goto_position_xy(20,14);
    print_n_Character('=',45);

    goto_position_xy(30,18);
    printf(" Enter Your Option:  ");


    int a;
    scanf("%d",&a);
///////////////////////
    switch(a)  //swithches action depending the value of a;
    {
    case 1:
        class_test_mark(roll);  //function called by value
        break;
    case 2:
        first();
        break;

}


}



//This function maintains student's sign in
void student_pannel()
{
    system("cls");  //clears the console
    system("color 1f"); //colors the console to blue
    printf("\n\n\n\t\t\t\t\t Enter To Student Pannel ");

    goto_position_xy(20,4);
    print_n_Character('=',65);
    fflush(stdin);  //flushes input buffer

    goto_position_xy(18,6);
    printf(" Enter User name : ");

    char nm[100];
    gets(nm); //inputs value of nm;

    goto_position_xy(18,8);
    printf(" Enter Password  : ");

    char pass[100];
    gets(pass);


    FILE *f1;
    f1=fopen("student info.dat","r"); //opens file in reading mode
    struct student tt;


    lli CK=0;
    while( fread(&tt,sizeof(tt),1,f1)){

        if(strcmp(nm,tt.first_name)==0 && strcmp(pass,tt.password)==0){  //compares strings to log in
            printf("Log in successfull \n");
            CK=1;
            student_pannel_main(tt.roll);
            break;
        }

    }
     if(CK==0){
            goto_position_xy(20,20);
            printf("Enter correct User Name & password \n");
            Sleep(900);       //stays paused 900 mS
            student_pannel();

        }

    fclose(f1);  //closes file f1


}


//This function maintains Teacher's sign in
void Teachers_pannel()
{
    system("cls");       //clears console output
    system("color 1f");
    printf("\n\n\n\t\t\t\t\t Enter To Teacher's Pannel ");

     goto_position_xy(20,4);
    print_n_Character('=',65);


    fflush(stdin); //flushes input buffer

    goto_position_xy(18,6);
    printf(" Enter User name : ");

    char nm[100];
    gets(nm);

    goto_position_xy(18,8);
    printf(" Enter Password  : ");

    char pass[100];
    gets(pass);



    FILE *f1;

    f1=fopen("teacher's info.dat","r"); //opens file in reading mode
    struct teacher tt;


    lli CK=0;
    while( fread(&tt,sizeof(tt),1,f1)){ //reads data from file until end;

        if(strcmp(nm,tt.first_name)==0 && strcmp(pass,tt.password)==0){ //compares first name and password for login
            printf("login successfull \n");
            CK=1;
            teachers_pannel_main();
            break;
        }

    }
     if(CK==0){
            printf("Enter correct user name & password \n");
            Sleep(900); //pauses for 900mS
            Teachers_pannel();

        }

    fclose(f1);//closes f1;

}


//This function creates teacher's account
void teachers_account_create(){
    system ("cls"); //clears console screen

    goto_position_xy(30,3);
    printf("Enter Teacher's Information : ");
     goto_position_xy(20,4);
    print_n_Character('=',45);

    FILE *f1;
    f1=fopen("teacher's info.dat","a+"); //opens file in append+ mode

    struct teacher tt;

    fflush(stdin);  //flushes input buffer

    goto_position_xy(30,6);
    printf("Enter First Name  :");
    gets(tt.first_name);

    goto_position_xy(30,8);
    printf("Enter Last  Name  :");
    gets(tt.last_name);


    goto_position_xy(30,10);
    printf("Enter Department  :");
    gets(tt.department);

    goto_position_xy(30,12);
    printf("Enter Designation :");
    gets(tt.designation);

    //fflush(stdin);
    goto_position_xy(30,14);
    printf("Enter Teacher's ID:");
    gets(tt.teachers_id);

    goto_position_xy(30,16);
    printf("Enter   password  :");
    gets(tt.password);

    fwrite(&tt,sizeof(tt),1,f1); //writes data on file
    fflush(stdin);

    fclose(f1);

    goto_position_xy(20,19);
    printf("***NB:First_Name Is the Username For The Teacher***");

    goto_position_xy(30,21);
    char another ;
    printf("Add Another Teacher? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        teachers_account_create();
    }
    else{
        Admin_pannel_main();
    }

}



//This function creates student's account
void student_account_create(){
system ("cls"); //clears console output

    goto_position_xy(30,3);
    printf("Enter Student's Information : ");
    goto_position_xy(20,4);
    print_n_Character('=',45);

    FILE *f1;
    f1=fopen("student info.dat","a+"); //opens file in append+ mode

    struct student tt;

    fflush(stdin);//flushes input buffer

    goto_position_xy(30,6);
    printf("Enter First Name :");
    gets(tt.first_name);

    goto_position_xy(30,8);
    printf("Enter Last  Name :");
    gets(tt.last_name);

    goto_position_xy(30,10);
    printf("Enter Roll       :");
    gets(tt.roll);

    goto_position_xy(30,12);
    printf("Enter Department :");
    gets(tt.department);

    goto_position_xy(30,14);
    printf("Enter Batch      :");
    gets(tt.batch);

    goto_position_xy(30,16);
    printf("Enter Password   :");
    gets(tt.password);

    fwrite(&tt,sizeof(tt),1,f1); //writes  student data on file
    fflush(stdin);

    fclose(f1);//closes file f1

    goto_position_xy(20,18);
    printf("***NB:First_Name Is the Username For The Student***");

    goto_position_xy(30,21);
    char another ;
    printf("Add Another Student? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        student_account_create();
    }
    else{
        Admin_pannel_main();
    }

}


//This function updates student account's information
void student_account_update(){


    system("cls"); //clears console output

    FILE *f1;
    f1=fopen("student info.dat","r+"); //opens file in reading+ mode

    struct student st;
    char roll[100];



    goto_position_xy(35,1);
    printf("---UPDATE ACCOUNT---");
    goto_position_xy(20,2);
    print_n_Character('=',50);

    goto_position_xy(30,4);
    printf("Enter Roll Of Student To Update: ");
    fflush(stdin);
    gets(roll);

    if(f1 == NULL){  //checks if thread faced opening file

        goto_position_xy(10,6);
        printf("Error opening file");
        exit(1);
    }



    fflush(stdin);
    while(fread(&st,sizeof(st),1,f1) == 1) //checks roll and updates data
    {

        if(strcmp(roll,st.roll) == 0)
        {
            goto_position_xy(30,6);
            printf("Full Name :%s  %s",st.first_name,st.last_name);


            goto_position_xy(30,8);
            printf("Roll      :%s",st.roll);

            goto_position_xy(30,10);
            printf("Department:%s",st.department);

            /////////////////////////////////
            goto_position_xy(30,14);
            printf("Enter First Name :");
            gets(st.first_name);

            goto_position_xy(30,16);
            printf("Enter Last  Name :");
            gets(st.last_name);

            goto_position_xy(30,18);
            printf("Enter Roll       :");
            gets(st.roll);

            goto_position_xy(30,20);
            printf("Enter Department :");
            gets(st.department);

            goto_position_xy(30,22);
            printf("Enter Batch      :");
            gets(st.batch);

            goto_position_xy(30,24);
            printf("Enter Password   :");
            gets(st.password);

            fseek(f1,-sizeof(st),SEEK_CUR);
            fwrite(&st,sizeof(st),1,f1);
            break;
        }


    }
    fclose(f1); //closes file
    goto_position_xy(25,27);

    char another ;
    printf("Update Another Student? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        student_account_update();
    }
    else{
        Admin_pannel_main();
    }
}


//This function updates teacher account's information
void teachers_account_update(){

    system("cls"); //clears console output

    FILE *f1;
    f1=fopen("teacher's info.dat","r+"); //opens file in reading+ mode

    struct teacher st;
    char firstname[100];
    char department[100];
    char id[100];



    goto_position_xy(35,1);
    printf("---UPDATE ACCOUNT---");
    goto_position_xy(20,2);
    print_n_Character('=',50);


    goto_position_xy(25,3);
    printf("Enter First Name Of Teacher To Update  : ");
    fflush(stdin);
    gets(firstname);

    goto_position_xy(25,5);
    printf("Enter Department Of Teacher To Update  : ");
    fflush(stdin);
    gets(department);

    goto_position_xy(25,7);
    printf("Enter Teacher's ID of Teacher To Update: ");
    fflush(stdin);
    gets(id);

    if(f1 == NULL){ //if file cannot be opened

        goto_position_xy(10,9);
        printf("Error opening file");
        exit(1);
    }



    fflush(stdin);
    while(fread(&st,sizeof(st),1,f1) == 1)   //reads file and compares 2 strings to find teachers info then updates
    {

        if((strcmp(firstname,st.first_name) == 0)&&(strcmp(department,st.department) == 0)&&(strcmp(id,st.teachers_id) == 0))
        {
            goto_position_xy(20,8);
            print_n_Character('-',65);

            goto_position_xy(30,10);
            printf("Full  Name  :%s  %s",st.first_name,st.last_name);

            goto_position_xy(30,12);
            printf("Department  :%s",st.department);

            goto_position_xy(30,14);
            printf("Teacher's ID:%s",st.teachers_id);

            goto_position_xy(20,16);
            print_n_Character('-',65);

            /////////////////////////////////
            goto_position_xy(30,18);
            printf("Enter First Name  :");
            gets(st.first_name);

            goto_position_xy(30,20);
            printf("Enter Last  Name  :");
            gets(st.last_name);


            goto_position_xy(30,22);
            printf("Enter Department  :");
            gets(st.department);


            goto_position_xy(30,24);
            printf("Enter Designation :");
            gets(st.designation);

            goto_position_xy(30,26);
            printf("Enter Teacher's ID:");
            gets(st.teachers_id);


            //fflush(stdin);

            goto_position_xy(30,28);
            printf("Enter  password  :");
            gets(st.password);



            fseek(f1,-sizeof(st),SEEK_CUR); //sets the file position of the stream to given offset
            fwrite(&st,sizeof(st),1,f1);
            break;
        }


    }
    fclose(f1); //closes file f1
    goto_position_xy(30,30);

   char another ;
    printf("Update Another Teacher? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        teachers_account_update();
    }
    else{
        Admin_pannel_main();
    }
}


//This function assigns cources
void assign_cources(){

    system("cls");  //clears the console output

    FILE *f1;
    f1=fopen("teacher's course info.dat","a+"); //opens file in append+ mode

    struct teacher_with_course st;
    char firstname[100];
    char department[100];
    char id[100];



    goto_position_xy(35,1);
    printf("---ASSIGN COURSES---");
    goto_position_xy(30,3);
    printf("Enter First Name Of  Teacher  : ");
    fflush(stdin);
    gets(st.first_name);

    goto_position_xy(30,5);
    printf("Enter Department Of  Teacher  : ");
    fflush(stdin);
    gets(st.department);


    goto_position_xy(30,7);
    printf("Enter Teacher's ID Of Teacher : ");
    fflush(stdin);
    gets(st.teachers_id);





            goto_position_xy(30,10);
            printf("Enter Courses:");


            /////////////////////////////////
            goto_position_xy(30,12);
            printf("Enter Number Of Cources :");
            scanf("%d",&st.number_of_courses);

            FOR(i,0,st.number_of_courses,1)
            {
            goto_position_xy(30,(14+(i*2)));
            printf("Enter Course Name: ");
            fflush(stdin);
            gets(st.courses[i].sss);

            }
            fwrite(&st,sizeof(st),1,f1);  //writes in file

    fclose(f1);//closes file f1

    goto_position_xy(30,25);
    char another ;
    printf("Add Another Teacher's Courses? (Y/N)?");
    fflush(stdin);
    another=getchar();

    if(another=='y'||another=='Y'){
        assign_cources();
    }
    else{
        Admin_pannel_main();
    }

}


//Main Admin pannel
void Admin_pannel_main(){

    system("cls");      //clears the console output
    system("color 4f"); //sets console colour to red

    goto_position_xy(30,3);
    printf(" Welcome To Admin Pannel  ");

    goto_position_xy(20,4);
    print_n_Character('=',45);

    goto_position_xy(30,6);
    printf(" 1.Create Teacher's account ");

    goto_position_xy(30,8);
    printf(" 2.Update Teacher's account ");

    goto_position_xy(30,10);
    printf(" 3.Create Student's account ");

    goto_position_xy(30,12);
    printf(" 4.Update Student's account ");

    goto_position_xy(30,14);
    printf(" 5.Assign Course To A Teacher");

    goto_position_xy(30,16);
    printf(" 6.EXIT");

    goto_position_xy(20,18);
    print_n_Character('=',45);

    goto_position_xy(20,22);
    printf(" Enter Your Option:  ");

     int a;
    scanf("%d",&a);

    switch(a)   //switches with the value of a
    {
    case 1:
        teachers_account_create();
        break;
    case 2:
        teachers_account_update();
        break;
    case 3:
        student_account_create();
        break;

    case 4:
        student_account_update();
        break;

    case 5:
        assign_cources();
        break;

    case 6:
        first();
        break;

    }
}


//This function maintains admin's sign in
void Admin_pannel()
{
    system("cls");  //clears the console screen
    system("color 1f"); //sets console color to blue
    struct admin{
    char username[100];
    char password[100];
             }ad;

    goto_position_xy(20,3);
    printf(" Enter To Admin Pannel ");

    goto_position_xy(15,4);
    print_n_Character('=',30);

    //////////////////////////////////////////////////


    fflush(stdin);  //flushes input buffer
    goto_position_xy(18,6);
    printf(" Enter User Name : ");

    char nm[100];
    scanf("%s",nm);

    goto_position_xy(18,8);
    printf(" Enter  Password : ");

    char pw[100];
    scanf("%s",pw);

    /////////////////
    FILE *f1;
    f1=fopen("admin.dat","r"); //opens file in reading mode


    lli CK=0;
    while( fread(&ad,sizeof(ad),1,f1)){     //reads file and compares strings to log in

        if(strcmp(nm,ad.username)==0 && strcmp(pw,ad.password)==0){
            printf("Log in successfull \n");
            CK=1;
            Admin_pannel_main();
            break;
        }

    }

    fclose(f1);//closes file f1


    if(CK==0){
        goto_position_xy(22,10);
        printf(" Wrong User Name Or Password  ");
            goto_position_xy(22,12);
        printf(" Enter Password Again ");
        Sleep(500);
        Admin_pannel();
    }

}



//first window
void first(){
    system("cls");    //clears the console window
    system("color Cf");//sets color to light red

    goto_position_xy(30,1);
    printf("***Welcome To University Management System*** ");

    goto_position_xy(20,2);
    print_n_Character('=',64);

    goto_position_xy(45,4);
    printf(" Enter As : ");

    goto_position_xy(35,6);
    print_n_Character('-',30);

    goto_position_xy(45,8);
    printf(" 1.Admin ");

    goto_position_xy(45,10);
    printf(" 2.Teacher ");

    goto_position_xy(45,12);
    printf(" 3.Student ");

    goto_position_xy(45,14);
    printf(" 4.EXIT ");

    goto_position_xy(35,16);
    print_n_Character('-',30);

    goto_position_xy(35,20);
    printf(" Enter Your Option:  ");

    int a;
    scanf("%d",&a);

    switch(a)  //switches with the value of a;
    {
    case 1:
        Admin_pannel();
        break;
    case 2:
        Teachers_pannel();
        break;
    case 3:
        student_pannel();
        break;
    case 4:
        return 0;
        break;

    }

}



int main ()
{

system("color 5f"); //sets console color purple
welcome(); //welcome function is called
first();


    return 0;
}


//This function fixes output position in console
void goto_position_xy(int x,int y)
{
        COORD c;  //co-ordinate c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); //Sets Console Cursor Position
}


//This function prints n characters
void print_n_Character(char ch,int n)
 {
    while(n--)
    {
        putchar(ch);//prints char ch
    }
 }


 //1907069
