#include <string>
#include <map>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

void storeCodes(struct MinHeapNode* root, const string str);
void HuffmanCodes(int size);
void calcFreq(const string str, int n);

string decodeHuffman(Node*, const string);
Node* buildHuffmanTree(map<char, string>& codes);
std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);
