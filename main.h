#define MAX_PERSON 100

struct Details{
    char name[50];
    char phonenumber[20];
    char gmailid[50];
};

struct Data{
    struct Details Info[MAX_PERSON];
    int count;
}AddressBook;

void Add_Person_Details();
void Display_Person_Details();
void Update_Person_Details();
void Delete_Person_Details();
void No_Students();
void Info_Student();
