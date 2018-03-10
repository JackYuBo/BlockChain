#include "BlockChain.h"

BlockChain::BlockChain() :length(0)
{
	createGenesisBlock();
}

BlockChain::~BlockChain()
{
}

Block& BlockChain::operator[](int n)
{

}

const Block& BlockChain::operator[](int length) const
{


}

Block BlockChain::createGenesisBlock()
{
	length++;
	return Block(0, "2018-03-05", "GenesisBlock", "0");
}

Block BlockChain::getLatestBlock()
{
	return BlockChain[length - 1];

}


void BlockChain::addnewBlock(Block &NewBlock)
{
	NewBlock.previous_hash = getLatestBlock().calculateHash();
	NewBlock.hash = NewBlock.calculateHash();
	length++;
}


bool BlockChain::isChainValid()
{
	for (int i = 1; i < length; i++)
	{
		Block currentBlock = this[i];
		Block previousBlock = this[i - 1];
		if (currentBlock.hash != currentBlock.calculateHash())
			return false;
		if (currentBlock.previous_hash != previousBlock.hash)
			return false;
	}
	return false;
}