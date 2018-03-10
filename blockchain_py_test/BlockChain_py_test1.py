#!/usr/bin/env python
# -*- coding: utf-8 -*-

import hashlib as hasher
import datetime as date


class Block:
    def __init__(self, index, timestamp, data, previous_hash):
        self.index = index#索引
        self.timestamp = timestamp#时间戳
        self.data = data#数据，可以是任意存储的内容
        self.previous_hash = previous_hash#前一区块的哈希
        self.hash = self.hash_block()#区块本身的哈希

    def hash_block(self):
        sha = hasher.sha256()
        sha.update(
            bytes(
                str(self.index) + str(self.timestamp) + str(self.data) + str(
                    self.previous_hash), 'utf-8'))
        return sha.hexdigest()

#区块链中的第一个区块是如何而来？ 
#第一个区块，或者一般叫做创始块(genesis block), 这是一个十分特殊的块。
#在很多情况下，它是通过手动或是一些特殊的逻辑添加到区块链中。
#为简便起见，我们创建一个简单返回创世块的函数。
#创始块的索引为 0，有一个任意的数据值，一个属于 “前一个哈希” 参数的任意值。
def create_genesis_block():
    #  Manually construct a block with index 0 and arbitrary previous hash
    return Block(0, date.datetime.now(), "Genesis Block", "0")

#区块链的哈希就像是一个加密证明，它能够保证一旦一个区块被加入到区块链中，那么这个区块就永远无法被替换或者移除。
def next_block(last_block):
    this_index = last_block.index + 1
    this_timestamp = date.datetime.now()
    this_data = "Hey! I'm block " + str(this_index)
    this_hash = last_block.hash
    return Block(this_index, this_timestamp, this_data, this_hash)


def main():
    #  Create the blockchain and add the genesis block
    # 创建区块链，首先是创建出创始块(genesis block)
    blockchain = [create_genesis_block()]
    previous_block = blockchain[0]

    #  How many blocks should we add to the chain after the genesis block
    # 创世块之后连接的区块个数
    num_of_blocks_to_add = 20

    for i in range(0, num_of_blocks_to_add):
        block_to_add = next_block(previous_block)
        blockchain.append(block_to_add)
        previous_block = block_to_add
        #  Tell everyone about it!
        print("Block #{} has been added to the"
              "blockchain!".format(block_to_add.index))
        print("Hash: {}\n".format(block_to_add.hash))


if __name__ == "__main__":
    main()