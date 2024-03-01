// ( 0 _ o )

// Last updated: 2020-06-26 10:37 UTC+1

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIAS 1

#define EPOCHS 10000

#define WEIGHT_COUNT 3
#define DATASET_COUNT 4

#define LEARNING_RATE 0.5

const unsigned
training_dataset[DATASET_COUNT][WEIGHT_COUNT] =
{
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 0}
};

double weights[WEIGHT_COUNT];

int main(void)
{
    srand(time(NULL));

    for (unsigned i = 0; i < WEIGHT_COUNT; i++)
    {
        weights[i] = (double) rand() / RAND_MAX;
    }

    printf("Training the Perceptron...\n\n");

    unsigned epoch = 0;

    while (epoch < EPOCHS)
    {
        for (unsigned i = 0; i < DATASET_COUNT; i++)
        {
            const unsigned * set = training_dataset[i];

            unsigned inputs[WEIGHT_COUNT] =
            {
                set[0], set[1], BIAS
            };

            unsigned target = set[2];

            double sum = 0;

            for (unsigned j = 0; j < WEIGHT_COUNT; j++)
            {
                sum += inputs[j] * weights[j];
            }

            double output = 1 / (1 + exp(-sum));

            double error = target - output;

            for (unsigned j = 0; j < WEIGHT_COUNT; j++)
            {
                weights[j] += (error * inputs[j] * LEARNING_RATE);
            }
        }

        printf("epoch: %u - ", epoch);

        for (unsigned i = 0; i < WEIGHT_COUNT; i++)
        {
            printf("%u: %.10f ", i, weights[i]);
        }

        printf("\n");

        epoch++;
    }

    printf("\n");

    printf("Perceptron trained.\n");

    return 0;
}
