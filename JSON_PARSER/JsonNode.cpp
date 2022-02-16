#include "JsonNode.h"

JsonNode::~JsonNode()
{
	for (auto node : object)
	{
		delete node.second;
	}

	for (auto node : arrays)
	{
		delete node.second;
	}
}

void JsonNode::print(int deep) const
{
	int _deep = deep + 1;

	for (auto item : strings)
	{
		printTab(_deep);

		if (!isArray)
		{
			cout<< item.second
		}
	}
}

