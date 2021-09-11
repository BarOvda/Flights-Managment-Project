#pragma once
#include <string>
#include <iostream>

using namespace std;

class FlightCompException
{
public:
	virtual ~FlightCompException() {}
	virtual void Show() const = 0;

};

//======================================================================

class CompStringException :public FlightCompException
{
public:
	CompStringException(const char* message) {
		this->message = new char[strlen(message) + 1];
		strcpy(this->message, message);

	}

	virtual void Show() const override
	{
		std::cout << " Exeption was throw: " << this->message << endl;

	}

private:
	char* message;
};

//======================================================================

class CompLimitException :public FlightCompException
{
public:
	CompLimitException(int limit) {
		this->limit = limit;

	}

	virtual void Show() const override
	{
		std::cout << "Limit Exeption was throw: The limit was " << this->limit << endl;

	}

private:
	int limit;
};

//======================================================================

class CompFileException :public FlightCompException
{
public:
	CompFileException(char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy(this->fileName, fileName);

	}

	virtual void Show() const override
	{
		std::cout << "File Exeption was throw: " << this->fileName << endl;

	}

private:
	char* fileName;
};