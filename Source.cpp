//Name: Lukas Pentowski
//Class: CS 210 T2756 - Programming Languages
//Project 3 - Shopping Cart
//Prof Chan
//Dec 9, 2022

//This project reuses several bits of code from my previous assignments.
//printMenu() uses my menu formatting from Clocks assignment.
//My character string code from Clocks.
//
//Input verification from Project 2
//

#include <Python.h>			//Allows use of Python
#include <iostream>			//cout() and cin()
#include <cmath>			//Included in Starter Code
#include <string>			//To use string functions
#include <iomanip>			//setw() and setfill()
#include <limits>			//max()
#include <chrono>			//milliseconds()
#include <thread>			//sleep_for()
#include <fstream>			//File Stream for ifstream


/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(std::string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_modules.PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}


/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(std::string proc, std::string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(std::string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

//Declaring functions/variables to be used
void printMenu(unsigned char width);
std::string nCharString(size_t n, char c);
int userChoice;
std::string userValue;
int itemCount;
std::string item;
std::ifstream histo;


//Main function, 
int main()
{

	printMenu(60);

	return 0;
}

//Character string for menu formatting
std::string nCharString(size_t n, char c) {
	std::string charString = std::string(n, c);
	return charString;

}
//Program Menu
void printMenu(unsigned char width) {
	//Using a do while loop to return to the top menu.  Will continue until user picks 4.
	do {
		system("CLS");
		std::cout << "\u001b[32m";
		std::cout << nCharString(width, '*') << std::endl;
		std::cout << std::setw(width - 1) << std::setfill(' ') << std::left << "* 1 - Display All Items Purchased" << "*" << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width - 1) << std::setfill(' ') << std::left << "* 2 - Display Total Purchased of Specific Item" << "*" << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width - 1) << std::setfill(' ') << std::left << "* 3 - Display a Histogram of All Items Purchased" << "*" << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(width - 1) << std::setfill(' ') << std::left << "* 4 - Exit Program" << "*" << std::endl;
		std::cout << nCharString(width, '*') << std::endl;


		std::cout << "Please select an option: ";
		//User input for their choice.
		std::cin >> userChoice;
		switch (userChoice) {

			//If userChoice is 1 -> clears screen and calls on the Python PrintTotal() function, then pauses
			//to ensure user sees data provided 
		case 1:

			system("CLS");
			CallProcedure("PrintTotal");
			system("pause");
			break;

			//If userChoice is 2 -> Clears screen, prompts user for an item and displays the total sold.
		
		case 2:
			system("CLS");
			for (;;) {
				std::cout << "Enter an item: ";
				//Verifies userValue is a string. If it is, formats the input to pass on to the Python function
				//by ensuring the first letter is capitalized.
				if (std::cin >> userValue) {
					std::cout << "\033[2J\033[1;1H";
					userValue[0] = toupper(userValue[0]);
					itemCount = callIntFunc("ItemCount", userValue);

					//If the returned value is greater than zero, displays the item and amount sold.
					if (itemCount != 0) {
						std::cout << "The total number of " << userValue << " sold is " << itemCount << std::endl;
						system("pause");
						break;
					}
					//Otherwise, it lets the user know the Item was not found.
					else {
						std::cout << "Item not found." << std::endl;
						system("pause");
					}
				}
				//Error message if input was not a string
				else {
					//ERROR OUTPUT MESSAGE, CLEARS THE BUFFER, AND GOES BACK TO TOP OF FOR LOOP
					std::cout << "Please enter a valid input." << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
				}
			}
			
			break;
		
		//If userChoice is 3 -> Clears screen, generates the frequency.dat file via the Python function and
		//then opens the file
		case 3:
			system("CLS");
			CallProcedure("Histogram");
			histo.open("frequency.dat");

			//Informs the user if the file fails to open
			if (!histo.is_open()) {
				std::cout << "Error loading histogram data." << std::endl;
				break;
			}

			//While loop to output info if the file isn't empty.
			while (!histo.fail()) {
				std::cout << std::setw(34) << std::setfill(' ') << std::right << "Histogram of Items Sold" << std::endl;
				std::cout << nCharString(45, '_') << "\033[0;31m" << std::endl;
				histo >> item;
				histo >> itemCount;

				//While loop to print each line after the Histogram title.
				while (!histo.fail()) {
					std::cout << std::setw(15) << std::setfill(' ') << std::left << item 
						<< "\033[0;32m" << nCharString(itemCount, 'x') << "\033[0;31m" << std::endl;
					histo.ignore();
					histo >> item;
					histo >> itemCount;
				}
			}
			//Closes file.
			histo.close();
			std::cout << "\033[0;32m" << std::endl;
			system("pause");
			break;

			//If userChoice is 4 -> Outputs message stating exiting the program and exits.
		
		case 4:
			std::cout << "Exiting Program." << std::endl;
			exit(1);

			//Any input other than 1-4 will provide an error message.
		default:
			std::cout << "Pick a value between 1 and 4." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	} while (userChoice != 4);
}
