#include <stdio.h>
#include <string.h>

#define DB_PATH "./students.dat"
#define MAX 100


typedef struct Student Student;
typedef struct StudentDB StudentDB;

static void addStudents(StudentDB *self);
static void displayStudents(StudentDB *self);
static void searchStudent(StudentDB *self,int roll);
static void deleteAllRecords(StudentDB *self);
static _Bool reOpenDB(StudentDB *self);
static void updateByRoll(StudentDB *self);
static void updateHelper(Student *stu);
static void deleteByRoll(StudentDB *self,int roll);



struct Student{
    int roll;
    char name[MAX];
    float marks;
};

struct StudentDB{
    FILE *db;
    _Bool canClose;
    void (*addStudents)(StudentDB *self);
    void (*displayStudents)(StudentDB *self);
    void (*searchStudent)(StudentDB *self,int roll);
    void (*deleteAllRecords)(StudentDB *self);
    _Bool (*reopenDB)(StudentDB *self);
    void (*updateByRoll)(StudentDB *self);
    void (*deleteByRoll)(StudentDB *self,int roll);
};

int main(void){
    StudentDB stb = {
        .db = fopen(DB_PATH,"ab+"),
        .canClose = 1,
        .addStudents = addStudents,
        .displayStudents = displayStudents,
        .searchStudent = searchStudent,
        .deleteAllRecords = deleteAllRecords,
        .reopenDB = reOpenDB,
        .updateByRoll = updateByRoll,
        .deleteByRoll = deleteByRoll
    };
    int roll;
    if (stb.db == NULL){
        perror("Error while opening file");
        return 1;
    }
    StudentDB *self = &stb;
    int option;
    _Bool run;
    printf("======= Student Database =======\n1. Add Students\n2. Display All Students\n3. Search Student by Roll No\n4. Delete All Records\n5. Update data by Roll Num\n6. Delete a data by Roll\n7. Exit\n-------------------------------\n");
    do {
        run = 1;
        printf("Enter your choice: ");
        scanf("%d",&option);
        
        switch (option){
            case 1:
                stb.addStudents(self);
                break;
            case 2:
                stb.displayStudents(self);
                break;
            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d",&roll);
                stb.searchStudent(self,roll);
                break;
            case 4:
                stb.deleteAllRecords(self);
                break;
            case 5:
                stb.updateByRoll(self);
                break;
            case 6:
                printf("Enter the roll you need to delete: ");
                scanf("%d",&roll);
                stb.deleteByRoll(self,roll);
                break;
            case 7:
                run = 0;
                printf("Exiting the DataBase.....\n");
                break;
            default:
                printf("Invalid input, available options are (1,2,3,4,5)\n");
        }
        putchar('\n');
    } while (run);

    if (stb.canClose){
        printf("Closing the DataBase.\n");
        if (fclose(stb.db) == EOF){
            perror("error while closing DataBase.");
            return 1;
        };
    }
    return 0;
}

void addStudents(StudentDB *self){
    if (!self->canClose && !self->reopenDB(self)) return;
    Student stu;
    printf("Enter Roll No: ");
    scanf("%d",&stu.roll);
    while(getchar() != '\n');
    printf("Enter Name: ");
    fgets(stu.name,sizeof(stu.name),stdin);
    stu.name[strcspn(stu.name,"\n")] = '\0';
    printf("Enter Marks: ");
    scanf("%f",&stu.marks);

    size_t res = fwrite(&stu,sizeof(Student),1,self->db);

    if (res != 1){
        perror("Error while adding student.");
    }else{
        printf("✅ Student record added successfully!\n");
    }
}

void displayStudents(StudentDB *self){
    if (!self->reopenDB(self)) return;    
    Student stu;
    while(fread(&stu,sizeof(Student),1,self->db) == 1){
        printf("Roll: %d | Name: %s | Marks: %.2f\n",stu.roll,stu.name,stu.marks);
    }
}

void searchStudent(StudentDB *self,int roll){
    if (!self->reopenDB(self)) return;
    Student stu;

    while (fread(&stu,sizeof(Student),1,self->db) == 1){
        if (stu.roll == roll){
            printf("Found: Roll: %d | Name: %s | Marks: %.2f\n",stu.roll,stu.name,stu.marks);
            return;
        }
    }
    printf("Roll: %d was not in the DataBase.\n",roll);
}

void deleteAllRecords(StudentDB *self){
    if (!self->canClose){
        perror("Records are already empty");
        return;
    }
    printf("Closing the DataBase.\n");
    if (fclose(self->db) == EOF){
        perror("error while closing DataBase.");
    };
    if (remove(DB_PATH)){
        perror("Error while removing file");
        return;
    }
    self->canClose = 0;
    self->db = NULL;
    printf("⚠️ All records deleted successfully!\n");
}

_Bool reOpenDB(StudentDB *self){
    if (self->canClose){
        rewind(self->db);
    }else{
        self->db = fopen(DB_PATH,"ab+");
        if (self->db == NULL){
            perror("Error while reopening the DataBase");
            return 0;
        }
        self->canClose = 1;
    }
    return 1;
}

void updateByRoll(StudentDB *self){
    if (!self->canClose) {
        perror("Nothing in the file to update");
        return ;
    }
    if (fclose(self->db)){
        perror("Error while closing append mode");
        return;
    }

    if ((self->db = fopen(DB_PATH,"rb+"))==NULL){
        perror("Error opening the file to update");
        return;
    }

    Student stu;
    int roll;
    printf("Enter the Roll No you want to update: ");
    scanf("%d",&roll);
    _Bool flag = 1;
    while(fread(&stu,sizeof(Student),1,self->db) ==1){
        if (stu.roll == roll){
            updateHelper(&stu);
            flag = 0;
            if (fseek(self->db,-sizeof(stu),SEEK_CUR)){
                perror("failed to seek");
                break;
            }
            if (fwrite(&stu,sizeof(stu),1,self->db) != 1){
                perror("Error while updating the db");
                break;
            }
            printf("Successfully updated\n");
            break;
        }
    }

    if (fclose(self->db)){
        perror("Error while closing update db");
    }
    if ((self->db = fopen(DB_PATH,"ab+")) == NULL){
        perror("Error while reopening in append mode");
    }
    if (flag){
        printf("Roll number is not in DB\n");
    }
}


void updateHelper(Student *stu){
    printf("Enter the updated name of the student: ");
    while(getchar()!='\n');
    fgets(stu->name,sizeof(stu->name),stdin);
    stu->name[strcspn(stu->name,"\n")] = '\0';
    printf("Enter the updated mark of the student: ");
    scanf("%f",&stu->marks);
}


void deleteByRoll(StudentDB *self,int roll){
    if (!self->canClose){
        perror("Data base is empty");
        return;
    }
    Student stu;
    _Bool flag = 1;
    char tempDBPath[] = "./temp.dat";
    FILE *tempFile = fopen(tempDBPath,"ab+");
    rewind(self->db);
    while (fread(&stu,sizeof(stu),1,self->db) == 1){
        if (stu.roll != roll){
            if (fwrite(&stu,sizeof(stu),1,tempFile)!=1){
                perror("Error while deleting data");
                if (fclose(tempFile)){
                    perror("Error while closing temp file");
                }
                if (remove(tempDBPath)){
                    perror("Error while removing temp file");
                }
                return;
            }
        }else flag = 0;
    }

    if (flag){
        printf("Roll num %d was not in DB\n",roll);
    }
    if (fclose(self->db)){
        perror("Error while closing Main DB");
    }
    if (remove(DB_PATH)){
        perror("Error while removing the old file");
    }
    if (fclose(tempFile)){
        perror("Error while closing temp DB");
    }
    if (rename(tempDBPath,DB_PATH)){
        perror("Error while renaming the db");
    }
    if ((self->db = fopen(DB_PATH,"ab+")) == NULL){
        perror("Error while opening DB");
    }
    printf("data transfered successfully\n");
}



