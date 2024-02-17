#include<iostream>
using namespace std;

struct Course{
	string CourseName;
	string CourseCode;
	;
};
struct Instructor{
	string InstructorName;
	int InstructorID;
	Course Ecourse;
};
void PrintCourseInfo(Course course){
	cout<<"Course Name:"<<course.CourseName<<endl;
	cout<<"Course Code:"<<course.CourseCode<<endl;
};
void PrintInstructorInfo(Instructor instructore){
	cout<<"Instructor Name:"<<instructore.InstructorName<<endl;
	cout<<"Instructor ID:"<<instructore.InstructorID<<endl;
	PrintCourseInfo(instructore.Ecourse);
};

int main()
{
	Course course1;
	course1.CourseName = "ICT";
	course1.CourseCode = "1ICT23";
	
	Course course2;
	course2.CourseName = "CAL;CULUS";
	course2.CourseCode = "C113323";
	
	Instructor instructor1;
	instructor1.InstructorID = 11223;
	instructor1.InstructorName = "AMMAD MAADA";
	instructor1.Ecourse = course1;
	
	Instructor instructor2;
	instructor2.InstructorID=12123;
	instructor2.InstructorName="Ahsan  Ka Murga";
	instructor2.Ecourse=course2;
	
	
	PrintInstructorInfo(instructor1);
	PrintInstructorInfo(instructor2);
	
	return 0;
	
		
}

