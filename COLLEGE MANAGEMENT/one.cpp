#include<iostream>
#include<vector>
#include<string>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define vll vector<ll>
using namespace std;
void decor(){
    cout<<endl;
    cout<<"----------------------------------------------"<<endl;
}
class Entity{
public:
    virtual void display() = 0; 
};
class Test{
public:
    ll time;
    string ta,room;
    bool valid=false;
    Test() {}
    Test(ll time, string ta, string room){
        this->time = time;
        this->ta = ta;
        this->room = room;
    }
};
class Subjects:public Entity{
public:
    string subName,subCode,PIC;
    Test t;
    Subjects(string subName, string subCode, string PIC) {
        this->subName = subName;
        this->subCode = subCode;
        this->PIC = PIC;
    }
    void showSubject(){
        cout<<"Subject Name :"<<subName<<endl;
        cout<<"Subject Code :"<<subCode<<endl;
        cout<<"Professor In Charge:"<<PIC<<endl;
    }
    void addTest() {
    ll time;
    string ta, room;
    decor();
    cout << "Enter Time : " << endl;
    cin >> time;
    cout << "Enter Teaching Assistant : " << endl;
    cin >> ta;
    cout << "Enter Room : " << endl;
    cin >> room;
    t = Test(time, ta, room);
    t.valid = true;
    decor();
    
    cout << "Test Schedule:" << endl;
    cout << "Subject: " << subName << endl;
    cout << "Time: " << t.time << endl;
    cout << "Teaching Assistant: " << t.ta << endl;
    cout << "Room: " << t.room << endl;
}
    void display()override{
        showSubject();
    }
};
class Student:public Entity{
public:
    ll sid,sem;
    string name, course, batch, branch;
    double cgpa;
    vector<pair<ll,ll>>subjects;
    Student(ll sid, string name, string course, string batch, string branch, ll sem, double cgpa) {
        this->sid = sid;
        this->name = name;
        this->course = course;
        this->batch = batch;
        this->branch = branch;
        this->sem = sem;
        this->cgpa = cgpa;
    }
    void intro() {
        cout << "Name : " << name<<endl;
        cout << "Scholar ID : " << sid<<endl;
        cout << "Course : " << course<<endl;
        cout << "Batch : " << batch<<endl;
        cout << "Branch : " << branch<<endl;
        cout << "Semester :" << sem<<endl;
        cout << "CGPA : " << cgpa<<endl;
    }
    void display() override {
        intro();
    }
};
vector<Subjects> sub;
vector<Student> stud;
vector<Entity*> entities;
void enterDetails(){
    ll sid,sem;
    string name,course,batch,branch;
    double cgpa;
    decor();
    cout << "Enter Scholar ID : " << endl;
    cin>>sid;
    cout<<"Enter Name : " << endl;
    cin>>name;
    cout<<"Enter Course : " << endl;
    cin>> course;
    cout <<"Enter Batch : " << endl;
    cin>> batch;
    cout<<"Enter Branch : " << endl;
    cin>>branch;
    cout<<"Enter Semester : " << endl;
    cin >>sem;
    cout<< "Enter CGPA : " << endl;
    cin >>cgpa;
    Student s(sid, name, course, batch, branch, sem, cgpa);
    stud.push_back(s);
    decor();
}
void promote(){
    ll x;
    cout<<"Enter Student ID :";
    cin >>x;
    decor();
    bool yes_found=false;
    for(int i = 0; i < stud.size(); i++){
        if(stud[i].sid == x){
            yes_found = true;
            stud[i].sem++;
            break;}
    }
    if(!yes_found){
        cout<<"Not Present in Database"<<endl;
    }
}
void demote(){
    ll x;
    cout << "Enter Student ID : ";
    cin >> x;
    decor();
    bool yes_found = false;
    for(int i = 0; i < stud.size(); i++){
        if(stud[i].sid == x){
            yes_found = true;
            stud[i].sem--;
            break;}
    }
    if(!yes_found) cout << "Not Present in Database"<<endl;
}
void eraseIt(){
    ll x;
    cout<<"Enter Student ID:";
    cin>>x;
    decor();
    bool yes_found=false;
    vector<Student>temp;
    for(int i = 0; i< stud.size(); i++){
        if(stud[i].sid == x){
            yes_found = true;
            continue;
        }
        temp.push_back(stud[i]);
    }
    if(!yes_found)  cout<<"Not Present in Database" << endl;
    stud=temp;
    decor();
}
void viewIt(){
    decor();
    if(stud.size() == 0){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    cout<<"THE STUDENT RECORDS : "<<endl;
    decor();
    for(auto it:stud){
        it.intro();
        decor();
        cout << endl;
    }
}
void displayRecordOfStudent(){
    ll x;
    cout<<"Enter Student ID : ";
    cin>>x;
    decor();
    bool yes_found = false;
    for (int i=0;i<stud.size();i++){
        if(stud[i].sid == x){
            yes_found = true;
            stud[i].intro();
            break;
        }}
    if(!yes_found)
        cout<<"Not Present in Database" << endl;
}
void getNoStud(){
    decor();
    cout<<"The number of students are : ";
    cout<<stud.size();
    cout<<endl;
}
void createSubject(){
    string subName;
    string subCode;
    string PIC;
    decor();
    cout<<"Enter Subject Name:"<<endl;
    cin>>subName;
    cout<< "Enter Subject Code:"<<endl;
    cin>>subCode;
    cout <<"Enter PIC : "<<endl;
    cin >>PIC;
    Subjects s(subName,subCode,PIC);
    sub.push_back(s);
    decor();
}
void showAllSub(){
    decor();
    if(sub.size() == 0){
        cout << "LIST IS EMPTY" << endl;
        return;}
    cout << "SUBJECT RECORDS : " << endl;
    for(auto it : sub){
        it.showSubject();
        decor();
        cout << endl;}
}
void enroll(){
    cout <<endl;
    ll x,studind=-1,subind=-1;
    cout <<"Enter Student ID:";
    cin >> x;
    bool yes_found = false;
    for(int i = 0; i < stud.size(); i++){
        if(stud[i].sid == x){
            yes_found = true;
            studind = i;
            break;
        }}
    if(!yes_found){
        cout << "Not Present in Database" << endl;
        decor();
        return;
}
    yes_found = false;
    string y;
    cout << "Enter Subject Code : ";
    cin >> y;
    for(int i = 0; i < sub.size(); i++){
        if (sub[i].subCode == y){
            if (sub[i].t.valid == 0){
                cout << "Test for this subject has not been created" << endl;
                return;
            }
            yes_found = true;
            subind = i;
            break;
        }
    }
    if(!yes_found){
        cout << "Not Present in Database" << endl;
        decor();
        return;
    }
    cout<<"Enrollment done : ";
    stud[studind].subjects.push_back({subind, 0});
    cout << stud[studind].name << " -> " << sub[subind].subName << endl;
}
void studSub(){
    cout << endl;
    ll x,studind = -1;
    cout << "Enter Student ID : ";
    cin>>x;
    bool yes_found=false;
    for(int i=0;i<stud.size();i++){
        if(stud[i].sid ==x){
            yes_found = true;
            studind = i;
            break;
        }}
    if(!yes_found){
        cout<<"Not Present in Database"<<endl;
        decor();
        return;
    }
    ll i=0;
    if (stud[studind].subjects.size() == 0){
        cout << "No subjects enrolled" << endl;
        return;
    }
    for(auto it : stud[studind].subjects) cout<<i+1<<" "<<sub[it.first].subName<<endl;
 
}
struct Book{
    string title;
    string author;
    int year;
};
class Library{
private:    vector<Book> books;
public:
    void addBook(const Book &book){
        books.push_back(book);
        cout << "Book added successfully." << endl;
    }
    void displayBooks(){
        if (books.empty()){
            cout << "Library is empty." << endl;
            return;
        }
        cout << "Library Books:" << endl;
        for (const auto &book : books){
            cout<<"Title: " <<book.title << endl;
            cout<< "Author: " <<book.author << endl;
            cout <<"Year: " <<book.year << endl<<endl;
        }}
};
void fake_lib(){
    Library library;
    int choice;
    cin.ignore();
    fflush(stdin);
    do{
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Display all Books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1:{
            Book newBook;
            cout<<"Enter title:";
            cin.ignore();
            getline(cin, newBook.title);
            cout << "Enter author: ";
            getline(cin, newBook.author);
            cout << "Enter year: ";
            cin >> newBook.year;
            library.addBook(newBook);
            break;}
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout<<"Exiting the program." << endl;
            break;
        default:
            cout<<"Invalid choice. Please enter a valid option."<<endl;
        }}
        while(choice!=3);}
struct busyMen{
    string name;
    string position;
};
void displayStudentBody(const busyMen &president, const busyMen &vicePresident, const busyMen &secretary){
    cout<<"Student Body Members:" << endl;
    cout<<"President: " <<president.name<<endl;
    cout<<"Vice President: "<<vicePresident.name<<endl;
    cout<<"Secretary: "<<secretary.name<<endl;
}
void fake_allot(){
    cin.ignore();
    fflush(stdin);
    string studentName, hostelName;
    int roomNo;
    cout<<"Enter student name: ";
    getline(cin, studentName);
    cout<<"Enter hostel name: ";
    getline(cin, hostelName);
    cout<<"Enter room number: ";
    cin>>roomNo;
    cout<<studentName<<"has been allotted a room in "<<hostelName << ",Room No."<<roomNo<<endl;
}
class BHM{
private:
    double monthlyFee;
public:
    BHM(double fee) : monthlyFee(fee) {}
    double calculateTotalFees(int months){
        return monthlyFee * months;}
};
void fake_fee(){
    cin.ignore();
    fflush(stdin);
    double monthlyFee;
    int months;
    monthlyFee=16000;
    cout << "Enter the number of months: ";
    cin >> months;
    BHM bhm(monthlyFee);
    cout << "Total mess fees for " << months << " months: $" << bhm.calculateTotalFees(months) << endl;
}
void menu(){
    decor();
    cout<<"1. Enter Students Details" << endl;
    cout<<"2. Promote Student" << endl;
    cout<<"3. Demote Student" << endl;
    cout<<"4. Erase Student Record" << endl;
    cout<<"5. View Students Record" << endl;
    cout<<"6. Search Student" << endl;
    cout<<"7. Get Number of Students" << endl;
    cout<<"8. Create Subject" << endl;
    cout<<"9. how all Subjects" << endl;
    cout<<"10.Enroll Student into a Subject" << endl;
    cout<<"11.Show Student Subjects" << endl;
    cout<<"12.Library Management" << endl;
    cout<<"13.Mess Fees Generation" << endl;
    cout<<"14.Hostel Allotment" << endl;
    cout<<"15.Add a test"<<endl;
}
void choose(){
    ll choice;
    cout<<"Your Choice : ";
    cin >>choice;
    switch(choice){
    case 1:
        enterDetails();
        break;
    case 2:
        promote();
        break;
    case 3:
        demote();
        break;
    case 4:
        eraseIt();
        break;
    case 5:
        viewIt();
        break;
    case 6:
        displayRecordOfStudent();
        break;
    case 7:
        getNoStud();
        break;
    case 8:
        createSubject();
        break;
    case 9:
        showAllSub();
        break;
    case 10:
        enroll();
        break;
    case 11:
        studSub();
        break;
    case 12:
        fake_lib();
        break;
    case 13:
        fake_fee();
        break;
    case 14:
        fake_allot();
        break;
    case 15:
    if(sub.size()==0)cout<<"There are no subjects registred yet"<<endl;
        for(auto &s:sub)  s.addTest();
        break;
    default:
        cout << "Incorrect Option " << endl;
        break;}
}
void solve(){
    decor();
    cout<<"\tNITS COLLAGE MANAGEMENT PORTAL";
    while(1){
        menu();
        choose();
        cout <<"Press 0 to exit,1 to continue"<< " ";
        ll x;
        cin>>x;
        if(x==0){
            cout<<"Thank you!";
            return;
        }}} 
int main(){
    solve();
    return 0;
}