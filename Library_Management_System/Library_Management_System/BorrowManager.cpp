#include "BorrowManager.h"

void BorrowManager::initializeStock(Book book, int quantity) {
	stock[book.title] = quantity;
}