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
