#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main() {
	int M, N;
	std::vector<int> m, n;

	std::cin >> N >> M;


	do{
		int quant = 0, entrada;

		for( int i=0; i<N; ++i) {
			std::cin >> entrada;

			n.push_back(entrada);
		}

		for(int i=0; i<M; ++i) {
			std::cin >> entrada;
			m.push_back(entrada);
		}

		std::sort(n.begin(), n.end());
		std::sort(m.begin(), m.end());

		for(int i=0; i<N; ++i) {
			int inicio = 0;
			int fim = M;
			while(inicio<=fim){
    			auto index = (inicio+fim)/2;

			    if(m[index] == n[i]) { quant++; break;}
			    else if(m[index] < n[i]) { inicio = index+1;}
			    else { fim = index-1;}
  			}
		}

		std::cout << quant << std::endl;
		std::cin >> N >> M;

	} while(M != 0 && N != 0);

	return 0;
}