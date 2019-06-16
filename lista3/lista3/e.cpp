#include <bits/stdc++.h>

using namespace std;

void merge (vector<int> &all, int start, int middle, int end, long long int &count){
    int i, j, k;
    int n1 = middle - start + 1;
    int n2 = end - middle;

    vector<int> left(n1);
    vector<int> right(n2);

    for (i = 0; i < n1; i++){
        left[i] = all[start + i];
    }
    for (j = 0; j < n2; j++){
        right[j] = all[middle + j + 1];
    }
    k = start;

    i = j = 0;
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            all[k] = left[i];
            i++;
        }else{
            count += n1 - i;
            all[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        all[k] = left[i];
        i++; k++;
    }

    while (j < n2){
        all[k] = right[j];
        j++; k++;
    }

}

void mergeSort (vector<int> &all, int start, int end, long long int &count){
    if (start < end){
        int middle = (end + start)/2;

        mergeSort(all, start, middle, count);
        mergeSort(all, middle + 1, end, count);

        merge(all, start, middle, end, count);
    }
}

int main(){
    int n;
    cin >> n;

    while (n--){
        int size;
        cin >> size;

        vector<int> all(size);
        for (int i = 0; i < size; i++){
            cin >> all[i] ;
        }
        long long int count = 0;
        mergeSort(all, 0, size - 1, count);

        cout << count << endl;
    }
}