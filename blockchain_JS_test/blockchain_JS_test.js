//调用crypto-js库中的sha256哈希函数
const SHA256 = require("crypto-js/sha256"); //crypto-js需要安装Node.js

//创建Block类
class Block 
{ 
    constructor(index, timestamp, data, previousHash = '') 
    { 
        this.index = index; 
        this.previousHash = previousHash; 
        this.timestamp = timestamp; 
        this.data = data; 
        this.hash = this.calculateHash(); 
    } 
    //计算哈希值
    //在一个区块中，我们获取所有属性的数值，通过哈希函数获取它们的哈希值作为该区块的哈希值。
    //我们使用 JSON.stringify 函数将区块的数据转换成字符串后，与区块中其它数据一同求哈希值。
    calculateHash() 
    { 
        return SHA256(this.index + this.previousHash + this.timestamp + JSON.stringify(this.data)).toString(); 
    } 
}

class Blockchain
{
    //构造函数
    constructor()
    {
        this.chain=[this.createGenesisBlock()];
    }
    //第一步：创造创世块，创世块就是区块链中第一个区块
    //它之所以特殊的原因就是区块链中每一个区块都应该通过哈希值指向前一区块，
    //但创世区块并不指向任何区块。
    //因此，一条新链创建之时创世区块就立刻被创建了。
    createGenesisBlock()
    {
        return new Block(0,"2018-03-05","Genesis block","0");
    }
    //第二步：添加新的区块
    //获取当前区块链中最新的区块
    getLatestBlock()
    {
        return this.chain[this.chain.length-1];
    }
    //将新的区块加入到区块链中
    addBlock(newBlock)
    {
        newBlock.previousHash=this.getLatestBlock().hash;
        newBlock.hash=newBlock.calculateHash();
        this.chain.push(newBlock);
    }
    //验证区块链
    //现在，我们需要检查是不是没有人干扰我们的区块链，并检查是不是一切都很稳定。
    //我们使用 “for” 循环遍历从区块 1 到最新区块。创世区块是区块 0。
    isChainValid()
    {
        for(let i=1;i<this.chain.length;i++)
        {
            const currentBlock=this.chain[i];
            const previousBlock=this.chain[i-1];
            if(currentBlock.hash!==currentBlock.calculateHash())
            {
                return false;
            }
            if(currentBlock.previousHash!==previousBlock.hash)
            {
                return false;
            }
        }
        return true;
    }
}

//使用 Blockchian 类，创建区块链实例。
//现在，我们将使用 Blockchain 类创建我们的 BlockGeeksCoin。
let BlockGeeksCoin=new Blockchain();

BlockGeeksCoin.addBlock(new Block(1,"2018-03-05",{amount:4}));
BlockGeeksCoin.addBlock(new Block(2,"2018-03-05",{amount:8}));








