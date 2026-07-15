#include<stdio.h>
#include<string.h>
#include"main.h"
int main(){
    int choice;
    AddressBook.count = 0;
    Load_Person_Data_From_File();
    do{
        printf("***********AddressBook***********\n");
        printf("1. Add Person Details in AddressBook.\n");
        printf("2. Display Person Details in AddressBook.\n");
        printf("3. Update Person Details in AddressBook.\n");
        printf("4. Delete Person Details in AddressBook.\n");
        printf("5. No of Students in AddressBook.\n");
        printf("6. Student Information in AddessBook.\n\n");
        printf("Enter the Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            Add_Person_Details();
            break;
            case 2:
            Display_Person_Details();
            break;
            case 3:
            Update_Person_Details();
            break;
            case 4:
            Delete_Person_Details();
            break;
            case 5:
            No_Students();
            break;
            case 6:
            Info_Student();
            break;
            default:
            printf("Invalid input.\n");
        }
    }while(choice != 0);
    return 0;
}

void Add_Person_Details(){
    if(AddressBook.count == MAX_PERSON){
        printf("AddressBook is FULL.\n\n");
        return;
    }
    printf("Add_Person_Details.\n\n");

    do{
        printf("Enter Name: ");
        scanf(" %49[^\n]",AddressBook.Info[AddressBook.count].name);
    }while(!(Validate_Name(AddressBook.Info[AddressBook.count].name)));

    do{
        printf("Enter PhoneNumber: ");
        scanf(" %19[^\n]",AddressBook.Info[AddressBook.count].phonenumber);
    }while(!(Validate_Phone_Number(AddressBook.Info[AddressBook.count].phonenumber)));

    printf("Enter GmailID: ");
    scanf(" %49[^\n]",AddressBook.Info[AddressBook.count].gmailid);

    /*
    ***************Save  Person Details into a file**********************************
    Mode :
    1. "a"=> it will create new file if doen't exist but keeps Exiasiting content and add new data at the end;
    2. "w"=> it will create new file if doen't exist and erase all the content
    */
    char choice;
    printf("Perform Append[a] or Writing[w] into a file?");
    
    scanf(" %c",&choice);

    if(choice == 'w'){
        Save_Person_Data_to_File(AddressBook.Info[AddressBook.count].name, 
                                AddressBook.Info[AddressBook.count].phonenumber, 
                                AddressBook.Info[AddressBook.count].gmailid,
                                "w");
    }
    else{
        Save_Person_Data_to_File(AddressBook.Info[AddressBook.count].name,
                                 AddressBook.Info[AddressBook.count].phonenumber, 
                                 AddressBook.Info[AddressBook.count].gmailid,
                                 "a");
    }
    AddressBook.count = AddressBook.count+1;
}

void Display_Person_Details(){
    if(AddressBook.count == 0){
        printf("AddressBook is Empty.\n\n");
    }
    for(int i =0; i<AddressBook.count;i++){
        printf("Details of %s:\n\n",AddressBook.Info[i].name);
        printf("Name: %s\n",AddressBook.Info[i].name);
        printf("Phone Number: %s\n",AddressBook.Info[i].phonenumber);
        printf("GmailID: %s\n\n",AddressBook.Info[i].gmailid);
    }
}
void Update_Person_Details(){
    char Search_Name[50];
    int Found_Person =0;
    printf("Enter Person name to Update in AddressBook: ");
    scanf(" %49[^\n]",Search_Name);
    for(int i =0;i<AddressBook.count;i++){
        if(strcmp(AddressBook.Info[i].name,Search_Name)==0){
            printf("Person Details Found.\n");
            printf("Please Enter New Name: ");
            scanf(" %49[^\n]",AddressBook.Info[i].name);
            printf("Please Enter New PhoneNumber: ");
            scanf(" %19[^\n]",AddressBook.Info[i].phonenumber);
            printf("Please Enter New GmailID: ");
            scanf(" %49[^\n]",AddressBook.Info[i].gmailid);
            printf("New Details Updated Successfully.\n");
            Found_Person =1;
            Sync_File_Adressbook();
            break;
        }
    }
    if(Found_Person ==0){
        printf("Person Details Not Available in AddressBook\n\n");
    }
}
void Delete_Person_Details(){
    char Search_Name[50];
    int Delete_Person =0;
    printf("Enter Person name to Delete From AddressBook: ");
    scanf(" %49[^\n]",Search_Name);
    for(int i =0;i<AddressBook.count;i++){
        if(strcmp(AddressBook.Info[i].name,Search_Name)==0){
            printf("Person Details Found.\n");
            for(int j = i; j <(AddressBook.count-1);j++){
                AddressBook.Info[j]= AddressBook.Info[j+1];
            }
            printf("Deleted Person Details Successfully.\n");
            AddressBook.count = AddressBook.count-1;
            Delete_Person =1;
            Sync_File_Adressbook();
            break;
        }
    }
    if(Delete_Person == 0){
        printf("Person Details Not Available in AddressBook\n\n");
    }
}
void No_Students(){
    printf("Number of Student Available in AddressBook:%d \n\n",AddressBook.count);
}
void Info_Student(){
    char Search_Name[50];
    int Info_Person = 0;
    printf("Enter Person Name to Verify Details From AddressBook: ");
    scanf(" %49[^\n]",Search_Name);
    for(int i =0;i<AddressBook.count;i++){
        if(strcmp(AddressBook.Info[i].name,Search_Name)==0){
            printf("Person Details Found.\n");
            printf("Details of %s:\n\n",AddressBook.Info[i].name);
            printf("Name: %s\n",AddressBook.Info[i].name);
            printf("Phone Number: %s\n",AddressBook.Info[i].phonenumber);
            printf("GmailID: %s\n\n",AddressBook.Info[i].gmailid);
            Info_Person =1;
            break;
        }
    }
    if(Info_Person ==0){
        printf("Person Name is Not Present in the Address Book.\n\n");
    }
}
/*
******************Name_Validation**************************************
Not empty → reject if the string length is zero.
Allowed characters only → letters, spaces, and maybe hyphens/apostrophes.
*/
int Validate_Name(const char *name){
    if(strlen(name) == 0){
        printf("Name should not be Empty.\n");
        return 0;
    }
    for(int i =0; name[i]!='\0';i++){
            if(!(((name[i]>='a') && (name[i]<='z'))||
            ((name[i]>='A')&&(name[i]<='Z'))||
            (name[i] ==' ')||(name[i]=='-')||(name[i] == '\''))){
                printf("It is Not Valid Character %c in name:\n ",name[i]);
                return 0;
            }
    }
    return 1;
}
/*
**************PhonNumberValidation**************************
Not empty → must contain at least one digit.
Digits only → reject letters or symbols.
Length check → typical phone numbers are between 7–15 digits.
*/
int Validate_Phone_Number(const char *phonenumber){
    if(strlen(phonenumber) == 0){
        printf("Phone_Number should not be Empty.\n");
        return 0;
    }
    int Digit_Count =0;
    for(int i =0; phonenumber[i] !='\0';i++){
        if((phonenumber[i]>='0') && (phonenumber[i] <='9')){
            Digit_Count++;
        }
        else{
            printf("It is Not Valid Character %c in phonenumber:\n ",phonenumber[i]);
            return 0;
        }
    }
    if((Digit_Count<7)||(Digit_Count>15)){
        printf("Phone number must contain 7–15 digits.\n");
        return 0;
    }
    return 1;
}
/*
**************GmailValidation**************************
Not empty → must contain at least one digit.
Excatly one @ and it Can't be First or Last character.
Atleast one dot(.)should appear After @
Domain Validation -> @gmail.com
Allowed Letters, Digits, Underscore(_),Dot(.),hyphen(-),and Single @
*/
/*
int Validate_Gmail_ID(const char *GmailID){
    if(strlen(GmailID) == 0){
        printf("GmailID should not be Empty.\n");
        return 0;
    }
    for(int i =0; GmailID[i] != '\0'; i++){
        //Allowed Characters
        if(!(((GmailID[i]>='a') && (GmailID[i]<='z'))||
            ((GmailID[i]>='A')&&(GmailID[i]<='Z'))||
            ((GmailID[i]>='0')&&(GmailID[i]<='9'))||
            (GmailID[i] == '@')||(GmailID[i] == '.')||
            (GmailID[i] =='-')||(GmailID[i] == '_'))){
                printf("It is Not Valid Character %c in GmailID:\n ",GmailID[i]);
                return 0;
        }
        //Extactly one @ Should not be Start or End Position
        
        
        //Atleast one dot(.)should appear After @
        
        // Strict Gmail Domain CHeck
    }
}
*/
/* Save Person Details into File*/
void Save_Person_Data_to_File(const char *name, 
                            const char *phonenumber, 
                            const char *gmailid, 
                            const char *Mode){

    FILE *fp;
    // File Opened in Append Format;
    fp = fopen("StudentData.txt", Mode);
    if(fp == NULL){
        printf("FIle not created in the Repo.\n");
        return;
    }
    // Writing the Data into File
    fprintf(fp, "Name: %s\nPhonenumber: %s\nGmailid: %s\n\n",
                name, phonenumber, gmailid);
    fclose(fp);
    printf("%s Person Details Saved into a File.\n\n", name);
}
void Load_Person_Data_From_File(){
    FILE *fp;
    fp = fopen("StudentData.txt","r");
    if(fp == NULL){
        printf("File Not Available in the Repo.\n");
        return;
    }
    while (fscanf(fp,
              "Name: %49[^\n]\nPhonenumber: %19[^\n]\nGmailid: %49[^\n]\n\n",
              AddressBook.Info[AddressBook.count].name,
              AddressBook.Info[AddressBook.count].phonenumber,
              AddressBook.Info[AddressBook.count].gmailid) == 3){

                        AddressBook.count++;
                        if(AddressBook.count >= MAX_PERSON){
                            printf("AddressBook is FULL.\n\n");
                            break;
                        }
              }
}
void Sync_File_Adressbook(){
    FILE *fp;
    fp = fopen("StudentData.txt","w");
    if(fp == NULL){
        printf("File Not Available in the Repo.\n");
        return;
    }
    for(int i =0;i<AddressBook.count;i++){
        fprintf(fp, "Name: %s\nPhonenumber: %s\nGmailid: %s\n\n",
              AddressBook.Info[i].name,
              AddressBook.Info[i].phonenumber,
              AddressBook.Info[i].gmailid);
    }
    fclose(fp);
    printf("File synchronized with current AddressBook data.\n\n");
}