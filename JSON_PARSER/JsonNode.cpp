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
	//вначале печатаем табы, в колличестве уровней вложенности
	printTab(deep);

	//печатаем нужную скобку
	if (!isArray)
	{
		cout << '{' << endl;
	}

	else
	{
		cout << '[' << endl;
	}
	
	//дальше пропечатаем все что есть в объекте
	printStrings(deep);

	printNumbers(deep);

	printFlags(deep);

	printObjects(deep);

	printArrays(deep);

	printTab(deep);

	//и закрываем скобку
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
	когда мы проваливаемся в значение, то мы значение глубины увеличиваем  на единицу
	для того чтобы что-то напечатать мы делаем deep + 1
	*/
	int _deep = deep + 1;

	for (auto item : strings)
	{
		//для каждой строки мы печатаем смещение
		printTab(_deep);

		//если это не массив
		if (!isArray)
		{
			//то мы печатаем имя этого элемента
			cout << '\"' << item.first << "\":\"";
		}
		//и влюбом случае печатаем значение этого элемента
		cout << item.second << "\",\n";
	}
}

void JsonNode::printNumbers(int deep) const
{
	int _deep = deep + 1;

	for (auto item : numbers)
	{
		//для каждой строки мы печатаем смещение
		printTab(_deep);

		//если это не массив
		if (!isArray)
		{
			//то мы печатаем имя этого элемента
			cout << '\"' << item.first << "\": ";
		}
		//и влюбом случае печатаем значение этого элемента
		cout << item.second << "\",\n";
	}
}

void JsonNode::printFlags(int deep) const
{
	int _deep = deep + 1;

	for (auto item : flags)
	{
		//для каждой строки мы печатаем смещение
		printTab(_deep);

		//если это не массив
		if (!isArray)
		{
			//то мы печатаем имя этого элемента
			cout << '\"' << item.first << "\":\"";
		}
		//и влюбом случае печатаем значение этого элемента
		cout << item.second << "\",\n";
	}
}

void JsonNode::printObjects(int deep) const
{
	int _deep = deep + 1;

	for (auto item : objects)
	{
		//для каждой строки мы печатаем смещение
		printTab(_deep);

		//если это не массив
		if (!isArray)
		{
			//то мы печатаем имя этого элемента
			cout << '\"' << item.first << "\": ";
		}
		cout << endl;

		//просим объект напечатать себя вглубь
		item.second->print(_deep);
		//и влюбом случае печатаем значение этого элемента
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
		//4 пробела вместо таба, потому что \t это 8 пробелов
		cout << "    ";
	}
}

