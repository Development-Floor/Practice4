#pragma once
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class BookManager {
	vector<Book> books;

public:
	void addBook(string title, string author);
	void displayAllBooks();
	void searchByTitle(string title);
	void searchByAuthor(string author);
};