#include <stdio.h>
#include <gmp.h>
#include <time.h>

void multiply_matrices(mpz_t F[2][2], mpz_t M[2][2]) {
    mpz_t a, b, c, d;
    mpz_init(a); mpz_init(b); mpz_init(c); mpz_init(d);
    
    mpz_mul(a, F[0][0], M[0][0]);
    mpz_addmul(a, F[0][1], M[1][0]);

    mpz_mul(b, F[0][0], M[0][1]);
    mpz_addmul(b, F[0][1], M[1][1]);

    mpz_mul(c, F[1][0], M[0][0]);
    mpz_addmul(c, F[1][1], M[1][0]);

    mpz_mul(d, F[1][0], M[0][1]);
    mpz_addmul(d, F[1][1], M[1][1]);

    mpz_set(F[0][0], a);
    mpz_set(F[0][1], b);
    mpz_set(F[1][0], c);
    mpz_set(F[1][1], d);

    mpz_clear(a); mpz_clear(b); mpz_clear(c); mpz_clear(d);
}

void power_matrix(mpz_t F[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    mpz_t M[2][2];
    mpz_init(M[0][0]); mpz_init(M[0][1]);
    mpz_init(M[1][0]); mpz_init(M[1][1]);

    mpz_set_ui(M[0][0], 1); mpz_set_ui(M[0][1], 1);
    mpz_set_ui(M[1][0], 1); mpz_set_ui(M[1][1], 0);

    power_matrix(F, n / 2);
    multiply_matrices(F, F);

    if (n % 2 != 0)
        multiply_matrices(F, M);

    mpz_clear(M[0][0]); mpz_clear(M[0][1]);
    mpz_clear(M[1][0]); mpz_clear(M[1][1]);
}

void fibonacci(mpz_t result, int n) {
    if (n == 0) {
        mpz_set_ui(result, 0);
        return;
    }

    mpz_t F[2][2];
    mpz_init(F[0][0]); mpz_init(F[0][1]);
    mpz_init(F[1][0]); mpz_init(F[1][1]);

    mpz_set_ui(F[0][0], 1); mpz_set_ui(F[0][1], 1);
    mpz_set_ui(F[1][0], 1); mpz_set_ui(F[1][1], 0);

    power_matrix(F, n - 1);

    mpz_set(result, F[0][0]);

    mpz_clear(F[0][0]); mpz_clear(F[0][1]);
    mpz_clear(F[1][0]); mpz_clear(F[1][1]);
}

int main() {
    FILE *fp_time = fopen("fibonacci_times_matrix.csv", "w");  // Arquivo para salvar os tempos de execução
    FILE *fp_result = fopen("fibonacci_results_matrix.csv", "w");  // Arquivo para salvar os resultados do Fibonacci
    fprintf(fp_time, "Terms,ExecutionTime\n");
    fprintf(fp_result, "Terms,FibonacciResult\n");

    int terms[] = {100000, 500000, 1000000, 1500000, 2000000};  // Tamanhos de entrada específicos
    int numTests = 5;  // Número de entradas

    for (int test = 0; test < numTests; test++) {
        int n = terms[test];
        mpz_t result;
        mpz_init(result);

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        fibonacci(result, n);  // Chama a função Fibonacci usando a representação matricial
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp_time, "%d,%f\n", n, cpu_time_used);  // Salva os tempos de execução no arquivo
        gmp_fprintf(fp_result, "%d,%Zd\n", n, result);  // Salva os resultados do Fibonacci no arquivo

        mpz_clear(result);
    }

    fclose(fp_time);
    fclose(fp_result);
    return 0;
}
