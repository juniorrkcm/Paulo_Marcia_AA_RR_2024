#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main() {
    FILE *fp_time = fopen("fibonacci_times_interativo.csv", "w");  // Arquivo para salvar os tempos de execução
    FILE *fp_result = fopen("fibonacci_results_interativo.csv", "w");  // Arquivo para salvar os resultados do Fibonacci
    fprintf(fp_time, "Terms,ExecutionTime\n");
    fprintf(fp_result, "Terms,FibonacciResult\n");

    int terms[] = {100000, 500000, 1000000, 1500000, 2000000};  // Tamanhos de entrada específicos
    int numTests = 5;  // Número de entradas

    for (int test = 0; test < numTests; test++) {
        int n = terms[test];
        mpz_t t1, t2, nextTerm, sum;
        mpz_init(t1);
        mpz_init(t2);
        mpz_init(nextTerm);
        mpz_init(sum);
        mpz_set_ui(t1, 0);
        mpz_set_ui(t2, 1);
        mpz_add(nextTerm, t1, t2);
        mpz_add(sum, t1, t2);

        clock_t start, end;
        double cpu_time_used;

        start = clock();

        for (int i = 3; i <= n; ++i) {
            mpz_add(sum, sum, nextTerm);
            mpz_set(t1, t2);
            mpz_set(t2, nextTerm);
            mpz_add(nextTerm, t1, t2);
        }

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp_time, "%d,%f\n", n, cpu_time_used);  // Salva os tempos de execução no arquivo
        gmp_fprintf(fp_result, "%d,%Zd\n", n, nextTerm);  // Salva os resultados do Fibonacci no arquivo

        // Limpeza das variáveis GMP
        mpz_clear(t1);
        mpz_clear(t2);
        mpz_clear(nextTerm);
        mpz_clear(sum);
    }

    fclose(fp_time);
    fclose(fp_result);
    return 0;
}
