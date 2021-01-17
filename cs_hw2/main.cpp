/* Ammaar Iftikhar
   21901257
   Section 1*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

// PROTOTYPE
void algorithm1( const int* arr1, const int* arr2, int** arr3,
                  const int& N, int& newN);
void algorithm2( const int* arr1, const int* arr2, int** arr3,
                  const int& N, int& newN);
void displayArray( const int* const , const int&);

int main(){
   // INITIALISATION & DECLARATION
   int sizes[] = { 5, 10, 25, 50};
   int arrSize = 4;
   int *arr1, *arr2, *arr3;

   for( int i = 0; i < arrSize; i++) {
      cout<< "\n\nARRAY OF SIZE "<< sizes[i]<< endl;
      int ns;
      arr1 = new int[sizes[i]];
      arr2 = new int[sizes[i]];

      // when the elements in arr1 are smaller than those in arr2
      // ALGORITHM 1
      for( int j = 0; j < sizes[i]; j++){
         arr1[j] = rand() % 1000 + 1;
         arr2[j] = rand() % 1000 + 1000;
      }
      sort( arr1, arr1 + sizes[i]);
      sort( arr2, arr2 + sizes[i]);

      cout<< "\nPart I: All elements in array 1 < elements in array 2 "
          << "using algorithm 1."<< endl;
      algorithm1( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      cout<< "Part I: All elements in array 1 < elements in array 2 "
          << "using algorithm 2."<< endl;

      // USING ALGORITHM 2
      algorithm2( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      // when the elements in arr1 are larger than those in arr2
      // ALGORITHM 1
      for( int j = 0; j < sizes[i]; j++){
         arr1[j] = rand() % 1000 + 1000;
         arr2[j] = rand() % 1000;
      }
      sort( arr1, arr1 + sizes[i]);
      sort( arr2, arr2 + sizes[i]);

      cout<< "\nPart II: All elements in array 1 > elements in array 2 "
          << "using algorithm 1."<< endl;
      algorithm1( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      cout<< "Part II: All elements in array 1 > elements in array 2 "
          << "using algorithm 2."<< endl;

      // USING ALGORITHM 2
      algorithm2( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      // when the elements in arr1 are larger than those in arr2
      // ALGORITHM 1
      for( int j = 0; j < sizes[i]; j++){
         arr1[j] = rand() % 1000;
         arr2[j] = rand() % 1000;
      }
      sort( arr1, arr1 + sizes[i]);
      sort( arr2, arr2 + sizes[i]);

      cout<< "\nPart III: ELEMENTS HAVE A NATURAL ORDER "
          << "using algorithm 1."<< endl;
      algorithm1( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      cout<< "Part III: ELEMENTS HAVE A NATURAL ORDER "
          << "using algorithm 2."<< endl;

      // USING ALGORITHM 2
      algorithm2( arr1, arr2, &arr3, sizes[i], ns);
      displayArray( arr3, ns);
      delete [] arr3;
      arr3 = NULL;

      delete [] arr1;
      delete [] arr2;
   }
   cout<< endl;
   return 0;
}

// This is the first algorithm
void algorithm1( const int* arr1, const int* arr2, int** arr3,
                  const int& N, int& newN){

   // VARIABLE DECLARATION AND INITIALISATION
   newN = 2 * N;
   (*arr3) = new int[newN]{};
   int ind = 0, currSize = N;

   // copy the elements from the first array into the 3rd array
   for( int i = 0; i < N; i++){
      (*arr3)[i] = arr1[i];                               // O(N)
   }

   // for every element of the 2nd array find the right position
   // if all the elements of 1st have been placed
   // place elements of 2nd
   // O(N ^ 2)
   for( int i = 0; i < N; i++){
      while( (*arr3)[ind] < arr2[i] && ind < currSize) ind++;

      // move elements of arr 3
      for( int j = currSize; j > ind; j--)
         (*arr3)[j] = (*arr3)[j - 1];

      (*arr3)[ind++] = arr2[i];
      currSize++;
   }
}

void algorithm2( const int* arr1, const int* arr2, int** arr3,
                 const int& N, int& newN){
   // VARIABLE DECLARATION AND INITIALISATION
   newN = 2 * N;
   (*arr3) = new int[newN]{};

   int curSize =0, ind = 0, ind2 = 0;

   // O(N)  loop
   while( curSize < newN){
      if( arr2[ind] < arr1[ind2] && ind < N)       (*arr3)[curSize++] = arr2[ind++];
      else if( arr2[ind] > arr1[ind2] && ind2 < N) (*arr3)[curSize++] = arr1[ind2++];
      else if( ind < N)                            (*arr3)[curSize++] = arr2[ind++];
      else                                         (*arr3)[curSize++] = arr1[ind2++];
   }
}

void displayArray( const int* const arr, const int& ns){
   for( int i = 0; i < ns; i++){
      if ( i == 0) cout<< "{ ";
      cout<< arr[i];
      if( i != (ns - 1)) cout<< ", ";
      if( i == (ns - 1)) cout<< "}"<< endl;
   }
}

