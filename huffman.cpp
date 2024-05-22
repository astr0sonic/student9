#include "huffman.h"
#include<vector>
#include<map>
#include<string>
#include<queue>

using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, * right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)    {
        return (l->freq > r->freq);
    }
};

map<char, string> codes = {};
map<char, int> freq = {};
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap = {};


void storeCodes(struct MinHeapNode* root, const string str)
{
    if (root == NULL)
        return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

void HuffmanCodes(int size)
{
    struct MinHeapNode* left, * right, * top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void calcFreq(const string str, int n)
{
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

Node* buildHuffmanTree(map<char, string>& codes) {
    Node* root = new Node();
    root->data = '-';
    root->left = nullptr;
    root->right = nullptr;

    for (auto& pair : codes) {
        Node* curr = root;
        for (char& bit : pair.second) {
            if (bit == '0') {
                if (curr->left == nullptr) {
                    curr->left = new Node();
                    curr->left->data = '-';
                    curr->left->left = nullptr;
                    curr->left->right = nullptr;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = new Node();
                    curr->right->data = '-';
                    curr->right->left = nullptr;
                    curr->right->right = nullptr;
                }
                curr = curr->right;
            }
        }
        curr->data = pair.first;
    }

    return root;
}

string decodeHuffman(Node* root, const string encodedStr) {
    Node* curr = root;
    string ans = "";
    for (char bit : encodedStr) {
        if (bit == '0') {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
        if (curr->left == nullptr && curr->right == nullptr) {
            ans += curr->data;
            curr = root;
        }
    }
    return ans;
}

string encode(const string& text) 
{
    string encodedString = "";
    calcFreq(text, text.size());
    HuffmanCodes(text.size());
    for (auto i : text)
        encodedString += codes[i];
    return encodedString;
}

string decode(const string& encoded, map<char, string>& codes_) 
{
    string decodedString = "";
    Node* root = buildHuffmanTree(codes_);
    decodedString = decodeHuffman(root, encoded);
    return  decodedString;
}
