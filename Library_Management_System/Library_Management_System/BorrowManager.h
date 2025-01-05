#pragma once
#include <unordered_map>
#include <string>
#include "Book.h"

using namespace std;

class BorrowManager {
private:
	unordered_map<string, int> stock;

public:
	void initializeStock(Book book, int quantity = 3);
	bool borrowBook(string title);
	bool returnBook(string title);
	void displayStock();
};