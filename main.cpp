#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

/*
 *This program reads strings from a text file, and utilizes the Quick sorting method to
 *alphabetize the input
 *
 *Data Structures @ TCC
 *
 *Arick Mounts
 */
#define SIZE 11
using namespace std;


void quick_sort(string arry[], int start, int end);
void swap(string arry[], int a, int b);
void fill_array(string arry[], int size);
int partiton(string arry[], int start, int end);

int main() {
  string mainArr[SIZE];
  fill_array(mainArr, SIZE);
  
  quick_sort(mainArr, 0,  SIZE);
  
  for (int i = 1; i < SIZE+1 ; i++){
    cout << mainArr[i] << endl;
  }
}

void fill_array(string arry[], int size){
  
  ifstream filein;
  filein.open("Input.txt");
  for (int i = 0; i <= SIZE; i++){
    getline(filein, arry[i]);
  }
  filein.close();

}

void swap(string arry[], int a, int b){
  string temp = arry[ a ];
	arry[ a ] = arry[ b ];
	arry[ b ] = temp;
}

void quick_sort(string arry[], int start, int end){
  int part = 0;

  if (start < end){
    part = partiton(arry, start, end);
    quick_sort(arry, start, part - 1);
    quick_sort(arry,  part + 1, end);
  }
}

int partiton(string arry[], int start, int end){
  string pivot_value = arry[end];
  int pivot_index = end;

  int i = start -1;

  int temp = 0;
  for(temp = start; temp < end; temp++){
    if(arry[temp] <= pivot_value){
      i++;
      pivot_index = i+1;
      swap(arry, i, temp);
    }
  }
  swap(arry, i+1, end);
  pivot_index = i+1;
  return i+1;
}