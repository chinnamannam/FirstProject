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
int Validate_Name(const char *name);
int Validate_Phone_Number(const char *phonenumber);
//int Validate_Gmail_ID(const char *GmailID);
void Save_Person_Data_to_File(const char *name,const char *phonenumber, const char *gmailid,const char *Mode);
void Load_Person_Data_From_File();
void Sync_File_Adressbook();