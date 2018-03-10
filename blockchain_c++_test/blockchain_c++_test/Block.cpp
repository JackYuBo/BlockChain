#include "Block.h"

Block::Block()
{

}


Block::~Block()
{
}

Block::Block(int index,
	std::string timestamp,
	std::string data,
	std::string previous_hash)
{
	this->index = index;
	this->timestamp = timestamp;
	this->data = data;
	this->previous_hash = previous_hash;
}

std::string Block::calculateHash()
{


	return hash;
}