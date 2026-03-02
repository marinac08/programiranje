#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() {
    string filePath;
    cout << "Enter the location of the input file: ";
    getline(cin, filePath);

    ifstream input(filePath, ios::binary);
    if (!input.is_open()) {
        cerr << "Error opening file at: " << filePath << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
    input.close();

    auto originalSize = fs::file_size(filePath);

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }
    
    vector<unsigned char> compressedData;
    for (size_t i = 0; i < encoded.size(); i += 8) {
        string byteStr = encoded.substr(i, 8);
        while (byteStr.size() < 8) byteStr += '0';
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            if (byteStr[j] == '1') {
                byte |= (1 << (7 - j));
            }
        }
        compressedData.push_back(byte);
    }

    fs::path inputPath(filePath);
    fs::path outputPath = inputPath.parent_path() / (inputPath.stem().string() + ".huff");

    ofstream output(outputPath, ios::binary);
    output.write(reinterpret_cast<char*>(compressedData.data()), compressedData.size());
    output.close();

    auto compressedSize = fs::file_size(outputPath);
    double compressionRatio = (1.0 - (double)compressedSize / originalSize) * 100.0;

    cout << "Compression complete." << endl;
    cout << "Compressed file saved as: " << outputPath << endl;
    cout << "Original size: " << originalSize << " bytes" << endl;
    cout << "Compressed size: " << compressedSize << " bytes" << endl;
    cout << "Compression achieved: " << compressionRatio << "% reduction" << endl;

    return 0;
}
