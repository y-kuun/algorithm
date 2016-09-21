#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef unsigned int uint32;

class Error {
   public:
    Error(string str) {
        cout << "Error Init!" << endl;
        this->err_name = str;
    }
    const string err_info() { return this->err_name; }
    string& get_private_mdata() {
        return err_name;
    }  // release the private data

   private:
    string err_name;
};

int main() {
    int int_min = 0x80000000;
    unsigned int uint = 0;
    cout << int_min << " " << uint << endl;
    try {
        scanf("%d", &int_min);
        cout << int_min << " " << endl;
        throw Error("My Error!");
    } catch (Error e) {
        cerr << "Something Wrong! " << e.err_info() << __FILE__ << __LINE__
             << endl;
        string& p_mdata = e.get_private_mdata();
        p_mdata[0] = 'A';
        cerr << "Something Wrong! " << e.err_info() << __FILE__ << __LINE__
             << endl;
    }

    return 0;
}

template <typename T>
class Final_class {
   public:
    friend T;

   private:
    Final_class();
    ~Final_class();
};

class sealed_class : public virtual Final_class<sealed_class> {
   public:
    sealed_class();
    ~sealed_class();
};