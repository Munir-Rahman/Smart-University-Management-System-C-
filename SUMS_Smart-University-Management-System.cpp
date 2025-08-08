//Developed By Munir Rahman Rahmani
#include<iostream>
#include<string.h>
#include<string>
#include<iomanip>
#include<stdlib.h>//For Opening External Files in Code blocks
#include<fstream>//For Files Handling
#include<cstdio>//For File Handling to Print All Data From File
using namespace std;

const int TeacherNum=1000,StudentNum=1000,AdminNum=1;
//Use to Show how many Teachers and Students are Added
int TAdded=0;
int SAdded=0;
//Count the Feedbacks from Student
int FeedbackNum=0;
//It Will Increment When You Add Teacher and ID is Auto Created Like(TC-1-1A)
int TID=1;
//It Will Increment When You Add Student and ID is Auto Created Like(CS-1-1M)
int SID=1;
//This is the count of message which the Students and Teachers send to Admin
int StudentMessage=0;
//This Variables Count the New Messages of Student that Admin and Teachers Send
int NewMessagesofStudent=0,NewTeachertoStudent=0,NewAdmintoStudent=0;
//This Count the New Messages of Admin That Students Send
int NewtoAdmin=0;
//New Messages to Teacher from Students
int NewStudenttoTeacher=0;
//This is the  count the of message that the Students send to Teachers
int MessagesTC=0;
//This is the  count the of message that the Teachers send to Students
int MessagesST=0;
//How much Messages come it Show to student and teacher if Admin send message to Teacher or Student it will increment
int Stmessage=0,TCmessage=0;
//this Count the Number of Messages to Admin from Student and Teacher
int fromSTtoAdm=0,fromTCtoAdm=0;
//This Count Messages from Admin and Students to Teacher
int fromSTtoTC=0,fromADMtoTC=0;
//This Count Messages from Admin and Teacher to Student
int fromADMtoST=0,fromTCtoST=0;
//This is The Number of Projects That Teacher Give to Student and it Will Increment When Teacher Give Project to Student
int ProjectNum=1;

//Abstract Class
class User{
public:
    string Username,LastName,Gender,ID;
    string Phone,Email;
    int Age;
};

//STUDENT CLASS
class Student:public User{
private:
    string Password;
public:
    string FName;
    int Semester;
    //Attendance will be Store in 9 months and 30 days
    char Attendance[9][30];
    char AttendanceSub1[9][30],AttendanceSub2[9][30],AttendanceSub3[9][30],AttendanceSub4[9][30],AttendanceSub5[9][30];
    //Attendance Will be Inrease When Attendance Take
    int AttendanceSub1_Day=0,AttendanceSub2_Day=0,AttendanceSub3_Day=0,AttendanceSub4_Day=0,AttendanceSub5_Day=0;
    int AttendanceSub1_Month=0,AttendanceSub2_Month=0,AttendanceSub3_Month=0,AttendanceSub4_Month=0,AttendanceSub5_Month=0;

    string Faculty,Subjects[5],Shift,Project;
    //Student Can Receive 1000 Messages From Admin and Can Send 1000 Messages Direct to Admin Class Variable
    string TCMessage,AdmMessage;
    int Total,SubjectM[5];
    char SubjectG[5],Grade;
    double Percentage,GPA;
    //Get Password
    void get(string password){
    Password = password;
    }
    //Print Password
    string getPassword(){
    return Password;}
};
//Max Student Objects is 1000
Student Stud[StudentNum];

//TEACHER CLASS
class Teacher : public User{
private:
    string Password;
public:
    string Faculty;
    //Teacher Can Receive 1000 Messages From Admin and Can Send 1000 Messages Direct to Admin Class Variable
    string STMessage,AdmMessage;
    string Subject,Shift;
    int Semester;
    //Enter Password
    void enterpassword(string password){
    Password = password;
    }
    //Print Password
    string getPassword(){
    return Password;
    }
};

//Max Teacher Objects are 1000
Teacher Teach[TeacherNum];
//Use for Heap Memory
//student s[StudentNum]=new student;

//ADMIN CLASS
class Admin:public User{
private:
    string Password;
public:
    //Student Give Rate to System
    int Rate[1000];
    //Admin Can Receive 1000 Feedbacks from Students
    string feedback[1000];
    //Admin can Receive 1000 Messages from TC(Teacher) and ST (Student)
    string MessagefromTC[1000],MessagefromST[1000];
    //Enter Password from User
    void enterpassword(string password){
    Password = password;
    }
    //Print Password
    string getPassword(){
    return Password;}
};

//Max Admin Object are 1 of Admin
Admin Adm[AdminNum];

//For Admin Can Add Teacher
void AddTeacher(){
    int Number;
    string Password,id;
    system("cls");
    cout<<"                  -------------------------------------------------------------"<<endl;
    cout<<"                  ------------------Here You Can Add Teachers------------------"<<endl;
    cout<<"                  -------------------------------------------------------------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"How Many Teachers You Want to Add : ";
    cin>>Number;
    for(int i=0;i<Number;i++){
    system("cls");
    cout<<"-------------------------------------"<<endl;
    cout<<"Enter "<<TAdded+1<<" Teacher Information : "<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Enter UserName : ";
    cin>>Teach[TAdded].Username;
    cout<<"Enter Last Name : ";
    cin>>Teach[TAdded].LastName;
    cout<<"Enter Gender Male/Female : ";
    cin>>Teach[TAdded].Gender;
    id = "TC-"+to_string(TID)+"-1A";
    Teach[TAdded].ID = id;
    TID++;
    cout<<"Enter Age : ";
    cin>>Teach[TAdded].Age;
    cout<<"Enter Phone with Country Code ex.+93 : ";
    cin>>Teach[TAdded].Phone;
    cout<<"Enter Email : ";
    cin>>Teach[TAdded].Email;
    A:
    cout<<"Choose Faculty : \n1:CS(Computer Sciece) \n2:ENG(Engineering)\nChoose : ";
    int Choice;
    cin>>Choice;
    switch(Choice){
    case 1:
    Teach[TAdded].Faculty = "ComputerScience";
    B:
    cout<<"Choose Teaching Subject : \n1: DLD\n2: IT\n3: Programming\n4: Graphics\n5: Mathematics\nChoose : ";
    Choice = 0;
    cin>>Choice;
        switch(Choice){
        case 1:
        Teach[TAdded].Subject = "DLD";
        break;
        case 2:
        Teach[TAdded].Subject = "IT";
        break;
        case 3:
        Teach[TAdded].Subject = "Programming";
        break;
        case 4:
        Teach[TAdded].Subject = "Graphics";
        break;
        case 5:
        Teach[TAdded].Subject = "Mathematics";
        break;
        default:
        cout<<"---------------------------------------"<<endl;
        cout<<"-----Try Again Enter Correct Choice----"<<endl;
        cout<<"---------------------------------------"<<endl;
        system("cls");
        goto B;
        break;
        }
    break;
    case 2:
    Teach[TAdded].Faculty = "Engineering";
        Z:
        cout<<"Choose Teaching Subject : \n1: Calculas\n2: Termodynamic\n3: Chemistry\n4: Drawing\n5: AutoCad\nChoose : ";
        Choice = 0;
        cin>>Choice;
        switch(Choice){
        case 1:
        Teach[TAdded].Subject = "Calculas";
        break;
        case 2:
        Teach[TAdded].Subject = "Termodynamic";
        break;
        case 3:
        Teach[TAdded].Subject = "Chemistry";
        break;
        case 4:
        Teach[TAdded].Subject = "Drawing";
        break;
        case 5:
        Teach[TAdded].Subject = "AutoCad";
        break;
        default:
        cout<<"---------------------------------------"<<endl;
        cout<<"-----Try Again Enter Correct Choice----"<<endl;
        cout<<"---------------------------------------"<<endl;
        system("cls");
        goto Z;
        break;
        }
    break;
    default:
        cout<<"----------------------------------------"<<endl;
        cout<<"----Try Again Enter Correct Choice------"<<endl;
        cout<<"----------------------------------------"<<endl;
        goto A;
    }

    C:
    cout<<"Choose Shift\n1: AM\n2: PM\n3: Both\nChoose : ";
    Choice=0;
    cin>>Choice;
    switch(Choice){
    case 1:
    Teach[TAdded].Shift = "AM";
    break;
    case 2:
    Teach[TAdded].Shift = "PM";
    break;
    case 3:
    Teach[TAdded].Shift = "Both";
    break;
    default:
    goto C;
    break;
    }


    S:
    Choice=0;

    cout<<"Enter Semester : ";
    cin>>Choice;
    if(Choice > 0 & Choice <= 8){
        Teach[TAdded].Semester = Choice;
    }
    else{
        cout<<"------------------------"<<endl;
        cout<<"-Enter Correct Semester-"<<endl;
        cout<<"------------------------"<<endl;
        goto S;
    }
    cout<<"Enter Password : ";
    cin>>Password;
    Teach[TAdded].enterpassword(Password);
    TAdded++;
    }
    system("cls");
    cout<<"-----------------------------------------------"<<endl;
    cout<<"-----------Teacher Added Successfully----------"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}

//For Admin Can Add Student
void AddStudent(){
    int Number,ID=1;
    string Password,id;
    system("cls");
    cout<<"                  -------------------------------------------------------------"<<endl;
    cout<<"                  ------------------Here You Can Add Students------------------"<<endl;
    cout<<"                  -------------------------------------------------------------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"How Many Students You Want to Add : ";
    cin>>Number;
    for(int i=0;i<Number;i++){
    system("cls");
    cout<<"-------------------------------------"<<endl;
    cout<<"Enter "<<SAdded+1<<" Student Information : "<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Enter UserName : ";
    cin>>Stud[SAdded].Username;
    cout<<"Enter Last Name : ";
    cin>>Stud[SAdded].LastName;
    cout<<"Enter F/Name : ";
    cin>>Stud[SAdded].FName;
    cout<<"Enter Gender Male/Female : ";
    cin>>Stud[SAdded].Gender;

    A:
    cout<<"Choose Faculty : \n1:CS(Computer Sciece) \n2:ENG(Engineering)\nChoose : ";
    int Choice;
    cin>>Choice;
    switch(Choice){
    case 1:{
    Stud[SAdded].Faculty = "ComputerScience";
    id = "CS-"+to_string(SID)+"-1M";
    Stud[SAdded].ID = id;
    SID++;
    Stud[SAdded].Subjects[0]="DLD";
    Stud[SAdded].Subjects[1]="IT";
    Stud[SAdded].Subjects[2]="Programming";
    Stud[SAdded].Subjects[3]="Graphics";
    Stud[SAdded].Subjects[4]="Mathematics";
    break;}
    case 2:{
    Stud[SAdded].Faculty = "Engineering";
    id = "EG-"+to_string(SID)+"-1M";
    Stud[SAdded].ID = id;
    SID++;
    Stud[SAdded].Subjects[0]="Calculas";
    Stud[SAdded].Subjects[1]="Termodynamic";
    Stud[SAdded].Subjects[2]="Chemistry";
    Stud[SAdded].Subjects[3]="Drawing";
    Stud[SAdded].Subjects[4]="AutoCad";
    break;}
    default:
        cout<<"----------------------------------------"<<endl;
        cout<<"----Try Again Enter Correct Choice------"<<endl;
        cout<<"----------------------------------------"<<endl;
        goto A;
    }

    cout<<"Enter Age : ";
    cin>>Stud[SAdded].Age;
    cout<<"Enter Phone with Country Code ex.+93 : ";
    cin>>Stud[SAdded].Phone;
    cout<<"Enter Email : ";
    cin>>Stud[SAdded].Email;
    cout<<"Enter Semester : ";
    cin>>Stud[SAdded].Semester;
    cout<<"Enter Shift AM/PM : ";

    C:
    cout<<"Choose Shift\n1: AM\n2: PM\nChoose : ";
    Choice=0;
    cin>>Choice;
    switch(Choice){
    case 1:
    Stud[SAdded].Shift = "AM";
    break;
    case 2:
    Stud[SAdded].Shift = "PM";
    break;
    default:
    goto C;
    break;
    }

    cout<<"Enter Password : ";
    cin>>Password;
    Stud[SAdded].get(Password);
    SAdded++;
    }
    system("cls");
    cout<<"-----------------------------------------------"<<endl;
    cout<<"-----------Student Added Successfully----------"<<endl;
    cout<<"-----------------------------------------------"<<endl;
}

//Admin Can View all Teachers Details
void ViewTeacher(){
    if(TAdded>0){
    for(int i=0;i<TAdded;i++){
    cout<<"No : "<<i+1<<" Teacher Information : "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-----------"<<Teach[i].Username<<" Information-----------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"|User Name : "<<Teach[i].Username<<endl;
    cout<<"|Last Name : "<<Teach[i].LastName<<endl;
    cout<<"|Gender    : "<<Teach[i].Gender<<endl;
    cout<<"|Age       : "<<Teach[i].Age<<endl;
    cout<<"|ID        : "<<Teach[i].ID<<endl;
    cout<<"|Phone     : "<<Teach[i].Phone<<endl;
    cout<<"|Email     : "<<Teach[i].Email<<endl;
    cout<<"|Faculty   : "<<Teach[i].Faculty<<endl;
    cout<<"|Shift     : "<<Teach[i].Shift<<endl;
    cout<<"|Teaching Subject   : "<<Teach[i].Subject<<endl;
    cout<<"|Teaching Semester  : "<<Teach[i].Semester<<endl;
    cout<<"|Password           : "<<Teach[i].getPassword()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    }}
    else{
    system("cls");
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"------------There are 0 Teachers in System-----------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }
    cout<<"_____________________________________________________________________________"<<endl;
}

//Admin Can View Teacher Names & IDs
void TeachNameId(){
    if(TAdded>0){
    for(int i=0;i<TAdded;i++){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-----------------Teachers Information----------------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"No          UserName"<<setw(30)<<"ID       "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<i+1<<"|        "<<setw(11)<<Teach[i].Username<<setw(24)<<Teach[i].ID<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    }}
    else{
    system("cls");
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"------------There are 0 Teachers in System-----------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }
    cout<<"_____________________________________________________________________________"<<endl;

}

//Admin Can View Students Details
void ViewStudent(){
    if(SAdded>0){
    for(int i=0;i<SAdded;i++){
    cout<<"No : "<<i+1<<" Student Information : "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-----------"<<Stud[i].Username<<" Information--------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"|User Name : "<<Stud[i].Username<<endl;
    cout<<"|Last Name : "<<Stud[i].LastName<<endl;
    cout<<"|F/Name    : "<<Stud[i].FName<<endl;
    cout<<"|Gender    : "<<Stud[i].Gender<<endl;
    cout<<"|Age       : "<<Stud[i].Age<<endl;
    cout<<"|ID        : "<<Stud[i].ID<<endl;
    cout<<"|Phone     : "<<Stud[i].Phone<<endl;
    cout<<"|Email     : "<<Stud[i].Email<<endl;
    cout<<"|Shift     : "<<Stud[i].Shift<<endl;
    cout<<"|Faculty   : "<<Stud[i].Faculty<<endl;
    cout<<"|Semester  : "<<Stud[i].Semester<<endl;
    cout<<"|Password  : "<<Stud[i].getPassword()<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }
    }
    else{
    system("cls");
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"------------There are 0 Students in System-----------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }
    cout<<"_____________________________________________________________________________"<<endl;
}


void StudNameId(){
    if(SAdded>0){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-----------------Students Information----------------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    for(int i=0;i<SAdded;i++){
    cout<<"No          UserName"<<setw(30)<<"ID       "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<i+1<<"|        "<<setw(11)<<Stud[i].Username<<setw(24)<<Stud[i].ID<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    }}
    else{
    system("cls");
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"------------There are 0 Students in System-----------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }
    cout<<"_____________________________________________________________________________"<<endl;
}

//Admin Search for Teacher by ID
void SearchIDT(){
    string ID;
    cout<<"Enter Teacher ID : ";
    cin>>ID;
    for(int i=0;i<TAdded;i++){
        if(ID == Teach[i].ID){
            system("cls");
            cout<<"Teacher by ID : "<<ID<<" Founded."<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"-----------------Teacher Information-----------------------"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"ID               UserName           Faculty        Semester"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<Teach[i].ID<<"          "<<Teach[i].Username<<"      "<<Teach[i].Faculty<<"           "<<Teach[i].Semester<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            return;
        }
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----Teacher did not Found By "<<ID<<" ID"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

//Admin Search for Student by ID
void SearchIDS(){
    string ID;
    cout<<"Enter Student ID : ";
    cin>>ID;
    for(int i=0;i<SAdded;i++){
        if(ID == Stud[i].ID){
            system("cls");
            cout<<"Student by ID : "<<ID<<" Founded."<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"-----------------Student Information-----------------------"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"ID               UserName           Shift        Semester"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<Stud[i].ID<<"          "<<Stud[i].Username<<"        "<<Stud[i].Shift<<"           "<<Stud[i].Semester<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            return;
        }
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----Student did not Found By "<<ID<<" ID"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

//Update Teacher Details
void UpdateTC(){
    string Username;
    int Choice;
    bool Exit=true;
    cout<<"Enter Teacher Username : ";
    cin>>Username;
    for(int i=0;i<TAdded;i++){
        if(Username == Teach[i].Username){
            while(Exit){
            system("cls");
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"---------- Update Mr."<<Teach[i].Username<<" Information---------"<<endl;
            cout<<"--------------------"<<endl;
            cout<<"1: Update UserName "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"2: Update LastName "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"3: Update Age "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"4: Update Phone "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"5: Update Email "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"6: Update Shift "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"7: Update Subject "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"8: Update Semester "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"9: Exit "<<endl;
            cin>>Choice;
            switch(Choice){
            case 1:
            cout<<"Enter New UserName : ";
            cin>>Teach[i].Username;
            cout<<"UserName Change to "<<Teach[i].Username<<" Successfully."<<endl;
            break;
            case 2:
            cout<<"Enter New LastName : ";
            cin>>Teach[i].LastName;
            cout<<"LastName Change to "<<Teach[i].LastName<<" Successfully."<<endl;
            break;
            case 3:
            cout<<"Enter New Age : ";
            cin>>Teach[i].Age;
            cout<<"Age Change to "<<Teach[i].LastName<<" Successfully."<<endl;
            break;
            case 4:
            cout<<"Enter New Phone : ";
            cin>>Teach[i].Phone;
            cout<<"Phone Change to "<<Teach[i].Phone<<" Successfully."<<endl;
            break;
            case 5:
            cout<<"Enter New Email : ";
            cin>>Teach[i].Email;
            cout<<"Email Change to "<<Teach[i].Email<<" Successfully."<<endl;
            break;
            case 6:
            cout<<"Enter New Shift : ";
            cin>>Teach[i].Shift;
            cout<<"Shift Change to "<<Teach[i].Shift<<" Successfully."<<endl;
            break;
            case 7:
            cout<<"Enter New Subject : ";
            cin>>Teach[i].Subject;
            cout<<"Subject Change to "<<Teach[i].Subject<<" Successfully."<<endl;
            break;
            case 8:
            cout<<"Enter New Semester : ";
            cin>>Teach[i].Semester;
            cout<<"Subject Change to "<<Teach[i].Semester<<" Successfully."<<endl;
            break;
            case 9:
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"You Have Successfully Exited from Update Student Profile"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            Exit=false;
            break;
            default:
                cout<<"---------------------------------"<<endl;
                cout<<"Try Again Choose Correct Option!"<<endl;
                cout<<"--------------------------------"<<endl;
                break;
            }

        }
        }
    }
}

//Update Student Details
void UpdateST(){
    string Username;
    int Choice;
    bool Exit=true;
    cout<<"Enter Student Username : ";
    cin>>Username;
    for(int i=0;i<SAdded;i++){
        if(Username == Stud[i].Username){
            while(Exit){
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"---------- Update Mr."<<Stud[i].Username<<" Information---------"<<endl;
            cout<<"--------------------"<<endl;
            cout<<"1: Update UserName "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"2: Update LastName "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"3: Update Age "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"4: Update Phone "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"5: Update Email "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"6: Update Shift "<<endl;
            cout<<"--------------------"<<endl;
            cout<<"7: Exit "<<endl;
            cin>>Choice;
            switch(Choice){
            case 1:
            cout<<"Enter New UserName : ";
            cin>>Stud[i].Username;
            cout<<"UserName Change to "<<Stud[i].Username<<" Successfully."<<endl;
            break;
            case 2:
            cout<<"Enter New LastName : ";
            cin>>Stud[i].LastName;
            cout<<"LastName Change to "<<Stud[i].LastName<<" Successfully."<<endl;
            break;
            case 3:
            cout<<"Enter New Age : ";
            cin>>Stud[i].Age;
            cout<<"Age Change to "<<Stud[i].LastName<<" Successfully."<<endl;
            break;
            case 4:
            cout<<"Enter New Phone : ";
            cin>>Stud[i].Phone;
            cout<<"Phone Change to "<<Stud[i].Phone<<" Successfully."<<endl;
            break;
            case 5:
            cout<<"Enter New Email : ";
            cin>>Stud[i].Email;
            cout<<"Email Change to "<<Stud[i].Email<<" Successfully."<<endl;
            break;
            case 6:
            cout<<"Enter New Semester : ";
            cin>>Stud[i].Semester;
            cout<<"Semester Change to "<<Stud[i].Semester<<" Successfully."<<endl;
            break;
            case 7:
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"You Have Successfully Exited from Update Student Profile"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            Exit=false;
            break;
            default:
                cout<<"---------------------------------"<<endl;
                cout<<"Try Again Choose Correct Option!"<<endl;
                cout<<"--------------------------------"<<endl;
                break;
            }

        }
        }
    }
}

//Recover Teacher Password
void RecoverTC(){
    string Username,ID,Phone,Email;
    int Age;
    char Password1[20],Password2[20];
    int Answer;
    cout<<"Enter UserName : ";
    cin>>Username;
    cout<<"Enter ID : ";
    cin>>ID;
    cout<<"Enter Phone : ";
    cin>>Phone;
    cout<<"Enter Email : ";
    cin>>Email;
    cout<<"Enter Age : ";
    cin>>Age;
    for(int i=0;i<TAdded;i++){
    if(Username == Teach[i].Username && ID == Teach[i].ID && Phone == Teach[i].Phone && Email == Teach[i].Email){
        if(Age == Teach[i].Age){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Student by Username : "<<Username<<" Founded."<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        A:
        cout<<"Enter New Password : "<<endl;
        cin>>Password1;
        cout<<"Confirm New Password : "<<endl;
        cin>>Password2;
        Answer = strcmp(Password1,Password2);
        if(Answer==0){
            system("cls");
            cout<<"Password is match"<<endl;
            Teach[i].enterpassword(Password2);
            cout<<"-------------------------------"<<endl;
            cout<<"Password is Change Successfully"<<endl;
            cout<<"-------------------------------"<<endl<<endl;
            break;
            i = 10000;
        }
        else{
        system("cls");
        cout<<"------------------------------------------"<<endl;
        cout<<"------Try Again Enter Match Password------"<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
        goto A;
        }
        system("cls");
        cout<<"------------------------------------------"<<endl;
        cout<<"------Try Again Enter Match Password------"<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
        goto A;
      }
    }
  }
  system("cls");
  cout<<"------------------------------------------------"<<endl;
  cout<<"-----Student Not Found by this Details----------"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
}

//Recover Teacher Password
void RecoverST(){
    string Username,ID,Phone,Email;
    int Age;
    char Password1[20],Password2[20];
    int Answer;
    cout<<"Enter UserName : ";
    cin>>Username;
    cout<<"Enter ID : ";
    cin>>ID;
    cout<<"Enter Phone : ";
    cin>>Phone;
    cout<<"Enter Email : ";
    cin>>Email;
    cout<<"Enter Age : ";
    cin>>Age;
    for(int i=0;i<SAdded;i++){
    if(Username == Stud[i].Username && ID == Stud[i].ID && Phone == Stud[i].Phone && Email == Stud[i].Email){
        if(Age == Stud[i].Age){
        system("cls");
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Student by Username : "<<Username<<" Founded."<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        A:
        cout<<"Enter New Password : "<<endl;
        cin>>Password1;
        cout<<"Confirm New Password : "<<endl;
        cin>>Password2;
        Answer = strcmp(Password1,Password2);
        if(Answer==0){
            system("cls");
            cout<<"Password is match"<<endl;
            Stud[i].get(Password2);
            cout<<"-------------------------------"<<endl;
            cout<<"Password is Change Successfully"<<endl;
            cout<<"-------------------------------"<<endl<<endl;
            break;
            i = 10000;


        }
        else{
        system("cls");
        cout<<"------------------------------------------"<<endl;
        cout<<"------Try Again Enter Match Password------"<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
        goto A;
        }
        system("cls");
        cout<<"------------------------------------------"<<endl;
        cout<<"------Try Again Enter Match Password------"<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
        goto A;

      }
    }
  }
  system("cls");
  cout<<"------------------------------------------------"<<endl;
  cout<<"-----Student Not Found by this Details----------"<<endl;
  cout<<"------------------------------------------------"<<endl<<endl;
}

//Change Admin Password
void Changepass(){
    char Password1[20],Password2[20];
    int Answer1,Answer2;
    A:
    system("cls");
    cout<<"Enter New Password : ";
    cin>>Password1;
    cout<<"Confirm Password : ";
    cin>>Password2;
    Answer1 = strcmp(Password1,Password2);
    if(Answer1 == 0){
        system("cls");
        cout<<"Password is Match"<<endl;
        Adm[0].enterpassword(Password2);
        cout<<"-------------------------------------"<<endl;
        cout<<"---Password is Change Successfully---"<<endl;
        cout<<"-------------------------------------"<<endl;
    }
    else{
        goto A;
    }
}

//Change Teacher Subject
void ChangeSub(){
    string Subject,ID;
    cout<<"Enter Teachers ID : ";
    cin>>ID;
    for(int i=0;i<TAdded;i++){
    if(ID == Teach[i].ID){
        cout<<"-----------------------------------------"<<endl;
        cout<<"Teacher By "<<Teach[i].ID<<" ID Found."<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Teacher UserName Is "<<Teach[i].Username<<"."<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Enter New Subject Name for "<<Teach[i].Username;
        cin>>Teach[i].Subject;
    }
    }
    cout<<"--------------------------------------"<<endl;
    cout<<"---Teacher By "<<ID<<" ID not found---"<<endl;
    cout<<"--------------------------------------"<<endl<<endl;
    cout<<"___________________________________________________________"<<endl<<endl;
}

//Admin Can Backup  Teacher All Details
void BackupTC(){
    system("cls");
    cout<<"--------------------------------"<<endl;
    cout<<"All Teachers Details will Backup"<<endl;
    cout<<"--------------------------------"<<endl;
    ofstream in("Backup Teachers Details.txt");
    string Name,Username,LastName,ID,Phone,Email;
    string Password;
    if(TAdded==0){
        cout<<"------------------------------------------"<<endl;
        cout<<"-----There Are No Teachers to Backup------"<<endl;
        cout<<"------------------------------------------"<<endl;
        return;
    }
    in<<"-------------------------------------------------------------------------"<<endl;
    in<<"-------------------------SUMS Teachers Details---------------------------"<<endl;
    in<<"-------------------------------------------------------------------------"<<endl;
    for(int i=0;i<TAdded;i++){
    //Loop is Teachers Added Time Work mean How much Teachers we Added by That Count it Iterate
    in<<"---------------------"<<Teach[i].Username<<"Information-------------------"<<endl;
    in<<"ID : "<<Teach[i].ID<<"   Gender : "<<Teach[i].Gender<<endl;
    in<<"UserName : "<<Teach[i].Username<<"  LastName : "<<Teach[i].LastName<<"   Age : "<<Teach[i].Age<<endl;
    in<<"Phone : "<<Teach[i].Phone<<"  Email : "<<Teach[i].Email<<endl;
    in<<"Semester : "<<Teach[i].Semester<<"  Subject : "<<Teach[i].Subject<<"  Shift : "<<Teach[i].Shift<<endl;
    in<<"Password : "<<Teach[i].getPassword()<<endl;
    in<<"--------------------------------------------------------------------------"<<endl;
    }
    in.close();
    cout<<"---------------------------------------"<<endl;
    cout<<"All Teacher Details Backup Successfully"<<endl;
    cout<<"---------------------------------------"<<endl;
}

//Admin Can Backup  Student All Details
void BackupST(){
    system("cls");
    cout<<"--------------------------------"<<endl;
    cout<<"All Students Details will Backup"<<endl;
    cout<<"--------------------------------"<<endl;
    ofstream in("Backup Students Details.txt");
    string Name,Username,LastName,ID,Phone,Email;
    string Password;
    if(SAdded==0){
        cout<<"-----------------------------------------"<<endl;
        cout<<"-----There Are No Student to Backup------"<<endl;
        cout<<"-----------------------------------------"<<endl;
        return;
    }
    in<<"-------------------------------------------------------------------------"<<endl;
    in<<"-------------------------SUMS Students Details---------------------------"<<endl;
    in<<"-------------------------------------------------------------------------"<<endl;
    for(int i=0;i<SAdded;i++){
    //Loop is Student Added Time Work mean How much Student we Added by That Count it Iterate
    in<<"---------------------"<<Stud[i].Username<<"Information-------------------"<<endl;
    in<<"ID : "<<Stud[i].ID<<"  Gender : "<<Stud[i].Gender<<endl;
    in<<"UserName : "<<Stud[i].Username<<"  LastName : "<<Stud[i].LastName<<"  Age : "<<Stud[i].Age<<endl;
    in<<"Phone : "<<Stud[i].Phone<<"  Email : "<<Stud[i].Email<<endl;
    in<<"Semester : "<<Stud[i].Semester<<"  Faculty : "<<Stud[i].Faculty<<"  Shift : "<<Stud[i].Shift<<endl;
    in<<"Password : "<<Stud[i].getPassword()<<endl;
    in<<"--------------------------------------------------------------------------"<<endl;
    }
    in.close();
    cout<<"---------------------------------------"<<endl;
    cout<<"All Students Details Backup Successfully"<<endl;
    cout<<"---------------------------------------"<<endl;

}


//Admin Send Message to Student
void SendtoST(){
    string Username,ID;
    int Choice;
    cout<<"----------------------------------------"<<endl;
    cout<<"--Here You Can Send Message to Student--"<<endl;
    cout<<"----------------------------------------"<<endl<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter ID to Send Message : ";
    cin>>ID;
    if(SAdded>0){
    for(int i=0;i<SAdded;i++){
        if(ID == Stud[i].ID){
        system("cls");
        cout<<"---------------------------------"<<endl;
        cout<<"----"<<Stud[i].ID<<"Founded----"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter Your Message to Send to Student : ";
        char Message[300];
        cin.ignore();
        fgets(Message,300,stdin);
        Stud[i].AdmMessage = Message;
        //This Count New Messages of Student
        NewAdmintoStudent++;
        NewMessagesofStudent+=NewAdmintoStudent;
        //it Count The Number of Messages
        Stmessage++;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"--Your Message is Successfully Send to "<<Stud[i].Username<<"--"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        return;
        }
    }
    system("cls");
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"--There are no Teacher Found by This "<<Username<<" Username"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    }
    else{
    system("cls");
    cout<<"------------------------------------------------------"<<endl;
    cout<<"--There are no Students in System First  Add Student--"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    }
}

//Stmessages are Messages which Admin Send to Student
//Receive Messages to ST(Student) from Admin
void ReceivetoST(int StudentNo){
    cout<<" ---------------------------------------------------------------------"<<endl;
    cout<<"|---------------------Received Messages from Admin---------------------|"<<endl;
    cout<<" ---------------------------------------------------------------------"<<endl;
    if(Stmessage>0){
    cout<<Stud[StudentNo].AdmMessage;
    cout<<"-----------------------------------------------"<<endl;
    return;
    }
    else{
        cout<<"---------------------------------------"<<endl;
        cout<<"-----0 Messages Received from Admin----"<<endl;
        cout<<"---------------------------------------"<<endl;
    }
}

//TCmessage are messages which Teacher Send to Student
//Received Messages to ST(Student) from Teacher
void fromTCtoStudent(int StudentNo){
    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<"|----------------------Message from Student Recived------------------------|"<<endl;
    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<Stud[StudentNo].TCMessage;
    cout<<"-----------------------------------------------"<<endl;
}


//Variable of NumberofTC(Teacher Number) is for Object Number of Teacher it use to find Object
//Receive to Message to Teacher from ST(Student)
void fromSttoTeacher(int TeacherNo){
    if(fromSTtoTC > 0){
    cout<<" ---------------------------------------------------------"<<endl;
    cout<<"|-------------Message Received from Teacher---------------|"<<endl;
    cout<<" -------------------------------------------------------"<<endl;
    for(int i=0;i<fromSTtoTC;i++){
    cout<<" ----------------------------------------------"<<endl;
    //STMessage is Message of Student to Teacher from Student
    cout<<Teach[TeacherNo].STMessage;
    cout<<"-----------------------------------------------"<<endl;
        }
    }
    else{
    cout<<"--------------------------------------------"<<endl;
    cout<<"----There Are Zero Messages From Student----"<<endl;
    cout<<"--------------------------------------------"<<endl;
    }
}

//Student Send Message to Admin
//StudentNo is Array Number of Object That By Search will Find Object by Number and After will Send Message by to Admin
void StudenttoAdmin(string username,int StudentNo){
    system("cls");
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"---Welcome "<<username<<" to Message System here you can Send Message to Admin---"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter Your Message : ";
    char Message[300];
    cin.ignore();
    fgets(Message,300,stdin);
    Adm[0].MessagefromST[fromSTtoAdm] = "This Messages is Receive from "+username+"\n"+Message;
    system("cls");
    cout<<"--------------------------------------"<<endl;
    cout<<"--Message Send Successfully to Amdin--"<<endl;
    cout<<"--------------------------------------"<<endl;
    //this count new messages to admin from Student
    NewtoAdmin++;
    //This Count the Number of Messages from Student
    fromSTtoAdm++;

    StudentMessage++;
}

//Student Send Message to Teacher
void StudentSendtoTC(string username,int StudentNo){
    string TCID;
    system("cls");
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---Welcome "<<username<<" to Message System here you can Send Message to Teacher---"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter Teacher ID to Find : "<<endl;
    cin>>TCID;
    for(int i=0;i<TAdded;i++){
        if(TCID == Teach[i].ID){
            cout<<"-------------------------------------------"<<endl;
            cout<<"Teacher Found by This "<<TCID<<" ID"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<"Enter Your Message here : ";
            char Message[300];
            cin.ignore();
            fgets(Message,300,stdin);
            Teach[i].STMessage = "This Messages is Receive from "+username+"\n"+Message;
            system("cls");
            cout<<"-----------------------------------------------"<<endl;
            cout<<"--Message Send Successfully to "<<Teach[i].Username<<"--"<<endl;
            cout<<"-----------------------------------------------"<<endl;
            //This Variable Count New Messages of Student
            NewStudenttoTeacher++;
            //This Count the Messages from Student to Teacher
            fromSTtoTC++;
        }
    }
}

//StudentNo is Array Number of Object That By Search will Find Object by Number and After will Send Message by ID Number
//Teacher Send Message to Student
void TeachertoST(string username,int TeacherNo){
    string STID;
    system("cls");
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---Welcome "<<username<<" to Message System here you can Send Message to Student---"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter Student ID to Find : ";
    cin>>STID;
    if(SAdded >0){
    for(int i=0;i<SAdded;i++){
        if(STID == Stud[i].ID && Stud[i].Faculty == Teach[TeacherNo].Faculty){
                if(Stud[i].Shift == Teach[TeacherNo].Shift || Teach[TeacherNo].Shift == "Both"){
            cout<<"-------------------------------------------"<<endl;
            cout<<"Student Found by This "<<STID<<" ID"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<"Enter Your Message here : ";
            char Message[300];
            cin.ignore();
            fgets(Message,300,stdin);
            Stud[i].TCMessage = "This Messages is Receive from "+username+"\n"+Message;
            //Count New Messages of Student
            NewTeachertoStudent++;
            NewMessagesofStudent+=NewTeachertoStudent;
            system("cls");

            cout<<"-------------------------------------------------"<<endl;
            cout<<"--Message Send to "<<STID<<" ID Successfully--"<<endl;
            cout<<"-------------------------------------------------"<<endl;
            return;
        }
      }
    }
    cout<<"----------------------------------"<<endl;
    cout<<"------------ID Not Found----------"<<endl;
    cout<<"----------------------------------"<<endl;
    }
    else{
    cout<<"--------------------------------------------"<<endl;
    cout<<"-----There are Zero Students in System------"<<endl;
    cout<<"--------------------------------------------"<<endl;
    }
}

//Received to Admin from Student
void ReceivetoAdmfromST(){
    if(fromSTtoAdm > 0){
    for(int i=0;i<fromSTtoAdm;i++){
    cout<<" ----------------------------------------------------"<<endl;
    cout<<"|----------Message is Received From Student----------|"<<endl;
    cout<<" ----------------------------------------------------"<<endl;
    cout<<i+1<<"|"<<Adm[0].MessagefromST[i]<<endl;
    cout<<"---------------------------------"<<endl;

    }
    }else if(fromSTtoAdm == 0){
    system("cls");
    cout<<"---------------------------------------"<<endl;
    cout<<"--There Are Zero Message from Student--"<<endl;
    cout<<"---------------------------------------"<<endl;
    }

}

//View Teachers Details from Backup
void TCdetailsfrombackup(){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"--Here You Can View All Teachers Details From File--"<<endl;
    cout<<"----------------------------------------------------"<<endl;

    //Creat a File Pointer
    FILE* TeacherData;
    TeacherData = fopen("Backup Teachers Details.txt","r");//R is use for To Read data From File

    //data is get characters from files
    char data;
    data = fgetc(TeacherData);
    //EOF is End Of File it is use for Last Character or End of File When it is Equal With End it will Stop
    while(data != EOF){
        //Read One One Characters From File
        cout<<data;
        data = fgetc(TeacherData);
    }
    cout<<endl;
}

//Attendance Data From File
void AtendancefromBackup(){
    ifstream inFile("Attendance of Students.txt");
    string line;
    if(!inFile){
        cout<<"Can't Open File"<<endl;
        return;
    }
    while(getline(inFile, line)){
        cout<<line;
    }
    inFile.close();
    return;
}

//View Students Details from Backup
void STdetailsfrombackup(){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"--Here You Can View All Students Details From File--"<<endl;
    cout<<"----------------------------------------------------"<<endl;

    //Creat a File Pointer
    FILE* StudentData;
    StudentData = fopen("Backup Students Details.txt","r");//R is use for To Read data From File

    //data is get characters from files
    char data;
    data = fgetc(StudentData);
    //EOF is End Of File it is use for Last Character or End of File When it is Equal With End it will Stop
    while(data != EOF){
        //Read One One Characters From File
        cout<<data;
        data = fgetc(StudentData);
    }
    cout<<endl;
}


//Admin Can View Own Details
void AdminDetails(){

    system("cls");
    cout<<"--------------------------------------"<<endl;
    cout<<"--Here You Can View Your Own Details--"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Username : "<<Adm[0].Username<<"  LastName : "<<Adm[0].LastName<<endl;
    cout<<"Phone    : "<<Adm[0].Phone<<"  Email : "<<Adm[0].Email<<endl;
    cout<<"Age   : "<<Adm[0].Age<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    return;
}

//Student Feedback System
void StudentFeedback(int StudentNumber){

    cout<<"---------------------------------------------------"<<endl;
    cout<<"--Here You Can Feedback to Admin About University--"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Enter Your Feedback : ";
    char feedback[400];
    cin.ignore();
    fgets(feedback,400,stdin);
    //Because Feedback Send to Student Number Array Number that Student Can Feedback one time
    // if Student Do Feedback Again it will Replace by Last Feedback
    Adm[0].feedback[StudentNumber] = feedback;
    cout<<"Enter Your Rate From 5 : ";
    cin>>Adm[0].Rate[StudentNumber];
    system("cls");
    cout<<"-----------------------------------------"<<endl;
    cout<<"----Feedback & Rate Send Successfully----"<<endl;
    cout<<"-----------------------------------------"<<endl;
}

//Show Feedbacks of Students
void ShowFeedbacks(){

    system("cls");
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"--Here You Can View Students Feedback About University--"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    if(SAdded==0){
        cout<<"----------------------------------------------------"<<endl;
        cout<<"----------There Are No Student in System------------"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        return;
    }
    //Loop is Run By Student Number that how many Student Added
    for(int i=0;i<SAdded;i++){
        cout<<"Rate : "<<Adm[0].Rate[i]<<"/5"<<endl;
        cout<<Adm[0].feedback[i]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
    }
    return;
}

//Teacher Can Add Projects to Student

//StudentNo is Array Number of Object That By Search will Find Object by Number and After will Give Project to Student by ID Number
void Addproject(int TeacherNo){

    string ID;
    cout<<"-------------------------------------------"<<endl;
    cout<<"---Here You Can Give Project to Student----"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter Student ID : ";
    cin>>ID;
    for(int i=0;i<SAdded;i++){
        if(ID == Stud[i].ID){
            if(Stud[i].Semester == Teach[TeacherNo].Semester){
                cout<<"Enter Project Name : ";
                char Project[400];
                cin.ignore();
                fgets(Project,400,stdin);
                Stud[i].Project = Project;
                ProjectNum++;
                system("cls");
                cout<<"------------------------------------------"<<endl;
                cout<<"-------Project is Added Successfully------"<<endl;
                cout<<"------------------------------------------"<<endl;
                return;
            }
        }
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"--Student Not Found or Not Your Student--"<<endl;
    cout<<"-----------------------------------------"<<endl;
}

//Admin Can View All Projects of Students
void Allprojects(){

    system("cls");
    cout<<"---------------------------------------------"<<endl;
    cout<<"---Here You Can View All Students Projects---"<<endl;
    cout<<"---------------------------------------------"<<endl;
    if(ProjectNum>=1){
    for(int i=0;i<ProjectNum;i++){
        cout<<i+1<<" : Project : "<<Stud[i].Project<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }}
    else{
        cout<<"--------------------------------------------"<<endl;
        cout<<"----There are No Give Projects to Student---"<<endl;
        cout<<"--------------------------------------------"<<endl;
    }

}


//Here Student Can View Own Project
void ViewProject(int StudentNumber){

    system("cls");
    string ID;
    cout<<"----------------------------------------"<<endl;
    cout<<"---Here Student Can View Own Project----"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Which Teacher Project You Want to Check "<<endl;
    cout<<"Enter Teacher ID : ";
    cin>>ID;
    if(TAdded>0){
    for(int i=0;i<TAdded;i++){
        if(ID == Teach[i].ID){
            system("cls");
            cout<<"---------------------------------------"<<endl;
            cout<<"Teacher UserName : "<<Teach[i].Username<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"Project : "<<Stud[StudentNumber].Project<<endl;
            cout<<"----------------------------------------------"<<endl;
            return;
        }
     }  system("cls");
        cout<<"--------------------------------------"<<endl;
        cout<<"--Try Again Enter Correct Teacher ID--"<<endl;
        cout<<"--------------------------------------"<<endl;
   }else if(TAdded == 0){
        system("cls");
        cout<<"--------------------------------------"<<endl;
        cout<<"----There Are No Teacher in System----"<<endl;
        cout<<"--------------------------------------"<<endl;
   }

}


//Change Teaching Semester
void changeSemesterofTC(){

    string ID;
    int Choice;
    cout<<"-------------------------------------------"<<endl;
    cout<<"--Here You Can Change Semester of Teacher--"<<endl;
    cout<<"-------------------------------------------"<<endl<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1: Find Teacher by ID       : "<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter Teacher ID : "<<endl;
    cin>>ID;
    if(TAdded>0){
    for(int i=0;i<TAdded;i++){
        if(ID == Stud[i].ID){
        system("cls");
        cout<<"---------------------------------"<<endl;
        cout<<"----"<<Teach[i].ID<<"Founded----"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter New Semester : ";
        cin>>Teach[i].Semester;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"--Semester is Changes Successfully to "<<Teach[i].Semester<<"--"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        return;
        }
      }
      cout<<"-----------------------------------------------"<<endl;
      cout<<"---Teacher Not Found By This "<<ID<<" ID."<<endl;
      cout<<"-----------------------------------------------"<<endl;
    }
    else{
    system("cls");
    cout<<"------------------------------------"<<endl;
    cout<<"-- Try Again Enter Correct Choice --"<<endl;
    cout<<"------------------------------------"<<endl;
    }

}


//Add Grades to Students
void AddGrades(int NumofTeacher){

    system("cls");
    string ID;
    cout<<"-----------------------------------------"<<endl;
    cout<<"---Here You Can Give Grades to Student---"<<endl;
    cout<<"-----------------------------------------"<<endl;
    //if Student was not Your Student
    cout<<"Enter Student ID : ";
    cin>>ID;
    if(SAdded>=1){
    for(int i=0;i<SAdded;i++){
        if(ID == Stud[i].ID){
            system("cls");
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"------ Student Founded by this "<<Stud[i].ID<<" ID---------"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            if(Stud[i].Faculty == Teach[NumofTeacher].Faculty && Stud[i].Semester == Teach[NumofTeacher].Semester){
                if(Stud[i].Shift == Teach[NumofTeacher].Shift || Teach[NumofTeacher].Shift == "Both"){
                system("cls");
                cout<<"-------------------------------------------------"<<endl;
                cout<<"------Enter "<<Stud[i].Username<<" Grades--------"<<endl;
                cout<<"-------------------------------------------------"<<endl;

                for(int j=0;j<5;j++){
                    if(Teach[NumofTeacher].Subject == Stud[i].Subjects[j]){
                        Stud[i].Total -= Stud[i].SubjectM[j];
                        M:
                        cout<<"Enter "<<Teach[NumofTeacher].Subject<<" Mark : ";
                        cin>>Stud[i].SubjectM[j];
                        if(Stud[i].SubjectM[j] > 0 || Stud[i].SubjectM[j] < 100){
                        Stud[i].Total += Stud[i].SubjectM[j];
                        system("cls");
                        cout<<"----------------------------------------------"<<endl;
                        cout<<"-------Student Marks Added Successfully-------"<<endl;
                        cout<<"----------------------------------------------"<<endl;
                        return;
                        }
                        else{
                            system("cls");
                            cout<<"-----------------------------------"<<endl;
                            cout<<"---Try Again Enter Correct Marks---"<<endl;
                            cout<<"-----------------------------------"<<endl;
                            goto M;
                        }

                    }
                  }
                }
                    cout<<"----------------------------------"<<endl;
                    cout<<"-----This is Not Your Student-----"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Try Again Enter Your Student ID "<<endl;
                    return;

            }
            else{
                cout<<"----------------------------------"<<endl;
                cout<<"-----This is Not Your Student-----"<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<"Try Again Enter Your Student ID "<<endl;
                return;

            }
        }
    }
    }else{
    cout<<"----------------------------------------"<<endl;
    cout<<"-----There Are No Student In System-----"<<endl;
    cout<<"----------------------------------------"<<endl;
    return;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"---Try Again Enter Correct Student ID----"<<endl;
    cout<<"-----------------------------------------"<<endl;

}


//Here Student Can View Result Card
void Resultcard(int NumofStudent){

    system("cls");
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"---Here "<<Stud[NumofStudent].Username<<" You Can View Your Result Card"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;

    //If Student Open Again This Function so Results will Clean And Again Will Calculate
    Stud[NumofStudent].GPA = 0;
    Stud[NumofStudent].Percentage = 0;

    //Process of Calculating Results
    //Find Total, GPA and Percentage
    Stud[NumofStudent].GPA = Stud[NumofStudent].Total*5 / 500;
    Stud[NumofStudent].Percentage = Stud[NumofStudent].Total*100 / 500;

    //Find Grade of Every Subjects
    for(int i=0;i<5;i++){
        if(Stud[NumofStudent].SubjectM[i] >= 90 && Stud[NumofStudent].SubjectM[i] <= 100){
            Stud[NumofStudent].SubjectG[i] = 'A';
        }
        else if(Stud[NumofStudent].SubjectM[i] >= 80 && Stud[NumofStudent].SubjectM[i] < 90){
            Stud[NumofStudent].SubjectG[i] = 'B';
        }
        else if(Stud[NumofStudent].SubjectM[i] >= 70 && Stud[NumofStudent].SubjectM[i] < 80){
            Stud[NumofStudent].SubjectG[i] = 'C';
        }
        else if(Stud[NumofStudent].SubjectM[i] >= 55 && Stud[NumofStudent].SubjectM[i] < 70){
            Stud[NumofStudent].SubjectG[i] = 'D';
        }
        else if(Stud[NumofStudent].SubjectM[i] >= 0 && Stud[NumofStudent].SubjectM[i] < 55){
            Stud[NumofStudent].SubjectG[i] = 'F';
        }
    }

    //Find Grade of Student Percentage
    if(Stud[NumofStudent].Percentage >= 90 && Stud[NumofStudent].Percentage < 100){
       Stud[NumofStudent].Grade = 'A';
    }
    else if(Stud[NumofStudent].Percentage >= 80 && Stud[NumofStudent].Percentage < 90){
       Stud[NumofStudent].Grade = 'B';
    }
    else if(Stud[NumofStudent].Percentage >= 70 && Stud[NumofStudent].Percentage < 80){
       Stud[NumofStudent].Grade = 'C';
    }
    else if(Stud[NumofStudent].Percentage >= 55 && Stud[NumofStudent].Percentage < 70){
       Stud[NumofStudent].Grade = 'D';
    }
    else if(Stud[NumofStudent].Percentage >= 0 && Stud[NumofStudent].Percentage < 55){
       Stud[NumofStudent].Grade = 'F';
    }

    //Print Result Card of Computer Science Faculty
    if(Stud[NumofStudent].Faculty == "ComputerScience"){
    cout<<"---------------"<<Stud[NumofStudent].Username<<" Result Card---------------"<<endl;
    cout<<"Name : "<<Stud[NumofStudent].Username<<setw(20)<<"F/Name : "<<Stud[NumofStudent].FName<<"  Gender : "<<Stud[NumofStudent].Gender<<endl;
    cout<<"ID   : "<<Stud[NumofStudent].ID<<setw(20)<<"Faculty : "<<Stud[NumofStudent].Faculty<<endl;
    cout<<"Semester : "<<Stud[NumofStudent].Semester<<setw(20)<<"Shift : "<<Stud[NumofStudent].Shift<<endl;
    cout<<"............................................................"<<endl;
    cout<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"DLD      "<<setw(17)<<Stud[NumofStudent].SubjectM[0]<<setw(20)<<Stud[NumofStudent].SubjectG[0]<<endl;
    cout<<"IT        "<<setw(15)<<Stud[NumofStudent].SubjectM[1]<<setw(20)<<Stud[NumofStudent].SubjectG[1]<<endl;
    cout<<"Programming"<<setw(13)<<Stud[NumofStudent].SubjectM[2]<<setw(20)<<Stud[NumofStudent].SubjectG[2]<<endl;
    cout<<"Graphics   "<<setw(13)<<Stud[NumofStudent].SubjectM[3]<<setw(20)<<Stud[NumofStudent].SubjectG[3]<<endl;
    cout<<"Mathematics"<<setw(13)<<Stud[NumofStudent].SubjectM[4]<<setw(20)<<Stud[NumofStudent].SubjectG[4]<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(20)<<"GPA"<<setw(20)<<"GRADE"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<Stud[NumofStudent].Total<<setw(20)<<Stud[NumofStudent].Percentage<<setw(20)<<Stud[NumofStudent].GPA<<setw(20)<<Stud[NumofStudent].Grade<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    }

    //Result Card of Engineering Faculty
    else if(Stud[NumofStudent].Faculty == "Engineering"){
    cout<<"---------------"<<Stud[NumofStudent].Username<<" Result Card---------------"<<endl;
    cout<<"Name : "<<Stud[NumofStudent].Username<<setw(20)<<"F/Name : "<<Stud[NumofStudent].FName<<"  Gender : "<<Stud[NumofStudent].Gender<<endl;
    cout<<"ID   : "<<Stud[NumofStudent].ID<<setw(20)<<"Faculty : "<<Stud[NumofStudent].Faculty<<endl;
    cout<<"Semester : "<<Stud[NumofStudent].Semester<<setw(20)<<"Shift : "<<Stud[NumofStudent].Shift<<endl;
    cout<<"............................................................"<<endl;
    cout<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Calculas     "<<setw(20)<<Stud[NumofStudent].SubjectM[0]<<setw(20)<<Stud[NumofStudent].SubjectG[0]<<endl;
    cout<<"Thermodynamic"<<setw(20)<<Stud[NumofStudent].SubjectM[1]<<setw(20)<<Stud[NumofStudent].SubjectG[1]<<endl;
    cout<<"Chemistry    "<<setw(20)<<Stud[NumofStudent].SubjectM[2]<<setw(20)<<Stud[NumofStudent].SubjectG[2]<<endl;
    cout<<"Drawing      "<<setw(20)<<Stud[NumofStudent].SubjectM[3]<<setw(20)<<Stud[NumofStudent].SubjectG[3]<<endl;
    cout<<"AutoCad      "<<setw(20)<<Stud[NumofStudent].SubjectM[4]<<setw(20)<<Stud[NumofStudent].SubjectG[4]<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(20)<<"GPA"<<setw(20)<<"GRADE"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<Stud[NumofStudent].Total<<setw(20)<<Stud[NumofStudent].Percentage<<setw(20)<<Stud[NumofStudent].GPA<<setw(20)<<Stud[NumofStudent].Grade<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    }

    else{
        cout<<"-----------------------------------"<<endl;
        cout<<"------Error is in Faculty ---------"<<endl;
        cout<<"-----------------------------------"<<endl;
    }

}

//Here Teacher Can View Student Performance GPA Results
void CheckStudentResult(int NumofTeacher){

    system("cls");
    cout<<"-------------------------------------------------"<<endl;
    cout<<"----Here You Can View All Student Performance----"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    if(SAdded>0){
    cout<<"Name"<<setw(20)<<"Percentage"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0;i<SAdded;i++){
        //Check Faculty for Check Marks of Subject
     if(Teach[NumofTeacher].Faculty == "Computer Science"){
        if(Stud[i].Faculty == Teach[NumofTeacher].Faculty && Stud[i].Semester == Teach[NumofTeacher].Semester){
            if(Stud[i].Shift == Teach[NumofTeacher].Shift || Teach[NumofTeacher].Shift == "Both"){
                //Check the Subject of Teaccher
                //Mean Give Array Number of Subject eg.0 index Subject is DLD
                int SubjectNumber;
                for(int j=0;j<5;j++){
                    if(Teach[NumofTeacher].Subject == "DLD"){
                        SubjectNumber = 0;
                    }else if(Teach[NumofTeacher].Subject == "Programming"){
                        SubjectNumber = 2;
                    }else if(Teach[NumofTeacher].Subject == "Graphics"){
                        SubjectNumber = 3;
                    }else if(Teach[NumofTeacher].Subject == "Mathematics"){
                        SubjectNumber = 4;
                    }else if(Teach[NumofTeacher].Subject == "IT"){
                        SubjectNumber = 1;
                    }
                }
                cout<<Stud[i].Username<<setw(15)<<Stud[i].SubjectM[SubjectNumber]<<endl;
                cout<<"--------------------------------------------------------"<<endl;
            }
          }

        //Check Faculty for Check Marks of Subject
       else if(Teach[NumofTeacher].Faculty == "Engineering"){
            if(Stud[i].Faculty == Teach[NumofTeacher].Faculty && Stud[i].Semester == Teach[NumofTeacher].Semester){
             if(Stud[i].Shift == Teach[NumofTeacher].Shift || Teach[NumofTeacher].Shift == "Both"){
                //Check the Subject of Teaccher
                //Mean Give Array Number of Subject eg.0 index Subject is Calculas
                int SubjectNumber;
                for(int j=0;j<5;j++){
                    if(Teach[NumofTeacher].Subject == "Calculas"){
                        SubjectNumber = 0;
                    }else if(Teach[NumofTeacher].Subject == "Termodynamic"){
                        SubjectNumber = 1;
                    }else if(Teach[NumofTeacher].Subject == "Chemistry"){
                        SubjectNumber = 2;
                    }else if(Teach[NumofTeacher].Subject == "Drawing"){
                        SubjectNumber = 3;
                    }else if(Teach[NumofTeacher].Subject == "AutoCad"){
                        SubjectNumber = 4;
                    }
                }
                cout<<Stud[i].Username<<setw(15)<<Stud[i].SubjectM[SubjectNumber]<<endl;
                cout<<"--------------------------------------------------------"<<endl;
            }
          }
          }
        }
    }
    }
    else{
    cout<<"------------------------------------------------"<<endl;
    cout<<"---------There are No Student in System---------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    }
}

//Here Student Can Download Own Result Card
void DownloadResult(int NumofStudent){

    //creat Variable to Store name and ID of Student to Create File By This Name
    string Name = Stud[NumofStudent].Username;
    string ID = "("+Stud[NumofStudent].ID+")";

    //Check the Students that there are any Student in System
    if(SAdded > 0){

    //ofstream is Use for Writing Data in File
    //Creat an Object of Writedata
    ofstream Writedata(Name+ID+"Result Card.txt");

    system("cls");
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----Here"<<Stud[NumofStudent].Username<<" You Can Download Your Result Card----"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    if(Stud[NumofStudent].Faculty == "ComputerScience"){
    Writedata<<"---------------"<<Stud[NumofStudent].Username<<" Result Card---------------"<<endl;
    Writedata<<"Name : "<<Stud[NumofStudent].Username<<setw(20)<<"F/Name : "<<Stud[NumofStudent].FName<<"  Gender : "<<Stud[NumofStudent].Gender<<endl;
    Writedata<<"ID   : "<<Stud[NumofStudent].ID<<setw(20)<<"Faculty : "<<Stud[NumofStudent].Faculty<<endl;
    Writedata<<"Semester : "<<Stud[NumofStudent].Semester<<setw(20)<<"Shift : "<<Stud[NumofStudent].Shift<<endl;
    Writedata<<"....................................................................................."<<endl;
    Writedata<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    Writedata<<"----------------------------------------------------------------------"<<endl;
    Writedata<<"DLD   "<<setw(20)<<Stud[NumofStudent].SubjectM[0]<<setw(20)<<"  "<<Stud[NumofStudent].SubjectG[0]<<endl;
    Writedata<<"IT         "<<setw(20)<<Stud[NumofStudent].SubjectM[1]<<setw(20)<<"   "<<Stud[NumofStudent].SubjectG[1]<<endl;
    Writedata<<"Programming"<<setw(10)<<Stud[NumofStudent].SubjectM[2]<<setw(20)<<"  "<<Stud[NumofStudent].SubjectG[2]<<endl;
    Writedata<<"Graphics   "<<setw(15)<<Stud[NumofStudent].SubjectM[3]<<setw(20)<<"     "<<Stud[NumofStudent].SubjectG[3]<<endl;
    Writedata<<"Mathematics"<<setw(11)<<Stud[NumofStudent].SubjectM[4]<<setw(20)<<"  "<<Stud[NumofStudent].SubjectG[4]<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    Writedata<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(20)<<"GPA"<<setw(20)<<"GRADE"<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    Writedata<<Stud[NumofStudent].Total<<setw(26)<<Stud[NumofStudent].Percentage<<setw(37)<<Stud[NumofStudent].GPA<<setw(24)<<Stud[NumofStudent].Grade<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"You Result Card is Download Successfully by File Name of "<<Name<<"("<<ID<<")"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    }

    //Result Card of Engineering Faculty
    else if(Stud[NumofStudent].Faculty == "Engineering"){
    Writedata<<"---------------"<<Stud[NumofStudent].Username<<" Result Card---------------"<<endl;
    Writedata<<"Name : "<<Stud[NumofStudent].Username<<setw(20)<<"F/Name : "<<Stud[NumofStudent].FName<<"  Gender : "<<Stud[NumofStudent].Gender<<endl;
    Writedata<<"ID   : "<<Stud[NumofStudent].ID<<setw(20)<<"Faculty : "<<Stud[NumofStudent].Faculty<<endl;
    Writedata<<"Semester : "<<Stud[NumofStudent].Semester<<setw(20)<<"Shift : "<<Stud[NumofStudent].Shift<<endl;
    Writedata<<"............................................................"<<endl;
    Writedata<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    Writedata<<"------------------------------------------------------------"<<endl;
    Writedata<<"Calculas     "<<setw(20)<<Stud[NumofStudent].SubjectM[0]<<setw(20)<<Stud[NumofStudent].SubjectG[0]<<endl;
    Writedata<<"Thermodynamic"<<setw(20)<<Stud[NumofStudent].SubjectM[1]<<setw(20)<<Stud[NumofStudent].SubjectG[1]<<endl;
    Writedata<<"Chemistry    "<<setw(20)<<Stud[NumofStudent].SubjectM[2]<<setw(20)<<Stud[NumofStudent].SubjectG[2]<<endl;
    Writedata<<"Drawing      "<<setw(20)<<Stud[NumofStudent].SubjectM[3]<<setw(20)<<Stud[NumofStudent].SubjectG[3]<<endl;
    Writedata<<"AutoCad      "<<setw(20)<<Stud[NumofStudent].SubjectM[4]<<setw(20)<<Stud[NumofStudent].SubjectG[4]<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;
    Writedata<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(37)<<"GPA"<<setw(24)<<"GRADE"<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;
    Writedata<<Stud[NumofStudent].Total<<setw(26)<<Stud[NumofStudent].Percentage<<setw(20)<<Stud[NumofStudent].GPA<<setw(20)<<Stud[NumofStudent].Grade<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;

    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"You Result Card is Download Successfully by File Name of "<<Name<<"("<<ID<<")"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    }

    else{
        cout<<"-----------------------------------"<<endl;
        cout<<"------Error is in Faculty ---------"<<endl;
        cout<<"-----------------------------------"<<endl;
    }
   }
   else{
    cout<<"---------------------------------------------"<<endl;
    cout<<"------There Are No Student in System---------"<<endl;
    cout<<"---------------------------------------------"<<endl;
   }


}

//Admin Can Backup All Students Result
void BackupResults(){

    system("cls");
    cout<<"---------------------------------------"<<endl;
    cout<<"Here You Can Backup All Students Result"<<endl;
    cout<<"---------------------------------------"<<endl;

    //Check the Students that there are any Student in System
    if(SAdded > 0){

    //ofstream is Use for Writing Data in File
    //Creat an Object of Writedata
    ofstream Writedata("All Students Results.txt");
    for(int i=0;i<SAdded;i++){
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----Here"<<Stud[i].Username<<" You Can Download Your Result Card----"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    if(Stud[i].Faculty == "Computer Science"){
    Writedata<<"---------------"<<Stud[i].Username<<" Result Card---------------"<<endl;
    Writedata<<"Name : "<<Stud[i].Username<<setw(20)<<"F/Name : "<<Stud[i].FName<<"  Gender : "<<Stud[i].Gender<<endl;
    Writedata<<"ID   : "<<Stud[i].ID<<setw(20)<<"Faculty : "<<Stud[i].Faculty<<endl;
    Writedata<<"Semester : "<<Stud[i].Semester<<setw(20)<<"Shift : "<<Stud[i].Shift<<endl;
    Writedata<<"....................................................................................."<<endl;
    Writedata<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    Writedata<<"----------------------------------------------------------------------"<<endl;
    Writedata<<"DLD        "<<setw(20)<<Stud[i].SubjectM[0]<<setw(20)<<Stud[i].SubjectG[0]<<endl;
    Writedata<<"IT         "<<setw(20)<<Stud[i].SubjectM[1]<<setw(20)<<Stud[i].SubjectG[1]<<endl;
    Writedata<<"Programming"<<setw(20)<<Stud[i].SubjectM[2]<<setw(20)<<Stud[i].SubjectG[2]<<endl;
    Writedata<<"Graphics   "<<setw(20)<<Stud[i].SubjectM[3]<<setw(20)<<Stud[i].SubjectG[3]<<endl;
    Writedata<<"Mathematics"<<setw(20)<<Stud[i].SubjectM[4]<<setw(20)<<Stud[i].SubjectG[4]<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    Writedata<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(20)<<"GPA"<<setw(20)<<"GRADE"<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    Writedata<<Stud[i].Total<<setw(46)<<Stud[i].Percentage<<setw(37)<<Stud[i].GPA<<setw(24)<<Stud[i].Grade<<endl;
    Writedata<<"------------------------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"All Students Result Backup Successfully by File Name of ll Students Results.txt"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    }

    //Result Card of Engineering Faculty
    else if(Stud[i].Faculty == "Engineering"){
    Writedata<<"---------------"<<Stud[i].Username<<" Result Card---------------"<<endl;
    Writedata<<"Name : "<<Stud[i].Username<<setw(20)<<"F/Name : "<<Stud[i].FName<<"  Gender : "<<Stud[i].Gender<<endl;
    Writedata<<"ID   : "<<Stud[i].ID<<setw(20)<<"Faculty : "<<Stud[i].Faculty<<endl;
    Writedata<<"Semester : "<<Stud[i].Semester<<setw(20)<<"Shift : "<<Stud[i].Shift<<endl;
    Writedata<<"............................................................"<<endl;
    Writedata<<"Subject"<<setw(20)<<"Marks"<<setw(20)<<"Grade"<<endl;
    Writedata<<"------------------------------------------------------------"<<endl;
    Writedata<<"Calculas     "<<setw(20)<<Stud[i].SubjectM[0]<<setw(20)<<Stud[i].SubjectG[0]<<endl;
    Writedata<<"Thermodynamic"<<setw(20)<<Stud[i].SubjectM[1]<<setw(20)<<Stud[i].SubjectG[1]<<endl;
    Writedata<<"Chemistry    "<<setw(20)<<Stud[i].SubjectM[2]<<setw(20)<<Stud[i].SubjectG[2]<<endl;
    Writedata<<"Drawing      "<<setw(20)<<Stud[i].SubjectM[3]<<setw(20)<<Stud[i].SubjectG[3]<<endl;
    Writedata<<"AutoCad      "<<setw(20)<<Stud[i].SubjectM[4]<<setw(20)<<Stud[i].SubjectG[4]<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;
    Writedata<<"TOTAL"<<setw(20)<<"PERCENTAGE"<<setw(20)<<"GPA"<<setw(20)<<"GRADE"<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;
    Writedata<<Stud[i].Total<<setw(20)<<Stud[i].Percentage<<setw(20)<<Stud[i].GPA<<setw(20)<<Stud[i].Grade<<endl;
    Writedata<<"-----------------------------------------------------------"<<endl;

    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"All Students Result Backup Successfully by File Name of ll Students Results.txt"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    }

    else{
        cout<<"-----------------------------------"<<endl;
        cout<<"------Error is in Faculty ---------"<<endl;
        cout<<"-----------------------------------"<<endl;
    }
   }
 }
   else{
    cout<<"---------------------------------------------"<<endl;
    cout<<"------There Are No Student in System---------"<<endl;
    cout<<"---------------------------------------------"<<endl;
   }
}

//Admin View Student Result Report
void ViewResultReport(){
    system("cls");
    cout<<"--------------------------------------------------"<<endl;
    cout<<"---Here You Can View All Students Result Report---"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    //Loop is Used to Print All Studenta Report
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"  ID               NAME               FACULTY        GPA         TOTAL"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    for(int i=0;i<SAdded;i++){
        cout<<" "<<Stud[i].ID<<"                 "<<Stud[i].Username<<"          "<<Stud[i].Faculty<<"    "<<Stud[i].GPA<<"      "<<Stud[i].Total<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }

}

//Student Can View Own Profile
//NumberofStudent is Array Number of Student
void ProfileofStudent(int NumberofStudent){
    system("cls");
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"----------Here "<<Stud[NumberofStudent].Username<<" You Can View Your Profile----------"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Name     : "<<Stud[NumberofStudent].Username<<"     F/Name : "<<Stud[NumberofStudent].FName<<endl;
    cout<<"LastName : "<<Stud[NumberofStudent].LastName<<"     ID : "<<Stud[NumberofStudent].ID<<endl;
    cout<<"Gender   : "<<Stud[NumberofStudent].Gender<<"     Faculty : "<<Stud[NumberofStudent].Faculty<<endl;
    cout<<"Semester : "<<Stud[NumberofStudent].Semester<<"     Shift : "<<Stud[NumberofStudent].Shift<<endl;
    cout<<"--------------------------------------------------------"<<endl;
}

//Student Can View Contact details of Teachers
void ContactTeacher(int NumberofStudent){

    system("cls");
    cout<<"------------------------------------------"<<endl;
    cout<<"---Here You Can View Contact of Teacher---"<<endl;
    cout<<"------------------------------------------"<<endl;

    if(TAdded>0){
    //Loop For to Find Own Subject Teacher
    for(int i=0;i<TAdded;i++){
        if(Teach[i].Semester == Stud[NumberofStudent].Semester && Teach[i].Faculty == Stud[NumberofStudent].Faculty){
            if(Teach[i].Shift == Stud[NumberofStudent].Shift || Teach[i].Shift == "Both"){
                //if teacher semester and shift equal with student so contact details will show
                cout<<"--------------------------------------"<<endl;
                cout<<"Name  : "<<Teach[i].Username<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Phone : "<<Teach[i].Phone<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Email : "<<Teach[i].Email<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
            }
          }
        }
    }
    else{
        cout<<"----------------------------------------"<<endl;
        cout<<"-----There are No Teacher in System-----"<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}

//Student Performance
void StudentPerformance(int NumberofTeacher){

    system("cls");
    cout<<"---------------------------------------------"<<endl;
    cout<<"----Here You Can View Student Performance----"<<endl;
    cout<<"---------------------------------------------"<<endl;
    //Loop For Student
    for(int i=0;i<SAdded;i++){
        if(Teach[NumberofTeacher].Semester == Stud[i].Semester && Teach[NumberofTeacher].Faculty == Stud[i].Faculty){
            if(Teach[NumberofTeacher].Shift == Stud[i].Shift || Teach[NumberofTeacher].Shift == "Both"){
                //if teacher semester and shift equal with student so contact details will show
                cout<<"------------------------------------------"<<endl;
                cout<<"ID              Name       GPA       TOTAL"<<endl;
                cout<<"------------------------------------------"<<endl;
                cout<<Stud[i].ID<<"        "<<Stud[i].Username<<"   "<<Stud[i].GPA<<"    "<<Stud[i].Total<<endl;
                cout<<"------------------------------------------"<<endl;
            }
        }
    }

}

//Teacher Can Change Own Password
void ChangePasswordTC(int NumberofTC){

    system("cls");
    char Password[30],Password2[30];
    int Answer,Answer2;
    cout<<"-------------------------------------"<<endl;
    cout<<"------Here You Change Password-------"<<endl;
    cout<<"-------------------------------------"<<endl;
    A:
    cout<<"Enter New Password : ";
    cin>>Password;
    cout<<"Confirm Password : ";
    cin>>Password2;
    Answer = strcmp(Password,Password2);
    if(Answer == 0){
        Teach[NumberofTC].enterpassword(Password2);
        system("cls");
        cout<<"----------------------------"<<endl;
        cout<<"Password Change Successfully"<<endl;
        cout<<"----------------------------"<<endl;
    }
    else{
        system("cls");
        cout<<"---------------------"<<endl;
        cout<<"Password is Not Match"<<endl;
        cout<<"---------------------"<<endl;
        goto A;
    }

}

//Student Can Change Own Password
void ChangePasswordST(int NumberofST){
    system("cls");
    char Password[30],Password2[30];
    int Answer,Answer2;
    cout<<"-------------------------------------"<<endl;
    cout<<"------Here You Change Password-------"<<endl;
    cout<<"-------------------------------------"<<endl;
    A:
    cout<<"Enter New Password : ";
    cin>>Password;
    cout<<"Confirm Password : ";
    cin>>Password2;
    Answer = strcmp(Password,Password2);
    if(Answer == 0){
        Stud[NumberofST].get(Password2);
        system("cls");
        cout<<"----------------------------"<<endl;
        cout<<"Password Change Successfully"<<endl;
        cout<<"----------------------------"<<endl;
    }
    else{
        system("cls");
        cout<<"---------------------"<<endl;
        cout<<"Password is Not Match"<<endl;
        cout<<"---------------------"<<endl;
        goto A;
    }

}

//Teacher Can Take Attendance
void TakeAttendance(int NumofTeacher){

    system("cls");
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"--"<<Teach[NumofTeacher].Username<<" Here You Can Take Attendance--"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Take Attendance For Present (1) and Absent (0)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    int Attendance;
    //Check The System are there Added any Student
    if(SAdded>0){
    //Check the Faculty
    if(Teach[NumofTeacher].Faculty == "ComputerScience"){
    //Loop to Find Own Student and Take Attendance
    for(int i=0;i<SAdded;i++){
        if(Teach[NumofTeacher].Faculty == Stud[i].Faculty && Teach[NumofTeacher].Semester == Stud[i].Semester){
            if(Teach[NumofTeacher].Shift == Stud[i].Shift || Teach[NumofTeacher].Shift == "Both"){

                if(Teach[NumofTeacher].Subject == "DLD"){
                    A:
                    cout<<Stud[i].AttendanceSub1_Day+1<<" Day of "<<Stud[i].AttendanceSub1_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub1[Stud[i].AttendanceSub1_Month][Stud[i].AttendanceSub1_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub1[Stud[i].AttendanceSub1_Month][Stud[i].AttendanceSub1_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto A;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub1_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub1_Day > 30){
                    Stud[i].AttendanceSub1_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "IT"){
                    B:
                    cout<<Stud[i].AttendanceSub2_Day+1<<" Day of "<<Stud[i].AttendanceSub2_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub2[Stud[i].AttendanceSub2_Month][Stud[i].AttendanceSub2_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub2[Stud[i].AttendanceSub2_Month][Stud[i].AttendanceSub2_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto B;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub2_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub2_Day > 30){
                    Stud[i].AttendanceSub2_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Programming"){
                    C:
                    cout<<Stud[i].AttendanceSub3_Day+1<<" Day of "<<Stud[i].AttendanceSub3_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub3[Stud[i].AttendanceSub3_Month][Stud[i].AttendanceSub3_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub3[Stud[i].AttendanceSub3_Month][Stud[i].AttendanceSub3_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto C;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub3_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub3_Day > 30){
                    Stud[i].AttendanceSub3_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Graphics"){
                    D:
                    cout<<Stud[i].AttendanceSub4_Day+1<<" Day of "<<Stud[i].AttendanceSub4_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub4[Stud[i].AttendanceSub4_Month][Stud[i].AttendanceSub4_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub4[Stud[i].AttendanceSub4_Month][Stud[i].AttendanceSub4_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto D;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub4_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub4_Day > 30){
                    Stud[i].AttendanceSub4_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Mathematics"){
                    E:
                    cout<<Stud[i].AttendanceSub5_Day+1<<" Day of "<<Stud[i].AttendanceSub5_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub5[Stud[i].AttendanceSub5_Month][Stud[i].AttendanceSub5_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub5[Stud[i].AttendanceSub5_Month][Stud[i].AttendanceSub5_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto D;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub5_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub5_Day > 30){
                    Stud[i].AttendanceSub5_Month++;
                    }
                }
            }
        }
      }

        return;

    }else if(Teach[NumofTeacher].Faculty == "Engineering"){
        for(int i=0;i<SAdded;i++){
        if(Teach[NumofTeacher].Faculty == Stud[i].Faculty && Teach[NumofTeacher].Semester == Stud[i].Semester){
            if(Teach[NumofTeacher].Shift == Stud[i].Shift || Teach[NumofTeacher].Shift == "Both"){

                if(Teach[NumofTeacher].Subject == "Calculas"){
                    K:
                    cout<<Stud[i].AttendanceSub1_Day+1<<" Day of "<<Stud[i].AttendanceSub1_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub1[Stud[i].AttendanceSub1_Month][Stud[i].AttendanceSub1_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub1[Stud[i].AttendanceSub1_Month][Stud[i].AttendanceSub1_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto K;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub1_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub1_Day > 30){
                    Stud[i].AttendanceSub1_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Termodynamic"){
                    F:
                    cout<<Stud[i].AttendanceSub2_Day+1<<" Day of "<<Stud[i].AttendanceSub2_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub2[Stud[i].AttendanceSub2_Month][Stud[i].AttendanceSub2_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub2[Stud[i].AttendanceSub2_Month][Stud[i].AttendanceSub2_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto F;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub2_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub2_Day > 30){
                    Stud[i].AttendanceSub2_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Chemistry"){
                    G:
                    cout<<Stud[i].AttendanceSub3_Day+1<<" Day of "<<Stud[i].AttendanceSub3_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub3[Stud[i].AttendanceSub3_Month][Stud[i].AttendanceSub3_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub3[Stud[i].AttendanceSub3_Month][Stud[i].AttendanceSub3_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto G;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub3_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub3_Day > 30){
                    Stud[i].AttendanceSub3_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "Drawing"){
                    H:
                    cout<<Stud[i].AttendanceSub4_Day+1<<" Day of "<<Stud[i].AttendanceSub4_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub4[Stud[i].AttendanceSub4_Month][Stud[i].AttendanceSub4_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub4[Stud[i].AttendanceSub4_Month][Stud[i].AttendanceSub4_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto H;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub4_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub4_Day > 30){
                    Stud[i].AttendanceSub4_Month++;
                    }
                }else if(Teach[NumofTeacher].Subject == "AutoCad"){
                    I:
                    cout<<Stud[i].AttendanceSub5_Day+1<<" Day of "<<Stud[i].AttendanceSub5_Month+1<<" Month Attendance  of This Student:"<<endl;
                    cout<<Stud[i].Username<<" : ";
                    cin>>Attendance;
                    if(Attendance == 1){
                        Stud[i].AttendanceSub5[Stud[i].AttendanceSub5_Month][Stud[i].AttendanceSub5_Day] = 'P';
                    }else if(Attendance == 0){
                        Stud[i].AttendanceSub5[Stud[i].AttendanceSub5_Month][Stud[i].AttendanceSub5_Day] = 'A';
                    }else{
                    cout<<"Try Again Enter Correct Choice"<<endl;
                    goto I;
                    }
                    //when Attendance Take Day Will Update
                    Stud[i].AttendanceSub5_Day+=1;
                    //When 30 Days Attendance Take Month Will Auto Update
                    if(Stud[i].AttendanceSub5_Day > 30){
                    Stud[i].AttendanceSub5_Month++;
                    }
                }
            }
          }
        }
      }
    return;
    }else{
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"----There Are No Students in System Admin Can Add Students----"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        return;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"--You Don't Have Students in this Class--"<<endl;
    cout<<"-----------------------------------------"<<endl;
    return;
}

//Student Can View Own Attendance
void ViewAttendance(int NumberofStudent){

    system("cls");
        cout<<setw(20)<<"------------------------------------------"<<endl;
        cout<<setw(20)<<"----Student Can View Attendance Report----"<<endl;
        cout<<setw(20)<<"------------------------------------------"<<endl;
        cout<<setw(20)<<"--------------------------------------------------------------------------"<<endl;
        cout<<setw(20)<<"Subject"<<setw(20)<<"Present"<<setw(20)<<"Absent"<<setw(20)<<"Percentage"<<endl;
        cout<<setw(20)<<"--------------------------------------------------------------------------"<<endl;
    int Present[5]={0,0,0,0,0},Absent[5]={0,0,0,0,0},TotalDays[5]={0,0,0,0,0};
    float Percentage[5]={0,0,0,0,0};
    int Day,Month;
    if(Stud[NumberofStudent].Faculty == "ComputerScience"){
    //Check Every Subject Present and Absent and Percentage
        //Check Every Subject
        //first Check First Subject
        Month = Stud[NumberofStudent].AttendanceSub1_Month;
        Day = Stud[NumberofStudent].AttendanceSub1_Day;
        if(Day>0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub1[i][j] == 'P'){
                    Present[0]++;
                    TotalDays[0]++;
                }else if(Stud[NumberofStudent].AttendanceSub1[i][j] == 'A'){
                    Absent[0]++;
                    TotalDays[0]++;
                }
            }
        }
        Percentage[0] = Present[0]*100/TotalDays[0];
        }

        //Print Attendance Data
        cout<<"DLD  "<<setw(20)<<Present[0]<<setw(20)<<Absent[0]<<setw(20)<<Percentage[0]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Second Subject
        Month = Stud[NumberofStudent].AttendanceSub2_Month;
        Day = Stud[NumberofStudent].AttendanceSub2_Day;
        if(Day>0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'P'){
                    Present[1]++;
                    TotalDays[1]++;
                }else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[1]++;
                    TotalDays[1]++;
                }
            }
        }
        Percentage[1] = Present[1]*100/TotalDays[1];
        }

        //Print Attendance Data
        cout<<"IT   "<<setw(20)<<Present[1]<<setw(20)<<Absent[1]<<setw(20)<<Percentage[1]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Third Subject
        Month = Stud[NumberofStudent].AttendanceSub3_Month;
        Day = Stud[NumberofStudent].AttendanceSub3_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub3[i][j] == 'P'){
                    Present[2]++;
                    TotalDays[2]++;
                }else if(Stud[NumberofStudent].AttendanceSub3[i][j] == 'A'){
                    Absent[2]++;
                    TotalDays[2]++;
                }
            }
        }
        Percentage[2] = Present[2]*100/TotalDays[2];
        }
        //Print Attendance Data
        cout<<"Programming"<<setw(14)<<Present[2]<<setw(20)<<Absent[2]<<setw(20)<<Percentage[2]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Fourth Subject
        Month = Stud[NumberofStudent].AttendanceSub4_Month;
        Day = Stud[NumberofStudent].AttendanceSub4_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub4[i][j] == 'P'){
                    Present[3]++;
                    TotalDays[3]++;
                }else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[3]++;
                    TotalDays[3]++;
                }
            }
        }
        Percentage[3] = Present[3]*100/TotalDays[3];
        }
        //Print Attendance Data
        cout<<"Graphics"<<setw(17)<<Present[3]<<setw(20)<<Absent[3]<<setw(20)<<Percentage[3]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Fifth Subject
        Month = Stud[NumberofStudent].AttendanceSub5_Month;
        Day = Stud[NumberofStudent].AttendanceSub5_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub5[i][j] == 'P'){
                    Present[4]++;
                    TotalDays[4]++;
                }else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[4]++;
                    TotalDays[4]++;
                }
            }
        }
        Percentage[4] = Present[4]*100/TotalDays[4];
        }
        //Print Attendance Data
        cout<<"Mathematics"<<setw(14)<<Present[4]<<setw(20)<<Absent[4]<<setw(20)<<Percentage[4]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;

    }

    else if(Stud[NumberofStudent].Faculty == "Engineering"){
    //Check Every Subject Present and Absent and Percentage
        //Check Every Subject
        //first Check First Subject
        Month = Stud[NumberofStudent].AttendanceSub1_Month;
        Day = Stud[NumberofStudent].AttendanceSub1_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub1[i][j] == 'P'){
                    Present[0]++;
                    TotalDays[0]++;
                }else if(Stud[NumberofStudent].AttendanceSub1[i][j] == 'A'){
                    Absent[0]++;
                    TotalDays[0]++;
                }
            }
        }
        Percentage[0] = Present[0]*100/TotalDays[0];
        }

        //Print Attendance Data
        cout<<"Calculas"<<setw(18)<<Present[0]<<setw(20)<<Absent[0]<<setw(20)<<Percentage[0]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Second Subject
        Month = Stud[NumberofStudent].AttendanceSub2_Month;
        Day = Stud[NumberofStudent].AttendanceSub2_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'P'){
                    Present[1]++;
                    TotalDays[1]++;
                }else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[1]++;
                    TotalDays[1]++;
                }
            }
        }
        Percentage[1] = Present[1]*100/TotalDays[1];
        }

        //Print Attendance Data
        cout<<"Termodynamic"<<setw(14)<<Present[1]<<setw(20)<<Absent[1]<<setw(20)<<Percentage[1]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Third Subject
        Month = Stud[NumberofStudent].AttendanceSub3_Month;
        Day = Stud[NumberofStudent].AttendanceSub3_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub3[i][j] == 'P'){
                    Present[2]++;
                    TotalDays[2]++;
                }else if(Stud[NumberofStudent].AttendanceSub3[i][j] == 'A'){
                    Absent[2]++;
                    TotalDays[2]++;
                }
            }
        }
        Percentage[2] = Present[2]*100/TotalDays[2];
        }

        //Print Attendance Data
        cout<<"Chemistry"<<setw(17)<<Present[2]<<setw(20)<<Absent[2]<<setw(20)<<Percentage[2]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Fourth Subject
        Month = Stud[NumberofStudent].AttendanceSub4_Month;
        Day = Stud[NumberofStudent].AttendanceSub4_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub4[i][j] == 'P'){
                    Present[3]++;
                    TotalDays[3]++;
                }else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[3]++;
                    TotalDays[3]++;
                }
            }
        }
        Percentage[3] = Present[3]*100/TotalDays[3];
        }

        //Print Attendance Data
        cout<<"Drawing"<<setw(18)<<Present[3]<<setw(20)<<Absent[3]<<setw(20)<<Percentage[3]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        //Check Fifth Subject
        Month = Stud[NumberofStudent].AttendanceSub5_Month;
        Day = Stud[NumberofStudent].AttendanceSub5_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[NumberofStudent].AttendanceSub5[i][j] == 'P'){
                    Present[4]++;
                    TotalDays[4]++;
                }
                else if(Stud[NumberofStudent].AttendanceSub2[i][j] == 'A'){
                    Absent[4]++;
                    TotalDays[4]++;
                }
            }
        }
        Percentage[4] = Present[4]*100/TotalDays[4];
        }
        //Print Attendance Data
        cout<<"AutoCad"<<setw(19)<<Present[4]<<setw(20)<<Absent[4]<<setw(20)<<Percentage[4]<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
    }

}



//Admin Can Backup Attendance Report
void BackupAttendance(){

    system("cls");
    cout<<"-----------------------------------------------"<<endl;
    cout<<"--------Here You Can Backup Attendance---------"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    int Semester,Choice;
    string Shift,Faculty;
    cout<<"1:ComputerScience  2:Engineering "<<endl;
    cout<<"Choose Faculty : ";
    cin>>Choice;
    switch(Choice){
    case 1:
        Faculty="ComputerScience";
        break;
    case 2:
        Faculty="Engineering";
        break;
    }

    A:
    cout<<"Choose Semester Number from 1 to 8 : ";
    cin>>Choice;
    switch(Choice){
    case 1:
        Semester = 1;
    break;
    case 2:
        Semester = 2;
    break;
    case 3:
        Semester = 3;
    break;
    case 4:
        Semester = 4;
    break;
    case 5:
        Semester = 5;
    break;
    case 6:
        Semester = 6;
    break;
    case 7:
        Semester = 7;
    break;
    case 8:
        Semester = 8;
    break;
    default:
        cout<<"---------------------------------"<<endl;
        cout<<"Try Again Choose Correct Semester"<<endl;
        cout<<"---------------------------------"<<endl;
        goto A;

    }

    cout<<"Choose Shift 1: AM, 2: PM : ";
    cin>>Choice;
    switch(Choice){
    case 1:
        Shift = "AM";
    break;
    case 2:
        Shift = "PM";
    break;
    default:
        cout<<"------------------------------"<<endl;
        cout<<"---Try Again Correct Choice---"<<endl;
        cout<<"------------------------------"<<endl;
        break;
    }

    if(SAdded > 0){
        for(int i=0;i<SAdded;i++){
            if(Stud[i].Shift == Shift && Stud[i].Semester == Semester && Stud[i].Faculty == Faculty){

        //for File Handling
        string data = Faculty+to_string(Semester)+Shift;
        ofstream Writedata(data+" Student Attendance Report.txt");

                //Add Data to File
                Writedata<<"-------------------------Attendance------------------------"<<endl;
                Writedata<<"-----------------------------------------------------------"<<endl;
                Writedata<<Faculty<<"   Faculty "<<Semester<<"   Semester "<<Shift<<"   Shift"<<endl;
                Writedata<<"-----------------------------------------------------------"<<endl;
                Writedata<<"Name : "<<Stud[i].Username<<", F/Name : "<<Stud[i].FName<<", ID : "<<Stud[i].ID<<endl;
                Writedata<<"--------------------------------------------------------------------------"<<endl;
                Writedata<<"Subject"<<setw(20)<<"Present"<<setw(20)<<"Absent"<<setw(20)<<"Percentage"<<endl;
                Writedata<<"--------------------------------------------------------------------------"<<endl;

                //Create File

        int Present[5]={0,0,0,0,0},Absent[5]={0,0,0,0,0},TotalDays[5]={0,0,0,0,0};
        float Percentage[5]={0,0,0,0,0};
        int Day,Month;
        if(Faculty == "ComputerScience"){
        //Check Every Subject Present and Absent and Percentage
            //Check Every Subject
            //first Check First Subject
            Month = Stud[i].AttendanceSub1_Month;
            Day = Stud[i].AttendanceSub1_Day;
            if(Day>0){
            for(int i=0;i<Month+1;i++){
                for(int j=0;j<Day;j++){
                    if(Stud[i].AttendanceSub1[i][j] == 'P'){
                    Present[0]++;
                    TotalDays[0]++;
                    }else if(Stud[i].AttendanceSub1[i][j] == 'A'){
                    Absent[0]++;
                    TotalDays[0]++;
                    }
                }
            }
            Percentage[0] = Present[0]*100/TotalDays[0];
            }
            //Print Attendance Data
            Writedata<<"DLD  "<<setw(20)<<Present[0]<<setw(20)<<Absent[0]<<setw(20)<<Percentage[0]<<endl;
            Writedata<<"--------------------------------------------------------------------------"<<endl;
            //Check Second Subject
            Month = Stud[i].AttendanceSub2_Month;
            Day = Stud[i].AttendanceSub2_Day;
            if(Day>0){
            for(int i=0;i<Month+1;i++){
                for(int j=0;j<Day;j++){
                    if(Stud[i].AttendanceSub2[i][j] == 'P'){
                        Present[1]++;
                        TotalDays[1]++;
                    }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                        Absent[1]++;
                        TotalDays[1]++;
                }
            }
        }
        Percentage[1] = Present[1]*100/TotalDays[1];
        }
        //Print Attendance Data
        Writedata<<"IT   "<<setw(20)<<Present[1]<<setw(20)<<Absent[1]<<setw(20)<<Percentage[1]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Third Subject
        Month = Stud[i].AttendanceSub3_Month;
        Day = Stud[i].AttendanceSub3_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub3[i][j] == 'P'){
                    Present[2]++;
                    TotalDays[2]++;
                }else if(Stud[i].AttendanceSub3[i][j] == 'A'){
                    Absent[2]++;
                    TotalDays[2]++;
                }
            }
        }
        Percentage[2] = Present[2]*100/TotalDays[2];
        }
        //Print Attendance Data
        Writedata<<"Programming"<<setw(15)<<Present[2]<<setw(20)<<Absent[2]<<setw(20)<<Percentage[2]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Fourth Subject
        Month = Stud[i].AttendanceSub4_Month;
        Day = Stud[i].AttendanceSub4_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub4[i][j] == 'P'){
                    Present[3]++;
                    TotalDays[3]++;
                }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                    Absent[3]++;
                    TotalDays[3]++;
                }
            }
        }
        Percentage[3] = Present[3]*100/TotalDays[3];
        }
        //Print Attendance Data
        Writedata<<"Graphics"<<setw(18)<<Present[3]<<setw(20)<<Absent[3]<<setw(20)<<Percentage[3]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Fifth Subject
        Month = Stud[i].AttendanceSub5_Month;
        Day = Stud[i].AttendanceSub5_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub5[i][j] == 'P'){
                    Present[4]++;
                    TotalDays[4]++;
                }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                    Absent[4]++;
                    TotalDays[4]++;
                }
            }
        }
        Percentage[4] = Present[4]*100/TotalDays[4];
        }
        //Print Attendance Data
        Writedata<<"Mathematics"<<setw(15)<<Present[4]<<setw(20)<<Absent[4]<<setw(20)<<Percentage[4]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;

    }
    else if(Faculty == "Engineering"){
    //Check Every Subject Present and Absent and Percentage
        //Check Every Subject
        //first Check First Subject
        Month = Stud[i].AttendanceSub1_Month;
        Day = Stud[i].AttendanceSub1_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub1[i][j] == 'P'){
                    Present[0]++;
                    TotalDays[0]++;
                }else if(Stud[i].AttendanceSub1[i][j] == 'A'){
                    Absent[0]++;
                    TotalDays[0]++;
                }
            }
        }
        Percentage[0] = Present[0]*100/TotalDays[0];
        }
        //Print Attendance Data
        Writedata<<"Calculas"<<setw(19)<<Present[0]<<setw(20)<<Absent[0]<<setw(20)<<Percentage[0]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Second Subject
        Month = Stud[i].AttendanceSub2_Month;
        Day = Stud[i].AttendanceSub2_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub2[i][j] == 'P'){
                    Present[1]++;
                    TotalDays[1]++;
                }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                    Absent[1]++;
                    TotalDays[1]++;
                }
            }
        }
        Percentage[1] = Present[1]*100/TotalDays[1];
        }
        //Print Attendance Data
        Writedata<<"Termodynamic"<<setw(15)<<Present[1]<<setw(20)<<Absent[1]<<setw(20)<<Percentage[1]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Third Subject
        Month = Stud[i].AttendanceSub3_Month;
        Day = Stud[i].AttendanceSub3_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub3[i][j] == 'P'){
                    Present[2]++;
                    TotalDays[2]++;
                }else if(Stud[i].AttendanceSub3[i][j] == 'A'){
                    Absent[2]++;
                    TotalDays[2]++;
                }
            }
        }
        Percentage[2] = Present[2]*100/TotalDays[2];
        }
        //Print Attendance Data
        Writedata<<"Chemistry"<<setw(18)<<Present[2]<<setw(20)<<Absent[2]<<setw(20)<<Percentage[2]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Fourth Subject
        Month = Stud[i].AttendanceSub4_Month;
        Day = Stud[i].AttendanceSub4_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub4[i][j] == 'P'){
                    Present[3]++;
                    TotalDays[3]++;
                }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                    Absent[3]++;
                    TotalDays[3]++;
                }
            }
        }
        Percentage[3] = Present[3]*100/TotalDays[3];
        }
        //Print Attendance Data
        Writedata<<"Drawing"<<setw(19)<<Present[3]<<setw(20)<<Absent[3]<<setw(20)<<Percentage[3]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
        //Check Fifth Subject
        Month = Stud[i].AttendanceSub5_Month;
        Day = Stud[i].AttendanceSub5_Day;
        if(Day > 0){
        for(int i=0;i<Month+1;i++){
            for(int j=0;j<Day;j++){
                if(Stud[i].AttendanceSub5[i][j] == 'P'){
                    Present[4]++;
                    TotalDays[4]++;
                }else if(Stud[i].AttendanceSub2[i][j] == 'A'){
                    Absent[4]++;
                    TotalDays[4]++;
                }
            }
        }
        Percentage[4] = Present[4]*100/TotalDays[4];
        }
        //Print Attendance Data
        Writedata<<"AutoCad"<<setw(20)<<Present[4]<<setw(20)<<Absent[4]<<setw(20)<<Percentage[4]<<endl;
        Writedata<<"--------------------------------------------------------------------------"<<endl;
    }

                //Here Student Attendance Calculating


            }
        }

        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"All Students Result Backup Successfully by File Name of All Student Attendance.txt"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
    }
    else{
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--There are No Students in System First Add Student--"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
    }

    }


//Admin Function
void AdminFun(){
    system("cls");
    A:
    string Username,Password;
    int choose;
    cout<<"-------"<<endl;
    cout<<"Remember : If you don't have Account Only Programmer Can Create For You ! "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"|1: Log in     | "<<endl;
    cout<<"---------------"<<endl;
    cout<<"|2: Exit       |"<<endl;
    cout<<"---------------"<<endl;
    cout<<"|Choose an Option : ";
    cin>>choose;
    switch(choose){
    case 1:{
        system("cls");
        B:
        int Answer1=1,Answer2=1;
        cout<<"--------------"<<endl;
        cout<<"----Sign in---"<<endl;
        cout<<"--------------"<<endl;
        cout<<"Enter UserName :";
        cin>>Username;
        cout<<"Enter Password :";
        cin>>Password;
        if(Adm[0].getPassword() == Password){
            Answer1 = 0;
        }
        if(Adm[0].Username == Username){
            Answer2 = 0;
        }
        if(Answer1 != 0 && Answer2!= 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----ACCOUNT IS NOT RAGISTERED YET!------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto A;
        }
        if(Answer2 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----UserName is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }
        else if(Answer1 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"------Password is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }
    if(Answer1==0 && Answer2==0){
    system("cls");
    bool Exit=true;
    int Choice;
    while(Exit){
    cout<<endl;
    cout<<"                                       __________________________________________________________________________________________"<<endl;
    cout<<"                                            |                                                                                  |"<<endl;
    cout<<"                                            -----------------------------------------------------------------------------------"<<endl;
    cout<<"                                                |                                                                      |"<<endl;
    cout<<"                                                <-------------WELCOME "<<Adm[0].Username<<" TO SUMS ADMIN PORTAL------------------>"<<endl;
    cout<<"                                                |                                                                      |"<<endl;
    cout<<"                                                ------------------------------------------------------------------------"<<endl;
    cout<<"                                                ------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Total Unread  Messages are  :"<<NewtoAdmin<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"___________________________________________"<<"              "<<"__________________________________________________"<<"              "<<"_______________________________________________"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|------------ User Management ------------|"<<"              "<<"|------------ Information Management ------------|"<<"              "<<"|---------- Update & Edit Operations ---------|"<<endl;
    cout<<"|_________________________________________|"<<"              "<<"|________________________________________________|"<<"              "<<"|_____________________________________________|"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|    1. Add Teachers to University        |"<<"              "<<"|       5. View All Students Projects            |"<<"              "<<"|         12. Update Teacher Details          |"<<endl;
    cout<<"|    2. Add Students to University        |"<<"              "<<"|       6. View All Teachers Information         |"<<"              "<<"|         13. Update Student Details          |"<<endl;
    cout<<"|    3. View Added Teachers Username & ID |"<<"              "<<"|       7. View All Students Information         |"<<"              "<<"|         14. Change Subject of Teacher       |"<<endl;
    cout<<"|    4. View Added Students Username & ID |"<<"              "<<"|       8. Search For Teacher By ID              |"<<"              "<<"|         15. Change Teacher Semester         |"<<endl;
    cout<<"|                                         |"<<"              "<<"|       9. Search For Student By ID              |"<<"              "<<"|                                             |"<<endl;
    cout<<"|                                         |"<<"              "<<"|      10. View Teachers Details From Backup Data|"<<"              "<<"|                                             |"<<endl;
    cout<<"|                                         |"<<"              "<<"|      11. View Students Details From Backup Data|"<<"              "<<"|                                             |"<<endl;
    cout<<"|_________________________________________|"<<"              "<<"|________________________________________________|"<<"              "<<"|_____________________________________________|"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl<<endl;
    cout<<"___________________________________________"<<"              "<<"__________________________________________________"<<"              "<<"_______________________________________________"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|----------- Backup & Recovery -----------|"<<"              "<<"|----------- Messaging & Communication ----------|"<<"              "<<"|-------------- Security & Setting -----------|"<<endl;
    cout<<"|_________________________________________|"<<"              "<<"|________________________________________________|"<<"              "<<"|_____________________________________________|"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|     16. Backup All Teachers Details     |"<<"              "<<"|        23. Send Message to Student             |"<<"              "<<"|          27. Change Admin Password          |"<<endl;
    cout<<"|     17. Backup All Students Details     |"<<"              "<<"|        24. Received Messages From Students     |"<<"              "<<"|          28. Log Out                        |"<<endl;
    cout<<"|     18. Backup Students Results         |"<<"              "<<"|        25. Student Feedback System             |"<<"              "<<"|                                             |"<<endl;
    cout<<"|     19. Backup Student Attendance       |"<<"              "<<"|        26. View Own Details                    |"<<"              "<<"|                                             |"<<endl;
    cout<<"|     20. Recover Teacher Password        |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|     21. Recover Student Password        |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|     22. Auto Backup on Exit             |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl;
    cout<<"|_________________________________________|"<<"              "<<"|________________________________________________|"<<"              "<<"|_____________________________________________|"<<endl;
    cout<<"|                                         |"<<"              "<<"|                                                |"<<"              "<<"|                                             |"<<endl<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Choose Option : ";
    cin>>Choice;
    switch(Choice){
    case 1:{
    system("cls");
    AddTeacher();
    break;
    }
    case 2:{
    system("cls");
    AddStudent();
    break;
    }
    case 3:{
    system("cls");
    TeachNameId();
    break;
    }
    case 4:{
    system("cls");
    StudNameId();
    break;
    }
    case 5:{
    system("cls");
    Allprojects();
    break;
    }
    case 6:{
    system("cls");
    ViewTeacher();
    break;
    }
    case 7:{
    system("cls");
    ViewStudent();
    break;
    }
    case 8:{
    system("cls");
    SearchIDT();
    break;
    }
    case 9:{
    system("cls");
    SearchIDS();
    break;
    }
    case 10:{
    system("cls");
    TCdetailsfrombackup();
    break;
    }
    case 11:{
    system("cls");
    STdetailsfrombackup();
    }
    case 12:{
    system("cls");
    UpdateTC();
    break;
    }
    case 13:{
    system("cls");
    UpdateST();
    break;
    }
    case 14:{
    system("cls");
    ChangeSub();
    break;
    }
    case 15:{
    system("cls");
    changeSemesterofTC();
    break;
    }
    case 16:{
    system("cls");
    BackupTC();
    break;
    }
    case 17:{
    system("cls");
    BackupST();
    break;
    }
    case 18:{
    system("cls");
    BackupResults();
    break;
    }
    case 19:{
    system("cls");
    BackupAttendance();
    break;
    }
    case 20:{
    system("cls");
    RecoverTC();
    break;
    }
    case 21:{
    system("cls");
    RecoverST();
    break;
    }
    //Auto Backup Student and Teacher and Exit
    case 22:{
    system("cls");
    BackupTC();
    BackupST();
    Exit=false;
    break;
    }
    case 23:{
    system("cls");
    SendtoST();
    break;
    }
    case 24:{
    system("cls");
    ReceivetoAdmfromST();
    break;
    }
    case 25:{
    system("cls");
    ShowFeedbacks();
    break;
    }
    case 26:{
    system("cls");
    AdminDetails();
    break;
    }
    case 27:{
    system("cls");
    Changepass();
    break;
    }
    case 28:{
    system("cls");
    cout<<"----------------------------------------------"<<endl;
    cout<<"You Have Successfully Exited from Admin Portal"<<endl;
    cout<<"----------------------------------------------"<<endl;
    Exit = false;
    break;
    }
    default:
        cout<<"---------------------------------"<<endl;
        cout<<"Try Again Choose Correct Option!"<<endl;
        cout<<"--------------------------------"<<endl;
   }
  }
        }
        else{
            system("cls");
            cout<<"------------------------------------------"<<endl;
            cout<<"---------Something Going Wrong!-----------"<<endl;
            cout<<"------------------------------------------"<<endl;
            goto A;
        }
    break;
    }
    case 2:
    break;
    break;
    default:
        system("cls");
        cout<<"---Try Again Enter Correct Option----"<<endl;
        goto A;
    }

}

void TeacherFun(){

    A:
    bool Exit=true;
    int Choice,choose,FindTeacher;
    string Username,Password;
    system("cls");
    cout<<"-------"<<endl;
    cout<<"Remember : If you don't have Account Only Admin Can Create For You ! "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"|1: Log in     | "<<endl;
    cout<<"---------------"<<endl;
    cout<<"|2: Exit       |"<<endl;
    cout<<"---------------"<<endl;
    cout<<"|Choose an Option : ";
    cin>>choose;
    switch(choose){
    case 1:{
        system("cls");
        B:
        int Answer1=1,Answer2=1;
        cout<<"--------------"<<endl;
        cout<<"----Sign in---"<<endl;
        cout<<"Enter UserName :";
        cin>>Username;
        cout<<"Enter Password :";
        cin>>Password;
        for(int i=0;i<TAdded;i++){
        //string Password2 = Teach[0].getPassword();
        if(Teach[i].getPassword() == Password){
            FindTeacher=i;
            Answer1 = 0;

        }
        if(Teach[i].Username == Username){
            Answer2 = 0;
        }}
        if(Answer1 != 0 && Answer2!= 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----Account is Not Ragistered yet!------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto A;
        }
        if(Answer2 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----UserName is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }
        else if(Answer1 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"------Password is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }
        if(Answer1==0 && Answer2==0){
    system("cls");
    while(Exit){
    cout<<endl;
    cout<<"                 --------------------------------------------------------------------------"<<endl;
    cout<<"                 ---------------------------------------------------------------------------"<<endl;
    cout<<"                 <----------Welcome "<<Teach[FindTeacher].Username<<"to University Management System Teacher Portal---------->"<<endl;
    cout<<"                 ---------------------------------------------------------------------------"<<endl;
    cout<<"                 ---------------------------------------------------------------------------"<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<"  Unread Messages are : "<<NewStudenttoTeacher<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<"1 : View Enrolled Students    "<<endl;//T
    cout<<"3 : Enter Grades to Student   "<<endl;//T
    cout<<"4 : View Student Performance (GPA, Result)  "<<endl;//T
    cout<<"5 : Add Project to Student    "<<endl;//T
    cout<<"2 : Take Attendance           "<<endl;//T
    cout<<"7 : Received Messages from Student  "<<endl;//T
    cout<<"8 : Send Messages to Student  "<<endl;//T
    cout<<"9 : Change Password           "<<endl;
    cout<<"10 : Log Out                   "<<endl;//T
    cin>>Choice;
    switch(Choice){
    case 1:{//There Should be Don't Show Password to Teacher only ID and UserName
    system("cls");
    StudNameId();
    break;}
    case 2:{
    system("cls");
    TakeAttendance(FindTeacher);
    break;}
    case 3:{
    system("cls");
    AddGrades(FindTeacher);
    break;}
    case 4:{
    system("cls");
    StudentPerformance(FindTeacher);
    break;}
    case 5:{
    system("cls");
    Addproject(FindTeacher);
    break;}
    case 6:{
    system("cls");

    break;}
    case 7:{
    NewStudenttoTeacher=0;
    system("cls");
    fromSttoTeacher(FindTeacher);
    break;}
    case 8:{
    system("cls");
    TeachertoST(Teach[FindTeacher].Username,FindTeacher);
    break;}
    case 9:{
    system("cls");
    ChangePasswordTC(FindTeacher);
    break;
    }
    case 10:{
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"You Selected 10th Option "<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"------Exit from Teacher Portal Successfully--------"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    Exit=false;
    break;}
    default:
        cout<<"--------------------------------"<<endl;
        cout<<"Try Again Choose Correct Option!"<<endl;
        cout<<"--------------------------------"<<endl;
    }
    }
    }
    else{
        system("cls");
            cout<<"------------------------------------------"<<endl;
            cout<<"---------Something Going Wrong!-----------"<<endl;
            cout<<"------------------------------------------"<<endl;
            goto A;
        }
            }
    case 2:
    break;
    break;

    default:
        system("cls");
        cout<<"-------------------------------------"<<endl;
        cout<<"---Try Again Enter Correct Option----"<<endl;
        cout<<"-------------------------------------"<<endl;
        goto A;
    }
}

//This is Student Function Something Which Student do All in This Function
void StudentFun(){

    bool Exit=true;
    system("cls");
    int Choice,choose;
    //This Variable Take Array Number of Object
    int FindStudent=1;
    string Username,Password;
    system("cls");
    A:
    cout<<"-------"<<endl;
    cout<<"Remember : If you don't have Account Only Admin Can Create For You ! "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"|1: Log in     | "<<endl;
    cout<<"---------------"<<endl;
    cout<<"|2: Exit       |"<<endl;
    cout<<"---------------"<<endl;
    cout<<"|Choose an Option : ";
    cin>>choose;
    switch(choose){
    case 1:{
        system("cls");
        B:
        int Answer1=1,Answer2=1;
        cout<<"--------------"<<endl;
        cout<<"----Sign in---"<<endl;
        cout<<"Enter UserName :";
        cin>>Username;
        cout<<"Enter Password :";
        cin>>Password;
        for(int i=0;i<SAdded;i++){
        if(Stud[i].getPassword() == Password){
            FindStudent=i;
            Answer1 = 0;
        }
        if(Stud[i].Username == Username){
            Answer2 = 0;
        }}
        if(Answer1 != 0 && Answer2!= 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----Account is Not Ragistered yet!------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto A;
        }
        if(Answer2 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"-----UserName is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }
        else if(Answer1 != 0){
            system("cls");
            cout<<"-----------------------------------------"<<endl;
            cout<<"------Password is incorrect!--------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            goto B;
        }

        if(Answer1==0 && Answer2==0){
    system("cls");
    while(Exit){
    cout<<endl;
    cout<<"                 --------------------------------------------------------------------------------------------"<<endl;
    cout<<"                 --------------------------------------------------------------------------------------------"<<endl;
    cout<<"                 <----------"<<Stud[FindStudent].Username<<" Welcome to University Management System Student Portal---------->"<<endl;
    cout<<"                 --------------------------------------------------------------------------------------------"<<endl;
    cout<<"                 --------------------------------------------------------------------------------------------"<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<" Unread Messages are : "<<NewMessagesofStudent<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<"1 : Student Profile Management  "<<endl;//T
    cout<<"2 : Check Own Project           "<<endl;//T
    cout<<"3 : View Attendance  Record     "<<endl;//T
    cout<<"4 : View Result Card            "<<endl;//T
    cout<<"5 : Download Result Card        "<<endl;//T
    cout<<"6 : Contact Details of Teacher  "<<endl;//T
    cout<<"7: Send Messages to Teacher     "<<endl;//T
    cout<<"8: Received Messages From Teacher  "<<endl;//T
    cout<<"9: Send Messages to Admin       "<<endl;//T
    cout<<"10: Received Messages From Admin  "<<endl;//T
    cout<<"11: Send Feedback About Teacher,Lessons,Class,Classmates,and etc...  "<<endl;//T
    cout<<"12: Change Password             "<<endl;//T
    cout<<"13: Log Out                     "<<endl;//T
    cin>>Choice;
    switch(Choice){
    case 1:{
    system("cls");
    ProfileofStudent(FindStudent);
    break;}
    case 2:{
    system("cls");
    ViewProject(FindStudent);
    break;}
    case 3:{
    system("cls");
    ViewAttendance(FindStudent);
    break;}
    case 4:{
    system("cls");
    Resultcard(FindStudent);
    break;}
    case 5:{
    system("cls");
    DownloadResult(FindStudent);
    break;}
    case 6:{
    system("cls");
    ContactTeacher(FindStudent);
    break;}
    case 7:{
    system("cls");
    StudentSendtoTC(Stud[FindStudent].Username,FindStudent);
    break;}
    case 8:{
    system("cls");
    NewMessagesofStudent-=NewTeachertoStudent;
    NewTeachertoStudent=0;
    fromTCtoStudent(FindStudent);
    break;}
    case 9:{
    system("cls");
    StudenttoAdmin(Stud[FindStudent].Username,FindStudent);
    break;}
    case 10:{
    system("cls");
    NewMessagesofStudent-=NewAdmintoStudent;
    NewAdmintoStudent=0;
    ReceivetoST(FindStudent);
    break;}
    case 11:{
    system("cls");
    StudentFeedback(FindStudent);
    break;}
    case 12:{
    system("cls");
    ChangePasswordST(FindStudent);
    break;
    }
    case 13:{
    system("cls");
    cout<<"---------------------------------------------------"<<endl;
    cout<<"------Exit from Student Portal Successfully--------"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    Exit=false;
    break;
    break;
    }
    default:
        cout<<"--------------------------------"<<endl;
        cout<<"Try Again Choose Correct Option!"<<endl;
        cout<<"--------------------------------"<<endl;
    }
    }}
    else{
        system("cls");
            cout<<"------------------------------------------"<<endl;
            cout<<"---------Something Going Wrong!-----------"<<endl;
            cout<<"------------------------------------------"<<endl;
            goto A;
        }
    }
  }
}

//There Are All About SUMS Software
//This Function is For About Software or Developer(Programmer)
void About(){
    int Choice;
    system("cls");
    cout<<"--------------------------------------------------"<<endl;
    cout<<"1: About SUMS (Smart University Management System )"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"2: About Developer  "<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Select Choice : ";
    cin>>Choice;
    switch(Choice){
    case 1:{
    system("cls");
    cout<<"  ----------"<<endl;
    cout<<"  About SUMS"<<endl;
    cout<<"  --------------------------------------------------"<<endl;
    cout<<"    Smart University Management System (SUMS) is a desktop-based software application developed using C++ with Object-Oriented Programming (OOP) principles. \nThe system is designed to help universities efficiently manage key administrative tasks such as:\n  - Student records management\n  - Course enrollment and Attendance\n  - Academic performance tracking\n  - Teacher Details Management\n  - Faculty and class management\n  - Messaging System\n  - Feedback  System\n  - Security System\nSUMS was created to solve the common problems faced by educational institutions by offering an easy-to-use, secure, and scalable solution.\nIt includes over 3500+ lines of well-structured C++ code and demonstrates strong concepts of OOP, data handling, file management, and menu-driven UI.\nThis project reflects my ability to build real-world applications from scratch, debug large codebases, and develop systems that offer practical solutions in the education sector."<<endl;
    cout<<"  --------------------------------------------------------"<<endl;
    break;
    }
    case 2:{
    system("cls");
    system("start Munir.jpg");
    cout<<"  ---------------"<<endl;
    cout<<"  About Developer"<<endl;
    cout<<"  ---------------------------------------------------"<<endl;
    cout<<"   This project was developed by Munir Rahman Rahmani, a passionate and self-taught software developer from Afghanistan. \nI specialize in C, C++, Python, HTML, CSS, and JavaScript, with a strong interest in building real-world solutions that improve education, business, and society.\nI have completed multiple projects, including a Student Database System, Bank Management System, and this Smart University Management System (SUMS). \nMy focus is on writing clean, efficient code and continuously improving my technical and problem-solving skills.\nI believe in learning by doing, and every project is an opportunity to grow and contribute to the tech world.\nMy goal is to become a professional software engineer and use technology to make a positive impact."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Country : AFGHANISTAN , Province : KANDAHAR"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Phone   : +93711717893"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Email : munirrahmanrahmani0@gmail.com"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    break;
    }

    default:
        cout<<"-------------------------------"<<endl;
        cout<<"Try Again Enter Correct Option!"<<endl;
        cout<<"-------------------------------"<<endl;
        break;
    }
}

//This Function Help with User
void Help(){
    int Choice;
    cout<<"--------------"<<endl;
    cout<<"1: How to Use "<<endl;
    cout<<"--------------"<<endl;
    cout<<"2: How Run    "<<endl;
    cout<<"--------------"<<endl;
    cout<<"Select Choice : ";
    cin>>Choice;
    switch(Choice){
    case 1:

    break;
    case 2:

    break;
    default:
        cout<<"----------------------------------------"<<endl;
        cout<<"----Try Again Enter Correct Choice------"<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}

//Main Function All Funtion is Calling in Main Function
int main(){
    int Choice;
    bool Exit=true;
    //Admin Data Information
    Adm[0].Username="MUNIRRAHMAN";
    Adm[0].LastName="RAHMANI";
    Adm[0].Gender="Male";
    Adm[0].Email="munirrahman1717@gmail.com";
    Adm[0].Phone="+93711717893";
    Adm[0].Age=17;
    Adm[0].enterpassword("Munir01@");
    while(Exit){
    cout<<"         _____________________________________________________________________________"<<endl;
    cout<<"                |                                                           |"<<endl;
    cout<<"                |-----------------------------------------------------------|"<<endl;
    cout<<"                |-----------------------   SUMS    -------------------------|"<<endl;
    cout<<"                |------------SMART UNIVERSITY MANAGEMENT SYSTEM-------------|"<<endl;
    cout<<"                |------------CREATED BY ENG.MUNIRRAHMAN RAHMANI-------------|"<<endl;
    cout<<"                |-----------------------------------------------------------|"<<endl;
    cout<<"                |-----------------------------------------------------------|"<<endl;
    cout<<"                |                                                           |"<<endl;
    cout<<"__________________________"<<endl;
    cout<<" | 1: ADMIN              |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | 2: TEACHER            |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | 3: STUDENT            |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | 4: HELP               |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | 5: About US/Software  |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | 6: EXIT               |"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<" | Enter Choice          :";
    cin>>Choice;
    switch(Choice){
    case 1:
    AdminFun();
    break;
    case 2:
    TeacherFun();
    system("cls");
    break;
    case 3:
    StudentFun();
    system("cls");
    break;
    case 4:
    system("cls");
    Help();
    break;
    case 5:
    system("cls");
    About();
    break;
    case 6:
    Exit = false;
    system("cls");

    cout<<endl<<endl<<endl;
    cout<<setw(90)<<"-----------------------------------------------------------"<<endl;
    cout<<setw(90)<<"-----------------------------------------------------------"<<endl;
    cout<<setw(90)<<"-------------   Program Exited Successfully   -------------"<<endl;
    cout<<setw(90)<<"-----------------------------------------------------------"<<endl;
    cout<<setw(90)<<"-----------------------------------------------------------"<<endl;
    cout<<endl<<endl<<endl;
    break;

    }
    }

return 0;

}
