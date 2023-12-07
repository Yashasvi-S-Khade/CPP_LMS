#include <iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include <ctime>
#include<conio.h>
#include<sstream>
void Add_user();
void Apply_leave();
void view_record();
void Profile();
void Log_out();
void view_mrecord();
void Approve_leave();
char *name;
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0
string usn,name_,pass_;
int m,coun=0;
void valid(string str)
{
  string dir,user;
  ifstream file;
  dir = str+".txt";
  file.open(dir.c_str());
  if(!file.is_open() && file.fail())
  {
    return;
  }
  else
  {
    m++;
    if(m==3)
    {
      cout<<"\n\tThis username already exists\nPlease try Again.";
      return;
    }
    cout<<"\n\tThis username already exists!\nCreate a username:";
    cin>>usn;
    valid(usn);
  }
}
int exceedsDaysInMonth(int month,int day){
  int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if ( month < 1 || month > 12 || day > days[month-1])
     return TRUE;
  else
     return FALSE;
}
int isLeapYear(int year){
   if ( (year % 4)  != 0 ){
      return FALSE;
   }
   else if ( (year % 400)  != 0 ){
      return TRUE;
   }
   else if ( (year % 100)  == 0 ){
      return FALSE;
   }
   else
   {
      return FALSE;
   }
}
int main()          //the main function
{
  string ans,psd,name,fname,bio,usern,pw,line,nusn;
  ofstream fileo;
  ifstream filei;
  h:system("cls");
  cout<<"\n\t _________________________________________________________________________________________\n";
  cout<<"\t|                               Welcome to our system!                                    |\n";
  cout<<"\t|_________________________________________________________________________________________|\n";
  cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] LOGIN                  |\n";
	cout<<"\t\t\t\t\t|        2] EXIT                   |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<endl;
          cout<<"\tEnter Your Choice : ";
          string r;
      //cin.ignore();
      getline(cin,r);
          if(r=="1")
    {
    system("cls");              //user validation part
  m:cout<<"\n\t _________________________________________________________________________________________\n";
  cout<<"\t|                               Welcome to our system!                                    |\n";
  cout<<"\t|_________________________________________________________________________________________|\n";
      cout<<"\t\tEnter your username:";
      cin>>usn;
      cout<<"\n\t\tEnter your password:";
      cin>>psd;
      name_=usn;
      pass_=psd;
      system("cls");
      fname=usn+".txt";
      filei.open(fname.c_str());
      getline(filei,usern);
      getline(filei,line);
      getline(filei,pw);
      filei.close();

      if(usn=="Admin"&& psd==pw)            //interface for Admin
      {
          int c;
  cout<<"\n\t_________________________________________________________________________________________\n";
  cout<<"\t|                           You are successfully logged in:)\a                                    |\n";
  cout<<"\n\t|_________________________________________________________________________________________|\n";
  Sleep(50);
  system("cls");
           do
           {
    cout<<"\n\t ______________________________________________________________________________________________\n";
	cout<<"\t|\t\t\t\t              ADMIN                                            |\n";
	cout<<"\t|______________________________________________________________________________________________|\n";
	cout<<endl;
	cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] Add User               |\n";
	cout<<"\t\t\t\t\t|        2] Apply For Leave        |\n";
	cout<<"\t\t\t\t\t|        3] View Record            |\n";
	cout<<"\t\t\t\t\t|        4] Profile                |\n";
	cout<<"\t\t\t\t\t|        5] Logout                 |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<endl;
          cout<<"\tEnter Your Choice : ";
          cin>>c;
          switch(c)
          {
          case 1:
            Add_user();
            break;
          case 2:
            Apply_leave();
            break;
          case 3:
            view_record();
            break;
          case 4:
            Profile();
            break;
          case 5:
              {
                  system("cls");
     ofstream fileo;
     ifstream filei;
      fileo.open("temp.txt",ios::out);
      fileo.close();
            goto h;
              }
          default :
            cout<<"\tInvalid Input!!\n";
          }
           }while(c!=5);


      }
      else if(usn=="Head"&& psd==pw)        //interface for Head
         {
          int c;
 cout<<"\n\t_________________________________________________________________________________________\n";
  cout<<"\t|                           You are successfully logged in:)\a                                    |\n";
  cout<<"\n\t|_________________________________________________________________________________________|\n";
  Sleep(50);
  system("cls");
           do
           {
    cout<<"\n\t ______________________________________________________________________________________________\n";
	cout<<"\t|\t\t\t\t              HEAD                                             |\n";
	cout<<"\t|______________________________________________________________________________________________|\n";
	cout<<endl;
	cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] Add User               |\n";
	cout<<"\t\t\t\t\t|        2] Apply for Leave        |\n";
	cout<<"\t\t\t\t\t|        3] View Record(Personal)  |\n";
	cout<<"\t\t\t\t\t|        4] View Record(Employee)  |\n";
	cout<<"\t\t\t\t\t|        5] Profile                |\n";
	cout<<"\t\t\t\t\t|        6] Approve leave          |\n";
	cout<<"\t\t\t\t\t|        7] Log Out                |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<endl;
          cout<<"\tEnter Your Choice : ";
          cin>>c;
          switch(c)
          {
          case 1:
            Add_user();
            break;
          case 2:
            Apply_leave();
            break;
          case 3:
            view_record();
            break;
          case 4:
              view_mrecord();
            break;
          case 5:
            Profile();
            break;
          case 6:
            Approve_leave();
            break;
          case 7:
          {
            system("cls");
     ofstream fileo;
     ifstream filei;
      fileo.open("temp.txt",ios::out);
      fileo.close();
            goto h;
          }
          default :
            cout<<"\tInvalid Input!!\n";
          }
           }while(c!=7);
    }
    else
     if(usn==usern && psd==pw)              //interface for employee
      {
          int c;
  cout<<"\n\t_________________________________________________________________________________________\n";
  cout<<"\t|                           You are successfully logged in:)\a                                    |\n";
  cout<<"\n\t|_________________________________________________________________________________________|\n";
  Sleep(50);
  system("cls");
            do
    {
   x: cout<<"\n\t ______________________________________________________________________________________________\n";
	cout<<"\t|\t\t\t\t              USER                                             |\n";
	cout<<"\t|______________________________________________________________________________________________|\n";
	cout<<endl;
	cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] Apply For Leave        |\n";
	cout<<"\t\t\t\t\t|        2] View Record            |\n";
	cout<<"\t\t\t\t\t|        3] Profile                |\n";
	cout<<"\t\t\t\t\t|        4] Logout                 |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<endl;
          cout<<"\tEnter Your Choice : ";
          cin>>c;
          switch(c)
          {
          case 1:
            Apply_leave();
            break;
          case 2:
            view_record();
            break;
          case 3:
            Profile();
            break;
          case 4:
              {
                  system("cls");
     ofstream fileo;
     ifstream filei;
      fileo.open("temp.txt",ios::out);
      fileo.close();
            goto h;
              }
          default :
            cout<<"\tInvalid Input!!\n";
          }
           }while(c!=4);
      }
      else{
        cout<<"\tuser not found"<<endl;
        goto m;
      }
      cout<<endl;
          }
          else
            if(r=="2")
          {
              system("cls");
              cout<<"\n\n\n\t----------------------------------------Thank you for visiting:)----------------------------------------------\n\n\n";
              return 0;

          }
          else
          {
              cout<<"\t\tInvalid input...!!";
              goto h;
          }

}
void Add_user()             //Add user function- To register new employee
{
    system("cls");
    cout<<"\n\t-------------------------------------------***ADD USER***-------------------------------------------\n\n"<<endl;
    string name,psd,fname,bio,mob,mail,sal,date;
    int cl=15,med=20,parent=40;
    ofstream fileo;
    ifstream filei;
    cout<<"\n\tEnter employee name:";
      cin.ignore();
      getline(cin,name);
      cout<<"\n\tCreate a username:";
      cin>>usn;
      m=0;
      valid(usn);
      cout<<"\n\tCreate a password:";
      cin>>psd;
      fname=usn+".txt";
      //cout<<fname;
      fileo.open(fname.c_str());
      fileo<<usn<<endl<<name<<endl<<psd<<endl;
      cout<<"\n\tEmployee successfully registered:)";
      cout<<"\n\tEnter other information : \n\t\t1.Mobile No. : ";
      cin.ignore();
      getline(cin,mob);
      fileo<<mob<<endl;
      cout<<"\n\t\t2.E-mail : ";
      getline(cin,mail);
      fileo<<mail<<endl;
      cout<<"\n\t\t3.Salary: ";
      getline(cin,sal);
      fileo<<sal<<endl;
      cout<<"\n\t\t4.Date of Joining [DD/MM/YYYY] : ";
      getline(cin,date);
      fileo<<date<<endl;
      fileo<<cl<<endl;
      fileo<<med<<endl;
      fileo<<parent<<endl;
      fileo.close();

}
void Apply_leave()          //Apply leave-to apply the leaves
{
   system("cls");
    cout<<"\n\t-------------------------------------------***APPLY LEAVE***-------------------------------------------\n\n"<<endl;

   int c;
    string fname,sr[10],dates,datee,leave;
    int cl,med,Parent,flag=0,day;
     ifstream filei;
     ofstream fileo;
    string name,pw,usern,bio,mob,mail,sal,date;
     fname=name_+".txt";
      filei.open(fname.c_str());
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      getline(filei,mob);
      getline(filei,mail);
      getline(filei,sal);
      getline(filei,date);
      filei>>cl;
      filei>>med;
      filei>>Parent;
      filei.close();
    s: cout<<"\n\t___________________________________________________________________________________________________\n";            //display type of leave
	cout<<"\t|\t\t\t\t           TYPE OF LEAVE                                           |\n";
	cout<<"\t|__________________________________________________________________________________________________|\n";
    cout<<endl;
	cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] Casual Leave           |\n";
	cout<<"\t\t\t\t\t|        2] Medical Leave          |\n";
	cout<<"\t\t\t\t\t|        3] Parental Leave         |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<"\n\n\tEnter the choice [1-3]: ";
    cin>>c;
      /*check for availability of requested leave and if leave is available
      the decrements the requested leave from available count of leaves*/
      if(c==1)
      {
          if(cl!=0)
          {
         leave="Casual";
         flag=1;

          }
      }
      else
     if(c==2)
      {
          if(med!=0)
          {
         leave="Medical";
         flag=1;

          }
      }
      else
      if(c==3)
      {
          if(Parent!=0)
          {
         leave="Parental";
         flag=1;

        }
    }
      else
    {
        cout<<"\n\tInvalid input....!\n Enter [1-3]";
        goto s;
    }
    if(flag==1)
    {
        cout<<"\tEnter no of days of leave : ";
        cin>>day;
        if(leave=="Casual")
      {
          if(cl-day<0)
          {
              cout<<"\tYou dont have sufficient no. of "<<leave<<"type of leave"<<endl;
              cout<<"\tPlease Try with less no. of days...!!"<<endl;
              return;
          }
          else
          {
              cl=cl-day;
          }
      }
      else
      if(leave=="Medical")
      {
          if(med-day<0)
          {
              cout<<"\tYou dont have sufficient no. of "<<leave<<"type of leave"<<endl;
              cout<<"\tPlease Try with less no. of days...!!"<<endl;
              return;
          }
          else
          {
              med=med-day;
          }
      }
      else
         if(leave=="Parental")
      {
          if(Parent-day<0)
          {
              cout<<"\tYou dont have sufficient no. of "<<leave<<"type of leave"<<endl;
              cout<<"\tPlease Try with less no. of days...!!"<<endl;
              return;
          }
          else
          {
              Parent=Parent-day;
          }
      }
      int date_n,month,year;
 p: cout<<"\n\tEnter start date[DD/MM/YYYY]: "<<endl;
  cout << "\tEnter day [DD] : ";
   cin >> date_n;
   cout << "\tEnter Month[MM]: ";
   cin >> month;
   cout << "\tEnter year[YYYY]: ";
   cin >> year;
   int td, tm, ty;
  int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if ( year < 0 ){
       cerr << year << " is not a valid year" << endl;
       goto p;
  }
  if ( exceedsDaysInMonth(month,day) ){
    if ( month == 2 && date_n == 29 ){
        if ( ! isLeapYear(year) ){
          cerr << year << " is not a leap year, so Feb doesn't have 29 days" << endl;
          goto p;
        }
    }
    else
    {
      cerr << "\tWrong Date input ";
      goto p;
    }
  }
 td=date_n;
 tm=month;
 ty=year;
 td=td+day-1;
 if(day<=29)
 {
    if ( td > days[month-1]){
   td=td-days[month-1];
   tm++;
   if ( tm > 12 )
    { ty++; tm=1; }
 }
 cout << "\tValid date;\n\t The end date is : " <<  td << "/" <<  tm << "/" <<  ty << endl;
 }
 else
 {
     cout<<"\tEnter end date[DD/MM/YYYY]: "<<endl;
     cout << "\tEnter day[DD]: ";
   cin >> td;
   cout << "\tEnter Month[YY]: ";
   cin >> tm;
   cout << "\tEnter year[YYYY]: ";
   cin >> ty;
 }
      string status="Requested";
      y:cout<<"\tAre you sure to apply for leave ? [Yes=1/No=2] : ";
      int g;
      cin>>g;
      /*if employee is sure about applying leave then information about leave
      will be updated in respected files*/
      if(g==1)
      {
        fname=name_+"u.txt";
     fileo.open(fname.c_str(),ios::out|ios::app);
     fileo<<leave<<endl;
     fileo<<day<<endl;
     fileo<<date_n;
     fileo<<"/";
     fileo<<month;
     fileo<<"/";
     fileo<<year<<endl;
     fileo<<td;
     fileo<<"/";
     fileo<<tm;
     fileo<<"/";
     fileo<<ty<<endl;
     fileo<<status<<endl;
     fileo.close();
    fname=name_+".txt";
    fileo.open(fname.c_str());
    fileo<<usern<<endl;
    fileo<<name<<endl;
    fileo<<pass_<<endl;
    fileo<<mob<<endl;
    fileo<<mail<<endl;
    fileo<<sal<<endl;
    fileo<<date<<endl;
    fileo<<cl<<endl;
    fileo<<med<<endl;
    fileo<<Parent;
    fileo.close();
    fileo.open("Request.text",ios::out|ios::app);
      fileo<<name_<<endl;
      fileo<<leave<<endl;
      fileo<<day<<endl;
      fileo<<date_n;
     fileo<<"/";
     fileo<<month;
     fileo<<"/";
     fileo<<year<<endl;
     fileo<<td;
     fileo<<"/";
     fileo<<tm;
     fileo<<"/";
     fileo<<ty<<endl;
      fileo<<status<<endl;
      fileo.close();
      }
      else
        if(g==2)
      {
          cout<<"\tPls Try Later to apply for leave"<<endl;
          return;
      }
      else
      {
          cout<<"\tInvalid Input"<<endl;
          goto y;
      }
    }
    else
    {
        cout<<"\tYou can't get this type of leave as these are already exhausted!!" ;
    }
}
 void view_record()   //view record- displays the record of previous requested/approved leaves
 {
     system("cls");
     cout<<"\n\t------------------------------------------------***RECORD***------------------------------------------------\n\n"<<endl;

     ifstream filei;
     int i=0;
     string fname,type[MAX],no[MAX],sdate[MAX],edate[MAX],status[MAX];
     fname=name_+"u.txt";
      filei.open(fname.c_str());
      if(!filei)
      {
          cout<<"\tRecord not found...!/New Record"<<endl;
          return;
      }
      while(!filei.eof())
      {
           i++;
      getline(filei,type[i]);
      getline(filei,no[i]);
      getline(filei,sdate[i]);
      getline(filei,edate[i]);
      getline(filei,status[i]);

      }
      i--;
      filei.close();
      cout<<"\n\t________________________________________________________________________________________________\n\t|";
      cout.width(10);
      cout<<"Sr.No.";
      cout.width(15);
      cout<<"Type of Leave";
      cout.width(15);
      cout<<" No_of days";
      cout.width(15);
       cout<<" start date.";
      cout.width(15);
      cout<<" end date";
      cout.width(20);
      cout<<"Status   \t|"<<endl;
      cout<<"\t|_______________________________________________________________________________________________|\n";
      for(int n=1;n<=i;n++)
      {
          cout<<"\t|";
      cout.width(7);
      cout<<n;
      cout.width(15);
      cout<<type[n];
      cout.width(15);
      cout<<no[n];
      cout.width(20);
       cout<<sdate[n];
      cout.width(15);
      cout<<edate[n];
      cout.width(15);
      cout<<status[n];
      cout<<"      \t|\n";
      }
      cout<<"\t|_______________________________________________________________________________________________|\n";
 }
 void Profile()    //displays the data of employee stored in system
 {

     system("cls");
     int c;
    system("cls");
    cout<<"\n\t-------------------------------------------***PROFILE***-------------------------------------------\n\n"<<endl;
    string name,name1,name2,pw,usern,bio,mob,mail,sal,date,fname;
    int cl=0,med=0,Parent=0;
    ofstream fileo;
    ifstream filei;
     fname=name_+".txt";
      filei.open(fname.c_str());
      getline(filei,usern);
      getline(filei,name);
      getline(filei,pw);
      getline(filei,mob);
      getline(filei,mail);
      getline(filei,sal);
      getline(filei,date);
      filei>>cl;
      filei>>med;
      filei>>Parent;
      filei.close();
    cout<<endl;
	cout<<"\t\t\t\t\t __________________________________\n";
	cout<<"\t\t\t\t\t|        1] View Profile           |\n";
	cout<<"\t\t\t\t\t|        2] Edit Profile           |\n";
	cout<<"\t\t\t\t\t|        3] Change Pass-word       |\n";
	cout<<"\t\t\t\t\t|        4] Check Leave count      |\n";
	cout<<"\t\t\t\t\t|__________________________________|\n";
	cout<<endl;
    cout<<"\tEnter your choice : ";
    cin>>c;
    if(c==1)
    {
    filei.open(fname.c_str());
    cout<<"\tUser-name:"<<usern<<endl;
    cout<<"\tName:"<<name<<endl;
    cout<<"\tContact number : "<<mob<<endl;
    cout<<"\tMail ID : "<<mail<<endl;
    cout<<"\tSalary : "<<sal<<endl;
    cout<<"\tDate of joinning : "<<date<<endl;
    cout<<"\tCasual Leave : "<< cl<<endl;
    cout<<"\tMedical Leave : "<< med<<endl;
    cout<<"\tParental Leave : "<< Parent<<endl;
    filei.close();
    }
    else
        if(c==2)
    {
        string input;
    fileo.open(fname.c_str());
    cout<<"\t_________________________Details can be edited________________________"<<endl;
    cout<<"\t1.Name : "<<name<<endl;
    cout<<"\t2.Contact number : "<<mob<<endl;
    cout<<"\t3.Mail ID : "<<mail<<endl;
    cout<<"\t________________________________________________________________________"<<endl;
    cout<<"\tEnter the number of field to be changed/edited [1-3]: ";
    cin>>input;
 if(input=="1")
    {
    cout<<"\tEnter first name : ";
    cin>>name1;
    name1=name1+" ";
    cout<<"\tEnter Last name : ";
    cin>>name2;
    fileo<<usern<<endl;
    fileo<<name1;
    fileo<<name2<<endl;
    fileo<<pw<<endl;
    fileo<<mob<<endl;
    fileo<<mail<<endl;
    fileo<<sal<<endl;
    fileo<<date<<endl;
    fileo<<cl<<endl;
    fileo<<med<<endl;
    fileo<<Parent;
    fileo.close();
    cout<<"\tName changed successfully...!!"<<endl;
    }
else
{
    if(input=="2")
    {
    cout<<"\tNew Number : ";
    cin>>mob;
    cout<<"\tContact number changed successfully !!"<<endl;
    }
    else
 if(input=="3")
    {
    cout<<"\tNew Mail : ";
    cin>>mail;
    cout<<"\tMail ID changed successfully !!"<<endl;
    }
   fileo<<usern<<endl;
    cin.ignore();
    fileo<<name<<endl;
    fileo<<pw<<endl;
    fileo<<mob<<endl;
    fileo<<mail<<endl;
    fileo<<sal<<endl;
    fileo<<date<<endl;
    fileo<<cl<<endl;
    fileo<<med<<endl;
    fileo<<Parent;
    fileo.close();
}
 }
    else
        if(c==3)
    {
    cout<<"\tEnter New Password : ";
    cin>>pass_;
    fileo.open(fname.c_str());
    fileo<<usern<<endl;
    fileo<<name<<endl;
    fileo<<pass_<<endl;
    fileo<<mob<<endl;
    fileo<<mail<<endl;
    fileo<<sal<<endl;
    fileo<<date<<endl;
    fileo<<cl<<endl;
    fileo<<med<<endl;
    fileo<<Parent;
    fileo.close();
    cout<<"\tPassword changed successfully....";
    }
    else
        if(c==4)
    {
        cout<<"\t LEAVE         Alloted Leaves     Available Leaves"<<endl;
        cout<<"\tCasual              15\t\t\t"<<cl<<endl;
        cout<<"\tMedical             20\t\t\t"<<med<<endl;
        cout<<"\tParental            40\t\t\t"<<Parent<<endl;
    }
    else
    cout<<"\tWrong input !!"<<endl;
}
 void view_mrecord()            //displays the previous record of leaves of employees which are approved/rejected.
 {
     system("cls");
    cout<<"\n\t-------------------------------------------***RECORD***-------------------------------------------\n\n"<<endl;
     string name[MAX],leave[MAX],sdate[MAX],edate[MAX],status[MAX],time[MAX],day[MAX];
     ifstream filei;
     filei.open("mrecord.text",ios::out|ios::app);
      int i=0;
      while(!filei.eof())
      {
           i++;
      getline(filei,time[i]);
      getline(filei,name[i]);
      getline(filei,leave[i]);
      getline(filei,day[i]);
      getline(filei,sdate[i]);
      getline(filei,edate[i]);
      getline(filei,status[i]);

      }
      i--;
      filei.close();
    cout<<"\n\t__________________________________________________________________________________________________________\n\t|";
       cout.width(10);
      cout<<"Sr.No.";
      cout.width(20);
      cout<<"Date & Time";
      cout.width(15);
      cout<<"name";
      cout.width(10);
      cout<<"Type";
      cout.width(13);
       cout<<"no of days";
       cout.width(12);
      cout<<"start date";
      cout.width(13);
      cout<<"end date";
      cout.width(10);
      cout<<"Status";
      cout<<"  |"<<endl;
      cout<<"\t|_________________________________________________________________________________________________________|\n";
      for(int n=1;n<=i;n++)
      {
      cout<<"\t|";
      cout.width(6);
      cout<<n;
      cout.width(30);
      cout<<time[n];
      cout.width(10);
      cout<<name[n];
      cout.width(10);
      cout<<leave[n];
      cout.width(6);
      cout<<day[n];
      cout.width(18);
       cout<<sdate[n];
      cout.width(14);
      cout<<edate[n];
      cout.width(10);
      cout<<status[n];
      cout<<" |"<<endl;
      }
      cout<<"\t|_________________________________________________________________________________________________________|\n";
}
  void Approve_leave()      //function to approve leave
  {
      system("cls");
      cout<<"\n\t-------------------------------------------***APPROVE LEAVE***-------------------------------------------\n\n"<<endl;
    string fname,type[MAX],no[MAX],dates[MAX],datee[MAX],estatus[MAX],st,day[MAX];
    string namee,pw,usern,bio,mob,mail,sal,date;
       ifstream filei;
       ofstream fileo;
      string name[50],leave[50],sdate[50],edate[50],status[50];
      int cl,med,Parent,iday[50];
      filei.open("Request.text",ios::in);
      int i=0;
      while(!filei.eof())
      {
           i++;
      getline(filei,name[i]);
      getline(filei,leave[i]);
      getline(filei,day[i]);
      getline(filei,sdate[i]);
      getline(filei,edate[i]);
      getline(filei,status[i]);
      }
      i--;
      filei.close();
      cout<<"\n\t\t____________________________________________________________________________\n\t\t|";
       cout.width(8);
      cout<<"Sr.No.";
      cout.width(8);
      cout<<"name";
      cout.width(9);
      cout<<"Type";
      cout.width(13);
       cout<<"no of days";
       cout.width(12);
      cout<<"start date";
      cout.width(13);
      cout<<"end date";
      cout.width(10);
      cout<<"Status";
      cout<<"  |"<<endl;
      cout<<"\t\t|___________________________________________________________________________|\n";
      for(int n=1;n<=i;n++)
      {
      cout<<"\t\t|";
      cout.width(4);
      cout<<n;
      cout.width(12);
      cout<<name[n];
      cout.width(10);
      cout<<leave[n];
      cout.width(6);
      cout<<day[n];
      cout.width(18);
       cout<<sdate[n];
      cout.width(14);
      cout<<edate[n];
      cout.width(10);
      cout<<status[n];
      cout<<" |"<<endl;
      }
      cout<<"\t\t|___________________________________________________________________________|\n";
      for(int m=1;m<=i;m++)
      {
          stringstream geek(day[m]);
          iday[m]=0;
          geek>>iday[m];
      }
      for(int p=1;p<=i;p++)
      {
          string st;
          int c;
          s:cout<<"\tTake Action for sr. no."<<p;
          cout<<"\n\t1.Approve\n\t2.Reject\n\t\tEnter your choice [1/2]: ";
          cin>>c;
          if(c==1)
          {
              status[p]="Approved";
          }
          else if(c==2)
          {
      status[p]="Rejected";
      /*if leave is rejected then this function will return the leaves of employee which are
      decremented during employee applying for leave */
      fname=name[p]+".txt";
      filei.open(fname.c_str());
      getline(filei,usern);
      getline(filei,namee);
      getline(filei,pw);
      getline(filei,mob);
      getline(filei,mail);
      getline(filei,sal);
      getline(filei,date);
      filei>>cl;
      filei>>med;
      filei>>Parent;
      filei.close();
      if(leave[p]=="Casual")
      {
          cl=cl+iday[p];
      }
      else
        if(leave[p]=="Medical")
      {
          med=med+iday[p];
      }
      else
        if(leave[p]=="Parental")
      {
          Parent=Parent+iday[p];
      }
    fileo.open(fname.c_str());
    fileo<<usern<<endl;
    fileo<<namee<<endl;
    fileo<<pw<<endl;
    fileo<<mob<<endl;
    fileo<<mail<<endl;
    fileo<<sal<<endl;
    fileo<<date<<endl;
    fileo<<cl<<endl;
    fileo<<med<<endl;
    fileo<<Parent;
    fileo.close();
          }
          else
          {
              cout<<"\tInvalid Input";
              goto s;
          }
          fname=name[p]+"u.txt";
      filei.open(fname.c_str());
      int h=0;
      string utype[MAX],uno[MAX],udate[MAX],usdate[MAX],uedate[MAX],ustatus[MAX];
      while(!filei.eof())
      {
           h++;
      getline(filei,utype[h]);
      getline(filei,uno[h]);
      getline(filei,usdate[h]);
      getline(filei,uedate[h]);
      getline(filei,ustatus[h]);
      }
      h--;
      filei.close();
      for(int k=1;k<=h;k=k)
      {
          while(ustatus[k]=="Approved"||ustatus[k]=="Rejected")
          {
              k++;
          }
          ustatus[k]=status[p];
         // cout<<"Status has been changed \n";
          break;
      }
      fname=name[p]+"u.txt";
      int j;
     fileo.open(fname.c_str(),ios::out);
     if(!fileo)
     {
         cout<<"Unable to open user file"<<endl;
     }
     for(j=1;j<=h;j++)
     {
       fileo<<utype[j]<<endl;
     fileo<<uno[j]<<endl;
     fileo<<usdate[j]<<endl;
     fileo<<uedate[j]<<endl;
     fileo<<ustatus[j]<<endl;
     }
     fileo.close();

      }
       time_t now = time(0);
   char* date_time = ctime(&now);
   l:cout<<"\tAre you done with your work ??\n\n\tWant to confirm??\n\n\t1.Yes\n\t2.No\n\tEnter your choice[1/2] : ";
   int v;
   cin>>v;
   if(v==1)
   {
      fileo.open("Request.text",ios::out);
      fileo.close();
      fileo.open("mrecord.text",ios::out|ios::app);
      if(!fileo)
      {
          cout<<"Unable to open master record "<<endl;
      }
      for(int q=1;q<=i;q++)
      {
      fileo<<date_time;
      fileo<<name[q]<<endl;
      fileo<<leave[q]<<endl;
      fileo<<day[q]<<endl;
      fileo<<sdate[q]<<endl;
      fileo<<edate[q]<<endl;
      fileo<<status[q]<<endl;
      }
      fileo.close();
   }
   else
    if (v==2)
   {
       cout<<"\tPlease Try again to approve leave ";
       return;
   }
   else
   {
       cout<<"\tInvalid Input !!"<<endl;
       goto l;
   }
}
