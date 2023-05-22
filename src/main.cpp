#include <iostream>
#include <string>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;

#include "Student.h"
#include "Arr_Student.h"

int main()
{
	int finish_program = 1;
	Arr_Student arr_student;

	if (finish_program == 1) {
		cout << endl << "Демонстрація роботи конструкторів класу Student" << endl;
		Student student1(1, "коля", "ваня", 2018, "БК", "23", Y1);
		student1.write_on_screen();
		Student student2(student1);
		student2.write_on_screen();
	}

	cout << endl << "кількість студентів: "<< arr_student.get_n_student()<< endl;
	
	do {
		int operation_n = 0;

		cout << endl
		     << "Програма для роботи зі списком" << endl
		     << "1. Додати студента до списку" << endl
		     << "2. Видалити студента зі списку" << endl
		     << "3. Вивести окремого студента" << endl
		     << "4. Вивести весь список на екран" << endl
		     << "5. Вивести студентів певного року вступу" << endl
		     << "6. Вихід" << endl
		     << "Оберіть номер операції: ";
		cin >> operation_n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (operation_n == 1) {
			Student *student = new Student;
			student->write_info_student();

			arr_student.add_student(*student);
			arr_student.print();
		} else if (operation_n == 2) {
			unsigned int index = 0;

			cout << endl << "Введіть номер студента: ";
			cin >> index;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			arr_student.remove_student(index);
			arr_student.print();
		} else if (operation_n == 3) {
			unsigned int index = 0;

			cout << endl << "Введіть номер студента: ";
			cin >> index;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			arr_student.get_student(index);
		} else if (operation_n == 4) {
			arr_student.print();
		} else if (operation_n == 5) {
			unsigned int year = 0;

			cout << endl << "Введіть рік вступники якого вас цікавлять: ";
			cin >> year;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			arr_student.find_student(year);

		} else if (operation_n == 6) {
			finish_program = 0;
		} else
			cout << endl << "Ви ввели некоректні дані" << endl;

	} while (finish_program != 0);

	return 0;
}
