


#include "team1.h"
#include "team2.h"
#include "team3.h"
#include "team4.h"
#include "team5.h"
#include "team6.h"
#include "team7.h"
#include "team8.h"
#include "team9.h"
#include "team10.h"


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define N 10
#define TR 1000
#define TFLIP 10
#define TBATTLE 100

int whenflipA[TR], whenflipB[TR];

void detwhenflip(int when[], int num) {
	int i, w;
	for(i=0; i<TR; i++) when[i] = 0;
	for(i=0; i<num;) {
		w = rand() % TR;
		if(!when[w]) {
			when[w] = 1;
			i++;
		} 
	}
}

void clear(int x[]) {
	int i;
	for(i=0; i<TR; i++) x[i] = -1;
}

// allocate players.. dirty. could you suggest a better way?
strategy *players[N][N+1];
void newplayers() {
	int i;
	// N+1th player is opponent for self-battle
	for(i=0;i<=N;i++)players[0][i] = new team1;
	for(i=0;i<=N;i++)players[1][i] = new team2;
	for(i=0;i<=N;i++)players[2][i] = new team3;
	for(i=0;i<=N;i++)players[3][i] = new team4;
	for(i=0;i<=N;i++)players[4][i] = new team5;
	for(i=0;i<=N;i++)players[5][i] = new team6;
	for(i=0;i<=N;i++)players[6][i] = new team7;
	for(i=0;i<=N;i++)players[7][i] = new team8;
	for(i=0;i<=N;i++)players[8][i] = new team9;
	for(i=0;i<=N;i++)players[9][i] = new team10;
}
void deleteplayers() {
	for(int i=0; i<N; i++)
		for(int j=0; j<=N; j++)
			delete players[i][j];
}
char names[N][100] = {"team1", "team2", "team3", "team4", "team5", "team6", "team7", "team8", "team9", "team10"};
int score[N], total_score[N] = {0}, rank[N] = {0}, index[N];
int matchinfo[TBATTLE][N][N];

double avg_score[N] = {0};

// for report
char ch_res[101], ch_scA[101], ch_selA[101], ch_flipA[101], ch_flipB[101], ch_selB[101], ch_scB[101];

// for args
int g_selA[TR], g_selB[TR], g_finA[TR], g_finB[TR],
	g_flipA[TR], g_flipB[TR], g_resA[TR], g_resB[TR];

int main() {
	
	srand(GetTickCount());

	// locals
	FILE *gout, *out;
	int h, i, j, round, g, mcnt, battle;
	int tscA, tscB, selA, selB, finA, finB, scA, scB, maxsc;
	strategy *playerA, *playerB;
	char filename[10];
	
	
	gout = fopen("report.txt", "w");
	
	// a battle start!
	
	
	
	for(h=0;h<TBATTLE; h++) {
		
		sprintf(filename, "report%d.txt", h+1);
		out = fopen(filename, "w");
	
		for(i=0;i<N;i++) score[i] = 0;
	
		newplayers();
		mcnt = 0;
		
		for(i = 0; i < N; i++) {
			for(j = 0; j <= i; j++) {
				fprintf(out, "[Match #%d] %s vs %s\n", ++mcnt, names[i], names[j]);
				// pick players
				if(i == j) {
					playerA = players[i][i];
					playerB = players[i][N];
				} else {
					playerA = players[i][j];
					playerB = players[j][i];
				}
				// prepare match
				detwhenflip(whenflipA, TFLIP);
				detwhenflip(whenflipB, TFLIP);
				clear(g_selA); clear(g_selB);
				clear(g_flipA); clear(g_flipB);
				clear(g_resA); clear(g_resB);
				tscA = 0, tscB = 0;
				for(round=0; round<TR; round++) {
					g = round % 100;
					// run a round 
					selA = playerA->decision(g_selA, g_finB, g_flipA, g_resA, round);
					selB = playerB->decision(g_selB, g_finA, g_flipB, g_resB, round);
					// random selection
					if(selA != 0 && selA != 1) selA = rand() % 2;
					if(selB != 0 && selB != 1) selB = rand() % 2;
					g_selA[round] = selA, g_selB[round] = selB;
					// flipping
					g_flipA[round] = whenflipA[round], g_flipB[round] = whenflipB[round];
					finA = selA, finB = selB;
					if(g_flipA[round]) finA = !finA;
					if(g_flipB[round]) finB = !finB;
					g_finA[round] = finA, g_finB[round] = finB;
					// calculate score
					if(!selA && !selB) scA = 2, scB = 2;
					else if(!selA && selB) scA = -1, scB = 4;
					else if(selA && !selB) scA = 4, scB = -1;
					else scA = 0, scB = 0;
					g_resA[round] = scA, g_resB[round] = scB;
					tscA += scA, tscB += scB;
					// for report
					ch_scA[g] = (scA < 0 ? '-' : scA + '0');
					ch_scB[g] = (scB < 0 ? '-' : scB + '0');
					ch_flipA[g] = g_flipA[round] ? '@' : ' ';
					ch_flipB[g] = g_flipB[round] ? '@' : ' ';
					ch_selA[g] = selA + '0';
					ch_selB[g] = selB + '0';
					ch_res[g] = selA ? (selB ? ' ' : 'v') : (selB ? '^' : '-');
					// report line
					if(g == 99) {
						fprintf(out, "Round %d..%d\n", round-99, round);
						fprintf(out, "====================================================");
						fprintf(out, "====================================================\n");
						fprintf(out, "%s %d\n%s\n%s\n%s\n%s\n%s\n%s %d\n",
						ch_scA, tscA, ch_selA, ch_flipA, ch_res,
						ch_flipB, ch_selB, ch_scB, tscB);
						fprintf(out, "====================================================");
						fprintf(out, "====================================================\n");
					}
				}
				if(i == j) {
					maxsc = tscA > tscB ? tscA : tscB;
					score[i] += maxsc;
				} else {
					score[i] += tscA;
					score[j] += tscB;
				}
			}
		}
		
		deleteplayers();
		
		fprintf(out, "<Total Result>\n");
		for(i=0; i<N; i++)
			fprintf(out, "%s : %d\n", names[i], score[i]);
		
		// a battle ends
		for(i=0; i<N; i++) total_score[i] += score[i];
		
		fclose(out);
		printf("battle %d finished\n", h+1);
		
		if(i == j) {
			matchinfo[h][i][i] = score[i];
			matchinfo[h][i][N] = score[j];
		}
		matchinfo[h][i][j] = score[i];
		matchinfo[h][i][j] = score[i];
	}
	
	for(i=0; i<N; i++) avg_score[i] = (double)total_score[i] / TBATTLE;
	
	
	// get rank
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(avg_score[i] <= avg_score[j]) rank[i]++;

	// assume there's no tie score
	for(i = 0; i < N; i++)
		index[rank[i] - 1] = i;

	fprintf(gout, "\n[unsorted rank]\n");
	for(i = 0; i < N; i++)
		fprintf(gout, "#%d %s : %.2lf\n", rank[i], names[i], avg_score[i]); 
	fprintf(gout, "\n[sorted rank]\n");
	for(i = 0; i < N; i++)
		fprintf(gout, "#%d %s : %.2lf\n", i+1, names[index[i]], avg_score[index[i]]); 
		
	fclose(gout);

}

