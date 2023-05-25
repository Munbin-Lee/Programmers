#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct Node {
    bool isTerminal;
    array<Node*, 10> child;
};

int nodeCnt;
Node nodes[2000000];

Node* createNode() {
    auto pNode = &nodes[nodeCnt++];
    pNode->isTerminal = false;
    pNode->child.fill(nullptr);
    return pNode;
}

Node* root = createNode();

bool hasPrefix(string &s) {
    auto pNode = root;
    for (char ch : s) {
        int idx = ch - '0';
        if (!pNode->child[idx]) {
            pNode->child[idx] = createNode();
        } else if (pNode->child[idx]->isTerminal) return true;
        pNode = pNode->child[idx];
    }
    pNode->isTerminal = true;
    return false;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (string &s : phone_book) {
        if (hasPrefix(s)) return false;
    }
    return true;
}