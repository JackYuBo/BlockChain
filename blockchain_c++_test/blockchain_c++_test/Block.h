#pragma once
#ifndef BLOCK_H
#define BLOCK_H
//#include<iostream>
#include<string>
//using namespace std;

class Block
{
public:
	Block();
	~Block();
	Block(int index,
		std::string timestamp, 
		std::string data, 
		std::string previous_hash);
	std::string calculateHash();

public:
	int index;
	std::string timestamp;
	std::string data;
	std::string previous_hash;
	std::string hash;
	
};
#endif