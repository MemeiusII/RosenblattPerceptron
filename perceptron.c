#include <stdio.h>
#include <stdlib.h>

const float LEARNING_RATE = 0.05;
const float ITERATIONS = 30;

float randomFloat(float min, float max) {
  return min + (float)rand() / RAND_MAX * (max - min);
}

float activate(float z) {
	return z > 0 ? 1.0 : 0.0;
}

float forward(float x1, float x2,float w1, float w2) {
	return activate(x1 * w1 + x2 * w2);
}

float cost(float estimate, float truth) {
	return truth - estimate;
}

void adjustWeight(float* w, float x, float estimate, float truth) {
	*w = *w + (LEARNING_RATE * (truth - estimate) * x);
}

int main(void) {
	// Seed the random number generator
	  srand(1);

	// Inputs
	size_t input_size = 4;
	float x1[] = { 1, 1, 0, 0 };
	float x2[] = { 1, 0, 1, 0 };

	// Truth values
	float y[] = { 1, 1, 1, 0 };

	// Weights
	float w1 = randomFloat(-5.0, 5.0);
	float w2 = randomFloat(-5.0, 5.0);

	// Train loop
	for(size_t i = 0; i < ITERATIONS; i++) {
		float c = 0;
		// Forward for output
		for(size_t j = 0; j < input_size; j++) {
			float output = forward(x1[j], x2[j], w1 ,w2);

			adjustWeight(&w1, x1[j], output, y[j]);
			adjustWeight(&w2, x2[j], output, y[j]);

			c += cost(output, y[j]);
		}
		printf("w1: %f w2: %f \t", w1, w2);
		printf("Iteration %zu cost: %f\n", (i + 1), c);
	}

	// See output after training
	for(size_t i; i < input_size; i++) {
		float output = forward(x1[i], x2[i], w1, w2);
		printf("Ouput: %f Expected Value: %f\n", output, y[i]);
	}

	return 0;
}
