#include "JsonNode.h"

JsonNode::~JsonNode()
{
	for (auto node: objects)
	{
		delete node.second;
	}

	for (auto node: arrays)
	{
		delete node.second;
	}
}

void JsonNode::print(int deep) const
{
	//������� �������� ����, � ����������� ������� �����������
	printTab(deep);

	//�������� ������ ������
	if (!isArray)
	{
		cout << '{' << endl;
	}

	else
	{
		cout << '[' << endl;
	}
	
	//������ ����������� ��� ��� ���� � �������
	printStrings(deep);

	printNumbers(deep);

	printFlags(deep);

	printObjects(deep);

	printArrays(deep);

	printTab(deep);

	//� ��������� ������
	if (!isArray)
	{
		cout << '}';
	}

	else
	{
		cout << ']';
	}
}



void JsonNode::printStrings(int deep) const
{
	/*
	����� �� ������������� � ��������, �� �� �������� ������� �����������  �� �������
	��� ���� ����� ���-�� ���������� �� ������ deep + 1
	*/
	int _deep = deep + 1;

	for (auto item : strings)
	{
		//��� ������ ������ �� �������� ��������
		printTab(_deep);

		//���� ��� �� ������
		if (!isArray)
		{
			//�� �� �������� ��� ����� ��������
			cout << '\"' << item.first << "\":\"";
		}
		//� ������ ������ �������� �������� ����� ��������
		cout << item.second << "\",\n";
	}
}

void JsonNode::printNumbers(int deep) const
{
	int _deep = deep + 1;

	for (auto item : numbers)
	{
		//��� ������ ������ �� �������� ��������
		printTab(_deep);

		//���� ��� �� ������
		if (!isArray)
		{
			//�� �� �������� ��� ����� ��������
			cout << '\"' << item.first << "\": ";
		}
		//� ������ ������ �������� �������� ����� ��������
		cout << item.second << "\",\n";
	}
}

void JsonNode::printFlags(int deep) const
{
	int _deep = deep + 1;

	for (auto item : flags)
	{
		//��� ������ ������ �� �������� ��������
		printTab(_deep);

		//���� ��� �� ������
		if (!isArray)
		{
			//�� �� �������� ��� ����� ��������
			cout << '\"' << item.first << "\":\"";
		}
		//� ������ ������ �������� �������� ����� ��������
		cout << item.second << "\",\n";
	}
}

void JsonNode::printObjects(int deep) const
{
	int _deep = deep + 1;

	for (auto item : objects)
	{
		//��� ������ ������ �� �������� ��������
		printTab(_deep);

		//���� ��� �� ������
		if (!isArray)
		{
			//�� �� �������� ��� ����� ��������
			cout << '\"' << item.first << "\": ";
		}
		cout << endl;

		//������ ������ ���������� ���� ������
		item.second->print(_deep);
		//� ������ ������ �������� �������� ����� ��������
		cout << ",\n";
	}
}

void JsonNode::printArrays(int deep) const
{
	int _deep = deep + 1;

	for(auto item : arrays)
	{
		printTab(_deep);

		if (!isArray)
		{
			cout << '\"' << item.first << "\": ";
		}
		cout << endl;

		item.second->print(_deep);

		cout << ",\n";
	}
}

void JsonNode::printTab(int deep) const
{
	for (int i = 0; i < deep; i++)
	{
		//4 ������� ������ ����, ������ ��� \t ��� 8 ��������
		cout << "    ";
	}
}

