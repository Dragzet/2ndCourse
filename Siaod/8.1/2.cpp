#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

struct Node {
    wchar_t character;  
    int frequency;
    Node *left, *right;

    Node(wchar_t character, int frequency) {
        left = right = nullptr;
        this->character = character;
        this->frequency = frequency;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void generateHuffmanCodes(Node* root, wstring code, map<wchar_t, wstring>& huffmanCodes) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    generateHuffmanCodes(root->left, code + L"0", huffmanCodes);
    generateHuffmanCodes(root->right, code + L"1", huffmanCodes);
}

map<wchar_t, wstring> buildHuffmanTree(const wstring& text) {
    map<wchar_t, int> frequencyMap;
    for (wchar_t ch : text) {
        frequencyMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : frequencyMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        int sum = left->frequency + right->frequency;
        Node* newNode = new Node(L'\0', sum);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    map<wchar_t, wstring> huffmanCodes;
    generateHuffmanCodes(minHeap.top(), L"", huffmanCodes);

    return huffmanCodes;
}

wstring encodeText(const wstring& text, map<wchar_t, wstring>& huffmanCodes) {
    wstring encodedText = L"";
    for (wchar_t ch : text) {
        encodedText += huffmanCodes[ch];
    }
    return encodedText;
}

wstring decodeText(Node* root, const wstring& encodedText) {
    wstring decodedText = L"";
    Node* currentNode = root;
    for (wchar_t bit : encodedText) {
        if (bit == L'0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decodedText += currentNode->character;
            currentNode = root;
        }
    }
    return decodedText;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstring text = L"Харитонов Арсений Николаевич";

    map<wchar_t, wstring> huffmanCodes = buildHuffmanTree(text);

    wcout << L"Коды Хаффмана для каждого символа:\n";   
    for (auto pair : huffmanCodes) {
        wcout << pair.first << L": " << pair.second << endl;
    }

    wstring encodedText = encodeText(text, huffmanCodes);

    wcout << L"\nЗакодированный текст:\n" << encodedText << endl;

    
    Node* root = nullptr;
    map<wchar_t, int> frequencyMap;
    for (wchar_t ch : text) {
        frequencyMap[ch]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (auto pair : frequencyMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    while (minHeap.size() != 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();
        int sum = left->frequency + right->frequency;
        Node* newNode = new Node(L'\0', sum);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }
    root = minHeap.top();

    wstring decodedText = decodeText(root, encodedText);

    wcout << L"\nДекодированный текст:\n" << decodedText << endl;

    return 0;
}