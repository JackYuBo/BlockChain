#pragma once
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include"Block.h"

class BlockChain
{
public:
	BlockChain();
	~BlockChain();
	
	Block& operator[](int n);
	const Block& operator[](int length) const;

	Block createGenesisBlock();
	Block getLatestBlock();
	void addnewBlock(Block &NewBlock);
	bool isChainValid();



private:
	int length;




};
#endif
