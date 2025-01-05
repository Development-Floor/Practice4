#include <iostream>
#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main() {

	/*
	*  도서관 관리 기능 만들기
	* 1. 책 제목으로 검색
	* 2. 작가로 검색
	*/

	BookManager bookManager;

	// 책 10개 추가
	for (int i = 1; i <= 10; i++) { //도서관에 책 추가
		bookManager.addBook("Book" + to_string(i), "Author" + to_string(i));
	}

	// 현재 책 목록 출력
	bookManager.displayAllBooks();

	// 제목 검색
	bookManager.searchByTitle("Book6");

	// 작가 검색
	bookManager.searchByAuthor("Author3");


	// ------------------------------------ 도전 과제

	/*
	* (도전) 대여 기능 만들기
	* 
	* 도서관, 대여목록에 책 추가
	* 책 목록 보기
	* 책 대여하기
	* 책 반납하기
	*/

	cout << "\n\n------------- 도전 과제 -------------";

	BookManager bookManager2;
	BorrowManager borrowManager;

	char action = ' ';

	string title = "";
	string author = "";

	cout << "\n안녕하세요~" << endl;
	cout << "도서관에 오신 것을 환영합니다!\n" << endl;

	while (true) {
		cout << "어떤 것을 하시겠습니까? (숫자키)" << endl;
		cout << "1) 도서관에 책 추가" << endl;
		cout << "2) 도서관의 책 목록 보기" << endl;
		cout << "3) 책의 대여 목록 보기" << endl;
		cout << "4) 제목으로 책 대여" << endl;
		cout << "5) 작가 이름으로 책 대여" << endl;
		cout << "6) 제목으로 책 반납" << endl;
		cout << "0) 나가기\n" << endl;
		cout << "행동 입력: ";
		cin >> action;

		cout << endl;

		// 반복문 탈출
		if (action == '0') {
			cout << "좋은 하루 되세요~" << endl;
			break;
		}

		// 책 추가
		if (action == '1') {
			cout << "\n제목: ";
			cin >> title;

			cout << "\n저자: ";
			cin >> author;

			if (bookManager2.findByTitle(title)) {
				cout << "\n해당 제목의 책이 도서관에 있습니다\n" << endl;
				continue;
			}

			// 도서관에 추가, 대여(재고) 목록에 추가
			bookManager2.addBook(title, author);
			borrowManager.initializeStock({ title, author });

			cout << "\n" << title << "책을 추가했습니다.\n" << endl;
			continue;
		}

		// 도서관 책 목록
		if (action == '2') {
			bookManager2.displayAllBooks();
			continue;
		}

		// 대여 목록
		if (action == '3') {
			borrowManager.displayStock();
			continue;
		}

		// 제목으로 책 빌리기
		if (action == '4') {
			cout << "\n제목: ";
			cin >> title;

			if (bookManager2.findByTitle(title) == NULL || !borrowManager.borrowBook(title)) {
				cout << "\n찾는 책이 도서관에 없습니다.\n" << endl;
				continue;
			}

			cout << "\n" << title << "책을 빌렸습니다.\n" << endl;

			continue;
		}

		// 작가 이름으로 책 빌리기
		if (action == '5') {
			cout << "\n저자: ";
			cin >> author;

			if (bookManager2.findByAuthor(author) == NULL || !borrowManager.borrowBook(bookManager2.findByAuthor(author)->title)) {
				cout << "\n찾는 책이 도서관에 없습니다.\n" << endl;
				continue;
			}

			cout << "\n" << title << "책을 빌렸습니다.\n" << endl;

			continue;
		}

		// 제목으로 책 반납
		if (action == '6') {
			cout << "\n제목: ";
			cin >> title;

			if (bookManager2.findByTitle(title) == NULL || !borrowManager.returnBook(title)) {
				cout << "\n해당 책은 도서관의 책이 아닙니다.\n" << endl;
				continue;
			}

			cout << "\n" << title << "책을 반납했습니다.\n" << endl;

			continue;
		}
	}

	return 0;
}