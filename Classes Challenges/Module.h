#pragma once

#include <string>

class Module
{
private:
	std::string moduleTitle_;
	std::string moduleCode_;
	int moduleCreditPoints_;
	int moduleMark_;
public:
	Module();
	Module(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);

	std::string getModuleTitle() const;
	void setModuleTitle(std::string);

	std::string getModuleCode() const;
	void setModuleCode(std::string);

	int getModuleMark() const;
	void setModuleMark(int mark);

	int getModuleCreditPoints() const;
	void setModuleCreditPoints(int creditPoints);


};

