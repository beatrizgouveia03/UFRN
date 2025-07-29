#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main() {
	int A, B, entry;
	bool search, found = false;

	std::vector<int> a, b;

	std::cin >> A;

	for(int i=0; i<A; ++i) {
		std::cin >> entry;
		a.push_back(entry); 
	}

	std::cin >> B;

	for( int i=0; i<B; ++i){
		std::cin >> entry;
		b.push_back(entry);
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	for(int i=0; i<A; ++i){
		for(int j=0; j<B; ++j){
			int value = a[i]+b[j];
			search = false;

			for(int k=0; k<A; ++k){
				if(value == a[k]){ search = true; break;} 
				if(value < a[k]){ break;}
			}

			if(search){ continue;}

			for(int k=0; k<B; ++k){
				if(value == b[k]){  search = true; break;}
				if(value < b[k]){ break;}
			}

			if(search ){ continue;}

			std::cout << a[i] << " " << b[j] << std::endl;
			found = true;
			break;
		}
		if(found){ break;}
	}

	return 0;
}