#include "BookManager.h"
#include <iostream>

BookManager::BookManager(): size(0) {}

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
	++size;
}

void BookManager::displayAllBooks() {
	cout << " --- å ��� ---" << endl;
	for (Book book : books) {
		cout << "����: " << book.title << endl;
		cout << "����: " << book.author << "\n" << endl;
	}
}

void BookManager::searchByTitle(string title) {
	cout << "���� �˻�: " << title << endl;
	cout << "--------------------" << endl;
	for (Book book : books) {
		if ((book.title).compare(title) == 0) {
			cout << "����: " << book.title << endl;
			cout << "����: " << book.author << "\n" << endl;
			return;
		}
	}
}