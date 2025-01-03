#include "BorrowManager.h"
#include <iostream>

void BorrowManager::initializeStock(Book book, int quantity) {
	stock[book.title] = quantity;
}

void BorrowManager::borrowBook(string title) {
	if (stock.find(title) == stock.end()) {
		return;
	}

	if (stock[title] > 0) {
		--stock[title];
	}
}

void BorrowManager::returnBook(string title) {
	if (stock.find(title) == stock.end()) {
		return;
	}

	if (stock[title] < 3) {
		++stock[title];
	}
}

void BorrowManager::displayStock() {
	cout << "------- �뿩 -------";

	if (stock.empty()) {
		cout << "\n\n ����.\n" << endl;
	}
	else {
		for (pair<string, int> book : stock) {
			cout << "\n����: " << book.first << endl;
			cout << "���: " << book.second << "��" << endl;
		}
	}

	cout << "--------------------\n" << endl;
}