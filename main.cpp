#include <iostream>
#include<fstream>
#include<string>
#include<stdio.h> 
using namespace std;

class Vaccine                                                       //Hybrid Inheritance
{                                                                     //Vaccine 
  protected:                                            //Booking   //Center1   //Center2
       string no;
       string Aadhar;    
       string fname,lname;
       string gender;  //
       int age;
       int status;

  public:
      
      virtual void getdata()=0;                   //Abstract Class
        void intro();
        bool checkinfiles(); 
        bool login(string);
        void asperstatus_options(int status);
        bool inputinfile1();
     

};

class Booking :  public Vaccine
{
  protected:
       string Center;
       string VaccineName;
  public : 
      void getdata(); 
      bool inputinfile2();
      void certificate();   //Not yet ready
      bool book() //Not yet ready
      {
        
        getdata();
      
        try
        {
          
        if(inputinfile2()==0)                       //EXCEPTION HANDLING
        throw "\nException Occured";
        }
        catch(...)
        {
          cout<<"\nException Occured";
        }
        
        return true;
      }
}b; 

void Booking::getdata()
      {
        int ch;
        cout<<"1.Covishield\n2.Covaxin\n3.Sputnik"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
          case 1:
          VaccineName="Covishield";
          break;
          case 2:
          VaccineName="Covaxin";
          break;
          case 3:
          VaccineName="Sputnik";
          break;
          default:
          cout<<"Wrong choice";
        }
        
        cout<<"1.Center 1\n2.Center 2 \n ";
        cout<<"Enter your choice";
        cin>>ch;
        switch(ch)
        {
          case 1:
                 Center="Center1";
                 cout<<"Your vaccine is booked";
                 break;
          case 2:
                 Center="Center2";
                 cout<<"Your vaccine is booked";
                 break;
          
          default:
          cout<<"You entered wrong choice";
          break;
        }
      }


void Vaccine::intro()
{
 int i=0;
  cout<<"\nEnter mobile number : "; //Take user mobile number
 cin>>no;
 while(no[i]!='\0')
  {
  i++;
  }
  if(i!=10)     //Condition for mobile number greater than 10
  {
  cout<<"\n!! Enter correct mobile no !!";
  intro();
  } 
 cout<<"\nEnter name  : ";
 cin>>fname;

 for(int i=0;i<fname.length();i++){
   if(fname[i]>='a' && fname[i]<='z')
   {
     fname[i]=fname[i]-32;
   }
 }
 
     if(checkinfiles())
    {
        asperstatus_options(status);  
    }
    else  login(no);
       
}

bool Vaccine :: checkinfiles()       
{
       int a;
       string k,n;
       ifstream f;
       f.open("File1.txt");
   //f>>k;
   //  cout<<k<<endl<<no;
   
 while(f)
  {
     f>>k;
     f>>n;
     f>>n;
    
     if(k==no && n==fname)
     {
     
     f>>lname;
     f>>gender;
     f>>age;
     f>>status;
     
     
     }
     else{
     
      f>>k;
      f>>k;
      f>>a;
      f>>a;
     }
   
  }
  
  
  f.close();
  if(lname.size()>0) {
    return true;
  }
  return false;

}     //Returns 1 if no is in files

void Vaccine :: asperstatus_options(int status)
{
  int choice;
  if(status==0) //If not vaccinated then book the vaccine
  {
    cout<<"\n1.BOOK VACCINE\n2.Add more profile with same mobile number\n3.Exit\n";
    cin>>choice;
    switch(choice) 
    {
      case 1:b.book();
            break;
     case 2:cout<<"\nEnter fname : ";
            cin>>fname;
            login(no);
            break;    
     case 3:cout<<"\nYour loved ones need you\nGet the COVID-19 vaccine to make sure you can be there for them." <<endl;
             cout<<"\nBe smart,wear mask\n|| STAY HEALTHY,STAY VACCINATED ||" <<endl;
             cout<<"\nStay tuned for further updates"<<endl;
             
             exit(0);
             break;     
    };
   }
   else if(status==1)
   {
    cout<<"\n1.BOOK VACCINE\n2.Add more profile with same mobile number\n3.Certificate\n4.Exit\n";
    cin>>choice;
    switch(choice) 
    {
     case 1 : b.book();
            break;
      case 2:cout<<"\nEnter fname : ";
            cin>>fname;
             login(no);
             break;   
   case 3:b.certificate();
           break; 
      case 4:cout<<"\nYour loved ones need you\nGet the COVID-19 vaccine to make sure you can be there for them." <<endl;
             cout<<"\nBe smart,wear mask\n|| STAY HEALTHY,STAY VACCINATED ||" <<endl;
             cout<<"\nStay tuned for further updates"<<endl;
             exit(0);
             break;     
    };
  }
  else if(status==2)
  {
      cout<<"\n1.Certificate\n2.Add more profile with same mobile number\n3.Exit\n";
    cin>>choice;
    switch(choice) 
    {
     case 1:b.certificate();
            break;
     case 2:cout<<"\nEnter fname : ";
            cin>>fname;
            login(no);
            break;    
      case 3:cout<<"\nYour loved ones need you\nGet the COVID-19 vaccine to make sure you can be there for them." <<endl;
             cout<<"\nBe smart,wear mask\n|| STAY HEALTHY,STAY VACCINATED ||" <<endl;
             cout<<"\nStay tuned for further updates"<<endl;
             exit(0);
             break;     
    };      
  }
}
 
 bool Vaccine :: inputinfile1()
{
ofstream f; 
f.open("File1.txt",ios::app);
f<<no<<" ";//Add phone number to file
f<<Aadhar<<" ";  
f<<fname<<" ";             
f<<lname<<" ";  
f<<gender<<" ";          
f<<age<<" ";             
f<<status<<" "<<endl;     
f.close();
return true;
}

bool Booking :: inputinfile2()
{
fstream f; 
f.open("booking.txt",ios::app|ios::out);
f<<no<<" ";            //Add phone number to file
f<<Aadhar<<" ";  
f<<fname<<" ";
f<<lname<<" ";           
f<<age<<" ";            
f<<status<<" ";  
f<<VaccineName<<" ";
f<<Center<<" "<<endl;
f.close();
return true;
}


bool Vaccine :: login(string no)
{
  int choice,i=0;
  cout<<"\nEnter Aadhar No(no spaces allowed): ";
  cin>>Aadhar;
  while(Aadhar[i]!='\0')
  {
  i++;
  }
  if(i!=12)     //Condition for mobile number greater than 10
  {
  cout<<"\n!! Enter correct Aadhar No of 12 digits !!";
  login(no);
   } 
 
   cout<<"\nEnter surname:";
   cin>>lname;
   for(int i=0;i<lname.length();i++){
   if(lname[i]>='a' && lname[i]<='z'){
     lname[i]=lname[i]-32;
   }
 }
 
   cout<<"\nEnter  gender:"<<endl;
   cin>>gender;
     
  cout<<"\nEnter age : ";
  cin>>age;
  if(age<=18)                            //Only above 18 can take vaccination
  {
  cout<<"\n\t\tSORRY!!Vaccination for  under 18 age is not started yet.\nStay tuned for further updates.\n\n"<<endl;
  cout<<"\nYour loved ones need you\nGet the COVID-19 vaccine to make sure you can be there for them." <<endl;
  cout<<"\nBe smart,wear mask\n|| STAY HEALTHY,STAY VACCINATED ||" <<endl;
  cout<<"\nStay tuned for further updates"<<endl;
  exit(0);
  }
  
  cout<<"\nNo. of vaccines taken(0/1/2) : ";
  cin>>status;
                         //Add status to file
 inputinfile1();
  asperstatus_options(status);

 return true;  //Return 1 if successfull
}

 void Booking :: certificate()
 {
   

cout<<"-------------------------------------------------------"<<endl;
cout<<"CERTIFICATE FOR COVID-19 VACCINATION"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"-------------------"<<endl;
cout<<"Beneficiary Details"<<endl;
cout<<"--------------------"<<endl;
cout<<"Beneficiary Name :"<<fname<<endl;
cout<<" "<<lname;
cout<<"Age: "<<age<<endl;
cout<<"Gender: "<<gender<<endl;

if(status==2){
  cout<<"Vacccination Status:Fully Vaccinated (2 Doses)"<<endl;
}
else
cout<<"Vacccination Status:Partially Vaccinated ( 1 Dose)"<<endl;
cout<<"\n-------------------"<<endl;
cout<<"Vaccination Details"<<endl;
cout<<"-------------------"<<endl;
if(VaccineName=="Covisheild"){
  cout<<"Vaccine Name:Covisheild"<<endl;
  cout<<"Manufacturer: Serum Institute of India pvt.Ltd."<<endl;
}
else if(VaccineName=="Covaxin"){
  cout<<"Vaccine Name: Covaxin "<<endl;
  cout<<"Manufacturer: Bharat Biotech Institute of India pvt.Ltd."<<endl;
}
else if(VaccineName=="Sputnik"){
  cout<<"Vaccine Name: Sputnik "<<endl;
  cout<<"Manufacturer: Gamaleya Research institute of Epidemiology and Microbiology ,Russia."<<endl;
}
cout<<"Vaccine Type:COVID-19 Vaccine"<<endl;
cout<<"Dose Status:"<<status<<endl;
if(b.Center=="Center1"){
  cout<<"Vaccination At:Center 1"<<endl;
}
else
cout<<"Vaccination At:Center 2"<<endl;
exit(0);
 }


int main()
{   
     cout<<"\n\t\t\t------------------------------------------\n" ;
   cout<<"\t\t\t\t ### VACCINE BOOKING SYSTEM ###"<<endl;
   cout<<"\n\t\t\t------------------------------------------\n" ; 
   cout<<"\n\t\t\t\t================ WELCOME ================\n" ;  
  char x;
       
  do
  {

       b.intro(); 
       cout<<"\nDo you want to continue(y/n)";
       cin>>x; //introduction
  }while(x=='Y'||x=='y');
  
     cout<<"\nYour loved ones need you\nGet the COVID-19 vaccine to make sure you can be there for them." <<endl;
     cout<<"\nBe smart,wear mask\n|| STAY HEALTHY,STAY VACCINATED ||" <<endl;
     cout<<"\nStay tuned for further updates"<<endl;
}

  