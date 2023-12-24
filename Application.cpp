#pragma once
#include <iostream>
#include <fstream>
#include "Student.cpp"
#include "Department.cpp"
#include "Payoff.cpp"
#include "FeeStudent.cpp"
#include "HourlyStudent.cpp"
#include "StudentService.cpp"

using namespace std;

enum{
    ADD_STUDENT=1,
    VIEW_STUDENT,
    EDIT_STUDENT,
    DELETE_STUDENT,
    SAVE_STUDENT,
    LOAD_STUDENT,
    EXIT_APPLICATION
};
enum{
    FEE_STUDENT=1,
    HOURLY_STUDENT
};

class Application{
private:

public:
    void run(){
        int option;
        int choice = 0;
        int count=0;
        string name;

        FeeStudent feeStudent;
        HourlyStudent hourlyStuent;

        StudentService studentService;
    


        do{
            showMenu();

            int choice=getCommand();

            switch(choice){
                case ADD_STUDENT:
                    cout<<"================"<<endl;
                    cout<<"STDUENT TYPES"<<endl;
                    cout<<"================"<<endl;
                    cout<<"1. Student Fee"<<endl;
                    cout<<"================"<<endl;
                    cout<<"2. Student Hourly"<<endl;
                    cout<<"================"<<endl;
                    cout<<"Please enter your option: ";
                    cin>>option;
                    switch(option){
                        case FEE_STUDENT:
                            feeStudent.getStudent();
                            studentService.addStudent(&feeStudent);
                            break;
                        case HOURLY_STUDENT:
                            hourlyStuent.getStudent();
                            studentService.addStudent(&hourlyStuent);
                            count++;
                            break;
                    }
                    break;
                case VIEW_STUDENT:
                    cout<<"============="<<endl;
                    cout<<"Student Info: "<<endl;
                    cout<<"============="<<endl;
                    studentService.viewStudent();
                    cout<<endl;
                    break;
                case EDIT_STUDENT:
                cout<<"======================="<<endl;
                cout<<"Enter name to edit ";
                cout<<"======================="<<endl;
                    cin>>name;
                    studentService.editStudent(name);
                    break;
            
                case DELETE_STUDENT:
                cout<<"======================="<<endl;
                cout<<"Enter name to delete ";
                cout<<"======================="<<endl;
                    cin>>name;
                    studentService.deleteStudent(name);
                    break;
                case SAVE_STUDENT:
                    studentService.saveStudentToFile();
                    cout<<"======================="<<endl;
                    cout<<"Data has been saved"<<endl;
                    cout<<"======================="<<endl;
                    break;
                case LOAD_STUDENT:
                    studentService.loadStudentFromFile();
                    cout<<"======================="<<endl;
                    cout<<"Data has been loaded"<<endl;
                    cout<<"======================="<<endl;
                    break;
            }
        }while(choice!=7);

        cout<<"Exit program"<<endl;
    }

    void showMenu(){
        cout<<"---------WELCOME TO EMPLOYEE MANAGEMENT SOFTWARE---------"<<endl;
        cout<<"================"<<endl;
        cout<<"MAIN MENU"<<endl; 
        cout<<"================"<<endl;
        cout<<"1. ADD STUDENT"<<endl;
        cout<<"================"<<endl;
        cout<<"2. VIEW STUDENT"<<endl;
        cout<<"================"<<endl;
        cout<<"3. EDIT STUDENT"<<endl;
        cout<<"================"<<endl;
        cout<<"4. DELETE STUDENT"<<endl;
        cout<<"========================"<<endl;
        cout<<"5. SAVE STUDENT TO FILE"<<endl;
        cout<<"========================"<<endl;
        cout<<"6. LOAD STUDENT FROM FILE"<<endl;
        cout<<"================"<<endl;
        cout<<"7. EXIT PROGRAM"<<endl;
        cout<<"================"<<endl;
    }

    int getCommand(){
        int choice;
        cout<<"Please enter your choice: ";
        cin>>choice;
        while(!isLegal(choice)){
            cout<<"Invalid choice, please enter again(1-7)"<<endl;
            showMenu();
            cin>>choice;
        }
        return choice;
    }

    bool isLegal(int c){
        return ((c==1) || (c==2) || (c==3) || (c==4) || (c==5) | (c==6) | (c==7));
    }


};
