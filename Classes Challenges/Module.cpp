#include "Module.h"


Module::Module()
{
}
Module::Module(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) :
	moduleTitle_{ moduleTitle }, moduleCode_{ moduleCode }, moduleCreditPoints_{ moduleCreditPoints }, moduleMark_{ moduleMark } {}

std::string Module::getModuleTitle() const{
	return moduleTitle_;
}
void Module::setModuleTitle(std::string title) {
	moduleTitle_ = title;
}

std::string Module::getModuleCode() const {
	return moduleCode_;
}
void Module::setModuleCode(std::string code) {
	moduleCode_ = code;
}


int Module::getModuleMark() const {
	return moduleMark_;
}
void Module::setModuleMark(int mark) {
	moduleMark_ = mark;
};


int  Module::getModuleCreditPoints() const {
	return moduleCreditPoints_;
}
void  Module::setModuleCreditPoints(int creditPoints) {
	moduleCreditPoints_ = creditPoints;
}