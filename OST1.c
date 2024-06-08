#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORKER_THREADS 26

int isPalindrome(const char *word) {
    int length = strlen(word);
    int i = 0, j = length - 1;

    while (i < j) {
        if (word[i] != word[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

typedef struct {
    const char **words;
    int start;
    int end;
    int count;
} WorkerData;

void *countPalindromicWords(void *data) {
    WorkerData *workerData = (WorkerData *)data;
    int count = 0;

    for (int i = workerData->start; i < workerData->end; i++) {
        if (isPalindrome(workerData->words[i])) {
            count++;
        }
    }

    workerData->count = count;
    return NULL;
}

int main() 
{
    printf("**************************************\n");
    printf("        NAME   : MONISHA.S\n");
    printf("        REG.NO : 21BCT0414\n");
    printf("**************************************\n");
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening the words file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    const char *words[MAX_WORKER_THREADS];
    pthread_t threads[MAX_WORKER_THREADS];
    WorkerData workerData[MAX_WORKER_THREADS] = {0};
    int totalPalindromicWordsSeq = 0;
    int totalPalindromicWordsParallel = 0;

    // Read words into an array
    int wordCount = 0;
    while (fgets(word, sizeof(word), file) != NULL && wordCount < MAX_WORKER_THREADS) {
        // Trim trailing newline character
        word[strcspn(word, "\n")] = '\0';

        words[wordCount] = strdup(word);
        wordCount++;
    }
    fclose(file);

    printf("Sequential Program:\n");

    // Count palindromic words sequentially and print palindrome names
    printf("Palindromic words found:\n");
    for (int i = 0; i < wordCount; i++) {
        if (isPalindrome(words[i])) {
            totalPalindromicWordsSeq++;
            printf("%s\n", words[i]);
        }
    }

    printf("Total number of palindromic words: %d\n", totalPalindromicWordsSeq);
    printf("\n");

    printf("Parallel Program:\n");

    // Divide work among worker threads
    int wordsPerThread = wordCount / MAX_WORKER_THREADS;
    int remainingWords = wordCount % MAX_WORKER_THREADS;
    int start = 0;
    for (int i = 0; i < MAX_WORKER_THREADS; i++) {
        workerData[i].words = words;
        workerData[i].start = start;
        workerData[i].end = start + wordsPerThread + (i < remainingWords ? 1 : 0);
        start = workerData[i].end;

        pthread_create(&threads[i], NULL, countPalindromicWords, &workerData[i]);
    }

    // Wait for worker threads to finish
    for (int i = 0; i < MAX_WORKER_THREADS; i++) {
        pthread_join(threads[i], NULL);
        totalPalindromicWordsParallel += workerData[i].count;
    }

    // Print results
    printf("Total number of palindromic words: %d\n", totalPalindromicWordsParallel);
    for (int i = 0; i < MAX_WORKER_THREADS; i++) {
        printf("Worker %c found %d palindromic words.\n", 'a' + i, workerData[i].count);
    }

    // Free allocated memory
    for (int i = 0; i < wordCount; i++) {
        free((void *)words[i]);
    }

    return 0;
}
