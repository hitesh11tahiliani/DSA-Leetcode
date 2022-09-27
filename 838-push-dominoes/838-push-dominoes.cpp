class Solution {
public:
    string pushDominoes(string s) {
    
    int n = s.size();
    int r=-1;
    
    for(int i=0;i<n;i++){
        
        if(s[i]=='L'){                                 
            if(r==-1){                                  //s[i]=='L' && r==-1
                for(int j=i-1;j>=0 && s[j]=='.';j--){   //update all dominoes to left beginning from j=i-1 to j>=0
                    s[j]='L';
                }
            }
            else{                                      //s[i]=='L' && r!=-1
                for(int j=r+1,k=i-1;j<k;j++,k--){      //update all dominoes lying between k=r+1 and j=i-1
                    s[j]='R';
                    s[k]='L';
                }
                r=-1;                                  //important step update r = -1
            }
        }
        else if(s[i]=='R'){                            //s[i]=='R' && r!=-1
            if(r!=-1){                                 //update all dominoes lying right to j=r+1 till i
                for(int j=r+1;j<i;j++){
                    s[j]='R';
                }
            }
            r=i;                                       //update r since r is found
        }
    }
    
    if(r!=-1){                                       //if you have traversed complete string and r!=-1,then update all dominoes
        for(int j=r+1;j<n;j++) {                     //beginning from r+1 to n to 'R'
            s[j]='R';
        }
    }
    
    return s;   
}
};