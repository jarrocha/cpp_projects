#include <iostream>
#include <fstream>      // file input and output
#include <string>
#include <string.h>     //strcmp

using namespace std;

int main(int argc, char *argv[]) {
    // similar to cat program?
    bool print_all = false;

    // check arguments quantity
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " FILENAME SEARCH_WORD\n";
        cout << argv[0] << " " << argv[1] << " " << argv[2];
        return 1;
    }
    
    // do cat behavior?
    if (strcmp(argv[2], "-a") == 0) {
        print_all = true;
        cout << "Printing all\n";
    } else {
        cout << "Searching for:  " << argv[2];
    }
    
    // open file
    fstream fp;
    fp.open(argv[1], ios::in | ios::out);

    // perform search or simply print all
    if (fp.is_open()) {
        string buffer;

        while (getline(fp, buffer)) {
            if (print_all) {
                cout << buffer << endl;
            } else {
                if (buffer.find(argv[2]) != std::string::npos) {
                    cout << buffer << endl;
                }
            }
        }
    }
    
    // close file
    fp.close();
    
    return 0;
}