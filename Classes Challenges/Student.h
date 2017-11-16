/*
* Student.h
*
* Version information
* Author: Dr. Shane Wilson
* Date: 08/10/2017
* Description: Class declaration header file for the Student Class
* Copyright notice
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Module.h"

class Student {

	//Friend function
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);

	//Priviate data members - we make them private so we can protect the data
	//This enforces encapsulation. We control access through the public member functions
private:
	std::string name_;
	std::string registrstionID_;
	std::string course_;
	int yearofStudy_;

	std::vector<Module> moduleMarks_{};

	//int moduleOneMark_;
	//int moduleTwoMark_;
	//int moduleThreeMark_;
	float CalculateAverage() const;
	static int enrolled_;

public:
	//Public member functions

	//Our default constructor. This does nothing other than create an empty student object. 
	//There isn't any data in the student object
	Student();

	//Custom constructor. We use this to initialise the object with data we pass in
	Student(std::string name, std::string registration, std::string course, int yearofStudy);

	Student(std::string name);

	//Getters and setters for each member variable
	void SetName(std::string name);
	std::string GetName() const;

	void SetRegistrationID(std::string registrstionID);
	std::string GetRegistrationID() const;

	void SetCourse(std::string course);
	std::string GetCourse() const;

	void SetYearofStudy(int year);
	int GetYearofStudy() const;

	void AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);
	void AddModule(Module m);
	void DeleteModule(std::string moduleCode);
	void UpdateModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);
	int GetNumberModules();

	void ToString() const;

	std::string Student::CalculateClassification() const;
	//std::string Student::CalculateClassification();
	
	//Default Constructor
	~Student();

	static int GetEnrolled();

};