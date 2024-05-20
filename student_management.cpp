#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>


using namespace std;

// ####################################### IMG_Member class ##################################################################
// ############################ Reviewer class ###############################################################################
class IMG_member
{
	public:
	char fName[50], lName[50];
    long long enrollmentNumber;
	 
	  

};

 

class Reviewer : public IMG_member{
private:
	
	
		
public:
	void createReviewer() {
		cout<<"Enter your first name: ";
		cin>>fName;
		cout<<"Enter your last name: ";
		cin>>lName;
		cout<<"Enter enrolment number: ";
		cin>>enrollmentNumber;
		
	}
		
	void showReviewer() {
		cout<<"Name: "<<fName<<" "<<lName<<endl;
		cout<<"Enrollment number : "<<enrollmentNumber;	
	}
		
	void writeOnFile() {
		char ch;
		ofstream f1;
		f1.open("reviewer_info.dat",ios::binary|ios::app);

		do {
			createReviewer();
			f1.write(reinterpret_cast<char*>(this),sizeof(*this));
			cout<<"Do you have next data?(y/n)";
			cin>>ch;
		}while(ch=='y');

		cout<<"Student has been Sucessfully Created...";
		f1.close();
	}
		
	void readFromFile() {
		ifstream f2;
		f2.open("reviewer_info.dat",ios::binary);

		cout<<"\n================================\n";
		cout<<"LIST OF REVIEWERS";
		cout<<"\n================================\n";

		while(!f2.eof()) {
			if(f2.read(reinterpret_cast<char*>(this),sizeof(*this)))
			{
				showReviewer();
				cout<<"\n================================\n";
			}
		}
		f2.close();
	}
		
	void searchOnFile() {
		ifstream f3;
		long long enroNo;
		cout<<"Enter student no.: ";
		cin>>enroNo;
		f3.open("reviewer_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					showReviewer();
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f3.close(); 
	}

    bool checkOnFile(long long enroNo) {
		ifstream f3;
		f3.open("reviewer_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					
					return true;
				}
			}
		}
		return false;
		f3.close(); 
	}
		
	void deleteFromFile() {
		long long num;
		int flag = 0;
		ofstream f4;
		ifstream f5;

		f5.open("reviewer_info.dat",ios::binary);
		f4.open("temp.dat",ios::binary);

		cout<<"Enter student no. to delete: ";
		cin>>num;

		while(!f5.eof()) {
			if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if(enrollmentNumber!=num) {
					f4.write(reinterpret_cast<char*>(this),sizeof(*this));
				}
				else 
					flag = 1;
			}
		}
		f5.close();
		f4.close();
		remove("reviewer_info.dat");
		rename("temp.dat","reviewer_info.dat");

		flag==1?
		cout<<endl<<endl<<"\tStudent Deleted...":
		cout<<endl<<endl<<"\tStudent Not Found...";
	}
		
	void editStudent() {
		long long num;
		fstream f6;

		cout<<"Edit Student";
		cout<<"\n===============================\n\n";
		cout<<"Enter the student number to be edit: ";
		cin>>num;

		f6.open("reviewer_info.dat",ios::binary|ios::out|ios::in);

		while(!f6.eof()) {
			if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if (enrollmentNumber==num) {
					cout<<"Enter new record\n";
					createReviewer();
					int pos=-1*sizeof(*this);
					f6.seekp(pos,ios::cur);
					f6.write(reinterpret_cast<char*>(this),sizeof(*this));
					cout<<endl<<endl<<"\t Student Successfully Updated...";
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f6.close(); 
	}
};




// #########################################################################################################
// ############################ Student class ##############################################################

class Student : public IMG_member{
private:
	char fName[50], lName[50];
    long long enrollmentNumber;
	
		
public:
	void createStudent() {
		cout<<"Enter your first name: ";
		cin>>fName;
		cout<<"Enter your last name: ";
		cin>>lName;
		cout<<"Enter enrollment number: ";
		cin>>enrollmentNumber;
		
	}
		
	void showStudent() {
		cout<<"Name: "<<fName<<" "<<lName<<endl;
		cout<<"Enrollment number : "<<enrollmentNumber;	
	}
		
	void writeOnFile() {
		char ch;
		ofstream f1;
		f1.open("student_info.dat",ios::binary|ios::app);

		do {
			createStudent();
			f1.write(reinterpret_cast<char*>(this),sizeof(*this));
			cout<<"Do you have next data?(y/n)";
			cin>>ch;
		}while(ch=='y');

		cout<<"Student has been Sucessfully Created...";
		f1.close();
	}
		
	void readFromFile() {
		ifstream f2;
		f2.open("student_info.dat",ios::binary);

		cout<<"\n================================\n";
		cout<<"LIST OF StudentS";
		cout<<"\n================================\n";

		while(!f2.eof()) {
			if(f2.read(reinterpret_cast<char*>(this),sizeof(*this)))
			{
				showStudent();
				cout<<"\n================================\n";
			}
		}
		f2.close();
	}


	bool checkOnFile2() {
		ifstream f3;
		long long enroNo;
		
		cout<<"Enter student no.: ";
		cin >> enroNo;
		
		f3.open("student_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					
					return true;
				}
			}
		}
		return false;
		f3.close(); 
	}


	bool checkOnFile3(long long enroNo) {
		ifstream f3;
		
		
		
		
		f3.open("student_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					
					return true;
				}
			}
		}
		return false;
		f3.close(); 
	}

    bool checkOnFile(long long enroNo) {
		ifstream f3;
		
		
		
		f3.open("student_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					return true;
				}
			}
		}
		return false;
		f3.close(); 
	}
		
	void searchOnFile(long long enroNo) {
		ifstream f3;
        int flag = 0;
		f3.open("student_info.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroNo==enrollmentNumber) {
					showStudent();
                    flag = 1;
				}
			}
		}
        if(flag == 0) cout<<"\n\n No record not found";
		f3.close(); 
	}
		
	void deleteFromFile() {
		long long num;
		int flag = 0;
		ofstream f4;
		ifstream f5;

		f5.open("student_info.dat",ios::binary);
		f4.open("temp.dat",ios::binary);

		cout<<"Enter student no. to delete: ";
		cin>>num;

		while(!f5.eof()) {
			if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if(enrollmentNumber!=num) {
					f4.write(reinterpret_cast<char*>(this),sizeof(*this));
				}
				else 
					flag = 1;
			}
		}
		f5.close();
		f4.close();
		remove("student_info.dat");
		rename("temp.dat","student_info.dat");

		flag==1?
		cout<<endl<<endl<<"\tStudent Deleted...":
		cout<<endl<<endl<<"\tStudent Not Found...";
	}
		
	void editStudent() { // to edit by the reviewer 
		long long num;
		fstream f6;

		cout<<"Edit Student";
		cout<<"\n===============================\n\n";
		cout<<"Enter the student number to be edit: ";
		cin>>num;

		f6.open("student_info.dat",ios::binary|ios::out|ios::in);

		while(!f6.eof()) {
			if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if (enrollmentNumber==num) {
					cout<<"Enter new record\n";
					createStudent();
					int pos=-1*sizeof(*this);
					f6.seekp(pos,ios::cur);
					f6.write(reinterpret_cast<char*>(this),sizeof(*this));
					cout<<endl<<endl<<"\t Student Successfully Updated...";
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f6.close(); 
	}



    void editStudent2(long long num) // to edit by the student itself
     { 
		fstream f6;

		cout << "Edit student" << endl;
		cout<<"\n===============================\n\n";
		

		f6.open("student_info.dat",ios::binary|ios::out|ios::in);

		while(!f6.eof()) {
			if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if (enrollmentNumber==num) {
					cout<<"Enter new record\n";
					createStudent();
					int pos=-1*sizeof(*this);
					f6.seekp(pos,ios::cur);
					f6.write(reinterpret_cast<char*>(this),sizeof(*this));
					cout<<endl<<endl<<"\t Student Successfully Updated...";
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f6.close(); 
	}
};



// #########################################################################################################
// ############################ Assignments class ##########################################################



class Assignment{
private:
	char name[50];
    long long ID;
    long long enrollmentNumber2;
    string date;
    string status;
		
public:

    void showStudentChoice()
    {
        Student s;
        string inputed_enrno;
        s.readFromFile();
		long long enrollmentEntered;
		while(true)
		{
        cout << "Enter the enrollment number of the student to which you want to assign this:- "<<endl;
        cin >> enrollmentEntered;

		// while(!f3.eof()) {
		// 	if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
		// 		if (enroll_number2==enrollmentNumber2) {
		// 			showAssignment(); 
		// 			flag = 1;
					
		// 		}
		// 	}
		// }
		
		if(s.checkOnFile3(enrollmentEntered))
		{
			enrollmentNumber2 = enrollmentEntered;
			return;
		}
		else
		{
			int userResponse;
			cout << "This student is not registered in the database. Please input a valid enrollment number or exit !"<<endl;
			cout << "[1] Enter a valid enrollment number" <<endl;
			cout << "[0] Exit" <<endl;
			cin >> userResponse;
			if(userResponse == 0)
			{
				exit(0);
			}

		}
	}
}
long long generateRandomSevenDigitNumber() {
	while(true)
	{
    // Seed the random number generator
    srand(time(nullptr));
	long long generatedID = rand() % 9000000 + 1000000;

    // Generate a random number between 1000000 and 9999999
	if(!searchOnFileForID(generatedID))
	{
    return rand() % 9000000 + 1000000;
	exit(0);
	}
	else
	{
		continue;
	}
	}

}


    void createAssignmentForAll(char name[50], string status1, string date1, long long enrollment)
	{
		ID = generateRandomSevenDigitNumber();
		name = name;
		date = date1;
		status = status1;
		enrollmentNumber2 = enrollment;
		cout << enrollmentNumber2 << endl ;


	}


	void assignToAll() {
		long long num;
		fstream f6;

		

		f6.open("Assignment_records.dat",ios::binary|ios::out|ios::in);
		char name1[50];
        string status1, date1;
				
		        cout<<"Enter the name of the assignment:- "<<endl;
				cin >> name1;

				cout<<"Enter the status of the assignment:- "<<endl;
				cin >> status1;

				cout<<"Enter the date of the assignment:- "<<endl;
				cin >> date1;

		while(!f6.eof()) {
			
			if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))) {

				
				
			    createAssignmentForAll(name1, status1, date1, enrollmentNumber2);
				if (enrollmentNumber2 > -1) {
					char name1[50];
                    
					int pos=-1*sizeof(*this);
					f6.seekp(pos,ios::cur);
					f6.write(reinterpret_cast<char*>(this),sizeof(*this));
					
					
				}
			}
		}
		
		f6.close(); 
	}

	void createAssignment() {
		showStudentChoice();
		
		if(enrollmentNumber2)
		{
			ID = generateRandomSevenDigitNumber();
			

			cout << "Enter the name of the assignment:- " <<endl;
			cin >> name;
			cout << "Enter the date:- " <<endl;
			cin >> date;
			cout << "Status:- " <<endl;
			cin >> status;


		}
		else 
		{
			cout << "Assignment creation failed !!!" <<endl;
		}
		



	}
		
	void showAssignment() {
		cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

		cout<<"Name of the assignment:- " << name << endl;
		cout<<"ID:- " << ID <<endl;
		cout<<"Student's enrollment number:- "<< enrollmentNumber2 << endl;
		cout<<"Status:- "<< status << endl;	
        cout<<"Assigned Date:- " << date << endl;

		cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}
		
	void writeOnFile() {
		char ch;
		ofstream f1;
		f1.open("Assignment_records.dat",ios::binary|ios::app);

		do {
			createAssignment();
			f1.write(reinterpret_cast<char*>(this),sizeof(*this));
			cout<<"Do you have next data?(y/n)";
			cin>>ch;
		}while(ch=='y');

		cout<<"Assignment(s) has/have been Sucessfully Created...";
		f1.close();
	}
		
	void readFromFile() {
		ifstream f2;
		f2.open("Assignment_records.dat",ios::binary);

		cout<<"\n================================\n";
		cout<<"LIST OF Assignments";
		cout<<"\n================================\n";

		while(!f2.eof()) {
			if(f2.read(reinterpret_cast<char*>(this),sizeof(*this)))
			{
				showAssignment();
				cout<<"\n================================\n";
			}
		}
		f2.close();
	}
		
	void searchOnFile() {
		ifstream f3;
		cout << "Enter the enrollment of the student whose assignment you want to check:- "<<endl;
		long long enroll_number2;
		cin >> enroll_number2;
		int flag = 0;

		
		
		f3.open("Assignment_records.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroll_number2==enrollmentNumber2) {
					showAssignment(); 
					flag = 1;
					
				}
			}
		}
        if (flag == 0)
		{
		cout<<"\n\n No record not found";
		}
		f3.close(); 
	}


	bool searchOnFileForID(long long ID1) {
		ifstream f3;
		f3.open("Assignment_records.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (ID1==ID) {
					return true;
					
				}
			}
		}
        return false;
		f3.close(); 
	}

	void searchOnFile2(long long enroll_number) {
		ifstream f3;
		
		int flag = 0;

		
		
		f3.open("Assignment_records.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (enroll_number==enrollmentNumber2) {
					showAssignment(); 
					flag = 1;
					
				}
			}
		}
        if (flag == 0)
		{
		cout<<"\n\n No record not found";
		}
		f3.close(); 
	}
	void searchOnFileThroughID() {
		cout << "Enter the ID of the assignment you want to check:- "<<endl;
		long long ID;
		cin >> ID;
		ifstream f3;

		
		
		f3.open("Assignment_records.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				if (ID==enrollmentNumber2) {
					showAssignment();
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f3.close(); 
	}

	
	

    bool checkOnFile(long long phone) {
		ifstream f3;
		cout<<"Enter Enrollment number ";
		f3.open("Assignment_records.dat",ios::binary);

		while(!f3.eof()) {
			if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
				cout << enrollmentNumber2 <<endl ;
				if (phone==enrollmentNumber2) {
					showAssignment();

					return true;
				}
			}
		}
		return false;
		f3.close(); 
	}
		
	void deleteFromFile() {
		long long num;
		int flag = 0;
		ofstream f4;
		ifstream f5;

		f5.open("Assignment_records.dat",ios::binary);
		f4.open("temp.dat",ios::binary);

		cout<<"Enter enrollment number corresponding to whcih assignment has to be deleted: ";
		cin>>num;

		while(!f5.eof()) {
			if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if(enrollmentNumber2!=num) {
					f4.write(reinterpret_cast<char*>(this),sizeof(*this));
				}
				else 
					flag = 1;
			}
		}
		f5.close();
		f4.close();
		remove("Assignment_records.dat");
		rename("temp.dat","Assignment_records.dat");

		flag==1?
		cout<<endl<<endl<<"\tAssignment Deleted...":
		cout<<endl<<endl<<"\tAssignment Not Found...";
	}
		
	void editAssignment() {
		long long num;
		fstream f6;

		cout<<"Edit assignment";
		cout<<"\n===============================\n\n";
		cout<<"Enter the enrollment corresponding to which assignment has to be edited: ";
		cin>>num;

		f6.open("Assignment_records.dat",ios::binary|ios::out|ios::in);

		while(!f6.eof()) {
			if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))) {
				if (enrollmentNumber2==num) {
					cout<<"Enter new record\n";
					createAssignment();
					int pos=-1*sizeof(*this);
					f6.seekp(pos,ios::cur);
					f6.write(reinterpret_cast<char*>(this),sizeof(*this));
					cout<<endl<<endl<<"\t Assignment Successfully Updated...";
					return;
				}
			}
		}
		cout<<"\n\n No record not found";
		f6.close(); 
	}

 // void createAssignmentForAll(char name1[50], string status1, string date1, long long enrollment)

	
};





// ############################################## MAIN FUNCTION ######################################################

int main() {
	

	cout<<"\n\n\n\n\n\n\n\n\t\t\t * WELCOME TO ASSIGNMENT MANAGEMENT SYSTEM *" <<endl;;
    int identity, student_choice, reviewer_choice;
    
    cout << "What is your role at IMG?"<<endl;
    cout << "[1] Reviewer" <<endl;
    cout << "[2] Student" <<endl;
    cout << "[0] Exit" <<endl;
    cin >> identity;
    switch(identity)
    {




        case 1: // #################reviewer############################
          








          char res1;
          cout<<"\n==============================\n";
          cout << "Do you have your record in the database? (Y/n)"<<endl;
          cout<<"\n==============================\n";
          cin >> res1;
          Reviewer r1 ;





          if(res1 == 'n' | res1 == 'N')
          {
            cout << "Please register yourself !!!" <<endl; 

            
            system("cls");
        	r1.writeOnFile();
          }



        
          else
          {
              cout << "What is your enrollment number? " << endl;
			  
              long long reviewer_enrollment;
              cin >> reviewer_enrollment;
              if(r1.checkOnFile(reviewer_enrollment))
               {
				  
				  while(1)
				  {
                    

                    Student c1;
                    Assignment a1;
                    cout<<"\n==============================\n";
                    cout<<"[1] Add a new Student\n";
                    cout<<"[2] List all Students\n";
                    cout<<"[3] Search for Student\n";
                    cout<<"[4] Delete a Student\n";
                    cout<<"[5] Edit a Student\n";
                    cout<<"[6] Add a new Assignment\n";
                    cout<<"[7] List all assignments\n";
                    cout<<"[8] Search for Assignment through its code \n";
                    cout<<"[9] Delete a Assignment\n";
                    cout<<"[10] Edit a Assignment\n";
					cout<<"[11] Search for the details of an assignment of a particular student\n";
					cout<<"[12] Assign an assignment to all \n";
                    cout<<"[0] Exit \n";
                    cout<<"\n==============================\n";
                    cout <<"Enter your choice !!!" <<endl;

                    cin >> reviewer_choice;
                    switch(reviewer_choice)
                    {
                    case 1:
                        system("cls");
                        c1.writeOnFile();
                        break;

                    case 2:
                        system("cls");
                        c1.readFromFile();
                        break;

                    case 3:
                        system("cls");
                        c1.checkOnFile2();
                        break;

                    case 4:
                        system("cls");
                        c1.deleteFromFile();
                        break;

                    case 5:
                        system("cls");
                        c1.editStudent();
                        break;
                    
                    case 6:
                        system("cls");
                        a1.writeOnFile();
                        break;

                    case 7:
                        system("cls");
                        a1.readFromFile();
                        break;

                    case 11:
                        system("cls");
                        a1.searchOnFile();
                        break;

                    case 9:
                        system("cls");
                        a1.deleteFromFile();
                        break;

                    case 10:
                        system("cls");
                        a1.editAssignment();
                        break;

					case 8:
					   system("cls");
					   a1.searchOnFileThroughID();
					   break;

					case 12:
				       system("cls");
					   a1.assignToAll();
					   break;

                    case 0:
                        system("cls");
                        exit(0);
                        break;

                    default:
                        cout << "Invalid input" <<endl;
					

                }
				cout << "\n====================================================\n";
				cout << " How would you like to proceed ?" <<endl;
				cout << "\n====================================================\n";
				cout << "[1] Main Menu " <<endl;
				cout << "[0] Exit " <<endl;
				int choice2; 
				cin >> choice2;
				if(choice2 == 0)
				exit(0);
				else
				continue;


				  }

				  
                }
                else
				{
                    cout << "You have not registered yourself in the system " <<endl;
					cout << "Please register yourself again and then retry (run the program)" <<endl;
					system("cls");
        	        r1.writeOnFile(); 
			    }
            
        }




        break;






        case 2: 
        
        //################################### student #################################################


        cout << "Have you registered yourself before (Y/n) ?" <<endl;
        char registered_or_not;
        Student s1 ;
		Assignment a;
        cin >> registered_or_not;


        if (registered_or_not == 'n' || registered_or_not == 'N')
        {
            cout << "Please register yourself !!!" <<endl; 
            
            system("cls");

        	s1.writeOnFile();

        }

        else{
			
            cout << "What is your enrollment number?" <<endl;
            long long student_enrollment;
            cin >> student_enrollment;
            if(s1.checkOnFile(student_enrollment))
            {
				while(1)
				{

                cout << "What would you like to do?" <<endl;
                cout << "\n==============================\n";
                cout << "[1]Edit your credentials" <<endl;
                cout << "[2]Check your assignments (due/completed)"<<endl;
                cout << "[0] Exit"<<endl;
                cout<<"\n==============================\n";

                int student_choice;
                cin >> student_choice;

                switch(student_choice)
                {
                    case 1:
                    system("cls");
                    s1.editStudent2(student_enrollment);
                    break;

                    case 2:
                    system("cls");
                    a.searchOnFile2(student_enrollment);
					break;

                    case 0:
                    system("cls");
                    exit(0);
                    break;

                    default: 
                    cout << "Invalid input" <<endl;

                }    
				
				cout << "\n====================================================\n";
				cout << " How would you like to proceed ?" <<endl;
				cout << "\n====================================================\n";
				cout << "[1] Main Menu " <<endl;
				cout << "[0] Exit " <<endl;
				int choice; 
				cin >> choice;
				if(choice == 0)
				{
				exit(0);
				}
				}
				
				

            }

            else
            {
                cout << "You have not registered yourself or maybe you have inputed the wrong enrollment number !!!" << endl;
				cout << "Please register yourself and check again !!" << endl;
				system("cls");
        	    s1.writeOnFile();
            }

			}        
        break;
        		
	}

    }
	




	

	// while(1) {
	// 	Student c1;
    //     Assignment a1;
	// 	int choice;

	// 	system("cls");
	// 	system("Color 03");




		
    // }


// 		cout<<"\n=====================\n";
//         cout<<"[1] Add a new Student\n";
//         cout<<"[2] List all Students\n";
//         cout<<"[3] Search for Student\n";
//         cout<<"[4] Delete a Student\n";
//         cout<<"[5] Edit a Student\n";
//         cout<<"[6] Add a new Assignment\n";
//         cout<<"[7] List all assignments\n";
//         cout<<"[8] Search for Assignment\n";
//         cout<<"[9] Delete a Assignment\n";
//         cout<<"[10] Edit a Assignment\n";
//         cout<<"[0] Exit";
// 		cout<<"\n=====================\n";
//         cout<<"Enter your choice: ";
//         cin>>choice;

//         switch(choice) {
//         	
//         	case 1:
//         		system("cls");
//         		c1.writeOnFile();
//         		break;

//         	case 2:
// 				system("cls");
//         		c1.readFromFile();
//         		break;

// 			case 3:
//         		system("cls");
//         		c1.searchOnFile();
//         		break;

//         	case 4:
// 				system("cls");
//         		c1.deleteFromFile();
//         		break;

//         	case 5:
// 			    system("cls");
//         		c1.editStudent();
//         		break;
            
//             case 6:
//         		system("cls");
//         		a1.writeOnFile();
//         		break;

//         	case 7:
// 				system("cls");
//         		a1.readFromFile();
//         		break;

// 			case 8:
//         		system("cls");
//         		a1.searchOnFile();
//         		break;

//         	case 9:
// 				system("cls");
//         		c1.deleteFromFile();
//         		break;

//         	case 10:
// 			    system("cls");
//         		a1.editAssignment();
//         		break;

//         	case 0:
//         		system("cls");
//         		cout<<"\n\n\n\t\t\tThank you for using CMS."<<endl<<endl;
//         		exit(0);
//         		break;

//         	default:
// 				continue;	
// 		}

// 		int opt;
// 		cout<<"\n\nEnter the Choice:\n[1] Main Menu\t\t[0] Exit\n";
// 		cin>>opt;

// 		switch (opt) {
// 			case 0:
//         		system("cls");
//         		cout<<"\n\n\n\t\t\tThank you for using CMS."<<endl<<endl;
//         		exit(0);
//         		break;

// 			default:
// 				continue;
// 		}
// 	}

// 	return 0;
// }

// 		int opt;
// 		cout<<"\n\nEnter the Choice:\n[1] Main Menu\t\t[0] Exit\n";
// 		cin>>opt;

// 		switch (opt) {
// 			case 0:
//         		system("cls");
//         		cout<<"\n\n\n\t\t\tThank you for using CMS."<<endl<<endl;
//         		exit(0);
//         		break;

// 			default:
// 				continue;
// 		}
// 	}

// 	return 0;
// }