#pragma once
#include <string>

using namespace std;

class Book {
public:
	const string title;
	const string author;

	Book(string title, string author);
};