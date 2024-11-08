/*
Programmed by:
Najam Iqbal
*/

/* IT WILL WORK ON WEEKLY BASIS.
This program is about clinical appointment and management sysytem, This is for 100 patients and 10 doctors.
It will allow doctor to enter his info like name, fee and schedule etc. Then display appointments to patients
according to the Dr schedule. If any appointment will get booked it will disply BOOKED for that. Along with 
this it will allow admin to calculate bill by entering price for the medicines recommended by the doctor
This Program will show menu for Doctor, Patient and Admin.
THIS PROGRAM USES STRICT INPUT VALIDATION WHICH PREVENT IT FROM CRASHING AT ANY POINT DUE TO WRONG INPUT*/


#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdlib.h>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;

// PROTOTYPES OF ALL FUNCTIONS.
void clrscr();
void line_1();
int input_validator(string , int ,int ,int );
string num_validator();
float float_validator(string ,int ,int );
int char_validator(string,int);
string bld_grp_validator();
string str_len_validator(int, int ,string );
string name_validator(int);
void dr_schd();
void Dr_data_entry(); 
void Dr_rec(int);
void Patient_entery();
void p_Delete(int );
void d_Delete(int);  
void p_info(int);
void DR_patient_entery(int);
void appt_dsply(int);
void appt_selection(int);
void appointments(char);
void patient_record(int);
void dr_menu();
void patient_menu();
void admin_menu();
void choices ();

//all the global constants and variables needed in two or more functions.
const int NUM_dr=20, PH_num=11, WEEK_days=7, NO_Patients=100,NO_medics=10;
string Dr_name[NUM_dr], Dr_specialization[NUM_dr],Patient_name[NO_Patients],Bld_grp[NO_Patients],Dgns[NO_Patients],Rpt[NO_Patients],Medcs[NO_Patients][NO_medics];
float hb[NO_Patients],Bld_p[NO_Patients],Hgt[NO_Patients],Weg[NO_Patients],bill[100];
string Patient_num[PH_num];
const string nameweekdays[]={"Monday","Tuesday","Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const string show_timmings[]={"08:00AM-02:00PM","02:00PM-08:00PM","08:00AM-08:00PM"},hrs[]={"08:00AM","09:00AM","10:00AM","11:00AM","12:00PM","01:00PM","02:00PM","03:00PM","04:00PM","05:00PM","06:00PM","07:00PM"};
int dr_time[NUM_dr][WEEK_days][1],dr_ID=0, p=0,Patient_age[NO_Patients],dr_fee[NUM_dr],selec_dr[100],sel_day[100],sel_time[100];
char week[NUM_dr][WEEK_days];
bool dr_avb[NUM_dr],appt[NUM_dr][WEEK_days][12],apt_chk[100];
string str_len_validator(int len,string txt),Exit_Program,exit1;
                              

/*###############*******************MAIN FUNCTION**************#######################*/
int main()
{
cout<<"WELCOME! This program is about clinical appointment and management sysytem, This is for 100 patients and 10 doctors.";
cout<<"\nPress any key to continue: ";
getch();
cout<<"\nYou are Admin,Before starting set password(max 10 digits-min 5 digits): ";
exit1=str_len_validator (5,10, "Password");
cout<<"\nRemember your password, You will need it frequently\nPress any key to continue\n";
getch();
do
{
  choices();
  
} while (Exit_Program!=exit1);
return 0;  
}

/*________________________________________Funtion to clear screen_____________________________________*/
void clrscr()// this code in comments should be used if other is not clearing screen properly.
{ /*{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);}*/

  cout << "\033[2J\033[H";
  cout << "\033[2J\033[H";
  cout << "\033[2J\033[H";
  }

/*________________________________________Funtion to draw line_____________________________________*/
void line_1()
{cout<<"\n___________________________________________________________________________________\n";}
/*___________________________________Function to Vlidate input (only numbers)_______________________*/
/* This functions takes a string as an argument to disply it on screen, range by getting minimum and maximum number
and length i.e maximum digits to avoid processing in case of large input*/

int input_validator(string choice, int min,int max,int len)
{
    string input=str_len_validator(min,max,choice);
    long long int calculatr=0;
    int l=input.length();//using length function to determine the length of string input
    for(int i=0;i<l;i++)
    if((input[i]<char(48))||(input[i]>char(57)))//confirming that all charcters are numbers
     {
      cout<<"Non-Number values are not Allowed!\nTry Again!"<<endl;
     return input_validator(choice,min,max,len);//recursive function 
     break;}
       for(int counter=0;counter<l;counter++)
      calculatr=calculatr*10+int(input[counter]-'0');

     if(!(calculatr>=min&&calculatr<=max))
     {
      cout<<"\nWrong "<<choice<<"!\nEnter again";
     return input_validator(choice,min,max,len);//recursive function
     }
     else
      return calculatr;// returning the validated numerical value.
    }

/*___________________________________Function to Validate 11 digits phone number _______________________*/
string num_validator()
{
    string input=str_len_validator(11,11,"Phone Number");
    
    int l=input.length(),point_chk=0, point_locator=0;//finding the length of string input.
    for(int i=0;i<l;i++)
    if((input[i]<char(48))||(input[i]>char(57)))//confirming that all charcters are numbers
     {
      cout<<"Non-Number values are not Allowed!\nTry Again!"<<endl;
     return num_validator();//recursive function 
     }
    if (l==11)//  Check if the length of the input is exactly 11 digits
    return input;
    else
    {
      cout<<"Wrong Number!\nTry Again!"<<endl;
     return num_validator();//recursively  calling the  function in case of invalid input
    }
  }    
/*________________________________________Funtion to validate float INPUT____________________________________*/ 
float float_validator(string choice,int min,int max)
{
    string input;
    cout<<"Enter "<<choice<<": ";
    getline(cin,input);// using getline function to take input from user
    float calculatr=0;
    int l=input.length(),point_chk=0, point_locator=l-1;//finding the length of input string usin .length function
    
     for(int counter=0;counter<l;counter++)
     {if((input[counter]<char(48)||input[counter]>char(57))&&(input[counter]!='.'))//confirming that all charcters are numbers
     {
      cout<<"Non-Number values are not Allowed!\nTry Again!"<<endl;
      return float_validator( choice, min, max);
      break;
     }
      if (input[counter]=='.') //locating point(.) to convert int into float
       {point_locator=counter;
       }
        if (input[counter]=='.')// Skip for decimal point during conversion
      continue;
      calculatr=calculatr*10+int(input[counter]-'0');}// Convert the valid digits to float
     for(int counter=l-1;counter>point_locator;counter--) // Adjust the float value based on the position of the decimal point
      calculatr/=10;
	  // Check if the float value is within the specified range				
      if(calculatr<min||calculatr>max)
      {cout<<"\nInvalid "<<choice<<" Try again!\n";
       return float_validator( choice, min, max);
      }
      return calculatr;}  // Return the validated float value
/*________________________________________Funtion to validate CHARACTER INPUT (1-9)____________________________________*/ 
int char_validator(string choice, int max)
{   cout<<"\nEnter "<<choice<<": ";  
    string ch="123456789";
    char input=getche(); // Get a character input using getche() without enter key
    int calculatr=0;
    bool chk;
      for(int i=0;i<max;i++)
      {if(input==ch[i])//Checking with all charcters
      {chk=true;
      break;}
      else
      {chk=false;}}
      if(chk==false)// If the input character is not valid, prompt the user again
      {cout<<"\nWrong "<<choice<<endl;
      return char_validator(choice,max);}// Recursively call the function 
    
      calculatr=int(input)-'0';//converting string into integer
     
       return calculatr;}// Return the validated integer value
      

/*________________________________________Funtion to validate blood group____________________________________*/
  string bld_grp_validator()
	{//  Variables to store blood group and Rh factor
	string blod_group, outpt;
	char rhfactor;
	cout<<"\nEntetr the blood group (in BLOCK): ";//Prompt the user to enter the blood group (in BLOCK)
	getline(cin,blod_group);
	cout<<"\nplease enter whether your Blood group is positive or negative ";// Prompt the user to enter whether their Blood group is positive or negative
	rhfactor=getche();
	  if ((blod_group=="A"&&(rhfactor=='+'||rhfactor=='-'))||(blod_group=="B"&&(rhfactor=='+'||rhfactor=='-')) ||(blod_group=="O"&&(rhfactor=='+'||rhfactor=='-'))
	     ||(blod_group=="AB"&&(rhfactor=='+'||rhfactor=='-')) )// Check if the entered combination is a valid blood group
	     outpt=blod_group+rhfactor;
	     else
	    return bld_grp_validator();// If not valid, recursively call the function for re-entering the blood group
      return outpt;// Return the validated blood group and Rh factor combination
  }
/*________________________________________Funtion to validate string length____________________________________*/ 
   string str_len_validator(int min,int max,string txt)
    { string st;
      cout<<"\nEnter "<<txt<<": ";// Prompt the user to enter the specified text
      getline(cin, st);
      if(st.length()>max||st.length()<min)// Check if the length of the entered string is within the specified range
      {
        cout<<"Invalid "<<txt<<"!\nTry Again";// If invalid, print an error message and recursively call the function for re-entering the string
      return str_len_validator(min, max,txt);}
      else  // If valid, return the entered string
      return st; }
/*________________________________________Funtion to validate Name____________________________________*/ 
   string name_validator(int len)
    { string st;
       bool chek=1;
        // Use str_len_validator to ensure the length of the entered name is within the specified range
      st=str_len_validator(3,len,"Name");
      // Check if each character in the name is valid (letters, hyphen, period, space)
      for(int i=0;i<st.length();i++)
      if(!((st[i]>='A'&&st[i]<='Z')||(st[i]>='a'&&st[i]<='z')||(st[i]=='-'||st[i]=='.'||st[i]==char(32))))
      // If invalid, print an error message and recursively call the function for re-entering the name
      { cout<<"Invalid name!\nEnter Again";
      return name_validator(len);
        break;}
      return st; }// If the name is valid, return the entered name
/*___________________________________Function to take data from Doctor__________________________________________*/
int Dr_appointment(int id)
{ int apt=0;
  for(int i=0; i<100;i++)  // Loop through the array of Patient names
  if(Patient_name[i]=="0") // Skip empty slots in the array
  continue;
  else if(Patient_name[i]=="\0")// Break the loop if an empty slot is encountered
  break;
   else if(selec_dr[i]==id) // Check if the appointment is for the specified doctor ID
   apt++;
  return apt;// Return the count of appointments for the specified doctor
}
/*________________________________________Funtion to enter schedule from doctor____________________________________*/
void dr_schd(int drid)
{
  for(int day=0; day<WEEK_days; day++) // Iterate through the days of the week
      {
        do
        {cout<<endl<<"You are available on "<<nameweekdays[day]<<" ?-";  // Prompt the user to confirm his availability on a specific day
        week[drid][day]=getche();
        if( week[drid][day]=='Y'||week[drid][day]=='y')// If available, prompt the user to choose timings
        {cout<<"\nChoose Your Timmings:\n1=08:00AM-02:00PM\n2=02:00PM-08:00PM\n3=08:00AM-08:00PM\n"; 
        dr_time[drid][day][0]=char_validator("choice",3);
        dr_avb[drid]=true;}
        }
       while(week[drid][day]!='Y'&&week[drid][day]!='y'&&week[drid][day]!='N'&&week[drid][day]!='n');
       
    line_1();}// Call the line_1 function
}
/*___________________________________Function to take data from Doctor__________________________________________*/
void Dr_data_entry() 
{  for(int p=0; p<NUM_dr;p++)//loop to fill-up empty enteries i.e. for which data is deleted.
   { if(Dr_name[p]=="0"||Dr_name[p]=="\0") //checking for empty arrays 
  { dr_avb[p]=false;
    cout<<"\nRemember Your ID # "<<p+1;
   // Collect and validate doctor name, specialization, and fee
    Dr_name[p]=name_validator(25);
    Dr_specialization[p]=str_len_validator(1,25,"Specialization");
    dr_fee[p]=input_validator("Fee", 0,10000,5);
    cout<<"\nPress Y for yes and N for no ";// Prompt the user to set availability schedule
    dr_schd(p);
  }
  else
  continue;
  break;}
}
 /*______________________________________________Function to display doctor's Profile______________________________________________*/   
    void Dr_rec(int drec) 
    {
      cout<<"ID# "<<drec+1<<endl;// Display the doctor's ID
       // Display the doctor's name and specialization
      cout<<"Name : DR."<<Dr_name[drec]<<endl;
      cout<<"Specialization :"<<Dr_specialization[drec]<<endl;
    // Display the days and timings the doctor is available
      cout<<"Available on: ";
      for(int i=0;i<WEEK_days;i++)
      { if(week[drec][i]=='y'||week[drec][i]=='Y')
        {cout<<endl<<nameweekdays[i]<<" Timmings: "<<show_timmings[dr_time[drec][i][0]-1]<<endl;}
      }
      
    // Display a message if the doctor is not available
      if( dr_avb[drec]==false)
      cout<<" NOT AVAILABLE\n";
      line_1();//// Call the line_1 function
    }
/*___________________________________________________Function to take data from Patient___________________________________________________*/    
void Patient_entery() 
{  for(int p=0; p<NO_Patients;p++)//loop to fill-up empty enteries i.e. for which data is deleted.
    if(Patient_name[p]=="0"||Patient_name[p]=="\0") //checking for empty arrays
    {cout<<"\nRemember Your ID # "<<p+1;
     // Collect and validate patient name, age, and phone number
    Patient_name[p]=name_validator(25);
    cout<<endl<<Patient_name[p];
    cout<<"\nEnter your age (yrs): ";
    Patient_age[p]=input_validator("Age",1,100,2);
    cout<<"\nEnter your Phone number (11-digits) ";
    Patient_num[p]=num_validator();//calling number validator function
	line_1();// Call the line_1 function
    break;}
}
/*___________________________________________________Function to delete patient record_______________________________________________________*/
void p_Delete(int p){
// Adjust the index to start from ID-1, because at the timming of id assigning we assigned index+1.
  p-=p;
 // Check if the patient record exists at that location
  if(Patient_name[p]=="0"||Patient_name[p]=="\0")
{
  cout<<"\nNo Record Found!\n";
}
else
{Patient_name[p]="0";
Bld_grp[p]=Rpt[p]=Patient_age[p]=Patient_age[p]=Weg[p]=Hgt[p]=Bld_p[p]=hb[p]=appt[selec_dr[p]][sel_day[p]][sel_time[p]]=apt_chk[p]=bill[p]=0;

int mcount=0;
    do
    {
    Medcs[p][mcount]="\0";
    mcount++;
    } while (mcount<10);
    cout<<"\nRecord Deleted";
    line_1(); //caliing line()_1 function
}}
/*________________________________________________Function to delete doctor record_________________________________________________________*/
void d_Delete(int p)
{p-=p;
if(Dr_name[p]=="0"||Dr_name[p]=="\0")// Check if the doctor record exists
{
  cout<<"\nNo Record Found!\n";
}
else
{Dr_name[p]="0";//// Delete doctor record by setting the name to "0" 
Dr_specialization[p]='\0';
int dcount=0;
    do
    {
    week[p][dcount]='\0';
    dcount++;
    } while (dcount<7);
    cout<<"\nRecord Deleted";
    line_1();}//calling line_1() function
}
/*____________________________________________Function for editing doctor record___________________________________________*/
void edit_dr(int val)
{
int dc;
val-=1;// Adjust the index to match the array's zero-based indexing
if(Dr_name[val]!="0" && Dr_name[val]!="\0") // Check if a valid record exists for the given index
while(1)
{
cout<<"\nYou have following options:\n1=Edit Name.\n2=Edit Specialization.\n3.Edit Fee.\n4.Edit Timmings.\n5=Exit."; // Display the available options to the user
dc=char_validator("Choice",5);
 // Perform actions based on the user's choice
switch(dc)
{
  case 1:
  Dr_name[val]=name_validator(25); // Edit the doctor's name
  break;

  case 2:
  Dr_specialization[val]= str_len_validator(1,25, "Specialization");  // Edit the doctor's specialization
  break;

  case 3:
  dr_fee[val]=input_validator("Fee",100,50000,5); 
  break;

  case 4:
  if(Dr_appointment(val)==0) 
  dr_schd(val);
  else
  cout<<"\nYou cannot edit this, because you have pending appointments.";
  break;
  
  case 5:    // Exit the editing loop
  return;    
  break;
}
}
else
{
  cout<<"\nNo Record Found!\n";
  return;
}
}
/*______________________________________________Function to display patient persnol info_______________________________________________________*/
void p_info(int val){

// Adjust the index to start from ID-1, because at the timming of id assigning we assigned index+1.
val-=1;
// Displaying personal information (non-editable) for the patien
    cout<<"\"Personal Info (Non-Editable)\"";
    cout<<"\nPatient ID # "<<val+1;
    cout<<"\nName: "<<Patient_name[val];
    cout<<"\nAge (yrs): "<<Patient_age[val];
    cout<<"\nPhone number: "<<Patient_num[val];
}

/*____________________________________________Function to allow doctor to enter patient data_____________________________________________*/
void DR_patient_entery(int p) {

// Adjust the index to start from ID-1, because at the timming of id assigning we assigned index+1.
 p-=1;
  // Check if a valid patient record exists for the given index 
  if(Patient_name[p]!="0"&&Patient_name[p]!="\0")
  { p_info(p+1);// Display patient's personal information
     // Medical record entry for the patient
    cout<<"\n\"Medical Record\"";
    Weg[p]=float_validator("Weight(Kg)",1,150);
    Hgt[p]=float_validator("Height(Inches)",12,90);
    cout<<"\nBlood Group: ";
    Bld_grp[p]=bld_grp_validator();
    hb[p]=float_validator("Hb",4,23);
    Bld_p[p]=float_validator("Blood pressure (mmHg)",70,180);
    Rpt[p]=str_len_validator(1,3000,"Report");
    cout<<"\nMedicines/Injections Recommended:\n(ENTER * WHEN YOU COMPLETED WITH ALL Enteries) "; // Medicines/Injections Recommended entry
    int mcount=0;
    do
    {
    cout<<endl<<mcount+1<<". ";  
    Medcs[p][mcount]=str_len_validator(1,30,"");
    mcount++;
    } while (Medcs[p][mcount-1]!="*"&&mcount<10);
    appt[selec_dr[p]][sel_day[p]][sel_time[p]]=apt_chk[p]=0;}// Resetting appointment status for the patient
    else
    cout<<"\nNo record found!";// Display a message if no valid record is found for the given index
    line_1();
}

/*_____________________________________Function to display all the appointments__________________________________________________*/
void appt_dsply(int choice)
{ choice-=1;// Adjust the index to start from ID-1, because at the timming of id assigning we assigned index+1.
  cout<<"\nYou Choosed Dr."<<Dr_name[choice]; // Display the selected doctor's name and available appointments
  cout<<"\nHis Following Appointments are Available:\n";
  
  for(int d=0;d<7;d++)// Iterate through the days of the week
  { cout<<endl<<d+1<<"-"<<nameweekdays[d]<<endl;
  if(dr_avb[choice]==true && week[choice][d]=='y'||week[choice][d]=='Y') // Check if the doctor is available on the selected day
  {if(dr_time[choice][d][0]==1)
  { 
    for(int a=0;a<6;a++) // Display available appointments based on the time slots
   if(appt[choice][d][a]!=1)
   cout<<a+1<<". "<<hrs[a]<<endl;
   else
   cout<<" BOOKED\n";
  }
  else if(dr_time[choice][d][0]==2)
  {
    for(int b=0;b<6;b++)
    if(appt[choice][d][b]!=1)
   cout<<b+1<<". "<<hrs[b+6]<<endl;
   else
   cout<<" BOOKED\n";
  }
  else if(dr_time[choice][d][0]==3)
  {
    for(int c=0;c<12;c++)
    if(appt[choice][d][c]!=1)
   cout<<c+1<<". "<<hrs[c]<<endl;
   else
   cout<<" BOOKED\n";
  }}
  else
  cout<<"Not Available\n";// Indicate that appointments are not available on the selected day
  }}

/*_______________________________________Function for appointment selection_____________________________________________*/
void appt_selection(int choice)
{ choice-=1;
  int time, day;
  cout<<"\nSelect day(1-7)";
  day=char_validator("Day",7);
  while(week[choice][day-1]=='N'||week[choice][day-1]=='n')
 { cout<<"\nDoctor not Available, Enter again "; 
  day=char_validator("Day",7);}
  if(dr_time[choice][day-1][0]!=3)
  {cout<<"\nSelect Time(1-6)";
  time=input_validator("time",1,6,1);
  while(appt[choice][day-1][time-1]==1)
  time=input_validator("time",1,6,1);}
  else
  {cout<<"\nSelect Time(1-12)";
  time=input_validator("time",1,12,2);
  while(appt[choice][day-1][time-1]==1)
  {cout<<"\nAlready Booked, Enter Again";
    time=input_validator("time",1,12,2);}}
 
  
    cout<<"\nNeed Your ID to confirm appointment";
    int y=input_validator("ID",1,100,3);
    int brk=0;
    while(brk<3&&(Patient_name[y-1]=="0"||Patient_name[y-1]=="\0"))
    {  
       cout<<"\nNo record Found! Try again (for"<<3-brk<<" Times)"<<endl;
      y=input_validator("ID",1,100,3);
     brk++;
     }
    if(apt_chk[y-1])
    cout<<"\n Already having appointment";
    else if(Patient_name[y-1]!="0"&&Patient_name[y-1]!="\0")
    {appt[choice][day-1][time-1]=1;
    selec_dr[y-1]=choice,sel_day[y-1]=day-1,sel_time[y-1]=time-1, apt_chk[y-1]=1;
    cout<<"\nAppointment Booked for you!";}
    else
    {cout<<"\nAppointment not booked!";}
}
/*______________________________________________Function to get appointment_________________________________________*/
void appointments(char x='y')
{ if(x=='y')  // if y or nothing is passed in arguments then execute function for showing and booking appointments. other wise just show appointments
  { cout<<"\n1=Register Yourself(If new Patient)\n2=Previous Patient";
  int p_ch=input_validator("choice",1,2,1);
  if(p_ch==1) // Register a new patient if chosen
        
  Patient_entery();}
  int choice,chk1=0,chk2=0;
   // Display available doctors
  cout<<"\nAvialable Doctors: \n";
  for(int apcheck=0;apcheck<10;apcheck++)
  { // Check if any doctor's data is entered
    if(Dr_name[0]=="\0")
    {cout<<"Sorry! Doctor's Data is not entered";
    return;
    break;}
     else if(Dr_name[apcheck]=="\0")
     break;
     else if(Dr_name[apcheck]=="0"||dr_avb[apcheck]==false)
     continue;
     else
     Dr_rec(apcheck);
     if(Dr_name[apcheck]!="0"&&Dr_name[apcheck]!="\0")// Count the total number of doctors and the number of available doctors
     chk1++;
     if(Dr_name[apcheck]!="0"&&Dr_name[apcheck]!="\0"&&dr_avb[apcheck]==false)
     chk2++;
  }
  if (!((Dr_name[0]=="\0")||(chk1==chk2))) // Check if there are available doctors
  {
  {cout<<"Choose any Doctor by entering ID# "; // Prompt the user to choose a doctor by entering the ID
  choice=input_validator("ID",1,10,2);
  }
  appt_dsply(choice); // Display available appointments for the chosen doctor
  // If the user wants to proceed with appointment selection, call appt_selection function
  if(x=='y')//default argument is y. if user put 
  appt_selection(choice);
  }
  else
  cout<<"\nNo doctor Available"; // Inform the user if no doctors are available
  }

/*__________________________________Function to calculate bill_______________________________________________________*/
void cal_bill(int p_id)
{ if(apt_chk[p_id]==0)  // Check if the checkup for the patient has been held
 { p_id-=1;  
  for (int i=0; i<10;i++) // Iterate through the patient's prescribed medicines
  { if(Medcs[p_id][i]=="*"||Medcs[p_id][0]=="\0") // Break the loop if the end of the medicine list is reached
    break;
    cout<<"\nEnter price for"<<Medcs[p_id][i]<<endl;// Prompt the user to enter the price for each medicine
    int x=float_validator("price", 1,10000);
    bill[p_id]+=x;
  }
 bill[p_id]+=dr_fee[selec_dr[p_id]];}
 else
 cout<<"\nCheckup not held";// Inform the user if the checkup has not been held
}

/*_______________________________________________Function to disply bill______________________________________________________*/
void displ_bill(int p_id)
{p_id-=1; 
if(Patient_name[p_id]=="0"||Patient_name[p_id]=="\0")  // Check if a patient with the given ID exists 
cout<<"\nNo patient with this ID";
else if(bill[p_id]!=0) // Display the patient's bill if it is not zero 
cout<<"\nYour Bill is : Rs"<<bill[p_id];
else
cout<<"\n Not generated yet";// Inform the user that the bill has not been generated yet
}

/*________________________________________________________Function for displying patient record_________________________________________________________*/
void patient_record(int x)
{  
    { x=x-1;// Adjust the index to start from ID-1, because at the timming of id assigning we assigned index+1.
    p_info(x+1);   // Display personal information for the patient 
    cout<<"\n\"Medical Record\"";// Display medical record information for the patient
    cout<<"\nWeight(Kg): "<<Weg[x]<<"Kg";
    cout<<"\nHeight(Inches): "<<Hgt[x]<<"inches";
    cout<<"\nBlood Group: ";
    cout<<"\nHb: "<<hb[x];
    cout<<"\nBlood Pressure: "<<Bld_p[x]<<"mmHg";
    cout<<"\nReport: "<<Rpt[x];
    cout<<"\nMedicines Recommended: "; // Display recommended medicines for the patient
    for(int i=0;i<10;i++)
    { if(Medcs[x][0]=="*")  // Break the loop if the end of the medicine list is reached
      {cout<<"\n NO";
      break;
      }
      if(Medcs[x][i]=="*")
      break;
      cout<<Medcs[x][i]<<" ";
    }
    if(selec_dr[x])// Display the appointed consultant (doctor) for the patient
    cout<<"\nConsultant: Dr. "<<Dr_name[selec_dr[x]];
    else
    cout<<"\nConsultant not appointed ";
    }
    
    line_1();//calling line_1() function
   
}
/*_________________________________________________________Function for doctor menu______________________________________________________________*/

void dr_menu()
{   char c1;
   while(1)
   {
    clrscr();
   cout<<"\nMENU FOR DOCTORS ONLY\nEnter yor Choice: \n1= Fill-up new Entry\n";
   cout<<"2= Update your Profile\n3= View Patient's Record\n4= Enter Patient's Record\n5=Back to Main menu";
   c1=char_validator("choice",5);//calling char_validator function
   switch (c1)
   {
   case 1:
   { Dr_data_entry();}// Option to fill up a new entry in the doctor's data
    break;

   case 2:
   {int a;
   a=input_validator("ID",1,100,3);// Option to update the doctor's profile by entering the ID
   edit_dr(a);}
    break;

   case 3:
   {int p_Id;
   cout<<"\nEnter patient ID";// Option to view a patient's record by entering the patient's ID
   p_Id=input_validator("ID",1,100,2);
   if(Patient_name[p_Id-1]!="\0") // Check if the patient record exists and display it
   patient_record(p_Id);
   else
    {
    cout<<"\nNo Record Found!";
    }}
    break;
   case 4:
  { int p;  // Option to enter a patient's record by entering the patient's ID
   cout<<"\nEnter Patient ID#";
   p=input_validator("ID",1,100,2);
   DR_patient_entery(p);}
    break;
   case 5:  // Exit the doctor menu and return to the main menu
   return;
   }
   getch();}
   }
/*_______________________________________________________Function for patient menu____________________________________________________________*/
void patient_menu()
{
   int c2;
    // Loop to keep the menu running until the user chooses to exit
   while (1)
   {clrscr();// Clear the screen.
   cout<<"\nFOR PATIENTS ONLY\nEnter yor Choice: \n1= View Appointments\n2=Get Appointment\n3= View Bill\n4=Back to Main Menu\n";
   c2=char_validator("Choice",4);// Get and validate the user's choice
   switch (c2) // Switch statement to perform actions based on the user's choice
   {
   case 1:
   { appointments('n');} // Option to view appointments 
    break;
    
    case 2:
     {appointments();}// Option to get a new appointment
    break;

   case 3:
   {int p_id; // Option to view the bill by entering the patient's ID
    p_id=input_validator("ID",1,100,3);
    displ_bill(p_id);}
    break;

   case 4:     // Exit the patient menu and return to the main menu
     {return;}
    break;
   }getch();}
}
/*_______________________________________________Function for admin menu________________________________________________________________*/
void admin_menu()
{
  while(1) // Clear the screen (assuming clrscr() is a function to clear the screen)
   {clrscr();
    int c3;
    // Display the administrative menu options
   cout<<"\n Enter yor Choice: \n1=View Doctor's Record\n2=View Patients's Record\n3=Genarate Bill\n4=View All Doctors\n5=View All Patients\n6=Delete patient record\n7=Go Back to MAIN MENU\n";
   c3=char_validator("Choice",7); // Get and validate the user's choice
   switch (c3)
   {
   case 1:// Switch statement to perform actions based on the user's choice
   {int drec;
    cout<<"\nEnter Doctor ID";
    drec=input_validator("ID",1,10,2);
    if(Dr_name[drec-1]=="\0"||Dr_name[drec-1]=="0")
    {cout<<"\nNo record found!\n ";}
    else
     Dr_rec(drec-1);}
    break;
   case 2: // Option to view a specific patient's record by entering the patient's ID
   {int p_Id;
   cout<<"\nEnter patient ID";
   p_Id=input_validator("ID",1,100,2);
   if(Patient_name[p_Id-1]!="\0" && Patient_name[p_Id-1]!="0")
   patient_record(p_Id);}
    break;

   case 3: // Option to generate a bill for a specific patient by entering the patient's ID
   {int p_no=input_validator("ID",1,100,3);
   if(Patient_name[p_no-1]=="\0"||Patient_name[p_no-1]=="0")
    {cout<<"\nNo record found!\n ";}
    else
   cal_bill(p_no);}
    break;

   case 4: // Option to view all registered doctors
   for(int i=0; i<=100; i++)
   {
    if(Dr_name[i]!="\0"&&Dr_name[i]!="0")
    cout<<"\nID# "<<i+1<<" Name: Dr."<<Dr_name[i]<<" specialization: "<<Dr_specialization[i];
    else if(Dr_name[i]=="0")
    continue;
    else if(Dr_name[0]=="\0")
    { cout<<"\nNo Doctor registered yet";
      break;                        }
    else if(Dr_name[i]=="\0")
    break;
   }
    break;

   case 5:// Option to view all registered patients
   for(int i=0; i<100; i++)
   {
    if(Patient_name[i]!="\0"&&Patient_name[i]!="0")
    cout<<"\nID# "<<i+1<<" Name: "<<Patient_name[i];
    else if(Patient_name[i]=="0")
    continue;
    else if(Patient_name[0]=="\0")
    { cout<<"\nNo patient registered yet";
      break;                        }}
    break;

   case 6: // Option to delete a specific patient record by entering the patient's ID
   {int del;
   del=input_validator("Patient ID",1,100,2);
   p_Delete(del-1);}
    break;

   case 7:
   return; // Exit the admin menu and return to the main menu
   }
   getch();
   }
}
/*_______________________________________________________Function for main menu___________________________________________________________________*/   
void choices ()
{
  clrscr();
  int check;
   // Display menu choices
   cout<<"\nYour Choice: \n1= Doctor\n2= Patient\n3= Admin\n4=Exit program\nJUST PRESS THE NUMBER\n";
   check=char_validator("choice",4);
   switch(check) // Switch statement to perform actions based on the user's choice
   {
  case 1:// Option for doctors to access their menu
  dr_menu();
  break;

  case 2:// Option for patients to access their menu
  patient_menu();
  break;
   
  case 3: // Option for administrators to access their menu, requires password validation
  {string pass=str_len_validator(5,10,"Password");
  if(pass==exit1)
  admin_menu();
  else
  cout<<"\nWrong Password";}
  break;
  
  case 4: // Option to exit the program, requires password validation
  Exit_Program=str_len_validator(1,10,"Password");
  if(Exit_Program==exit1)
  return;
  else 
  cout<<"\nWrong Password";
  getch();
  }

}
/*_______________________________________________________END______________________________________________________________*/
