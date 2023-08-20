    vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int i=a.size()-1, max=INT_MIN;
    vector <int> a1;
    while(i>=0){
        if(a[i]>max) {
            a1.push_back(a[i]);
            max=a[i];
        }
        i--;
    }
    return a1;
}