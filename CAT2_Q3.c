#include <stdio.h>

int main() {
    FILE *in, *out;
    int i, n, sum = 0, count = 0;
    double avg;

    // Create input file
    in = fopen("input.txt", "w");
    if (in == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Integer #%d: ", i + 1);
        scanf("%d", &n);
        fprintf(in, "%d\n", n);
    }
    fclose(in);

    // Process file
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {
        printf("File error.\n");
        return 1;
    }

    while (fscanf(in, "%d", &n) == 1) {
        sum += n;
        count++;
    }
    avg = (count > 0) ? (double)sum / count : 0.0;

    fprintf(out, "Count: %d\nSum: %d\nAverage: %.2lf\n", count, sum, avg);
    fclose(in);
    fclose(out);

    // Display results
    printf("\n--- input.txt ---\n");
    in = fopen("input.txt", "r");
    while (fscanf(in, "%d", &n) == 1)
        printf("%d\n", n);
    fclose(in);

    printf("\n--- output.txt ---\n");
    out = fopen("output.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), out))
        printf("%s", line);
    fclose(out);

    return 0;
}
