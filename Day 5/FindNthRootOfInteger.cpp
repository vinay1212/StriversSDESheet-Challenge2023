int NthRoot(int n, int m) {
  // Write your code here.

  int r = m/n;
  int l = 1;
  while(l <= r){
    
    int mid = l + (r-l)/2;
    int i = 0;
    long long temp = 1;
    
    while(i < n){
      temp = temp*mid;
      if(temp > m){
        break;
      }
      i++;
    }
    // cout<<l<<" "<<r<<" "<<mid<<" "<<temp<<endl;
    if(temp == m){
      return mid;
    }
    else if(temp >  m){
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  return -1;
}
