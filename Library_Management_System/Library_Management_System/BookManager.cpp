#include "BookManager.h"
#include <iostream>

BookManager::BookManager(): size(0) {}

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
	++size;
}

void BookManager::displayAllBooks() {
	cout << " --- 책 목록 ---" << endl;
	for (Book book : books) {
		cout << "제목: " << book.title << endl;
		cout << "저자: " << book.author << "\n" << endl;
	}
}