// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
//  Modify     [2024/9/2 Meng-Chen Wu]
// **************************************************************************

#include "sort_tool.h"
#include <utility>
#include <ctime>
#include <cstdlib>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
  const int length = data.size();
  for(int i = 0; i < length; i++){
    int index = i;
    while(index > 0 && data[index] < data[index - 1]){
      swap(data[index], data[index - 1]);
      index--;
    }
  }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data,int f){
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high, const int flag) {
  if(high == low) return;
  int p;
  if(flag == 0) p = Partition(data, low, high);
  else p = RandomizedPartition(data, low, high);
  QuickSortSubVector(data, low, p, flag);
  QuickSortSubVector(data, p + 1, high, flag);
}
int SortTool::RandomizedPartition(vector<int>& data, int low, int high){
  srand(time(nullptr));
  int tmp = rand() % (high - low + 1);
  swap(data[low + tmp], data[low]);
  int pivot = data[low];
  int l = low;
  int r = high;
  while(true){
    while(data[r] > pivot) r--;
    while(data[l] < pivot) l++;
    if(l >= r) return r;
    else{
      swap(data[l], data[r]);
      l++;
      r--;
    } 
  }
}
int SortTool::Partition(vector<int>& data, int low, int high) {
  // Hoare
  int pivot = data[low];
  int l = low;
  int r = high;
  while(true){
    while(data[r] > pivot) r--;
    while(data[l] < pivot) l++;
    if(l >= r) return r;
    else{
      swap(data[l], data[r]);
      l++;
      r--;
    } 
  }
  // Lomuto
  // int pivot = data[high];
  // int l = low - 1;
  // for(int i = low; i <= high - 1; i++){
  //   if(data[i] <= pivot){
  //     l++;
  //     swap(data[l], data[i]);
  //   }
  // }
  // swap(data[l + 1], data[high]);
  // if(l + 1 == high) return l;
  // return l + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
  if(low == high) return;
  int mid = (low + high) / 2;
  MergeSortSubVector(data, low, mid);
  MergeSortSubVector(data, mid + 1, high);
  Merge(data, low, mid, mid + 1, high);
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
  vector<int> tmp;
  int l = 0;
  int r = 0;
  while(tmp.size() < high - low + 1){
    if(l == middle2 - low){
      tmp.push_back(data[middle2 + r]);
      r++;
      continue;
    }
    if(r == high - middle2 + 1){
      tmp.push_back(data[low + l]);
      l++;
      continue;
    }
    if(data[low + l] <= data[middle2 + r]){
      tmp.push_back(data[low + l]);
      l++;
    }
    else{
      tmp.push_back(data[middle2 + r]);
      r++;
    }
  }
  for(int i = 0; i < high - low + 1; i++){
    data[i + low] = tmp[i];
  }


}

// bottom-up style implementation of merge sort
void SortTool::BottomUpMergeSort(vector<int>& data) 
{
  vector<int> end(data.size());
  for(int i = 0; i < data.size(); i++) end[i] = i + 1;
  while(end[0] != data.size()){
    int ind = 0;
    while(ind != data.size() && end[ind] != data.size()){
      Merge(data, ind, end[ind] - 1, end[ind], end[end[ind]] - 1);
      int tmp = end[end[ind]];
      end[ind] = tmp;
      ind = tmp;
    }
  }
}

// Heap sort method, be aware that you are NOT required to implement heap sort in PA1
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
}
