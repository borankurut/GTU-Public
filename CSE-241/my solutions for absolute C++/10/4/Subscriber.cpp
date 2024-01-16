#include <iostream>
#include <string>

using namespace std;

class Subscriber{

public:
    Subscriber();
    Subscriber(string newName);
    Subscriber(string newName, int newNumChannels, string newChannelList[]);
    Subscriber(const Subscriber& subscriberObj);
    ~Subscriber();
    string& operator[](int index);
    Subscriber& operator=(const Subscriber& subscriberRight);
    friend ostream& operator<<(ostream& outputStrem, const Subscriber& subscriber);
    void resetChannels();

private:
    string name;            // name of the subscriber.
    int numChannels;        // total number of channels.
    string *channelList;    // dynamic string list.
};

int main(){
    string channels[3] = {"Nebuch", "Evrim Agaci", "C++"};
    Subscriber boran("Boran", 3, channels);
    Subscriber boranaOzeniyor("BoranaOzeniyorum");
    
    cout << (boranaOzeniyor = boran) << endl;
    cout << boran << endl;

    boranaOzeniyor[2] = "Artik ozenmiyorum";
    cout << boran << endl;
    cout << boranaOzeniyor << endl;

    return(0);
}

Subscriber::Subscriber(): name("Null"), numChannels(0), channelList(nullptr){/*empty*/}

Subscriber::Subscriber(string newName): name(newName), numChannels(0), channelList(nullptr){/*empty*/}

Subscriber::Subscriber(string newName, int newNumChannels, string newChannelList[]): 
name(newName), numChannels(newNumChannels){
    channelList = new string[numChannels];
    int ix;
    for(ix = 0; ix < numChannels; ++ix)
        channelList[ix] = newChannelList[ix];
}

Subscriber::Subscriber(const Subscriber& subscriberObj):
name(subscriberObj.name), numChannels(subscriberObj.numChannels){
    channelList = new string[numChannels];
    int ix;
    for(ix = 0; ix < numChannels; ++ix)
        channelList[ix] = subscriberObj.channelList[ix];
}

Subscriber::~Subscriber(){
    delete [] channelList;
}

string& Subscriber::operator[](int index){
    if(index < 0 || index >= numChannels){
        cerr << "Invalid index in Subscriber[]\n";
        exit(1);
    }
    return(channelList[index]);
}

Subscriber& Subscriber::operator=(const Subscriber& subscriberRight){ // copies the list not name.
    if(numChannels != subscriberRight.numChannels){
        resetChannels();
        numChannels = subscriberRight.numChannels;
        channelList = new string[numChannels];
    }
    int ix = numChannels;

    for(ix = 0; ix < numChannels; ++ix)
        channelList[ix] = subscriberRight.channelList[ix];

    return(*this);
}

ostream &operator<<(ostream &outputStrem, const Subscriber &subscriber){
    outputStrem << "Subscriber '" << subscriber.name << "' subscribed to following channels: \n";
    int ix;
    for(ix = 0; ix < subscriber.numChannels; ++ix)
        outputStrem << subscriber.channelList[ix] << endl;
    return(outputStrem);
}

void Subscriber::resetChannels(){
    delete [] channelList;
    channelList = nullptr;
    numChannels = 0;
}