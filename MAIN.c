#include <stdio.h>    
#include <ctype.h>   
#include <string.h>   


double subtotal_bill(int meals, int drinks) { return (meals * 4.50) + (drinks * 1.75); } 
double final_bill(double subtotal, int member) { return (member == 1) ? subtotal * 0.90 : subtotal; } 

int max_orders(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i]; 
    return max; 
}

int count_at_least(int a[], int n, int target) {
    int count = 0; 
    for (int i = 0; i < n; i++) if (a[i] >= target) count++;
    return count; 
}

int count_vowels(char s[]) {
    int count = 0; 
    for (int i = 0; s[i] != '\0'; i++) { 
        char c = tolower(s[i]); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++; 
    }
    return count; 
}

int count_underscore(char s[]) { 
    int count = 0; 
    for (int i = 0; s[i] != '\0'; i++) if (s[i] == '_') count++; 
    return count;
}

void normalize_item(char in[], char out[]) { 
    for (int i = 0; in[i] != '\0'; i++) { 
        if (in[i] == '_') out[i] = ' '; 
        else out[i] = toupper(in[i]); 
    }
    out[strlen(in)] = '\0'; 
}

void row_col_max(int R, int C, int grid[][100]) { 
    printf("ROWMAX"); for (int i = 0; i < R; i++) { int m = grid[i][0]; for (int j = 1; j < C; j++) if (grid[i][j] > m) m = grid[i][j]; printf(" %d", m); } 
    printf("\nCOLMAX"); for (int j = 0; j < C; j++) { int m = grid[0][j]; for (int i = 1; i < R; i++) if (grid[i][j] > m) m = grid[i][j]; printf(" %d", m); } 
    int z = 0; for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (grid[i][j] == 0) z++; printf("\nZERO=%d\n", z); 
}

int main() { // 33
    int act; scanf("%d", &act);
    if (act == 1) {
        int m, d, mem; scanf("%d %d %d", &m, &d, &mem); 
        if (m<0 || m>100 || d<0 || d>100 || (m==0 && d==0) || (mem!=0 && mem!=1)) printf("invalid input\n"); 
        else { double s = subtotal_bill(m, d); printf("SUBTOTAL=%.2f TOTAL=%.2f\n", s, final_bill(s, mem)); }
    } else if (act == 2) { 
        int n, t, a[1000]; scanf("%d", &n); if (n<1 || n>1000) { printf("invalid input\n"); return 0; }
        for (int i=0; i<n; i++) scanf("%d", &a[i]); scanf("%d", &t); 
        printf("MAX=%d HIT=%d\n", max_orders(a, n), count_at_least(a, n, t));
    } else if (act == 3) { 
        char s[201], o[201]; scanf("%s", s); printf("V=%d U=%d\n", count_vowels(s), count_underscore(s)); /
        normalize_item(s, o); printf("NORM=%s\n", o); 
    } else if (act == 4) { 
        int R, C, g[100][100]; scanf("%d %d", &R, &C);
        for(int i=0; i<R; i++) for(int j=0; j<C; j++) scanf("%d", &g[i][j]); 
        row_col_max(R, C, g); 
    } else printf("invalid input\n"); 
    return 0; // 51
}
