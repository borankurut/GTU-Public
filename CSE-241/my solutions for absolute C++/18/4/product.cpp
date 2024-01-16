#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class ProductNotFound{
public:
    ProductNotFound(string theName){name = theName;}
    string getName() const{return name;}
private:
    string name;
};


int getProductID(int ids[], string names[],
    int numProducts, string target) throw(ProductNotFound);

int main(){     // Sample code to test the getProductID function
    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = {"computer", "flash drive",
                         "mouse", "printer", "camera"};
    try{
        cout << getProductID(productIds, products, 5, "mouse") << endl;
        cout << getProductID(productIds, products, 5, "camera")
                << endl;
        cout << getProductID(productIds, products, 5, "laptop")
                << endl;
    }
    catch(ProductNotFound e){
        cout << e.getName() << " not found in the products.\n"
            <<  "Program aborted.\n";
        exit(1);
    }
    return 0;
}

int getProductID(int ids[], string names[],
    int numProducts, string target) throw(ProductNotFound){

    for (int i = 0; i < numProducts; ++i){
        if (names[i] == target)
            return ids[i];
    }
    throw ProductNotFound(target);
}