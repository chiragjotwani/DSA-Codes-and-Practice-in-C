// #include<stdio.h>
// int main(){
//     int n, arr[50];
//     printf("Enter the sixe of the array: ");
//     scanf("%d", &n);

//     printf("Enter the elements of the array: ");
//     for(int i = 0; i<n; i++){
//         scanf("%d", &arr[i]);
//     }

//     for(int i = n-1; i>=0; i--){
//         printf("%d\t", arr[i]);
//     }

//     return 0;
// }


#include<stdio.h>
int main(){
    int n, arr[50], temp;
    printf("Enter the sixe of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0, j = n-1; i<n/2; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i = 0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}