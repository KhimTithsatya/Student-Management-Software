#pragma once

#include <iostream>
#include "Student.cpp"
#include "DynamicArray.cpp"
#include <vector>


using namespace std;

//business logics
class StudentService{
    private:
        //dynamic array
        vector<Student *> students;
    public:

        StudentService(){
            //loadEmployeeFromFile();
        }
        ~StudentService(){
            vector<Student*>::iterator it;
            for(it=students.begin();it!=students.end();it++){
                delete *it;
            }
        }
        
        void addStudent(Student *studenet){
            students.push_back(studenet);
        }

        void viewStudent(){
            vector<Student*>::iterator it;
            for(it=students.begin();it!=students.end();it++){
                (*it)->display();
                cout<<endl;
            }
        }

        void editStudent(string name){
             vector<Student*>::iterator it;
             for(it=students.begin();it!=students.end();it++){
                if((*it)->getName().compare(name)){
                    (*it)->getStudent();
                    break;
                }
                
            }

        }
        void deleteStudent(string name){
            vector<Student*>::iterator it;
            for(it=students.begin();it!=students.end();it++){
                if((*it)->getName().compare(name)==0){
                    students.erase(it);
                    break;
                }
            }
        }
    
    Student* getStudentByName(string name){
        vector<Student*>::iterator it;
         for(it=students.begin();it!=students.end();it++){
                if((*it)->getName().compare(name)==0){
                    return *it;
                }
          }
        return nullptr;
    }
    
    vector<Student *> getAllStudents(){
        return students;
    }
    
   

    //Read and write object data into file
    void saveStudentToFile(){
         ofstream outputFile;
         outputFile.open("students.bin", ios::out|ios::binary|ios::trunc);
         if(!outputFile){
            cout<<"Error in creating file...\n";
            exit(1);
        }else{
            vector<Student*>::iterator it;
            for(it=students.begin();it!=students.end();it++){
                outputFile.write((char*) &it, sizeof(it));
                (*it)->display();
            }
        }
	
         outputFile.close();
    }
    void loadStudentFromFile(){
         Student student;
         ifstream inputFile;
         inputFile.open("students.bin", ios::in|ios::binary);
        if(!inputFile){
		    cout<<"Error in opening file...\n";
		    exit(1);
	    }else{
            while(inputFile.read((char*)(&student), sizeof(student))){
                students.push_back(&student);
                student.display();
                cout<<"H1"<<endl;
            }
        }
       
        
         cout<<"H2"<<endl;
         inputFile.close();
    }
      

};
