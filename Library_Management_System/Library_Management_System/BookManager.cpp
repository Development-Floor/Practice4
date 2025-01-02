#include "BookManager.h"
#include <iostream>

BookManager::BookManager(): size(0) {}

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
	++size;
}

void BookManager::displayAllBooks() {
	cout << "------- 格废 -------";
	for (Book book : books) {
		cout << "\n力格: " << book.title << endl;
		cout << "历磊: " << book.author << endl;
	}
	cout << "--------------------\n" << endl;
}

void BookManager::searchByTitle(string title) {
	cout << "--------------------" << endl;
	cout << "力格 八祸: " << title << "\n" << endl;
	for (Book book : books) {
		if ((book.title).compare(title) == 0) {
			cout << "力格: " << book.title << endl;
			cout << "历磊: " << book.author << endl;
			cout << "--------------------\n" << endl;
			return;
		}
	}
	cout << "--------------------\n" << endl;
}

void BookManager::searchByAuthor(string author) {
	cout << "--------------------" << endl;
	cout << "历磊 八祸: " << author << "\n" << endl;
	for (Book book : books) {
		if ((book.author).compare(author) == 0) {
			cout << "力格: " << book.title << endl;
			cout << "历磊: " << book.author << endl;
			cout << "--------------------\n" << endl;
			return;
		}
	}
	cout << "--------------------\n" << endl;
}