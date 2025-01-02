#include <iostream>
#include "Book.h"
#include "BookManager.h"

using namespace std;

int main() {

	/*
	*  ������ ���� ��� �����
	* 1. å �������� �˻�
	* 2. �۰��� �˻�
	*/

	BookManager bookManager;

	// å 10�� �߰�
	for (int i = 1; i <= 10; i++) {
		bookManager.addBook("Book" + to_string(i), "Author" + to_string(i));
	}

	// ���� å ��� ���
	bookManager.displayAllBooks();

	// ���� �˻�
	bookManager.searchByTitle("Book6");

	// �۰� �˻�
	bookManager.searchByAuthor("Author3");

	return 0;
}