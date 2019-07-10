
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

class staff1{

       string staffID;
       string staffName;
       string staffPosition;
       string staffDepartment;
       string staffHireDate;
       string staffSalary;

       public:
       staff1()
       {
    	   // do nothing
       }

       ~staff1()
        {

        }
       string getStaffID(){
           return staffID;
       }

       string getStaffName(){
           return staffName;
       }

       string getStaffPosition(){
           return staffPosition;
       }

       string getStaffDepartment(){
           return staffDepartment;
       }

       string getStaffHireDate(){
           return staffHireDate;
       }

       string getStaffSalary(){
           return staffSalary;
       }

       void setStaffID(string id){
           staffID = id;
       }

       void setStaffName(string name){
           staffName = name;
       }

       void setStaffPosition(string pos){
           staffPosition = pos;
       }

       void setStaffDepartment(string dept){
           staffDepartment = dept;
       }

       void setStaffHireDate(string date){
           staffHireDate = date;
       }

       void setStaffSalary(string salary){
           staffSalary = salary;
       }


};

void fileWriteBin( const char* file_name, std::vector<staff1>& list )
{
    std::ofstream file( file_name, std::ios::binary ) ;

    char text[256];
    string temp;
    for(int i = 0; i < list.size() ; i++){
    	   temp = list[i].getStaffID();
    	   strcpy(text, temp.c_str());
    	   file.write(text,temp.length());
    	   file.write(":",1);


    	   temp = list[i].getStaffName();
    	   strcpy(text, temp.c_str());
    	   file.write(text,temp.length());
    	   file.write(":",1);


    	   temp = list[i].getStaffPosition();
    	   strcpy(text, temp.c_str());
    	   file.write(text,temp.length());
    	   file.write(":",1);



    	   temp = list[i].getStaffDepartment();
    	   strcpy(text, temp.c_str());
    	   file.write(text,temp.length());
    	   file.write(":",1);



    	   temp = list[i].getStaffHireDate();
    	   strcpy(text, temp.c_str());
    	   file.write(text,temp.length());
    	   file.write(":",1);



    	   temp = list[i].getStaffSalary();
    	   strcpy(text, temp.c_str());
    	   //strncpy(text, temp.c_str(),6);
    	   file.write(text,temp.length());

    }
}

std::vector<staff1> readDataBinary( const char* file_name )
{
    std::vector<staff1> list ;
    std::ifstream file( file_name, std::ifstream::binary ) ;
	string token, delimiter;
	delimiter = ":";
	int count = 0;
    staff1 sample ;
    char buffer[800];
    int size = 51;




    while( file.read( buffer, size) ){
    	string line(buffer);

    	//cout<<line;

    	size_t temp;
		size_t found = line.find(delimiter);

    	if (count == 0)
    		token = line.substr(0, found);
    	else
    		token = line.substr(1, found-1); // 0-4
		sample.setStaffID(token);
		count = 1;

		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		sample.setStaffName(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		sample.setStaffPosition(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		sample.setStaffDepartment(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		sample.setStaffHireDate(token);


		temp = found;
		token = line.substr(temp+1, found-temp-1);
		sample.setStaffSalary(token);
		list.push_back(sample);
		size = 52;
    }

    return list ;
}


int main()
{

	cout << "\nTask#1 The listing of staff1 objects\n" << endl;
	std::vector<staff1> staffList;

	ifstream inFile;
  	inFile.open ("/home/010/y/yx/yxt170330/cs3377/a2part2/staff1.txt");

	if (!inFile) {
    	cerr << "Unable to open file datafile.txt";
    	exit(1);   // call system to stop
	}
	string line;
	int counter = 0;
	string token, delimiter;
	delimiter = ":";
	staff1 sample;

	while (std::getline(inFile, line)){
		size_t temp;
		size_t found = line.find(delimiter);
		token = line.substr(0, found); // 0-4
		//staffList[counter].setStaffID(token);
		sample.setStaffID(token);

		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		//staffList[counter].setStaffName(token);
		sample.setStaffName(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		//staffList[counter].setStaffPosition(token);
		sample.setStaffPosition(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		//staffList[counter].setStaffDepartment(token);
		sample.setStaffDepartment(token);


		temp = found;
		found = line.find(delimiter, found+1);
		token = line.substr(temp+1, found-temp-1);
		//staffList[counter].setStaffHireDate(token);
		sample.setStaffHireDate(token);


		temp = found;
		token = line.substr(temp+1, found-temp-1);
		//staffList[counter].setStaffSalary(token);
		sample.setStaffSalary(token);

		staffList.push_back(sample);

		counter++;
	}

	for (staff1 s: staffList){
		cout << "\nStaff ID  : " <<s.getStaffID() << endl;
		cout << "Name      : " << s.getStaffName()<< endl;
		cout << "Position  : " << s.getStaffPosition()<< endl;
		cout << "Department: " << s.getStaffDepartment()<< endl;
		cout << "Hire Date : " << s.getStaffHireDate()<< endl;
		cout << "Salary    : " << s.getStaffSalary() << endl;

		}
  	inFile.close();


  	cout << "Task#2 Start: Writing Binary to .obj file\n" << endl;
//  	ofstream outFile;
//  	outFile.open("/Users/Yugesh 1/desktop/cs3377/a2part2/staff2.obj");

  	const char* const file_name = "/home/010/y/yx/yxt170330/cs3377/a2part2/staff2.obj";

  	fileWriteBin(file_name, staffList);

  	cout << "Clearing all staff1 Objects: \n" << endl;
  	staffList.clear();
  	cout << "Size: " << staffList.size() << endl;

  	vector<staff1> List = readDataBinary(file_name);

  	
	cout << "Reading in from staff2.obj: \n" << endl;

  	for (staff1 &p :  List)
  	{
		cout <<"\nStaff ID  : " <<p.getStaffID() << endl;
		cout << "Name      : " << p.getStaffName()<< endl;
		cout << "Position  : " << p.getStaffPosition()<< endl;
		cout << "Department: " << p.getStaffDepartment()<< endl;
		cout << "Hire Date : " << p.getStaffHireDate()<< endl;
		cout << "Salary    : " << p.getStaffSalary() << endl;
		
  	}


    return 0;
}
