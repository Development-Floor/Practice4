#pragma once
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class BookManager {
	vector<Book> books;

public:
	void addBook(string title, string author);
	void displayAllBooks();

	// 필수 과제
	void searchByTitle(string title);
	void searchByAuthor(string author);

	// 도전 과제
	Book* findByTitle(string title); //제목으로 찾기 없으면, NULL 반환
};