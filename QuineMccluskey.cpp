#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Term{
public:
    int one;
    bool used;
    string bit;
    vector<bool> factor;
    Term(){};
    Term(int n){
        one = 0;
        used = false;
        factor.resize(1 << n);
        bit.resize(n, ' ');
    }
    Term(int n, int k){
        one = 0;
        used = false;
        factor.resize(1 << n);
        factor[k] = true;
        // k to bit
        while(n--){
            int m = k % 2;
            if(m) one++;
            bit.push_back(m + '0');
            k /= 2;
        }
        reverse(bit.begin(), bit.end());
    }
    
    // if couldn't merge term.one is -1, else term.one is count of '1' 
    Term merge(Term &obj){
        Term term(bit.size());
        int count = 0;
        for(int i = 0; i < bit.size(); i++){
            if(bit[i] != obj.bit[i]){
                count++;
                term.bit[i] = '-';
            }
            else{
                term.bit[i] = bit[i];
                if(term.bit[i] == '1') term.one++;
            }
        }
        if(count > 1) term.one = -1;
        else{
            used = true;
            obj.used = true;
            for(int i = 0; i < factor.size(); i++)
                term.factor[i] = factor[i] | obj.factor[i];
        }
        return term;
    }
};

vector<vector<Term> > step(vector<vector<Term> > &currentTerms){
    vector<vector<Term> > nextTerms(currentTerms.size());
    set<string> check;
    for(int i = 1; i < currentTerms.size(); i++){
        for(Term& low : currentTerms[i - 1]){
            for(Term& high : currentTerms[i]){
                Term term = high.merge(low);
                if(term.one != -1 && check.find(term.bit) == check.end()){
                    nextTerms[term.one].push_back(term);
                    check.insert(term.bit);
                }
            }
        }
    }
    return nextTerms;
}

bool compare(const Term& t1, const Term& t2){
    for(int i = 0; i < t1.bit.size(); i++){
        if(t1.bit[i] == t2.bit[i]) continue;
        if(t1.bit[i] == '-') return false;
        if(t2.bit[i] == '-') return true;
        return t1.bit[i] < t2.bit[i];
    }
    return true;
}

vector<string> solution(vector<int> input) {
    int n = 1 << input[0];
    vector<string> answer;
    vector<int> count(n);
    vector<Term> pi, epi, nepi;
    vector<vector<Term> > currentTerms(input[0] + 1);
    
    for(int i = 2; i < input.size(); i++){
        Term term(input[0], input[i]);
        currentTerms[term.one].push_back(term);
    }
    
    int size;
    do{
        vector<vector<Term> > nextTerms = step(currentTerms);
        size = 0;
        for(int i = 0; i < currentTerms.size(); i++){
            size += nextTerms[i].size();
            for(Term term : currentTerms[i])
                if(!term.used){
                    for(int f = 0; f < n; f++)
                        count[f] += term.factor[f];
                    pi.push_back(term);
                }
        }
        currentTerms = nextTerms;
    }while(size);
    
    for(Term term : pi){
        bool used = false;
        for(int f = 0; f < n; f++)
            if(term.factor[f] * count[f] == 1){
                epi.push_back(term);
                used = true;
                break;
            }
        if(!used) nepi.push_back(term);
    }
    
    sort(epi.begin(), epi.end(), compare);
    answer.push_back("EPI");
    for(Term term : epi)
        answer.push_back(term.bit);
    sort(nepi.begin(), nepi.end(), compare);
    answer.push_back("NEPI");
    for(Term term : nepi)
        answer.push_back(term.bit);
    
    return answer;
}

int main(){
    vector<int> input = {3, 4, 0, 1, 2, 3};
    solution(input);
    return 0;
}