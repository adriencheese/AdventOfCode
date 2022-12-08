#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <queue>

using namespace std;

class Directory {
    public:
        Directory *parent;
        vector<Directory *> subDirectories;
        size_t size;
        string name;

        Directory() {
            size = 0;
            parent = nullptr;
            name = "";
        }

        void addSubDirectory(const string &newDirectoryName) {
            // cout << "add new subdirectory: " << newDirectoryName << endl;
            Directory *newSubDirectory = new Directory();
            newSubDirectory->name = newDirectoryName;
            newSubDirectory->parent = this;
            subDirectories.push_back(newSubDirectory);
        }

        size_t findDirectory(const string &directoryName) {
            for (int i = 0; i < subDirectories.size(); i++) {
                if (subDirectories[i]->name == directoryName) {
                    return i;
                }
            }
            
            cout << "can't find dir" << endl;
            return 0;
        }
};

size_t directorySize(Directory *head) {
    size_t sum = 0;
    queue<Directory*> unvisited;

    unvisited.push(head);

    while(!unvisited.empty()) {
        Directory* temp = unvisited.front();
        unvisited.pop();

        // cout << "name: " << temp->name << " - size: " << temp->size << endl;
        
        sum += temp->size;

        if (!temp->subDirectories.empty()) {
            for (auto i : temp->subDirectories) {
                unvisited.push(i);
            }
        }
    }

    return sum;
}

size_t bfs(Directory *head) {
    if (head->subDirectories.empty()) {
        // cout << "subDirectories.size(): " << head->subDirectories.size() << endl;
        return head->size;
    }

    size_t sum = 0;
    queue<Directory*> unvisited;

    unvisited.push(head);

    while(!unvisited.empty()) {
        Directory* temp = unvisited.front();
        unvisited.pop();

        size_t dirSize = directorySize(temp);

        // cout << "name: " << temp->name << " - size: " << dirSize << endl;
        
        if (dirSize <= 100000) {
            sum += dirSize;
        }

        if (!temp->subDirectories.empty()) {
            for (auto i : temp->subDirectories) {
                unvisited.push(i);
            }
        }
    }

    return sum;
}

int main() {
    ifstream file("input.in");

//  current state
    string nextDirectory;
    Directory home;
    home.name = "/";
    Directory *currentDir = &home;
    bool cd = false;

    string line;

    while (getline(file,line)) {
        // cout << line << endl;
        if (line.substr(0, 4) == "$ cd") {
            cd = true;
            nextDirectory = line.substr(5);
        }

        if (cd && nextDirectory == "..") {
            currentDir = currentDir->parent;
            cd = false;
            continue;
        } else if (cd) {
            currentDir = currentDir->subDirectories[currentDir->findDirectory(nextDirectory)];
            cd = false;
            continue;
        }

        if (line.substr(0, 4) == "$ ls") {
            continue;
        }

        if (line.substr(0,3) == "dir") {
            string dir = line.substr(4);
            currentDir->addSubDirectory(dir);
            continue;
        }
        currentDir->size += stoi(line.substr(0, line.find(" ")));
    }
    
    cout << bfs(&home);
}