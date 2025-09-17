#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct education
{
	string degree;
	string passingyear;
	float per;
};
struct student
{
	char firstname[20];
	char lastname[20];
	string course;
	int regno;
	string dob;
	string contact;
	string econtact;
	string address;
	education q[10];
	string cnic;
	int count=0;
	int reg;
};


int next()
{
	ifstream file("reg.txt");
		int reg=1000;
		if(file>>reg)
		reg++;
		file.close();
		
		ofstream out("reg.txt");
		
		out<<reg;
		out.close();
		return reg;

}


void challan(int reg,string name)
{
int opt[5],c1,c2,c3,c4,c5,sum=0,course;
char ch;	
cout<<"\nIn how many courses you want to apply (Max 3): ";
while(true){
cin>>course;
if(course>3||course<0)
cout<<"\nEnter right amount!";
else
break;}
cout<<"\nSelect course:\n1. Basic Computer Course\n2. Advanced Computer Course\n3. Graphic Designing Course\n4. English Language Course\n5. Freelancing\n";
for(int i=0;i<course;i++)
{
cout<<"Enter your Choise for "<<i+1<<" course : ";
	cin>>opt[i];
}
char yn;
float per=0;
float dis;
cout<<"Do you want to apply any discount? (y/n)   : ";
cin>>yn;
	if(yn=='y'||yn=='Y')
{
	cout<<"Enter Discount in Percentage  : ";
	cin>>per;
	}
	int op=per;
cout<<"\033[32m\n=============================================================================\n";
cout<<"                                     Challan                                    ";
cout<<"\n=============================================================================\033[0m\n\n";
		
		cout<<"\nRegistration Number   :        "<<reg;
		cout<<"\nName                  :        "<<name
			<<"\033[32m\n_________________________________________________________\033[0m\n";

		cout<<"\033[32m\nTittle                                          Fee\033[0m"
		    <<"\nAdmission Fee                                 RS. 5000";
		int ad=5000;
		sum+=ad;
		for(int i=0;i<course;i++)
{
		switch (opt[i])
        {
 case 1:
	{
		c1=5000;
		sum+=c1;
		cout<<"\nBasic Computer Course                         RS. 5000";
		break;}
		
		case 2:
		{
		cout<<"\nAdvanced Computer Course                      RS. 8000";
		c2=8000;
		sum+=c2;
		break;
		}
		case 3:
		{
		cout<<"\nGraphic Designing Course                      RS. 7000";
		c3=7000;
		sum+=c3;
		break;
		}
		case 4:
		{
		cout<<"\nEnglish Language Course                       RS. 10000";
		c4=10000;
		sum+=c4;
		break;}
		case 5:
		{
		cout<<"\nFreelancing                                   RS. 10000";
		c5=10000;
		sum+=c5;
		break;	
		}
		}}
{
	per=per/100;
	dis=sum-(sum*per);	
}	
		cout<<"\nTotal Fee                                     RS. "<<sum;
		cout<<"\nDiscount Applied                               "<<op<<"%";
		cout<<"\nDiscounted Fee                                RS. "<<dis
			<<"\033[32m\n___________________________________________________________\033[0m\n";
		

}



int main()
{
	int option,choic;
	student s;
	char op='y';
int ch;
	cout<<"\033[31m============================================================================\033[31m\n";
	cout<<"\t\t\t\033[31mWelcome to eCure IT academy\033[0m\t\t\t\t\t";
	cout<<"\n\033[31m============================================================================\033[0m";
	cout<<"\n   eCure IT Academy is a modern training center offering practical courses in";
	cout<<"\n Basic & Advanced Computing, Web Designing, Graphic Designing, English Language,"; 
	cout<<"\n  and Freelancing. Our goal is to equip students with real-world IT skills for ";
	cout<<"\n                  success in today\'s digital world.\n";
	while(true)
	{
		cout<<"\n\033[32mMenu\033[0"
		<<"\n\033[32m1.\033[0m Registration"
		<<"\n\033[32m2.\033[0m Fee Challan"
		<<"\n\033[32m3.\033[0m Courses Detail"
		<<"\n\033[32m4.\033[0m View Records"
		<<"\n\033[32m5.\033[0m Exist";
		cout<<"\n\033[33mEnter your choice : \033[0m";
		cin>>ch;
		if(ch==5)
		break;
		switch (ch)
		{
			case 1:
				{
				s.reg=next();
				cout<<"Registration number             :    "<<s.reg<<endl;
				cout<<"Enter your First Name           :    ";
				cin>>s.firstname;
				cout<<"Enter your Last Name            :    ";
				cin>>s.lastname;
				cin.ignore();
				cout<<"Enter your Date of birth        :    ";
				getline(cin, s.dob);
				cout<<"Select your Desire course       :    ";
				getline(cin,s.course);
				cout<<"Enter your Address              :    ";
				getline(cin,s.address);
				cout<<"Enter your CNIC number          :    ";
				getline(cin,s.cnic);
				cout<<"\n\033[34m***********************Contact Info*********************\033[0m\n";
				cout<<"Enter your Contact Number       :    ";
				getline(cin,s.contact);
				cout<<"Enter Emargency Contact Number  :    ";
				getline(cin,s.econtact);
				cout<<"\n\033[34m***********************Qualification*********************\033[0m\n";
				
					for(int i=0;i<10;i++){
				cout<<"Enter Degree Title              :    ";
				getline(cin, s.q[i].degree);
				cout<<"Enter Passing year              :    ";
				cin>>s.q[i].passingyear;
				cout<<"Enter Percentage                :    ";
				cin>>s.q[i].per;
				s.count++;
				cout<<"Do you want to add more qualification(y/n) : ";
				cin>>op;
				cin.ignore();
				if(op!='y'&&op!='Y')
				{
				break;}
				
			
			}
			int opti;
			cout<<"\n\033[31m-----Please review your application before submit it-----\033[0m";
			cout<<"\nFor Submit it (Press 0) ";
			cout<<"\nTo Cancel your Application (Press 1)";
			cout<<"\nEnter your Choice : ";
			
			while (true)
			{
			cin>>opti;
			if(opti==0)
				{
				cout<<"\n\033[32m                     You Successfully Registered\033[0m";
				
				ofstream write;
				write.open("Student.txt", ios::app);
				write<<"______________________________________________________________\n";
				write<<"                    Registration Number : "<<s.reg;
				write<<"\n______________________________________________________________\n\n";
				write<<"\nFirst Name                    :     "<<s.firstname;
				write<<"\nLast Name                     :     "<<s.lastname;
				write<<"\nCNIC                          :     "<<s.cnic;
				write<<"\nDesire Course                 :     "<<s.course;
				write<<"\nDate of Birth                 :     "<<s.dob;
				write<<"\n=========================================================";
				write<<"\n                         Contact Info                    \n";
				write<<"=========================================================\n";
				write<<"Contact Number                :     "<<s.contact;
				write<<"\nEmergency Contact Number      :     "<<s.econtact;
				write<<"\n=========================================================";
				write<<"\n                         Qualification                    \n";
				write<<"=========================================================\n";
				for(int i=0;i<s.count;i++)
				{
				write<<"\nDegree Title                  :     "<<s.q[i].degree;
				write<<"\nPassing Year                  :     "<<s.q[i].passingyear;
				write<<"\nPercentage                    :     "<<s.q[i].per<<"%"<<endl;
				
				}
				break;}
				else if(opti==1){
				cout<<"";
				break;}
				else
				cout<<"\n\033[31mSelect right option : \033[0m";
				}
				cout<<"\nFor Main Menu Press 0\nFor Exit Press 1\nSelect option : ";
				while (true)
				{
						cin>>option;
				if(option==0)
				{
				cout<<"\n\033[032m--------------------Main Menu------------------------------\n\033[0m";
				break;}
				
				else if(option==1)
				{
				cout<<"\033[33m                      Good Bye              \033[0m\n";
				break;
				}
				else
				cout<<"\033[031mYou Select wrong option. Please Select correct option.\033[0m";
				}
				break;
				
		}
		break;
		case 2:
			{
			int reg;
			string name;
			cout<<"Enter Registeration Number           :     ";
			cin>>reg;
			cin.ignore();
			cout<<"Enter Name                           :     ";
			getline(cin,name);
			challan(reg,name);
			while(true)
			{
				cout<<"\nMain Menu Press 0 ";
				cout<<"\nExit Press 1\nYour Choice : ";
				cin>>choic;
				if(choic==0)
				{
				cout<<"\n\033[32m--------------------Main Menu------------------------------\033[0m\n";
				break;
				}
				else if(choic==1)
				{
				cout<<"\033[31m                      Good Bye              \033[0m\n";
				break;}
				else
				cout<<"\n\033[31mPlease Select right option.\033[0m";
			}
			break;
			
		
	}
	case 3:
	cout << "\033[32m=============================================================\n";
cout << "                 eCure IT Academy - Course Details           \n";
cout << "=============================================================\033[0m\n\n";

cout << "\033[32m1. Basic Computer Course\n";
cout << "-------------------------------------------------------------\033[0m\n";
cout << "\033[34m Description :\033[0m\n";
cout << "   - A beginner-level course to introduce basic computer skills.\n";
cout << "\033[34m Topics Covered :\033[0m\n";
cout << "   - Computer fundamentals\n";
cout << "   - MS Word, Excel, PowerPoint\n";
cout << "   - File management, typing practice\n";
cout << "   - Internet browsing and email usage\n";
cout << "\033[33m Course Fee  : Rs. 5000\033[0m\n";
cout << "\033[34m Benefits    :\033[0m\n";
cout << "   - Essential for beginners and students\n";
cout << "   - Helps in school, college, and basic jobs\n\n";

cout << "\033[32m2. Advanced Computer Course\n";
cout << "-------------------------------------------------------------\033[0m\n";
cout << "\033[34m Description :\033[0m\n";
cout << "   - Advanced-level course for technical computer operations.\n";
cout << "\033[34m Topics Covered :\033[0m\n";
cout << "   - Advanced MS Office (Excel formulas, PowerPoint animations)\n";
cout << "   - Windows installation, software installation\n";
cout << "   - Basic networking and troubleshooting\n";
cout << "\033[33m Course Fee  : Rs. 8000\n\033[0m";
cout << "\033[34m Benefits    :\033[0m\n";
cout << "   - Suitable for office workers and IT support roles\n";
cout << "   - Improves computer handling skills for career growth\n\n";

cout << "\033[32m3. Graphic Designing Course\n";
cout << "-------------------------------------------------------------\033[0m\n";
cout << "\033[34m Description :\033[0m\n";
cout << "   - Creative course to learn design for digital platforms.\n";
cout << "\033[34m Topics Covered :\033[0m\n";
cout << "   - Adobe Photoshop & Illustrator basics\n";
cout << "   - Social media post and logo design\n";
cout << "   - Poster, banner, and visiting card designing\n";
cout << "\033[33m Course Fee  : Rs. 7000\033[0m\n";
cout << "\033[34m Benefits    :\033[0m\n";
cout << "   - Ideal for freelancing and creative careers\n";
cout << "   - Enables work in advertising and digital marketing\n\n";

cout << "\033[32m4. English Language Course\n";
cout << "-------------------------------------------------------------\033[0m\n";
cout << "\033[34m Description :\033[0m\n";
cout << "   - Practical course to improve English speaking and writing.\n";
cout << "\033[34m Topics Covered :\033[0m\n";
cout << "   - Grammar and sentence structure\n";
cout << "   - Vocabulary building and conversation\n";
cout << "   - Listening, reading, writing, and speaking skills\n";
cout << "\033[33m Course Fee  : Rs. 10000\033[0m\n";
cout << "\033[34m Benefits    :\033[0m\n";
cout << "   - Increases confidence in communication\n";
cout << "   - Useful for academic, professional, and IELTS preparation\n\n";

cout << "\033[32m5. Freelancing Course\n";
cout << "-------------------------------------------------------------\033[0m\n";
cout << "\033[34m Description :\033[0m\n";
cout << "   - Learn how to earn money online using freelance platforms.\n";
cout << "\033[34m Topics Covered :\033[0m\n";
cout << "   - Fiverr, Upwork, Freelancer account setup\n";
cout << "   - Gig creation, client dealing, service delivery\n";
cout << "   - Time management, payment withdrawal\n";
cout << "\033[33m Course Fee  : Rs. 10000\033[0m\n";
cout << "\033[34m Benefits    :\033[0m\n";
cout << "   - Become financially independent\n";
cout << "   - Start earning from home with skills you already have\n\n";

cout << "-------------------------------------------------------------\n";
cout << "\033[32m Additional Info:\n";
cout << "   - Admission Fee (one-time)     : Rs. 5000\n";
cout << "   - Maximum Courses You Can Take: 3 at a time\n";
cout << "   - Discount Available           : Yes (by percentage)\n";
cout << "   - Certificate Provided         : Yes (after course completion)\033[0m\n";
cout << "-------------------------------------------------------------\n";
cout << "\033[31m Note: All courses are taught by professional trainers with\n";
cout << "       practical labs, assignments, and career guidance.\033[0m\n";
cout << "=============================================================\n";


while(true)
			{
				cout<<"\nMain Menu Press 0 ";
				cout<<"\nExit Press 1";
				cout<<"\nYour Choice : ";
				cin>>choic;
				if(choic==0)
				{
				cout<<"\033[32m\n--------------------Main Menu------------------------------\033[0m\n";
				break;
				}
				else if(choic==1)
				{
				cout<<"\033[31m                      Good Bye              \033[0m\n";
				break;}
				else
				cout<<"\033[31m\nPlease Select right option.\033[0m";
			}
			break;
	case 4:
{
    int choice4;
    cout << "\n1. View All Records";
    cout << "\n2. Search by Registration Number";
    cout << "\nEnter your choice: ";
    cin >> choice4;
    cin.ignore();

    if (choice4 == 1)
    {
        ifstream read("Student.txt");
        if (!read)
        {
            cout << "\nError! File not found.";
        }
        else
        {
            string data;
            cout << "\n========= All Student Records =========\n";
            while (getline(read, data))
            {
                cout << data << endl;
            }
            read.close();
        }
    }
    else if (choice4 == 2)
    {
        string line;
        int regno;
        bool found = false;

        cout << "Enter Registration Number to search: ";
        cin >> regno;

        ifstream read("Student.txt");
        if (!read)
        {
            cout << "\033[31m\nError! File not found.\033[0m";
        }
        else
        {
            while (getline(read, line))
            {
                if (line.find("Registration Number : " + to_string(regno)) != string::npos)
                {
                    found = true;
                    cout << "\033[32m\n================== Student Found ====================\033[0m\n";
                    cout << line << endl;

                    while (getline(read, line))
                    {
                        if (line.find("Registration Number : ") != string::npos)
                        {
                            break;
                        }
                        cout << line << endl;
                    }
                    break;
                }
            }
            read.close();

            if (!found)
            {
                cout << "\033[31m\nStudent with Registration Number " << regno << " not found.\033[0m\n";
            }
        }
    }
    else
    {
        cout << "\nInvalid choice!";
    }

    while (true)
    {
        cout << "\nMain Menu Press 0 ";
        cout << "\nExit Press 1\nYour Choice : ";
        cin >> choic;
        if (choic == 0)
        {
            cout << "\033[32m\n--------------------Main Menu------------------------------\033[0m\n";
            break;
        }
        else if (choic == 1)
        {
            cout << "\033[31m                      Good Bye              \033[0m\n";
            break;
        }
        else
        {
            cout << "\033[31m\nPlease Select right option.\033[0m";
        }
    }
    break;
}
case 5:
	{
	break;
	default:
		cout<<"\033[31m\nInvalid! Select right option.\033[0m";}
		}
if(option==1)
	break;
	if(choic==1)
	break;
		
		}}