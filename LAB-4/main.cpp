#include "DLList.h"
#include <iostream>
#include <string>
using namespace std;

class Voter {
public:
    string name;
    int age;
    string cnic;
    int voteCount;
    Voter(string n, int a, string c, int vc) 
     : name(n), cnic(c), voteCount(vc) { 
        if(a <= 18) { 
            age = a;
            cout << "candidate "<< name << " is underage. " << endl;
        }
        else age = -1; 
    }
     friend ostream& operator<<(ostream& os, const Voter& voter);
};

ostream& operator<<(ostream& os, const Voter& voter) {
    os << endl << "Name: " << voter.name
    << ", Age: " << voter.age
    << ", CNIC: " << voter.cnic
    << ", Voter Count: " << voter.voteCount << endl;
    return os;
}

int main() {
    DLList<Voter> Voters;
    Voters.push_back(Voter("Suleman Arshad", 37, "35202524555", 120));
    Voters.push_back(Voter("Abdullah Khalid", 43, "45222522724", 20));
    Voters.push_back(Voter("Tayyab Ibrar", 83, "31232524724", 166));
    Voters.push_back(Voter("Ali Jawad", 35, "35277774724", 50));
    Voters.push_back(Voter("Furqan Hassan", 31, "35202934724", 124));
    Voters.push_back(Voter("Mr.Underage", 13, "97123215624", 10)); //underage

    cout << "The list before finalizing Candidates" << endl;
    Voters.printList();

    cout << "Removing Mr.Underage because he is below the legal age to vote (ineligible)" << endl;
    Voters.Delete(Voters.SearchbyCNIC("97123215624"));
    cout << "Removing Tayyab because he passed away (ineligible)" << endl;
    Voters.Delete(Voters.SearchbyCNIC("31232524724"));

    cout << "List after Deleting ineligible Candidates" << endl;
    Voters.printList();

    cout << "the winner of the Election is " << Voters.getMaxVotes()->getData().name << " with " 
        << Voters.getMaxVotes()->getData().voteCount << " votes " << endl;

    return 0;
}



