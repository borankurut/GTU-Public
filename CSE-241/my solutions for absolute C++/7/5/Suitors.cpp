#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> suitors;

    int n,
        pos = 0;

    cout << "enter N\n>";
    cin >> n;

    for (int i = 0; i < n; i++){
        suitors.push_back(i + 1);
    }

    while(suitors.size() != 1){
        pos += 2; 
        pos = pos % suitors.size();

        for(int i = 0; i < suitors.size(); ++i)
            cout << suitors[i]; 

        cout << "  ";

        cout << "suitor " << suitors[pos]<< " elminated. " << endl;

        suitors.erase(suitors.begin() + pos);
    }

    cout << suitors[0] << " is the lucky number.";
}