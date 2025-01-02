#include "BookManager.h"

BookManager::BookManager(): size(0) {}

void BookManager::addBook(string title, string author) {
	books.push_back(Book(title, author));
	++size;
}