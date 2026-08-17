#include <stdio.h>    // 1
#include <ctype.h>    // 2
#include <string.h>   // 3


double subtotal_bill(int meals, int drinks) { return (meals * 4.50) + (drinks * 1.75); } // 4
double final_bill(double subtotal, int member) { return (member == 1) ? subtotal * 0.90 : subtotal; } // 5

int max_orders(int a[], int n) { // 6
    int max = a[0]; // 7
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i]; // 8
    return max; // 9
}

int count_at_least(int a[], int n, int target) { // 10
    int count = 0; // 11
    for (int i = 0; i < n; i++) if (a[i] >= target) count++; // 12
    return count; // 13
}

int count_vowels(char s[]) { // 14
    int count = 0; // 15
    for (int i = 0; s[i] != '\0'; i++) { // 16
        char c = tolower(s[i]); // 17
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++; // 18
    }
    return count; // 19
}

int count_underscore(char s[]) { // 20
    int count = 0; // 21
    for (int i = 0; s[i] != '\0'; i++) if (s[i] == '_') count++; // 22
    return count; // 23
}

void normalize_item(char in[], char out[]) { // 24
    for (int i = 0; in[i] != '\0'; i++) { // 25
        if (in[i] == '_') out[i] = ' '; // 26
        else out[i] = toupper(in[i]); // 27
    }
    out[strlen(in)] = '\0'; // 28
}

void row_col_max(int R, int C, int grid[][100]) { // 29
    printf("ROWMAX"); for (int i = 0; i < R; i++) { int m = grid[i][0]; for (int j = 1; j < C; j++) if (grid[i][j] > m) m = grid[i][j]; printf(" %d", m); } // 30
    printf("\nCOLMAX"); for (int j = 0; j < C; j++) { int m = grid[0][j]; for (int i = 1; i < R; i++) if (grid[i][j] > m) m = grid[i][j]; printf(" %d", m); } // 31
    int z = 0; for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (grid[i][j] == 0) z++; printf("\nZERO=%d\n", z); // 32
}

int main() { // 33
    int act; scanf("%d", &act); // 34
    if (act == 1) { // 35
        int m, d, mem; scanf("%d %d %d", &m, &d, &mem); // 36
        if (m<0 || m>100 || d<0 || d>100 || (m==0 && d==0) || (mem!=0 && mem!=1)) printf("invalid input\n"); // 37
        else { double s = subtotal_bill(m, d); printf("SUBTOTAL=%.2f TOTAL=%.2f\n", s, final_bill(s, mem)); } // 38
    } else if (act == 2) { // 39
        int n, t, a[1000]; scanf("%d", &n); if (n<1 || n>1000) { printf("invalid input\n"); return 0; } // 40
        for (int i=0; i<n; i++) scanf("%d", &a[i]); scanf("%d", &t); // 41
        printf("MAX=%d HIT=%d\n", max_orders(a, n), count_at_least(a, n, t)); // 42
    } else if (act == 3) { // 43
        char s[201], o[201]; scanf("%s", s); printf("V=%d U=%d\n", count_vowels(s), count_underscore(s)); // 44
        normalize_item(s, o); printf("NORM=%s\n", o); // 45
    } else if (act == 4) { // 46
        int R, C, g[100][100]; scanf("%d %d", &R, &C); // 47
        for(int i=0; i<R; i++) for(int j=0; j<C; j++) scanf("%d", &g[i][j]); // 48
        row_col_max(R, C, g); // 49
    } else printf("invalid input\n"); // 50
    return 0; // 51
}