// function for setting cursor position
void gotoxy(int x, int y)
{
    COORD a;
    a.X = x;
    a.Y = y;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), a);
}
 
// Creating a structure to store data of the user
struct pass {
    char userName[50];
    int date, month, year;
    char pNumber[15];
    char adharNum[20];
    char fName[20];
    char lName[20];
    char fatherName[20];
    char motherName[20];
    char address[50];
    char typeAccount[20];
};
 
// Structure to keep track
// of amount transfer
struct money {
    char usernameTo[50];
    char userpersonFrom[50];
    long int money1;
};
 
struct userpass {
    char password[50];
};
 
// Driver Code
int main()
{
    int i, a, b, choice;
    int passwordlength;
 
    gotoxy(20, 3);
 
    // Creating a Main
    // menu for the user
    printf("WELCOME TO BANKING ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);
 
    printf("**********************************");
    gotoxy(25, 7);
 
    
    printf("1.... CREATE A BANK ACCOUNT");
 
    gotoxy(20, 12);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 14);
    printf("3.... EXIT\n\n");
 
    printf("\n\nENTER YOUR CHOICE..");
 
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        exit(0);
        break;
 
        getch();
    }
}
 
// Function to create accounts
// of users
void account(void)
{
    char password[20];
    int passwordlength, i, seek = 0;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;
 
    struct userpass u2;
 
    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");
 
    // Inputs
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
 
    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fName);
 
    printf("\n\n\nLAST NAME..");
    scanf("%s", &u1.lName);
 
    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fatherName);
 
    printf("\n\nMOTHER's NAME..");
    scanf("%s", &u1.motherName);
 
    printf("\n\nADDRESS..");
    scanf("%s", &u1.address);
 
    printf("\n\nACCOUNT TYPE");
    scanf("%s", &u1.typeAccount);
 
    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);
 
    printf("\n\nADHAR NUMBER");
    scanf("%s", u1.adharNum);
 
    printf("\n\nPHONE NUMBER");
    scanf("%s", u1.pNumber);
 
    printf("\n\nUSERNAME.. ");
    scanf("%s", &u1.userName);
 
    printf("\n\nPASSWORD..");
 
    // Taking password in the form of
    // stars
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
 
    // Writing to the file
    fwrite(&u1, sizeof(u1),
           1, fp);
 
    // Closing file
    fclose(fp);
 
    // Calling another function after successful creation of account
    accountCreated();
}
 
// Successful account creation
void accountCreated(void)
{
    int i;
    char ch;
    system("cls");
    printf("\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
 
    gotoxy(30, 10);
 
    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);
 
    printf("Press enter to login");
 
    getch();
    login();
}
 
// Login function to check
// the username of the user
void login(void)
{
    system("cls");
 
    char username[50];
    char password[50];
 
    int i, j, k;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass u2;
 
    // Opening file of
    // user data
    fp = fopen("username.txt",
               "rb");
 
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }
    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7, 5);
    printf("***********************************************");
 
    gotoxy(35, 10);
    printf("==== LOG IN ====");
 
    // Take input
    gotoxy(35, 12);
    printf("USERNAME.. ");
    scanf("%s", &username);
 
    gotoxy(35, 14);
    printf("PASSWORD");
 
    // Input the password
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
 
        else
            break;
    }
 
    // Checking if username
    // exists in the file or not
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username,
                   u1.username)
            == 0) {
            logins();
            display(username);
        }
    }
 
    // Closing the file
    fclose(fp);
}
 
// Redirect after
// successful login
void logins(void)
{
    int i;
    FILE* fp;
    struct pass u1;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 20000; i++) {
        i++;
        i--;
    }
 
    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");
 
    getch();
}
 
// Display function to show the
// data of the user on screen
void display(char username1[])
{
    system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("username.txt", "rb");
    struct pass u1;
 
    if (fp == NULL) {
        printf("error in opening file");
    }
 
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username1,
                   u1.username)
            == 0) {
            gotoxy(30, 1);
            printf("WELCOME, %s %s",
                   u1.fname, u1.lname);
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(55, 6);
            printf("==== YOUR ACCOUNT INFO ====");
            gotoxy(55, 8);
            printf("***************************");
            gotoxy(55, 10);
            printf("NAME..%s %s", u1.fname,
                   u1.lname);
 
            gotoxy(55, 12);
            printf("FATHER's NAME..%s %s",
                   u1.fathname,
                   u1.lname);
 
            gotoxy(55, 14);
            printf("MOTHER's NAME..%s",
                   u1.mothname);
 
            gotoxy(55, 16);
            printf("ADHAR CARD NUMBER..%s",
                   u1.adharnum);
 
            gotoxy(55, 18);
            printf("MOBILE NUMBER..%s",
                   u1.pnumber);
 
            gotoxy(55, 20);
            printf("DATE OF BIRTH.. %d-%d-%d",
                   u1.date, u1.month, u1.year);
 
            gotoxy(55, 22);
            printf("ADDRESS..%s", u1.address);
 
            gotoxy(55, 24);
            printf("ACCOUNT TYPE..%s",
                   u1.typeaccount);
        }
    }
 
    fclose(fp);
 
    gotoxy(0, 6);
 
    // Menu to perform different
    // actions by user
    printf(" HOME ");
    gotoxy(0, 7);
    printf("******");
    gotoxy(0, 9);
    printf(" 1....CHECK BALANCE");
    gotoxy(0, 11);
    printf(" 2....TRANSFER MONEY");
    gotoxy(0, 13);
    printf(" 3....LOG OUT\n\n");
    gotoxy(0, 15);
    printf(" 4....EXIT\n\n");
 
    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalances(username1);
        break;
 
    case 2:
        transferMoney();
        break;
 
    case 3:
        logout();
        login();
        break;
 
    case 4:
        exit(0);
        break;
    }
}
 
// Function to transfer
// money from one user to
// another
void transferMoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
 
    // Opening file in read mode to
    // read user's username
    fp = fopen("username.txt", "rb");
 
    // Creating a another file
    // to write amount along with
    // username to which amount
    // is going to be transfered
    fm = fopen("mon.txt", "ab");
 
    gotoxy(33, 4);
    printf("---- TRANSFER MONEY ----");
    gotoxy(33, 5);
    printf("========================");
 
    gotoxy(33, 11);
    printf("FROM (your username).. ");
    scanf("%s", &usernamet);
 
    gotoxy(33, 13);
    printf(" TO (username of person)..");
    scanf("%s", &usernamep);
 
    // Checking for username if it
    // is present in file or not
    while (fread(&u1, sizeof(u1),
                 1, fp))
 
    {
        if (strcmp(usernamep,
                   u1.username)
            == 0) {
            strcpy(m1.usernameto,
                   u1.username);
            strcpy(m1.userpersonfrom,
                   usernamet);
        }
    }
    gotoxy(33, 16);
 
    // Taking amount input
    printf("ENTER THE AMOUNT TO BE TRANSFERED..");
    scanf("%d", &m1.money1);
 
    // Writing to the file
    fwrite(&m1, sizeof(m1),
           1, fm);
 
    gotoxy(0, 26);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
 
    gotoxy(0, 28);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");
 
    gotoxy(0, 29);
    printf("transfering amount, Please wait..");
 
    gotoxy(10, 27);
    for (i = 0; i < 70; i++) {
        for (j = 0; j < 1200000; j++) {
            j++;
            j--;
        }
        printf("*");
    }
 
    gotoxy(33, 40);
    printf("AMOUNT SUCCESSFULLY TRANSFERED....");
    getch();
 
    // Close the files
    fclose(fp);
    fclose(fm);
 
    // Function to return
    // to the home screen
    display(usernamet);
}
 
// Function to check balance
// in users account
void checkbalances(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;
 
    // Opening amount file record
    fm = fopen("mon.txt", "rb");
 
    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;
 
    gotoxy(30, 2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(k, l);
    printf("S no.");
    gotoxy(m, n);
    printf("TRANSACTION ID");
    gotoxy(u, v);
    printf("AMOUNT");
 
    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1),
                 1, fm)) {
        if (strcmp(username2,
                   m1.usernameto)
            == 0) {
            gotoxy(k, ++l);
            printf("%d", i);
            i++;
            gotoxy(m, ++n);
            printf("%s", m1.userpersonfrom);
 
            gotoxy(u, ++v);
            printf("%d", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }
 
    gotoxy(80, 10);
    printf("TOTAL AMOUNT");
 
    gotoxy(80, 12);
    printf("%d", summoney);
 
    getch();
 
    // Closing file after
    // reading it
    fclose(fm);
    display(username2);
}
 
// Logout function to bring user to the login screen
void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out");
 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
    }
 
    gotoxy(30, 10);
    printf("Sign out successfully..\n");
 
    gotoxy(0, 20);
    printf("press any key to continue..");
 
    getch();
}