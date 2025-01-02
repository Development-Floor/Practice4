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

	// �ʼ� ����
	void searchByTitle(string title);
	void searchByAuthor(string author);

	// ���� ����
	Book* findByTitle(string title); //�������� ã�� ������, NULL ��ȯ
};