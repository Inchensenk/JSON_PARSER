#pragma once
#include "JsonNode.h"
#include <string>
class Parser
{
public:

	//����������� 
	Parser(const char* source);
	 
	~Parser();

	/*��������� �� �������������� ����� ������� ������������, ������ ��� ���������� ������� ���� ����� 1 ���
	������� ��� ����� ��������� ���, ������� ����� �� 1 ��� ��������
	
	������ ������ ���� �������������. 
	����� ������� ������ ������������� �����: ������� �������, ������� �������� ������� (/n, /r).
	��� ����� �������� ������ ��� ������ ��������� �� ������.
	�� ����� ����� �� ������
	*/
	//����� �������� ������ � ������ Node
	
	void parse();

	//����� ����� ��� ������)
	void print() const;

private:

	JsonNode* root;

	const char* source;

	size_t size;

	size_t currentIndex;

	
	//����� ���������� �� ������� ��������
	void parseObject(JsonNode* current);

	void parseArray(JsonNode* current);
	
	//����� ����������� ������ �������
	string parseString();

	void parseString(JsonNode* parent, string name);

	double parseNumber();

	//������ ��������� �������
	void parseNext(JsonNode* parent, string name);


	/*
	JSON ����� ���� ����� � ���-�� ����� ����� �� ���.
	����� ��������������� �� ����������� � ������������� ������.
	����� �� ����� �� ������� �������, ����������� 2 ������: assertSize(); � inrementIndex();
	*/
	//�������� �� ����� �� ������� �������
	void assertSize();

	//������ i++ � for 
	void incrementIndex();

	/*
	����� ����������� ������ � ��� ������� ����� �� ���� �� ������� ��������� ������,
	�� ���� �� �� ��������� ����� �� �������� �������� � �� �� ���������, �� ���� ��� ��� � ��� ����������� �������
	*/
	void goToNextSimbol();
};

