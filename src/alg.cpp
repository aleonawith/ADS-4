// Copyright 2021 NNTU-CS

void Sort(int* arr, int len) {
  int key = 0;
  int i = 0;
  for (int j = 1; j < len; j++) {
    key = arr[j];
    i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i = i - 1;
      arr[i + 1] = key;
    }
  }
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  Sort(arr, len);
  int count = 0, temp, left, right, middle;
  for (int i = 0; i < len - 1; i++) {
    left = i, right = len;
    while (left < right - 1) {
      middle = (left + right) / 2;
      if (arr[i] + arr[middle] == value) {
        count++;
        temp = middle + 1;
        while (arr[i] + arr[temp] == value && temp < right) {
          temp++; count++;
        }
        temp = middle - 1;
        while (arr[i] + arr[temp] == value && temp > left) {
          temp--; count++;
        }
        break;
      } else if (arr[i] + arr[middle] > value) {
        right = middle;
      } else {
        left = middle;
      }
    }
  }
  return count;
}
