//shellsort: sort v[0] ... v[n-1] into increasing order
void shellsort(int v[], int n){
    int gap, i, j, temp;

    for(gap = n / 2; gap > 0; gap /= 2){
        for(i = 0; i < n; i++){
            for(j = i - gap; i < n; i++){
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;  
            }
        }
    }
}
