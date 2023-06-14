#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<cmath>

using namespace std;
void resultsComputation(int index);
void menu(int tt);
void show_student_info(int searchkey);     //function used to show data to end-user.
void get_data(int i);           //function used to obtain data from end-user.
void search_student_info(int searchkey);
void add_student();      //This function is used to add record of new student.
void edit_student_info(int idnumber);   //function is used to edit existing record.
void updateStudentStatus(int studentIndex);
void addstudentresults(int s);
void viewstudentresults(int t);
void UpdateStudentResults();
   
int ts;

struct student    //Structure student is made to store student attributes.
{ 
  int rollno; 
  string name;
  string fname;
  int cell;
  string dob;
  string address;
};

struct studentResults
{
	string status;
    float subject1;
    float subject2;
    float subject3;
    float subject4;
    float subject5;
    float average;
    float total;
    string reward;
};

studentResults res[5]; // 
student rec[50];  //This is basic array of defined structure to student data.

int main()
{  
  system("CLS");
	cout << "***********===========================***********" << endl;
	cout << "\t WELCOME TO RESULT SYSTEM" << endl << endl;
	cout << "         Student Registration " << endl;
	cout << "<================================================>" << endl << endl; 		
	cout<<"Enter The Total Number of Student(s)- Max 50: ";
	cin>>ts;
	
	add_student();
	
	menu(ts); 
  return 0;
}

  
void get_data(int i)        //Function for receiving data from user and populatiing the variables with values.
{   
  cout<<"Enter student roll number: ";
  cin>>rec[i].rollno;
  cout<<"Enter student name: ";
  cin>>rec[i].name;
  cout<<"Enter student's Father name: ";
  cin>>rec[i].fname;
  cout<<"Enter student's cell phone number: ";
  cin>>rec[i].cell;
  cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
  cin>>rec[i].dob;
  cout<<"Enter student's Address: ";
  cin>>rec[i].address;
}

void show_student_info(int searchkey)      //Function for showing data on the screen.
{    
  int i=searchkey;
  cout<<i<<"    ";
  cout<<rec[i].rollno<<"   ";
  cout<<rec[i].name<<"     ";
  cout<<rec[i].fname<<"\t";
  cout<<rec[i].cell<<"   ";
  cout<<rec[i].dob<<"   ";
  cout<<rec[i].address<<"\n\n";
}

void search_student_info(int searchkey)
{
  for(int i=0;i<=ts;i++)       //Loop thrugh complete array.
 { 
   if(rec[i].rollno==searchkey)    //If roll number matches to search term.
  {   
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    show_student_info(i);       //A function is used inside another function.
   }
  } 
}

void add_student()         //This function is used to add record of new student.
{    
  for(int i=0;i<ts;i++)
 {
    get_data(i);          //Loop was processed 5 times to get input for 5 students.
  }
  system("CLS");
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
  cout<<"--------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<ts;i++)
 {
    show_student_info(i);        //Loop was processed for 5 times to show obtained records.
  }
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  system("pause");

  menu (ts);          //Return to main function to again show menu.
}

void edit_student_info(int idnumber)     //function is used to edit existing record.
{  
  for(int i=0;i<ts;i++)       //Loop is started.
 {  
   if(idnumber==i)       //Through loop every value is compared with search term.
  {         
    cout<<"\nExisted information about this record.\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    show_student_info(i);       //Load information for existing record.
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);         //Inputing data for that specific record.
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
    menu(ts);           //Return to main function.
   }
  }
}

void UpdateStudentResults() {
    int studentindex;
    cout << "Enter the index of the student to update: ";
    cin >> studentindex;
    if (studentindex < 1 || studentindex > ts){
        cout << "Invalid index." << endl;
        return;
    }
    cout << "Enter new results for student " << studentindex << ":" << endl;
    cout << "Subject 1: ";
    cin >> res[studentindex - 1].subject1;
    cout << "Subject 2: ";
    cin >> res[studentindex - 1].subject2;
    cout << "Subject 3: ";
    cin >> res[studentindex - 1].subject3;
    cout << "Subject 4: ";
    cin >> res[studentindex - 1].subject4;
    cout << "Subject 5: ";
    cin >> res[studentindex - 1].subject5;
    updateStudentStatus(studentindex - 1);
    cout << "Results updated for student " << studentindex << endl;
    
    system("pause");
    menu(ts);
}

void viewstudentresults(int t) {
    for (int i = 0; i < t; i++) {
        cout << "Results of student " << i + 1 << ":" << endl;
        cout << "Subject 1: " << res[i].subject1 << "\t" << res[i].reward << endl;
        cout << "Subject 2: " << res[i].subject2 << "\t" << res[i].reward << endl;
        cout << "Subject 3: " << res[i].subject3 << "\t" << res[i].reward << endl;
        cout << "Subject 4: " << res[i].subject4 << "\t" << res[i].reward << endl;
        cout << "Subject 5: " << res[i].subject5 << "\t" << res[i].reward << endl;
        cout << endl;
        cout << "Total Score: " << res[i].total << endl;
        cout << "Average: " << res[i].average << endl;
        cout << "Status: " << res[i].status << endl;
    }
    system("pause");
    menu(ts);
}

void addstudentresults(int s) {
    for (int i = 0; i < s; i++) {
        cout << "Enter results for student " << i + 1 << ":" << endl;
        cout << "Subject 1: ";
        cin >> res[i].subject1;
        cout << "Subject 2: ";
        cin >> res[i].subject2;
        cout << "Subject 3: ";
        cin >> res[i].subject3;
        cout << "Subject 4: ";
        cin >> res[i].subject4;
        cout << "Subject 5: ";
        cin >> res[i].subject5;
        updateStudentStatus(i);
        resultsComputation(i);
        cout << endl;
    }
    system("pause");
    menu(ts);
}

void updateStudentStatus(int studentIndex) {
    int subjectsAbove50 = 0;

    if (res[studentIndex].subject1 >= 50) {
        subjectsAbove50++;
    }
    if (res[studentIndex].subject2 >= 50) {
        subjectsAbove50++;
    }
    if (res[studentIndex].subject3 >= 50) {
        subjectsAbove50++;
    }
    if (res[studentIndex].subject4 >= 50) {
        subjectsAbove50++;
    }
    if (res[studentIndex].subject5 >= 50) {
        subjectsAbove50++;
    }

    if (subjectsAbove50 == 5) {
        res[studentIndex].status = "Pass";
    } else if (subjectsAbove50 >= 3) {
        res[studentIndex].status = "Retake";
    } else {
        res[studentIndex].status = "Supplementary";
    }
    
}

void menu(int tt){
  int choice;   //int variable used to determine which operation user want to do.
  int idnumber;   //int variable used to record ID number whih user want to edit.
  int searchkey;  //int variable to store student roll_no by which user can search.

 	while(tt--)
 	{
	  cout << "\n\t\tWhat do you want to do?"<<endl;
	  cout << "\t\t----------------------"<<endl;
	  cout << "\t\t1-Add student" << endl;
	  cout << "\t\t2-Edit student" << endl;
	  cout << "\t\t3-Search student"<<endl;
	  cout << "\t\t4-Quit Program" << endl;
	  cout << "\t\t5-Add Results" << endl;
	  cout << "\t\t6-View Results " << endl;
	  cout << "\t\t7-Update Results" << endl;
	  cout << "\t\t----------------------" << endl;
	  cout << "Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:         //If user presses 1 then student adding module would be displayed.
    add_student();
    break;
   
   case 2:         //If there are no records in array then it will ask the user to input records first.
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    menu(ts);
   }
    
	else         //If records are present in array then it will show table.
   { 
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl; 
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
     cout<<"--------------------------------------------------------------------------------"<<endl; 

     for(int i=0;i<=tt;i++)
    {
      show_student_info(i);     //funtion is called with index value to show data.
    }

     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";
   
     cin>>idnumber;            //Asking the user at which ID he wants to make a change.
       
    if(idnumber>tt || idnumber<0)  //Validating the ID number.
    {      
        cout<<"\nInvalid ID Number."<<endl;
    }
    
	else
    {
        edit_student_info(idnumber);    //Passing ID number to Edit Function.
    }
   }
   break;
   
  case 3:
    if(rec[0].rollno==0)     //If no record exist then ask the user o enter records first.
   {   
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     menu(ts);         //Return to main so user can input new record.
    }
    
	else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;     //roll_no as the search key can be entered by user.
     search_student_info(searchkey);}
     break;
   
   case 4:
    exit(0);        //Terminating the records.
    break;
   
   case 5:
    addstudentresults(ts);
    break;
    	
   case 6:
   	viewstudentresults(ts);
	break;
	
   case 7:
   	UpdateStudentResults();
	   break; 
   
   default:         //Default value for ivalid Input. 
    cout<<"Invalid number."<<endl;
    system("pause");
  menu(ts);
  }
}
}

void resultsComputation(int index)
{
	    res[index].total = res[index].subject1 + res[index].subject2 + res[index].subject3
    				+ res[index].subject4 +res[index].subject5; 
    
    res[index].average = res[index].total / 5;
    
	if(res[index].subject1 <= 100 && res[index].subject1 >= 80 )
    {
		res[index].reward = "A";
	}
	
	else if(res[index].subject1 <= 79 && res[index].subject1 >= 60 )
	{
		res[index].reward = "B";
	}
	
	else if(res[index].subject1 <= 59 && res[index].subject1 >= 40)
	{
		res[index].reward = "C";
	}
	
	else if(res[index].subject1 <= 39 && res[index].subject1 >= 20 )
	{
		res[index].reward = "D";
	}
	
	else if(res[index].subject1 <= 19 && res[index].subject1 >= 0 )
	{
		res[index].reward = "F";
	}
	
	if(res[index].subject2 <= 100 && res[index].subject1 >= 80 )
    {
		res[index].reward = "A";
	}
	
	else if(res[index].subject2 <= 79 && res[index].subject2 >= 60 )
	{
		res[index].reward = "B";
	}
	
	else if(res[index].subject2 <= 59 && res[index].subject2 >= 40)
	{
		res[index].reward = "C";
	}
	
	else if(res[index].subject2 <= 39 && res[index].subject2 >= 20 )
	{
		res[index].reward = "D";
	}
	
	else if(res[index].subject2<= 19 && res[index].subject2 >= 0 )
	{
		res[index].reward = "F";
	}

	if(res[index].subject3 <= 100 && res[index].subject3 >= 80 )
    {
		res[index].reward = "A";
	}
	
	else if(res[index].subject3 <= 79 && res[index].subject3 >= 60 )
	{
		res[index].reward = "B";
	}
	
	else if(res[index].subject3 <= 59 && res[index].subject3 >= 40)
	{
		res[index].reward = "C";
	}
	
	else if(res[index].subject3 <= 39 && res[index].subject3 >= 20 )
	{
		res[index].reward = "D";
	}
	
	else if(res[index].subject3 <= 19 && res[index].subject3 >= 0 )
	{
		res[index].reward = "F";
	}

	if(res[index].subject4 <= 100 && res[index].subject4 >= 80 )
    {
		res[index].reward = "A";
	}
	
	else if(res[index].subject4 <= 79 && res[index].subject4 >= 60 )
	{
		res[index].reward = "B";
	}
	
	else if(res[index].subject4 <= 59 && res[index].subject4 >= 40)
	{
		res[index].reward = "C";
	}
	
	else if(res[index].subject4 <= 39 && res[index].subject4 >= 20 )
	{
		res[index].reward = "D";
	}
	
	else if(res[index].subject4 <= 19 && res[index].subject4 >= 0 )
	{
		res[index].reward = "F";
	}

	else if(res[index].subject5 <= 100 && res[index].subject5 >= 80 )
    {
		res[index].reward = "A";
	}
	
	if(res[index].subject5 <= 79 && res[index].subject5 >= 60 )
	{
		res[index].reward = "B";
	}
	
	else if(res[index].subject5 <= 59 && res[index].subject5 >= 40)
	{
		res[index].reward = "C";
	}
	
	else if(res[index].subject5 <= 39 && res[index].subject5 >= 20 )
	{
		res[index].reward = "D";
	}
	
	else if(res[index].subject5 <= 19 && res[index].subject5 >= 0 )
	{
		res[index].reward = "F";
	}

    system("pause");
    menu(ts);


}
