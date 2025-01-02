#include "BookManager.h"
#include <iostream>

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
}

void BookManager::displayAllBooks() {
	cout << "------- ��� -------";
	for (Book book : books) {
		cout << "\n����: " << book.title << endl;
		cout << "����: " << book.author << endl;
	}
	cout << "--------------------\n" << endl;
}

void BookManager::searchByTitle(string title) {
	cout << "--------------------" << endl;
	cout << "���� �˻�: " << title << "\n" << endl;
	for (Book book : books) {
		if ((book.title).compare(title) == 0) {
			cout << "����: " << book.title << endl;
			cout << "����: " << book.author << endl;
			cout << "--------------------\n" << endl;
			return;
		}
	}
	cout << "--------------------\n" << endl;
}

void BookManager::searchByAuthor(string author) {
	cout << "--------------------" << endl;
	cout << "���� �˻�: " << author << "\n" << endl;
	for (Book book : books) {
		if ((book.author).compare(author) == 0) {
			cout << "����: " << book.title << endl;
			cout << "����: " << book.author << endl;
			cout << "--------------------\n" << endl;
			return;
		}
	}
	cout << "--------------------\n" << endl;
}

Book* BookManager::findByTitle(string title) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].title.compare(title) == 0) {
			return &books[i];
		}
	}

	return NULL;
}