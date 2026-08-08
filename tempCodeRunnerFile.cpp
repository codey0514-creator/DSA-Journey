set <int> dfsvisited ; // All nodes visited while we are doing DFS.......
    dfsvisited.insert(1);
    stack <int> stac ;
    vector<int> nextIndex(n + 1, 0);
    vector <int> dtraverse ;
    dtraverse.push_back(1);
    stac.push(1);
    while(!stac.empty()){
        cout << stac.top()<<" ";
        int i = nextIndex[stac.top()] ;
        vector <int> j = adjclist[stac.top()]; 
        while (i < j.size() && dfsvisited.find(j[i]) != dfsvisited.end()) i ++; //Here we are repaeatdly looking for whole list recursively
        if (i == j.size()) stac.pop();
        else{
            dfsvisited.insert(j[i]);
            stac.push(j[i]);
            dtraverse.push_back(j[i]);
        }
        }