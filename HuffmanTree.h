#pragma once
#include <memory>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ranges>
#include "FrequencyMap.h"

class Huffman;

class HuffmanTree {
private:
	struct TreeNode;
	using NodePtr = std::shared_ptr<TreeNode>;
	struct TreeNode {
		char key;
		uint32_t freq;
		NodePtr left = nullptr;
		NodePtr right = nullptr;
	};
	struct NodePtrCmp {
		bool operator() (NodePtr const& n1, NodePtr const& n2) {
			return n1->freq > n2->freq;
		}
	};
public:
	friend class Huffman;
	using NodePointer = std::shared_ptr<TreeNode>;
	using HuffmanCodeT = std::unordered_map<char, std::string>;
private:
	NodePtr root = nullptr;
public:
	HuffmanTree(FrequencyMap const& data);
	static HuffmanCodeT extractCode(HuffmanTree const& _tree);
private:
	void constructHuffmanTree(FrequencyMap const& data);
};