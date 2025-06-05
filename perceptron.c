#include <stdio.h>
#include <stdlib.h>
#include "logicgates.h"

#define LEARNING_RATE 0.1
#define ITERATIONS 50

float randomFloat(const float min, const float max) {
  return min + ((float)rand() / RAND_MAX * (max - min));
}

float activate(const float z) {
	return z > 0 ? 1.0 : 0.0;
}

float forward(const float* x, const float* w, const float b) {
	float sum = 0;
	for (size_t i = 0; i < INPUT_SIZE; i++) {
		sum += x[i] * w[i];
	}
	return activate(sum + b);
}

float error(float estimate, float truth) {
	return truth - estimate;
}

void adjustWeights(float* w, const float* x, float error) {
	for (size_t i = 0; i < INPUT_SIZE; i++) {
		w[i] += LEARNING_RATE * error * x[i];
	}
}

void adjustBias(float* b, const float error) {
	*b = *b + LEARNING_RATE * error;
}

int main(void) {
	// Seed the random number generator
	  srand(1);

	// Inputs
	float inputs[BATCH_SIZE][INPUT_SIZE] = GATE_INPUTS;
	// Truth values
	float y[BATCH_SIZE] = NAND_OUTPUT; // Swap for what yoyou want

	// Weights
	float weights[] = {
		randomFloat(-5, 5), randomFloat(-5, 5)
	};

	// Bias
	float b = 0;

	// Train loop
	for(size_t iter = 0; iter < ITERATIONS; iter++) {
		float cost = 0;
		for(size_t BATCH = 0; BATCH < BATCH_SIZE; BATCH++) {
			float output = forward(inputs[BATCH], weights, b);
			float err = error(output, y[BATCH]);

			adjustWeights(weights, inputs[BATCH], err);
			adjustBias(&b, err);

			cost += err * err;
		}
		printf("Iteration %zu cost: %f\n", iter + 1, cost);
	}

	// See output after training
	printf("--- Final results after training ---\n");
	for (size_t BATCH = 0; BATCH < BATCH_SIZE; BATCH++) {
		float output = forward(inputs[BATCH], weights, b);
		printf("Input: [%g, %g] => Output: %f Expected Value: %f\n",
		       inputs[BATCH][0], inputs[BATCH][1], output, y[BATCH]);
	}

	return 0;
}
