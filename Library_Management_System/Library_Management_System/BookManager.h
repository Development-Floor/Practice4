#pragma once
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class BookManager {
	vector<Book> books;
	int size;

public:
	BookManager();
};