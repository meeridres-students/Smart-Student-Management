#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

    string name[50];
    int roll[50];
    float marks[50];

    int count = 0;
    int choice;
    bool duplicate;
    

ifstream file("student_records.txt");

if(file){

    while(count < 50 && getline(file, name[count])){

        if(!(file >> roll[count] >> marks[count])){
            break;
        }

        file.ignore();

        count++;
    }

    file.close();

    cout << count << " Student Records Loaded Successfully!" << endl;
}

    do {

        cout << "===== SMART STUDENT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Calculate Result" << endl;
        cout << "5. Save Records" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:

    if(count < 50){

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin,name[count]);

        
do {

    duplicate = false;

    cout << "Enter Roll Number: ";

    if(!(cin >> roll[count])) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input! Enter numbers only." << endl;
        duplicate = true;
        continue;
    }

    if(roll[count] <= 0) {
        cout << "Roll Number Must Be Positive!" << endl;
        duplicate = true;
        continue;
    }

    for(int i = 0; i < count; i++){

        if(roll[i] == roll[count]){
            cout << "Roll Number Already Exists! Try Again." << endl;
            duplicate = true;
            break;
        }
    }

} while(duplicate);


        cout << "Enter Marks (0-100): ";

while(true){

    if(!(cin >> marks[count])){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input! Enter numbers only: ";
    }
    else if(marks[count] < 0 || marks[count] > 100){
        cout << "Marks must be between 0 and 100: ";
    }
    else{
        break;
    }
}

        count++;

        cout << "Student Added Successfully!" << endl;
    }
    else{
        cout << "Student Limit Reached!" << endl;
    }

    break;
            case 2:

    if(count == 0){
        cout << "No Students Found!" << endl;
    }
    else{

        cout << "===== STUDENT RECORDS =====" << endl;

        for(int i = 0; i < count; i++){

            cout << "Student " << i + 1 << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Roll Number: " << roll[i] << endl;
            cout << "Marks: " << marks[i] << endl;

        }
    }

    break;

            
case 3: {

    int searchRoll;
    bool found = false;

    cout << "Enter Roll Number to Search: ";
    cin >> searchRoll;

    for(int i = 0; i < count; i++){

        if(roll[i] == searchRoll){

            cout << "Student Found!" << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Roll Number: " << roll[i] << endl;
            cout << "Marks: " << marks[i] << endl;

            found = true;
            break;
        }
    }

    if(found == false){
        cout << "Student Not Found!" << endl;
    }

    break;
}


            
case 4: {

    int resultRoll;
    bool found = false;

    cout << "Enter Roll Number: ";
    cin >> resultRoll;

    for(int i = 0; i < count; i++){

        if(roll[i] == resultRoll){

            float percentage = marks[i];

            cout << "===== STUDENT RESULT =====" << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Roll Number: " << roll[i] << endl;
            cout << "Marks: " << marks[i] << "/100" << endl;
            cout << "Percentage: " << percentage << "%" << endl;

            if(percentage >= 90){
                cout << "Grade: A" << endl;
            }
            else if(percentage >= 80){
                cout << "Grade: B" << endl;
            }
            else if(percentage >= 70){
                cout << "Grade: C" << endl;
            }
            else if(percentage >= 60){
                cout << "Grade: D" << endl;
            }
            else{
                cout << "Grade: F" << endl;
            }
            
            if(percentage >=60){
            	cout<<"Status: Pass"<<endl;
			}
			
			else{
				cout<<"Status: Fail"<<endl;
			}

            found = true;
            break;
        }
    }

    if(found == false){
        cout << "Student Not Found!" << endl;
    }

    break;
}


            case 5: {

    ofstream file("student_records.txt");

    if(!file){
        cout << "Error opening file!" << endl;
    }
    else{

        for(int i = 0; i < count; i++){

            file << name[i] << endl;
            file << roll[i] << endl;
            file << marks[i] << endl;

        }

        file.close();

        cout << "Records Saved Successfully!" << endl;
    }

    break;
}

            case 6: {

    ofstream file("student_records.txt");

    if(file){

        for(int i = 0; i < count; i++){
            file << name[i] << endl;
            file << roll[i] << endl;
            file << marks[i] << endl;
        }

        file.close();

        cout << "Records Saved Successfully!" << endl;
    }
    else{
        cout << "Error Saving Records!" << endl;
    }

    cout << "Exiting Program..." << endl;
    break;
}

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}
