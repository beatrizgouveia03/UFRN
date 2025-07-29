#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

	int n; //qtd de nós
	int qtdArestas; //qtd de arestas

	cin >> n;
	cin >> qtdArestas;

	vector<vector<int>> m(n,vector<int>(n, 0));

	//leitura das arestas
	for(int i = 0; i < qtdArestas; i++) {
		int a, b;
		cin >> a >> b;
		m[a][b] = m[b][a] = 1;
	}

	//escrever na tela a matriz de adjacência
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	stack<int> pilha;
	vector<bool> visitado(n, false);
	vector<int> dist(n);
	pilha.push(0);
	visitado[0] = true;
	cout << "Colocando 0 na pilha" << endl;
	for(int i = 0; i < n; i++) {
		cout << visitado[i];
	}
	cout << endl;

	while(!pilha.empty()) {
		int k = pilha.top();
		pilha.pop();
		for(int i = 0; i < n; i++) {
			if(m[k][i] == 1 && !visitado[i]) {
				visitado[i] = true;
				pilha.push(i);
				cout << "Colocando " << i << " na pilha" << endl;
				for(int i = 0; i < n; i++) {
					cout << visitado[i];
				}
				cout << endl;
			}
		}
	}



	return 0;

}