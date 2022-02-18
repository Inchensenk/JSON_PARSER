// JSON_PARSER.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Parser.h"
const char* json =
"{ \"name\": \"dmb 20\", \"students\": [\"pulia\", \"bomba\", \"shtik\"], \"subjects\": [\"c++\", \"c#\", \"c##\"], \"marks\":[[4, 5, 5], [3, 5, 4], [5, 5, 3]]}";

int main()
{
	Parser parser(json);
	parser.parse();

	parser.print();
}

