#include <iostream>
#include <vector>

using std::string;
using std::vector;

#include "Student.h"
#include "Arr_Student.h"

#include <gtest/gtest.h>

TEST(ClassArrStudent, test_add_student)
{
  Student student1;
  Arr_Student arr_student;
  unsigned int expected_n_students = 0;
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
  
  arr_student.add_student(student1);
  expected_n_students = 1;
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
  
  Student student2;
  arr_student.add_student(student2);
  expected_n_students = 2;
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());

}

TEST(ClassArrStudent, test_delete_student)
{
  Student student1;
  Student student2;
  Arr_Student arr_student;
  arr_student.add_student(student1);
  arr_student.add_student(student2);
  unsigned int expected_n_students = 1;
  
  arr_student.remove_student(1);
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
  
  arr_student.remove_student(2);
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
  
  arr_student.remove_student(1);
  expected_n_students = 0;
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
  
  arr_student.remove_student(1);
  expected_n_students = 0;
  
  ASSERT_EQ(expected_n_students, arr_student.get_n_student());
}

TEST(ClassArrStudent, test_get_student)
{
  Student student1(0, "Ваня", "не вказано", 0, "не вказано", "не вказано", NO_INDICA);;
  Student student2(0, "Петя", "не вказано", 0, "не вказано", "не вказано", NO_INDICA);;
  Arr_Student arr_student;
  arr_student.add_student(student1);
  arr_student.add_student(student2);
  
  string expect_student = "Ваня";
  
  ASSERT_EQ(expect_student, arr_student.get_student(1));
  
  expect_student = "Невірний номер";
  
  ASSERT_EQ(expect_student, arr_student.get_student(3));
}

TEST(ClassArrStudent, test_found_student)
{
  Student student1(0, "Ваня", "не вказано", 2018, "не вказано", "не вказано", NO_INDICA);;
  Student student2(0, "Петя", "не вказано", 2018, "не вказано", "не вказано", NO_INDICA);;
  Arr_Student arr_student;
  arr_student.add_student(student1);
  arr_student.add_student(student2);
  
  int expect_n_student = 2;
  
  ASSERT_EQ(expect_n_student, arr_student.find_student(2018));
  
  expect_n_student = 0;
  
  ASSERT_EQ(expect_n_student, arr_student.find_student(2017));
  ASSERT_EQ(expect_n_student, arr_student.find_student(2016));
}







