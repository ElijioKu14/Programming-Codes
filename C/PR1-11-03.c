void sort(int array[], int n)
{
  int i = 0;
  int j = 0;
  for(i = 0; i < n; ++i){
    for(j = i +1; j< n; ++j){
      if(array[i] > array[j]){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
  }
}
  }
}