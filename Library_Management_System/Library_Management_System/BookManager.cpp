#include "BookManager.h"
#include <iostream>

BookManager::BookManager(): size(0) {}

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
	++size;
}

void BookManager::displayAllBooks() {
	cout << " --- 氓 格废 ---" << endl;
	for (Book book : books) {
		cout << "力格: " << book.title << endl;
		cout << "历磊: " << book.author << "\n" << endl;
	}
}