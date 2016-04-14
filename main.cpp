#include<iostream>
#include<string>
#include<list>
using namespace std;

typedef list<string> StringList;

list<StringList> permute(StringList&);
void print_list(StringList&);
int main() {
    
    StringList tracks;
    string track = "";
    
    while(getline(cin, track))
        tracks.push_back(track);

    list<StringList> res = permute(tracks);
    for(list<StringList>::iterator iter = res.begin(); iter != res.end(); iter++)
        print_list(*iter);
    
    return 0;
}

// Returns a list of lists
list<StringList> permute(StringList &tracks) {
    // DEBUG
    static int debug = false;
    if (debug) {
        static int running = 0;
        if(running == 0) {
            cout << "Still running..." << endl;
            running = 100000;
        } else {
            running--;
        }
    }
    // END DEBUG
    if (tracks.size() == 1)
        return list<StringList>(1,tracks);

    list<StringList> result;
    for (StringList::iterator i = tracks.begin(); i != tracks.end(); ) {
        string temp = (*i);
        
        // make a list without the current element
        StringList tmp(tracks.begin(), i++);
        tmp.insert(tmp.end(), i, tracks.end());
        
        // recurse to get all sub-permutations
        list<StringList> sub = permute(tmp);

        // amend sub-permutations by adding the element
        for (list<StringList>::iterator j = sub.begin(); j != sub.end(); j++)
            (*j).push_front(temp);

        result.insert(result.begin(), sub.begin(), sub.end());
    }
    return result;
}

void print_list(list<string> &tracks) {
    list<string>::iterator iter;
    static int perm = 1;
    cout << "\tVERSION " << perm << endl;
    cout << "=========================" << endl;
    cout << "Price" << endl << "Friends" << endl;
    for(iter = tracks.begin(); iter != tracks.end(); iter++)
        cout << *iter << endl;
    cout << "Montreal" << endl << "Broken" << endl;
    cout << "=========================" << endl;
    perm++;
}
