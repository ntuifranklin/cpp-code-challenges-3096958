// C++ Code Challenges, LinkedIn Learning

// Challenge #5: Factorial Sequence
// Write a recursive function to print a sequence of factorials from 0! to n!
// n is received as an argument.
// n = 4 : {1, 1, 2, 6, 24}
// Only calculate each element once.
// Print the sequence on the screen.

#include <iostream>

const int M = 5 ;
int counter = 1;
int current_array_size = counter * M;
int* arr = NULL ;

int next_index_to_compute ;
void initialize_factorial_array(){
 if (arr != NULL)
 return ;
 arr = static_cast<int*>(std::malloc(current_array_size * sizeof(int)));
 arr[0] = 1;
 arr[1] = 1 ;
 arr[2] = 2;
 next_index_to_compute = 3;
}

void expand_factorial_array(int hint){
    
    std::cout << "Expanding the size of the array:";
    while(current_array_size <= hint){
        counter++;
        current_array_size = counter * M;
    }
    int * new_arr = static_cast<int*>(std::malloc(current_array_size * sizeof(int)));
    int j;
    for(j=0; j < next_index_to_compute; j++){
        new_arr[j] = arr[j];
    } ;
    std::free(arr);
    arr = new_arr;
}
int factorial(int n){
    std::cout << "Receiving factorial(" << n << ")" << std::endl;
    if ( n < 0){
        return arr[0];
    }
    std::cout << "current_array_size" << current_array_size << std::endl ; 
    if (n < next_index_to_compute) {
        return arr[n];
    } 
    if ( n >= current_array_size ){
       expand_factorial_array(n);
    }
    for(int k = next_index_to_compute; k <= n ; k++){
        arr[k] = k * arr[k-1];
    }
    next_index_to_compute = n + 1;
    return arr[n];
}

// print_factorials()
// Summary: This function receives a (small) positive integer n and prints out a sequence from 0! through n!.
// Arguments:
//           n: The argument of the last factorial to print.
// Returns: n!, the last calculated factorial.
int print_factorials(int n){
    
    for(int j = 0 ; j <= n ; j++){
        std::cout << j << "!=" << factorial(j) << std::endl ;
    }

    return factorial(n);
}
void testFactorialThree(){
    int fThree = factorial(3);
    std::cout << "3! computes is " << (fThree == 6) << std::endl ;
}

void testFactorialFive(){
    int fFive = factorial(5);
    std::cout << "5! computes is " << (fFive == 120) << std::endl ;
}
// Main function
int main(){
    initialize_factorial_array();
    testFactorialThree();
    testFactorialFive();
    print_factorials(10);
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
