#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996).
void printfile(int en1, int num_of_engineers);
bool login(int num_of_en);
void  feedbackenginer(int num_engineer, char* name);

#define NUM_OF_USERS 11 

FILE* fp1;

int items;

#define MAX 50

struct Date
{
    int hour;
    int minute;
    int wday;
    int month;
} date[3];


struct feedbackuser {
    char  shortanswerq1[50];
    char  shortanswerq2[50];
    char  shortanswerq3[50];
    int   rankq1;


};

struct User {

    char  name[50];
    int  location;
    int  productID;
    int  problem;//1 
    int    rank;
    int   SerialNumber;
    Date date[3];


}user[NUM_OF_USERS];

int n = 0;
struct engineer {
    User u[11];
    char  user1[50];
    char  password[50];
    int location;
    int  productID;//123tv
    int    rank;
    int   problem;
    int num_of_users;
    int date[3];
    struct feedbackuser feedbackuser[NUM_OF_USERS];

}en[NUM_OF_USERS];


struct feedbackenginer {
    char  shortanswerqe1[50];
    char  shortanswerqe2[50];
    char  shortanswerqe3[50];
    int num_of_problem_solved;

}fbe[NUM_OF_USERS];

FILE* fpr1, * fpr2, * fpw1, * fpw2;
int counter = 0;
FILE* fprh, * fpwh;

FILE* fpr4, * fpw4;
FILE* fpr3, * fpw3;

FILE* fpr6, * fpw6;

FILE* fpr5, * fpw5;

FILE* fpr9, * fpw9;
FILE* fpri, * fpwi;
FILE* fpr7, * fpw7;

FILE* fprr, * fpwr;
FILE* fpr10, * fpw10;

struct engineer temp[11];



void cleanString(char* s) {
    //Clean the \n from the string
    int j = strlen(s);
    s[j - 1] = 0;
}

int time3()
{
    time_t rawtime;
    struct tm* time_;
    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i %i %i %i\n", time_->tm_hour, time_->tm_min + 30,
        time_->tm_sec, time_->tm_mday, time_->tm_mon + 1,
        time_->tm_year + 1900);
    return 1;

}

void red() {
    printf("\033[1;31m");
}

void blue() {
    printf("\033[0;34m");
}

void reset() {
    printf("\033[0m");
}

void yellow() {
    printf("\033[1;33m"); // the color yellow for a printing code in stidio  ( קלט )
}


void fpr2write(int num_of_en) { //write from en,// to write into engineer`s file .
    fopen_s(&fpr2, "engineer.bin", "wb"); // writing & reading  , it wipe everything and adds.
    if (fpr2 == NULL)
        printf("error");
    fwrite(&en, sizeof(struct engineer), num_of_en, fpr2);// to insert everything from engineer to fpr2.
    fclose(fpr2);
}
void fpw2read(int num_of_en) // read from enineer.bin// to read from engineer file.
{
    //Open the file to read
    fopen_s(&fpw2, "engineer.bin", "rb");// to open the file for reading only.
    if (fpw2 == NULL)
        printf("error");
    //Read all the structs from the file (5 structs)
    fread(&en, sizeof(struct engineer), num_of_en, fpw2);
    fclose(fpw2);
}

void newengineer(int num_of_engineer) {  //  Gets number of engineer 
    //t[0].details = { '0' };
    for (int n = 0; n < num_of_engineer; n++) {
        blue();
        printf("Get the name ");
        fgets(en[n].user1, 20, stdin);  // to scan from string .
        fgets(en[n].user1, 20, stdin);
        cleanString(en[n].user1);
        printf("Get the password ");
        fgets(en[n].password, 20, stdin);
        cleanString(en[n].password);
        printf("Get the location ");
        printf("1.Zefat 2.Tibrieas 3.Nahriya 4.akko\n");
        scanf_s("%d", &en[n].location);
        printf("Get the productID ");
        printf("1.TV & PC 2.W-Machine 3.Microwave 4.AC  5.Lamps & LEDS \n ");
        printf("6.Vaccum 7.Water Heater 8.Fridge 9.Tech support 10.Tech support \n ");
        scanf_s("%d", &en[n].productID);
        printf("Get the problem ");
        scanf_s("%d", &en[n].problem);
        printf("Get the rank ");
        scanf_s("%d", &en[n].rank);
        char ch = getchar();
        reset();

    }
    fpr2write(num_of_engineer); // to write the engineer array into engineer file.

    //print
    for (int n = 0; n < num_of_engineer; ++n)
    {
        printf("%s - %s - %d -%d -%d - %d\n", en[n].user1, en[n].password, en[n].location, en[n].problem, en[n].productID, en[n].rank);

    }



}


void fprwrite(int num_of_user) { // write users. // write to the user`s file.
    fopen_s(&fpr1, "user.bin", "wb");
    if (fpr1 == NULL)
        return;
    fwrite(&user, sizeof(struct User), num_of_user, fpr1);
    fclose(fpr1);
    return;
}
void fpread(int num_of_user) // reaed users
{

    //Open the file to read
    fopen_s(&fpw1, "user.bin", "rb");
    if (fpw1 == NULL)
        printf("error");
    //Read all the structs from the file (5 structs)
    fread(&user, sizeof(struct User), num_of_user, fpw1);
    fclose(fpw1);

}


int time1() {

    time_t rawtime;
    struct tm* time_;
    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i %i %i %i\n", time_->tm_hour, time_->tm_min + 10,
        time_->tm_sec, time_->tm_mday, time_->tm_mon + 1,
        time_->tm_year + 1900);

    return 1;
}

int time2()
{

    time_t rawtime;
    struct tm* time_;
    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i %i %i %i\n", time_->tm_hour + 2, time_->tm_min,
        time_->tm_sec, time_->tm_mday, time_->tm_mon + 1,
        time_->tm_year + 1900);

    return 1;
}

void newuser(int num_of_user) {
    for (int n = 0; n < num_of_user; n++) {
        red();
        printf("Get the name ");
        fgets(user[n].name, 20, stdin);
        fgets(user[n].name, 20, stdin);
        cleanString(user[n].name);
        printf("Get the location ");
        printf("Get the location ");
        printf("1.Zefat 2.Tibrieas 3.Nahriya 4.akko\n");
        scanf_s("%d", &en[n].location);
        printf("Get the productID ");
        printf("1.TV & PC 2.W-Machine 3.Microwave 4.AC  5.Lamps & LEDS \n ");
        printf("6.Vaccum 7.Water Heater 8.Fridge 9.Tech support 10.Tech support \n ");
        scanf_s("%d", &en[n].productID);
        printf("Get the problem ");
        scanf_s("%d", &user[n].problem);
        printf("Get the rank ");
        scanf_s("%d", &user[n].rank);
        printf("Get the serialnum ");
        scanf_s("%d", &user[n].SerialNumber);
        printf("Time & date to be fixed ");
        scanf_s("%d:%d %d %d", &user[n].date[0], &user[n].date[1], &user[n].date[2], &user[n].date[3]); // hours - minutes - days - months 
        char ch = getchar();
        if (user[n].rank == 3)  // rank 3= critical problem.
        {
            yellow();
            printf("Sorry to hear about your porblem, We will be at your place exactly at ");
            time3();
            reset();

        }
        if (user[n].rank == 2)
        {
            yellow();
            printf("Sorry to hear about your porblem, We will be at your place exactly at ");
            time2();
            reset();

        }
        if (user[n].rank == 1)
        {
            yellow();
            printf("Our technical support will call you exactly at ");
            time1();
            reset();
        }
    }

    reset();
    fprwrite(num_of_user);
    for (n = 0; n < num_of_user; ++n)
    {
        //printf("%s- %d -%d -%d- %d -%d\n", user[n].name, user[n].location, user[n].productID, user[n].problem, user[n].rank, user[n].SerialNumber);
    }
}


int time() {

    time_t rawtime;
    struct tm* time_;
    time(&rawtime);
    time_ = localtime(&rawtime);

    if (time_->tm_hour < 16 && time_->tm_hour < 8)
        printf("if you dont have a critical problem , we have to fix it later\n");
    if (time_->tm_wday == 6)
        printf("sorry we dont work in Saturdays , be patient till tomorrow");

    else
    {
        printf("%i:%i:%i %i %i %i\n", time_->tm_hour, time_->tm_min,
            time_->tm_sec, time_->tm_mday, time_->tm_mon + 1,
            time_->tm_year + 1900);
    }
    return 1;
}

void updateEngineer(int num_of_engineer) {
    fopen_s(&fpr2, "engineer.bin", "wb");
    if (fpr2 == NULL)
        printf("error");
    fwrite(&en, sizeof(struct engineer), num_of_engineer, fpr2);
    fclose(fpr2);
}








void fp3read_en(int num_of_en, char* name) {

    fopen_s(&fprh, name, "rb");
    if (fprh == NULL)
        printf("error");
    fread(&en[num_of_en], sizeof(struct engineer), 1, fprh);
    fclose(fprh);
    //Open the file to read
}
void fp3write_en(int num_of_en, char* name){

    fopen_s(&fpwh, name, "wb");
    if (fpwh == NULL)
        printf("error");
    //Read all the structs from the file (5 structs)
    fwrite(&en[num_of_en], sizeof(struct engineer), 2, fpwh);
    fclose(fpwh);
}
/*
void updateEngineer(int num_of_en, char* name) {
    fopen_s(&fprh, name, "wb");
    fwrite(&en[num_of_en], sizeof(struct engineer), 1, fprh);
    fclose(fprh);

}
*/

void updateu(int en1, int us, int num_of_engineer, int num_of_user) { // update only one engineer and writing
    fpw2read(num_of_engineer);
    fpread(num_of_user);
    /* int j;
     for(j=0;j<3;j++){
         if (en[i].u[j].name == NULL)
            break;

     }*/
    for (int i = 0; i < en[en1].num_of_users; i++) {
        if(!strcmp(user[us].name,en[en1].u[i].name))
            return;
    }
    int avilable = en[en1].num_of_users;// find the first free place in en
    
    strcpy_s(en[en1].u[avilable].name, user[us].name);
    en[en1].u[avilable].location = user[us].location;

    en[en1].u[avilable].productID = user[us].productID;
    en[en1].u[avilable].problem = user[us].problem;

    en[en1].u[avilable].rank = user[us].rank;
    en[en1].u[avilable].SerialNumber = user[us].SerialNumber;
    en[en1].num_of_users++;
    updateEngineer(num_of_engineer);

}

void print(char* name, int num_of_engineer)
{
    for (int i = 0; i < num_of_engineer; i++)
    {
        if (!strcmp(name, en[i].user1))
            printfile(i, num_of_engineer);
    }
}

void printfile(int en1, int num_of_engineers) {

    fpw2read(num_of_engineers);
    for (int j = 0; j < en[en1].num_of_users; j++){
         printf("%s - %d - %d -%d -%d - %d\n", en[en1].u[j].name, en[en1].u[j].location, en[en1].u[j].productID,
            en[en1].u[j].problem, en[en1].u[j].rank, en[en1].u[j].SerialNumber);
    }

}


void update(char ** name, int num_of_engineer,int num_of_user) {
    fpw2read(num_of_engineer);
    fpread(num_of_user);
    for (int i = 0; i < num_of_engineer; i++) // new en
    {
        for (int j = 0; j < num_of_user; j++) // user
        {
            if (user[j].location == en[i].location && user[j].productID == en[i].productID) {
                updateu(i, j, num_of_engineer, num_of_user);
                //printfile(i, num_of_engineer);
               
            }
        }
        // write to en file 
    }
    updateEngineer(num_of_engineer);

}

void main() {
    int user = 0; 
    int num_of_en = 2;
    int num_of_user = 3;
    char* names[2] = { (char*)"hala.bin",(char*)"rana.bin" };
    char name[50];
    time();
    printf("if you want to get new data press 0, is you  just print press 1 \n");
    scanf_s("%d", &user);
    if (user == 0)
    {
        //   newengineer(num_of_en);
        newengineer(num_of_en);
        newuser(num_of_user);
    }
    else
    {
        fpw2read(num_of_en);
        fpread(num_of_user);
    }
    printf("----------------------------------------------------------");
    //login(num_of_en);
    //newengineer(num_of_en);
    //newuser(num_of_user);

   
    
    //update(names, num_of_en, num_of_user);
    //print(name, num_of_en);
    
    /*if (scanf("%d", &user))
    {
        if (user == 1)
            user();
        else if (user == 0)
            engineer();
    }*/
      //   newengineer();
    
    
}





bool login(int num_of_en) {
    fpw2read(num_of_en);
    int i;
    char user[10];
    char password[10];
    bool login = false;
    printf("enter username\n");
    fgets(user, sizeof(user), stdin);
    fgets(user, sizeof(user), stdin);

    user[strlen(user) - 1] = 0;

    printf("enter pass\n");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = 0;

    for (int i = 0; i < 11; i++) {

        if ((strcmp(user, en[i].user1) == 0) && (strcmp(password, en[i].password) == 0)) {
            print(user, num_of_en);
            feedbackenginer(i,user);
        }
    }
}


FILE* fpf1, * fpf2;


void fpwFwrite(int num_of_feedback, int num_engineer) { //write from en
    fopen_s(&fpf2, "feedbackuser.bin", "wb");
    if (fpf2 == NULL)
        printf("error");
    fwrite(&en[num_engineer].feedbackuser, sizeof(struct feedbackuser), num_of_feedback, fpf2);
    fclose(fpf2);
}

void fpwFread(int num_of_feedback) // read from enineer.bin
{
    //Open the file to read
    fopen_s(&fpf2, "feedbackuser.bin", "rb");
    if (fpf2 == NULL)
        printf("error");
    fread(&en, sizeof(struct feedbackuser), num_of_feedback, fpf2);
    fclose(fpf2);
}

void fpwEwrite(int num_of_feedback, int num_engineer) { //write from en
    fopen_s(&fpf1, "feedbackenginer.bin", "wb");
    if (fpf1 == NULL)
        printf("error");
    fwrite(&en[num_engineer].feedbackuser, sizeof(struct feedbackenginer), num_of_feedback, fpf1);
    fclose(fpf1);
}

void fpwEread(int num_of_feedback) // read from enineer.bin
{
    //Open the file to read
    fopen_s(&fpf1, "feedbackenginer.bin", "rb");
    if (fpf1 == NULL)
        printf("error");
    fread(&en, sizeof(struct feedbackenginer), num_of_feedback, fpf1);
    fclose(fpf1);
}


void feedbackuser(char* user, int num_engineer, int num_user ) {

    
    printf("hello our dear %s,\n your opinion matters to us,\n and we would love to hear from you:\n what kind of electric problem did you had? ",user);
    fgets(en[num_engineer].feedbackuser[num_user].shortanswerq1, 50, stdin);
    fgets(en[num_engineer].feedbackuser[num_user].shortanswerq1, 50, stdin);
    cleanString(en[num_engineer].feedbackuser[num_user].shortanswerq1);
    printf(" ");
    printf("Did our engineer succeeded in fixing your problem?\n ");
    fgets(en[num_engineer].feedbackuser[num_user].shortanswerq2, 50, stdin);
    cleanString(en[num_engineer].feedbackuser[num_user].shortanswerq2);
    printf(" ");
    printf("Did our engineer make it on time?\n & are you happy with the service that our engineer provided to you?");
    fgets(en[num_engineer].feedbackuser[num_user].shortanswerq3, 50, stdin);
    cleanString(en[num_engineer].feedbackuser[num_user].shortanswerq3);
    printf(" ");
    printf("From one to five, how happy are you with the service?");
    printf("1.very bad 2.bad 3.good 4.very good  5.perfect \n ");
    scanf_s("%d", &en[num_engineer].feedbackuser[num_user].rankq1);
    ///
    char ch = getchar();

    fpwFwrite(NUM_OF_USERS, num_engineer);
    //en[num_engineer].feedbackuser[num_user] = fbu[num_user];



}

void  feedbackenginer(int num_engineer,char* name)
{
    int count = 0;
    for (int n = 0; n < NUM_OF_USERS; n++) {
        printf("hello our dears %s,\n your opinion matters to us,\n and we would love to hear from you:\nwhat kind of electric problem did our user had? ",name);
        fgets(fbe[n].shortanswerqe1, 50, stdin);
        fgets(fbe[n].shortanswerqe1, 50, stdin);
        cleanString(fbe[n].shortanswerqe1);
        printf(" ");
        printf("Did you succeeded in fixing the user problem?\n ");
        fgets(fbe[n].shortanswerqe2, 50, stdin);
        cleanString(fbe[n].shortanswerqe2);
        printf(" ");
        printf("Did you have all the equipment needed to fix the user problem?\n if not what kind of equipment missing you in order to fix the problem?");
        fgets(fbe[n].shortanswerqe3, 50, stdin);
        cleanString(fbe[n].shortanswerqe3);
        printf(" ");
        printf("Did you fix the problem? (1:yes, 0:no)");
        scanf_s("%d", &count);
        if (count == 1)
        {
            fbe[num_engineer].num_of_problem_solved++;
            feedbackuser(en[num_engineer].u[n].name, num_engineer, n);
        }


        printf(" ");

        //
        char ch = getchar();

    }
    for (int n = 0; n < NUM_OF_USERS; ++n) { //print
        struct feedbackuser a = en[num_engineer].feedbackuser[n];
        printf("user number : %d \n", n);
        printf("\t%s - %s - %s - %d\n",a.shortanswerq1, a.shortanswerq2, a.shortanswerq3, a.rankq1);
    }
    printf("number of problems solved by engineer is: %d\n ", fbe[num_engineer].num_of_problem_solved);
    fpwEwrite(NUM_OF_USERS, num_engineer);




}
