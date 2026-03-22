#include <stdio.h>
int main() 
{
    int n, c, b;
    int a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);         
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);  
    
    printf("Enter position and value to insert: ");
    scanf("%d", &c);        
    printf("Enter value to insert: ");
    scanf("%d", &b);          
    for(int i=n; i>=c; i--)
        a[i] = a[i-1];      

    a[c-1]=b;          

    for(int i=0; i<=n; i++)
        printf("%d ", a[i]);  

    return 0;
}


