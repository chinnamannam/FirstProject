#include<stdio.h>
#include<string.h>
#include"main.h"
int main(){
    int choice;
    AddressBook.count = 0;
    do{
        printf("Enter the Choice:\n");
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
        printf("AddressBook is FULL.\n");
    }
    printf("Add_Person_Details.\n\n");
    printf("Enter Name: ");
    scanf(" %49[^\n]",AddressBook.Info[AddressBook.count].name);
    printf("Enter PhoneNumber: ");
    scanf(" %19[^\n]",AddressBook.Info[AddressBook.count].phonenumber);
    printf("Enter GmailID: ");
    scanf(" %49[^\n]",AddressBook.Info[AddressBook.count].gmailid);
    AddressBook.count = AddressBook.count+1;
}
void Display_Person_Details(){
    if(AddressBook.count == 0){
        printf("AddressBook is Empty.\n");
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
    int Found_Person;
    printf("Enter Person name to Update in AddressBook:\n");
    scanf(" %49[^\n]",Search_Name);
    for(int i =0;i<AddressBook.count;i++){
        Found_Person =0;
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
            break;
        }
    }
    if(Found_Person ==0){
        printf("Person Details Not Available in AddressBook\n");
    }
}
void Delete_Person_Details(){
    char Search_Name[50];
    int Delete_Person;
    printf("Enter Person name to Delete From AddressBook:\n");
    scanf(" %49[^\n]",Search_Name);
    for(int i =0;i<AddressBook.count;i++){
        Delete_Person =0;
        if(strcmp(AddressBook.Info[i].name,Search_Name)==0){
            printf("Person Details Found.\n");
            for(int j = i; j <(AddressBook.count-1);j++){
                AddressBook.Info[j]= AddressBook.Info[j+1];
            }
            printf("Deleted Person Details Successfully.\n");
            AddressBook.count = AddressBook.count-1;
            Delete_Person =1;
            break;
        }
    }
    if(Delete_Person == 0){
        printf("Person Details Not Available in AddressBook\n");
    }
}
void No_Students(){
    printf("Number of Student Available in AddressBook:%d \n",AddressBook.count);
}
void Info_Student(){
    char Search_Name[50];
    int Info_Person = 0;
    printf("Enter Person Name to Verify Details From AddressBook:\n");
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
        printf("Person Name is Not Present in the Address Book.\n");
    }
}
