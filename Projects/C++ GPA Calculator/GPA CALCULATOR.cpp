
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

using namespace std;

class Subject {
public:
    string name;
    int credit = 0;
    string grade;
    float gradePoints = 0;
};

void addSubject(vector<Subject>& subjects) {
    Subject newSubject;

    cout << "Name: ";
    getline(cin, newSubject.name);

    cout << "Credit: ";
    cin >> newSubject.credit;
    cin.ignore();

    cout << "VALID GRADES: A+ A A- B+ B- C+ C C- D+ D D- F\n";
    cout << "YOUR GRADE: ";
    getline(cin, newSubject.grade);

    subjects.push_back(newSubject);
}

float calculateGPA(vector<Subject>& subjects) {
    float totalGP = 0;
    int totalCredit = 0;

    for(size_t i=0;i<subjects.size();i++){
    	
    	if(subjects[i].grade=="A+"|| subjects[i].grade=="a+"){
    		subjects[i].gradePoints = 4.3*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="A"|| subjects[i].grade=="a"){
			subjects[i].gradePoints = 4*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="A-"|| subjects[i].grade=="a-"){
    		subjects[i].gradePoints = 3.7*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="B+"|| subjects[i].grade=="b+"){
    		subjects[i].gradePoints = 3.3*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="B"|| subjects[i].grade=="b"){
    		subjects[i].gradePoints = 3*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="B-"|| subjects[i].grade=="b-"){
    		subjects[i].gradePoints = 2.7*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="C+"|| subjects[i].grade=="c+"){
    		subjects[i].gradePoints = 2.3*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="C"|| subjects[i].grade=="c"){
    		subjects[i].gradePoints = 2*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="C-"|| subjects[i].grade=="c-"){
    		subjects[i].gradePoints = 1.7*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="D+"|| subjects[i].grade=="d+"){
    		subjects[i].gradePoints = 1.3*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="D"|| subjects[i].grade=="d"){
    		subjects[i].gradePoints = 1*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="D-"|| subjects[i].grade=="d-"){
    		subjects[i].gradePoints = 0.7*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else if(subjects[i].grade=="F"|| subjects[i].grade=="f"){
    		subjects[i].gradePoints = 0*subjects[i].credit;
    		totalGP=totalGP+subjects[i].gradePoints;
		}
		else{
			system("CLS");
			cout<<"INVALID ENTRY!!!\n";
			break;
		}
}
    return totalGP / totalCredit;
}

int main() {
    vector<Subject> subjects;
    int exit = 0;

    while (exit == 0) {
        int choice = 1;
        int i = 1;

        while (choice == 1) {
            system("CLS");
            cout << "SUBJECT " << i << ":\n";
            addSubject(subjects);

            cout << "1. Add More\n";
            cout << "0. Calculate GPA\n";
            cin >> choice;
            cin.ignore();
            i++;
        }

        float gpa = calculateGPA(subjects);
        system("CLS");
        cout << "YOUR GPA: " << gpa << endl;

        cout << "1. Exit\n";
        cout << "0. Calculate Again\n";
        cin >> exit;
        cin.ignore();
    }

    return 0;
}

