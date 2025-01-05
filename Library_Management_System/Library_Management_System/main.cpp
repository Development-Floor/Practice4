#include <iostream>
#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main() {

	/*
	*  ������ ���� ��� �����
	* 1. å �������� �˻�
	* 2. �۰��� �˻�
	*/

	BookManager bookManager;

	// å 10�� �߰�
	for (int i = 1; i <= 10; i++) { //�������� å �߰�
		bookManager.addBook("Book" + to_string(i), "Author" + to_string(i));
	}

	// ���� å ��� ���
	bookManager.displayAllBooks();

	// ���� �˻�
	bookManager.searchByTitle("Book6");

	// �۰� �˻�
	bookManager.searchByAuthor("Author3");


	// ------------------------------------ ���� ����

	/*
	* (����) �뿩 ��� �����
	* 
	* ������, �뿩��Ͽ� å �߰�
	* å ��� ����
	* å �뿩�ϱ�
	* å �ݳ��ϱ�
	*/

	cout << "\n\n------------- ���� ���� -------------";

	BookManager bookManager2;
	BorrowManager borrowManager;

	char action = ' ';

	string title = "";
	string author = "";

	cout << "\n�ȳ��ϼ���~" << endl;
	cout << "�������� ���� ���� ȯ���մϴ�!\n" << endl;

	while (true) {
		cout << "� ���� �Ͻðڽ��ϱ�? (����Ű)" << endl;
		cout << "1) �������� å �߰�" << endl;
		cout << "2) �������� å ��� ����" << endl;
		cout << "3) å�� �뿩 ��� ����" << endl;
		cout << "4) �������� å �뿩" << endl;
		cout << "5) �۰� �̸����� å �뿩" << endl;
		cout << "6) �������� å �ݳ�" << endl;
		cout << "0) ������\n" << endl;
		cout << "�ൿ �Է�: ";
		cin >> action;

		cout << endl;

		// �ݺ��� Ż��
		if (action == '0') {
			cout << "���� �Ϸ� �Ǽ���~" << endl;
			break;
		}

		// å �߰�
		if (action == '1') {
			cout << "\n����: ";
			cin >> title;

			cout << "\n����: ";
			cin >> author;

			if (bookManager2.findByTitle(title)) {
				cout << "\n�ش� ������ å�� �������� �ֽ��ϴ�\n" << endl;
				continue;
			}

			// �������� �߰�, �뿩(���) ��Ͽ� �߰�
			bookManager2.addBook(title, author);
			borrowManager.initializeStock({ title, author });

			cout << "\n" << title << "å�� �߰��߽��ϴ�.\n" << endl;
			continue;
		}

		// ������ å ���
		if (action == '2') {
			bookManager2.displayAllBooks();
			continue;
		}

		// �뿩 ���
		if (action == '3') {
			borrowManager.displayStock();
			continue;
		}

		// �������� å ������
		if (action == '4') {
			cout << "\n����: ";
			cin >> title;

			if (bookManager2.findByTitle(title) == NULL || !borrowManager.borrowBook(title)) {
				cout << "\nã�� å�� �������� �����ϴ�.\n" << endl;
				continue;
			}

			cout << "\n" << title << "å�� ���Ƚ��ϴ�.\n" << endl;

			continue;
		}

		// �۰� �̸����� å ������
		if (action == '5') {
			cout << "\n����: ";
			cin >> author;

			if (bookManager2.findByAuthor(author) == NULL || !borrowManager.borrowBook(bookManager2.findByAuthor(author)->title)) {
				cout << "\nã�� å�� �������� �����ϴ�.\n" << endl;
				continue;
			}

			cout << "\n" << title << "å�� ���Ƚ��ϴ�.\n" << endl;

			continue;
		}

		// �������� å �ݳ�
		if (action == '6') {
			cout << "\n����: ";
			cin >> title;

			if (bookManager2.findByTitle(title) == NULL || !borrowManager.returnBook(title)) {
				cout << "\n�ش� å�� �������� å�� �ƴմϴ�.\n" << endl;
				continue;
			}

			cout << "\n" << title << "å�� �ݳ��߽��ϴ�.\n" << endl;

			continue;
		}
	}

	return 0;
}