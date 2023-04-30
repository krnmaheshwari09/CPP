//1.Triangular pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1,n;
//     cout<<"Enter a number:";
//     cin>>n;
//     while(i<=n){
//         int j=1;
//         while(j<=i){
//             cout<<j<<" ";
//             j++;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//Reverse triangular pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1;
//     while(i<=5){
//         int j=i;
//         while(j>0){
//             cout<<j<<" ";
//             j--;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//Alphabetic Pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1;
//     char ch = 'A';
//     while(i<=4){
//         int j=1;
//         while(j<=4){
//             cout<<ch<<" ";
//             j++;
//         }
//         cout<<"\n";
//         ch++;
//         i++;
//     }
// }


//Triangular alphabetic pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1;
//     while(i<=4){
//         int j=1;
//         char ch = 'A';
//         while(j<=i){
//             cout<<ch<<" ";
//             j++;
//             ch++;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//Flipped triangular pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1,n=4;
//     while(i<=n){
//         int j=1;
//         while(j<=(n-i)){
//             cout<<" ";
//             j++;
//         }
//         while(j<=n){
//             cout<<"*";
//             j++;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//Inverted flipped triangular pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1,n=4;
//     while(i<=n){
//         int j=1;
//         while(j<i){
//             cout<<" ";
//             j++;
//         }
//         while(j<=n){
//             cout<<"*";
//             j++;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//pyramidal numerical pattern:

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i=1,n=4;
//     while(i<=n){
//         int j=1;
//         while(j<=(n-i)){
//             cout<<" "<<" ";
//             j++;
//         }
//         int k=1;
//         while(j<=n){
//             cout<<k<<" ";
//             k++;
//             j++;
//         }
//         int l = i-1;
//         while(l>0){
//             cout<<l<<" ";
//             l--;
//         }
//         cout<<"\n";
//         i++;
//     }
// }


//Numerical pattern with pyramid of stars in middle:

#include<iostream>
using namespace std;
int main()
{
    int i=1,n=4;
    while(i<=n){
        int j=1;
        while(j<=(n-i+1)){
            cout<<j<<" ";
            j++;
        }
        int k=1;
        while(k<=(2*(i-1))){
            cout<<"* ";
            k++;
        }
        int l=n-i+1;
        while(l>0){
            cout<<l<<" ";
            l--;
        }
        cout<<"\n";
        i++;
    }
}