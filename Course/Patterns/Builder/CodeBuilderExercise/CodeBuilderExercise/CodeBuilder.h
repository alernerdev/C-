#pragma once
#include <string>
#include <ostream>
#include <vector>

using namespace std;

class CodeBuilder
{
private:
	string className;
	vector<pair<string, string>> fields;

public:
	CodeBuilder(const string & className) : className(className)
	{

	}

	CodeBuilder& add_field(const string & name, const string & type)
	{
		fields.emplace_back(make_pair(name, type));

		return *this;
	}

	friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
	{
		os
			<< "class " << obj.className << '\n'
			<< "{\n";

		for (auto p : obj.fields)
		{
			os << "  " << p.second << " " << p.first << ";\n";
		}

		os << "};";

		return os;
	}
};
