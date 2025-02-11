#include <stdio.h>
int main(){
    int n,i,x;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int arr[n];
    printf("Enter elements of array:");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int a=arr[0], b=arr[n-1];
    

    while(a<=b){
        int mid=(a+b)/2;
        if (x==arr[mid]){
            printf("Found %d", mid);
            break;
        }
        else if(x<arr[mid]){
            b=mid-1;
        }
        else if(x>arr[mid]){
            a=mid+1;
        }
        else{
            printf("element not found");

        }

    }
    
}