#include <iostream>
#include "Book.h"
#include "BookManager.h"

using namespace std;

int main() {

	/*
	*  도서관 관리 기능 만들기
	* 1. 책 제목으로 검색
	* 2. 작가로 검색
	*/

	BookManager bookManager;

	// 책 10개 추가
	for (int i = 1; i <= 10; i++) {
		bookManager.addBook("Book" + to_string(i), "Author" + to_string(i));
	}

	// 현재 책 목록 출력
	bookManager.displayAllBooks();

	// 제목 검색
	bookManager.searchByTitle("Book6");

	// 작가 검색
	bookManager.searchByAuthor("Author3");

	return 0;
}