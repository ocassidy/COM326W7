#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingModule
{		
	TEST_CLASS(UnitTestModule)
	{
	public:
		
		TEST_METHOD(TestCustomConstructor)
		{
			//Arrange
			//No arranging to do

			//Act - create a new module object
			Module* modulePtr{ new Module{ "Software testing for beginners", "TES101", 20, 0 } };

			//Assert - test the pointer is not null
			Assert::IsNotNull(modulePtr);

			delete modulePtr;
			modulePtr = nullptr;
			
		}

		TEST_METHOD(TestGetModuleCode)
		{
			//Arrange
			Module module { "Software testing for beginners", "TES101", 20, 0 };
			std::string expected{ "TES101" };
			std::string actual{};
			//Act
			actual = module.getModuleCode();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestSetModuleCode)
		{
			//Arrange
			Module module {};
			std::string expected{ "TES220" };
			std::string actual{};
			//Act
			module.setModuleCode("TES220");
			actual = module.getModuleCode();

			//Assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(TestGetCreditPoints)
		{
			//Arrange
			Module module { "Software testing for beginners", "TES101", 50, 0 };
			int expected{ 50 };
			int actual{};
			//Act
			actual = module.getModuleCreditPoints();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestSetCreditPoints)
		{
			//Arrange
			Module module {};
			int expected{40};
			int actual{};
			//Act
			module.setModuleCreditPoints(40);
			actual = module.getModuleCreditPoints();

			//Assert
			Assert::AreEqual(expected, actual);
		}

	};
}

namespace TestingStudent
{		
	TEST_CLASS(UnitTestModule)
	{
	public:
		
		TEST_METHOD(TestCustomConstructor)
		{
			//Arrange
			//No arranging to do

			//Act - create a new module object
			Student* studentPtr{ new Student{"Sarah Marshall", "BOO465854", "BSc Hons Media", 3} };

			//Assert - test the pointer is not null
			Assert::IsNotNull(studentPtr);

			delete studentPtr;
			studentPtr = nullptr;
			
		}

		TEST_METHOD(TestAddModule1)
		{
			//Arrange
			Student student{ "Sarah Marshall", "BOO465854", "BSc Hons Media", 3 };
			Module module { "Software testing for beginners", "TES101", 20, 0 };
			student.AddModule(module);
			int expected{1};
			int actual{0};
			//Act
			actual = student.GetNumberModules();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestAddModule2)
		{
			//Arrange
			Student student{ "Sarah Marshall", "BOO465854", "BSc Hons Media", 3 };
			student.AddModule("Software testing for beginners", "TES101", 20, 40);
			student.AddModule("Play fighting ", "ACT203", 40, 67);

			int expected{ 2 };
			int actual{ 0 };

			//Act
			actual = student.GetNumberModules();

			//Assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(TestCalculateClassification)
		{
			//Arrange
			Student student{ "Sarah Marshall", "BOO465854", "BSc Hons Media", 3 };
			student.AddModule("Software testing for beginners", "TES101", 20, 80);
			student.AddModule("Play fighting ", "ACT203", 40, 80);

			std::string expected{"1st class"};
			std::string actual{};

			//Act
			actual = student.CalculateClassification();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestSetDeleteModule)
		{
			//Arrange
			Student student{ "Sarah Marshall", "BOO465854", "BSc Hons Media", 3 };
			student.AddModule("Software testing for beginners", "TES101", 20, 40);
			student.AddModule("Play fighting ", "ACT203", 40, 67);

			int expected{ 1 };
			int actual{ 0 };

			//Act
			student.DeleteModule("ACT203");
			actual = student.GetNumberModules();

			//Assert
			Assert::AreEqual(expected, actual);
		}

	};
}