#include <bits/stdc++.h>
#include "colourblind.h"

static int H, W, Q, S;
static long long quer;
static std::vector<std::vector<long long> > rR, rG, rB;

int main(){
	std::cin >> H >> W >> Q >> S;
	rR.resize(H);
	rG.resize(H);
	rB.resize(H);
	for (int i = 0; i < H; ++i){
		rR[i].resize(W);
		for (int j = 0; j < W; ++j){
			std::cin >> rR[i][j];
		}
	}
	for (int i = 0; i < H; ++i){
		rG[i].resize(W);
		for (int j = 0; j < W; ++j){
			std::cin >> rG[i][j];
		}
	}
	for (int i = 0; i < H; ++i){
		rB[i].resize(W);
		for (int j = 0; j < W; ++j){
			std::cin >> rB[i][j];
		}
	}
	init(H,W,Q,S,rR,rG,rB);
	for (int i = 0; i < Q; ++i){
		std::cin >> quer;
		if (query(quer)) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}