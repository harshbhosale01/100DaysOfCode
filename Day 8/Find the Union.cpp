vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int i = 0, j = 0; // pointers
    int n=a.size().m=b.size();
  vector < int > Union;
  while (i < n && j < m) {
    if (a[i] <= b[j]) 
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(a[i]);
      i++;
    } else 
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(b[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
  return Union;
}