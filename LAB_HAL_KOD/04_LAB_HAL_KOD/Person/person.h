#pragma once

class Person {
	char* name;
	unsigned int age;
public:
	Person();
	Person(const char*, unsigned int);
	Person(const Person&);
	~Person();
	char* getName() const;
	void setName(const char*);
	unsigned int getAge() const;
	void setAge(unsigned int);
};