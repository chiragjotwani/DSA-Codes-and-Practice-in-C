#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for (int i=0; i<n; i++){
        if(a[i]==k){
            printf("yes");
            break;

        }
        else{
            printf("No");
        }
    }

}
        
    

