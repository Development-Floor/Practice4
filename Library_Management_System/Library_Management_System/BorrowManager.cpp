#include "BorrowManager.h"

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

	++stock[title];
}