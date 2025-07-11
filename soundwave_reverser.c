






#include <stdio.h>
#include <stdlib.h>

void reverse_audio_samples(short *audio_data, long num_samples) {
    long i = 0;
    long j = num_samples - 1;
    short temp;

    while (i < j) {
        temp = audio_data[i];
        audio_data[i] = audio_data[j];
        audio_data[j] = temp;
        i++;
        j--;
    }
}

int main() {
    long num_samples = 10;
    short *audio_buffer = (short *)malloc(num_samples * sizeof(short));

    if (audio_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Original audio data:\n");
    for (long i = 0; i < num_samples; i++) {
        audio_buffer[i] = i * 1000;
        printf("%d ", audio_buffer[i]);
    }
    printf("\n\n");

    reverse_audio_samples(audio_buffer, num_samples);

    printf("Reversed audio data:\n");
    for (long i = 0; i < num_samples; i++) {
        printf("%d ", audio_buffer[i]);
    }
    printf("\n");

    free(audio_buffer);
    audio_buffer = NULL;

    return 0;
}
