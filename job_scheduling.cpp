#include<bits/stdc++.h>
using namespace std;


int limit = 0, profit = 0;;  

class job {    
    public : 
        char id;
        int p;
        int d; 
        job() {
            id ='-';
            p = 0;
            d = 0;
        }
};

bool compare(job a, job b) {    return (a.p > b.p); }

priority_queue<job, vector<job>, compare> pq;

void scedule(int n)
{
    vector<job> res(n);
    
    while(!pq.empty()) {
        job t = pq.top();
        pq.pop();
        for(int i = min(n, t.d); i >= 0; i--) {
            if (res[i-1].id == '-') {
                res[i-1] = t;
                profit += t.p;
                break;
            }
        }
    }
    // cout << "\n ---- The Sequence in which the Jobs are completed ----\n";
    for(int i = 0; i < n; i++) {
        cout << endl << res[i].id << " " << res[i].p <<  " " << res[i].d;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    // cout << "\n > Enter the number of Jobs : \t";
    cin >> n;

    // job ar[n];

    // cout << "\n > Enter the Job id, Profit and Deadline for all jobs (id p d) : \n";
    for (int i = 0; i < n; i++) {
        job ar;
        cin >> ar.id >> ar.p >> ar.d;
        pq.push(ar);
        
        limit = max(ar.p, limit);
        // cin >> ar[i].id >> ar[i].p >> ar[i].d;
    }
    scedule(n);
    
}

/*
INPUT

5
j1 20 2
j2 15 2
j3 10 1
j4 5 3
j5 1 3


OUTPUT



*/