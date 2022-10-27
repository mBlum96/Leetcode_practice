
int partition(int* arr, int l, int r){
    int temp;
    while(r>l){
        if(arr[l]>arr[l+1]){
            temp = arr[l+1];
            arr[l+1] = arr[l];
            arr[l] = temp;
            l++;
        }
        else if(arr[r]>=arr[l]){
            r--;
        }else{
            temp= arr[l+1];
            arr[l+1] = arr[r];
            arr[r] = temp;
        }
    }
    return l;
}

int findKthLargest(int* nums, int numsSize, int k){
    int p = partition(nums,0,numsSize-1);
    while(p!=numsSize-k){
        if(p>numsSize-k){
            p = partition(nums,0,p-1);
        }else{
            p = partition(nums,p+1,numsSize-1);
        }
    }
    return nums[p];
}

int partition(int* arr, int l, int r){
    int temp;
    if(r>l){
        int j = rand()%(r-l)+l;
        temp = arr[j];
        arr[j] = arr[l];
        arr[l] = temp;
    }
    while(r>l){
        if(arr[l]>arr[l+1]){
            temp = arr[l+1];
            arr[l+1] = arr[l];
            arr[l] = temp;
            l++;
        }
        else if(arr[r]>=arr[l]){
            r--;
        }else{
            temp= arr[l+1];
            arr[l+1] = arr[r];
            arr[r] = temp;
        }
    }
    return l;
}

int findKthLargest(int* nums, int numsSize, int k){
    int p = partition(nums,0,numsSize-1);
    while(p!=numsSize-k){
        if(p>numsSize-k){
            p = partition(nums,0,p-1);
        }else{
            p = partition(nums,p+1,numsSize-1);
        }
    }
    return nums[p];
}