#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;
class JsonNode
{
public:

	~JsonNode();

	//deep- ������� ������� ���� ��� ���������
	void print(int deep) const;
//private:
	/*��������� ��� ������� ���� ������ ����� �������� ���������� ������������� ������ ��� �������� �����
	������� object  � array, �������� �������� ���������, ������ ������� ����������� ������ �������.
	string, number � bool, �������� �������� ���������, ������� �������� ���� ��� ��������.
	�� ���� ���������� ����� ������� ���������:
	��� �������� ������� �������� �� ����� ������������ ������ flags
	��� �������� ����� ����� ������������ ������ string
	��� ��� javascript object notation �������� ��� ������ Number ������� �������� � ���� 2 ���� ������ �����(�������� int) ����� � ����� ����� �������(�������� float), ����� ���������� � double

	� javascript ������ ������� ������������, ���� ���� �� ��������� ����� �� �� ��������� ������� ����� 0,1,2,3...

	��� ��� �� �������� � ��������� javascript, �� ����� ��������� ���������� � ��� javascript
	������ ��������� �� JsonNode � � �������� ����� ����� �� ��� � ���������� ����� �������� � �������

	���� ������ ������� ��������� �� �� ����� ������� ��� � �������� ���� 
	���� ������ �� ������ ����� ��� ��, ������ � ��������� ��� ��� ������
	���� ��� ������ �� �� ������ �� � ������� ���� ��������

	��� ��� � ��� ����������� ���������, ����� ����������
	*/

	/*
    JSONE Node ��� ��������� ������, ��� ���� ������ object, ���� ������ array
    */  

	//� ����� ���� ���� ���, ������������ ���� ��� ����� ��� �������� ����
	string name;

	//������� ��������� �������
	map<string, JsonNode*> object;

	//������� 
	map<string, JsonNode*> arrays;

	//������
	map<string, string> strings;

	//�����
	map<string, double> numbers;

	map<string, bool> flags;

	bool isArray = false;

	/*Noda ��� ������, � ��� ��� ��� ������ �� �� ����� ���� ����� nullptr*/

	bool isNull = false;

private:

	void printStrings(int deep) const;

	void printNumbers(int deep) const;

	void printFlags(int deep) const;

	void printObjects(int deep) const;

	void printArrays(int deep) const;

	void printTab(int deep) const;
};