/*
* Student.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Class definition .cpp file for the Student Class
* Copyright notice
*/

#include "Student.h"
int Student::enrolled_{ 0 };

//Default constuctor
//Note how we use the scope resolution operator ::
//We do that to specify which class the member functions belong to
//Class_Name::Member_Function
Student::Student() {
	enrolled_++;
}

Student::Student(std::string name) {
	name_ = name;
	std::cout << "Constructor created on " << this->GetName() << std::endl;
	enrolled_++;
}

//This constructor creates and initialises it by copying the data from each variable
//into the specified data member. We use an initializer list but we could also initialize each
//variable by using assignment statements in the main body of the function
Student::Student(std::string name, std::string registration, std::string course, int yearofStudy) : name_{ name }, registrstionID_{ registration }, course_{ course},
	yearofStudy_{ yearofStudy}
{
	std::cout << "Constructor created on " << this->GetName() << std::endl;
	enrolled_++;

	//we could assign the values of the parameters to the data members like this
	//name_ = name;
};

//Getters and setters
void Student::SetName(std::string name) {
	name_ = name;
}
//Make getters const so that it tells the compiler to complain if we accidentlly 
//try to change a data member 
std::string Student::GetName() const {
	return name_;
}

void Student::SetRegistrationID(std::string registrstionID) {
	registrstionID_ = registrstionID;
}
std::string Student::GetRegistrationID() const {
	return registrstionID_;
}

void Student::SetCourse(std::string course) {
	course_ = course;
}
std::string Student::GetCourse() const {
	return course_;
}

void Student::SetYearofStudy(int year) {
	yearofStudy_ = year;
}
int Student::GetYearofStudy() const {
	return yearofStudy_;
}

void Student::ToString() const {
	std::string output = name_ + " " + registrstionID_ + " " + course_ + " " + std::to_string(yearofStudy_) + " " + "\n";
		//+ std::to_string(moduleOneMark_) + " " + std::to_string(moduleTwoMark_) + " " + std::to_string(moduleThreeMark_) + "\n";
	//+yearofStudy_ + " " + moduleOneMark_ + " "	+ moduleTwoMark_ + " " + moduleThreeMark_;
	std::cout << output;
}

std::string Student::CalculateClassification() const {
//std::string Student::CalculateClassification(){

	float average{};

	//average = (moduleOneMark_ + moduleTwoMark_ + moduleThreeMark_) / 3;
	average = this->CalculateAverage();
	if (average < 40) {
		return "fail";
	}
	else if (average >= 40 && average <= 49) {
		return "3rd class";
	}
	else if (average >= 50 && average <= 59) {
		return "2nd class";
	}
	else if (average >= 60 && average <= 69) {
		return "2-1";
	}
	else
		return "1st class";

}

float Student::CalculateAverage() const {
	float average{};
	int index{ 0 };
	for (index ; index < this->moduleMarks_.size(); index++) {
		average += this->moduleMarks_.at(index).getModuleMark();
	}
	average = average / index;
		return average;
}

void Student::AddModule(Module m) {
	moduleMarks_.push_back(m);
}

void Student::AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	Module m(moduleTitle, moduleCode, moduleCreditPoints, moduleMark);
	moduleMarks_.push_back(m);

}

void Student::DeleteModule(std::string moduleCode) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.erase(moduleMarks_.begin()+ index);
		}
	}

}
void Student::UpdateModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.at(index).setModuleCreditPoints(moduleCreditPoints);
			moduleMarks_.at(index).setModuleTitle(moduleTitle);
			moduleMarks_.at(index).setModuleMark(moduleMark);
		}
	}
}

int Student::GetNumberModules() {
	return this->moduleMarks_.size();

}

//Static member
int Student::GetEnrolled(){
	return enrolled_;
}

std::ostream & operator<<(std::ostream& output, const Student& student){
	output << "Name: " << student.name_ << "RegID: " << student.registrstionID_
		<< "Course: " << student.course_ << "Year: " << student.yearofStudy_ << std::endl;

	return output;
}

std::istream & operator>>(std::istream& input, Student& student){
	std::string name, RegID, course;
	unsigned int year;

	std::cout << "Enter name: " << std::endl;
	input >> std::setw(20) >> name;

	std::cout << "Enter RegID: " << std::endl;
	input >> std::setw(10) >> RegID;

	std::cout << "Enter Course: " << std::endl;
	input >> std::setw(40) >> course;

	std::cout << "Enter Year: " << std::endl;
	input >> std::setw(1) >> year;

	student.SetName(name);
	student.SetRegistrationID(RegID);
	student.SetCourse(course);
	student.SetYearofStudy(year);
	
	return input;
}

Student::~Student() {
	std::cout << "Destructor called on " << this->GetName() << std::endl;
	enrolled_--;
}


