#include <stdio.h>
#include <iostream>
#include <vector>

std::vector<int> sub_sort(std::vector<int> &v);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	std::vector<int> v = {1,2,4,7,10,11,7,12,6,7,16,18,19};
	std::vector<int> a = sub_sort(v);
	std::cout << a[0] << " ";
	std::cout << a[1];

	return 0;
}

std::vector<int> sub_sort(std::vector<int> &v){

	std::vector<int> idx = {-1,-1};//idx[0] is thw low index and idx[1] is the high index

	//find initial indices
	for(int i = 1;i < v.size();i++){

		if(v[i-1] > v[i]){
			if(idx[0] == -1){
				idx[0] = i;
			}
			else{
				idx[1] = i;
			}
		}
	}

	//if there is no initials,the vector is sorted
	if(idx[0] == -1 && idx[1] == -1){
		return idx;
	}
	//if there is only one idx,i can just get i and i-1 as bounds
	if(idx[0] != 1 && idx[1] == -1){
		idx[1] = idx[idx[0]-1];
		return idx;
	}

	//find interval of values that will be moved if the array is sorted
	int interval[] = {v[idx[0]],v[idx[1]]};
	for(int i = idx[0];i <= idx[1];i++){
		if(v[i] > interval[1]){
			interval[1] = v[i];
		}
		if(v[i] < interval[0]){
			interval[0] = v[i];
		}
	}

	//find the final bounds

	//low bound
	for(int i = idx[0];i >= 0;i--){

		if(v[i] >= interval[0] && v[i] <= interval[1]){
			idx[0] = i;
		}

	}

	//high bound
	for(int i = idx[1];i < v.size();i++){

		if(v[i] >= interval[0] && v[i] <= interval[1]){
			idx[1] = i;
		}

	}

	return idx;

}
