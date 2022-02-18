#pragma once
#include "JsonNode.h"
#include <string>
class Parser
{
public:

	//конструктор 
	Parser(const char* source);
	 
	~Parser();

	/*поскольку мы инициализируем обект строкой неизменяемой, значит нам достаточно вызвать этот метод 1 раз
	вызвать его можно несколько раз, главное чтобы он 1 раз сработал
	
	Парсер должен быть однопроходный. 
	Можно конечно сперва нормализовать текст: удалить пробелы, удалить переводы каретки (/n, /r).
	Для этого придется каждый раз заново проходить по строке.
	Мы можем этого не делать
	*/
	//метод перевода текста в формат Node
	
	void parse();

	//метод чисто для дебага)
	void print() const;

private:

	JsonNode* root;

	const char* source;

	size_t size;

	size_t currentIndex;

	
	//метод отвечающий за парсинг объектов
	void parseObject(JsonNode* current);

	void parseArray(JsonNode* current);
	
	//метод считывающий стринг объекты
	string parseString();

	void parseString(JsonNode* parent, string name);

	double parseNumber();

	//парсит следующий элемент
	void parseNext(JsonNode* parent, string name);


	/*
	JSON может быть битый и что-то может пойти не так.
	Будем ориентироваться на открывающие и закрывающиеся скобки.
	Чтобы не выйти за пределы массива, понадобятся 2 метода: assertSize(); и inrementIndex();
	*/
	//проверка на выход за границы массива
	void assertSize();

	//аналог i++ в for 
	void incrementIndex();

	/*
	метод запускается только в тех случаях когда мы идем по внешней структуре файлов,
	то есть не по значениям каких то стрингов например а за их пределами, то есть там где у нас бесполезные символы
	*/
	void goToNextSimbol();
};

