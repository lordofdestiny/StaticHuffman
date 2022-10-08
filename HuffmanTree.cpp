#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(FrequencyMap const& _fmap) {
	constructHuffmanTree(_fmap);
}

void HuffmanTree::constructHuffmanTree(FrequencyMap const& _fmap) {
	auto const& fdata = _fmap.frequencies;
	std::vector<NodePtr> vec(fdata.size());
	std::ranges::copy(fdata | std::views::transform([](auto const& pair) {
		return std::make_shared<TreeNode>(pair.first, pair.second);
		}), vec.begin());
	std::priority_queue <NodePtr, std::vector<NodePtr>, NodePtrCmp> nodes({}, vec);

	while (nodes.size() > 1) {
		auto node = std::make_shared<TreeNode>(0);
		node->left = nodes.top();
		nodes.pop();
		node->right = nodes.top();
		nodes.pop();
		node->freq = node->left->freq + node->right->freq;
		nodes.emplace(std::move(node));
	}

	root = nodes.top();
}


std::unordered_map<char, std::string> HuffmanTree::extractCode(HuffmanTree const& _tree) {
	std::unordered_map<char, std::string> codes;
	std::stack<std::pair<NodePtr, std::string>> nodes;
	nodes.emplace(_tree.root, "");
	while (!nodes.empty()) {
		auto [node, prefix] = std::move(nodes.top());
		nodes.pop();
		if (node->left == nullptr && node->right == nullptr) {
			codes[node->key] = prefix;
			continue;
		}
		if (node->right != nullptr) {
			nodes.emplace(node->right, prefix + "1");
		}
		if (node->left != nullptr) {
			nodes.emplace(node->left, prefix + "0");
		}
	}
	return codes;
}