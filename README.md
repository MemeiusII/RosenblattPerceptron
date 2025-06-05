# Simple Perceptron in C

This project demonstrates a basic implementation of a **single-layer perceptron** in C, based on the **Rosenblatt model**. It uses **Rosenblatt's learning rule** for binary classification and is trained to simulate the logical **OR** function.

---

## 🧠 Overview

A perceptron is a type of linear classifier introduced by **Frank Rosenblatt** in 1958. This implementation includes:

- Two binary input features
- Two weights
- One bias
- Four batches
- A binary step activation function
- Weight updates using **Rosenblatt’s learning rule**

---

## 🔁 Rosenblatt’s Learning Rule

Weight update formula:
```c
w = w + learning_rate * (truth - prediction) * input
```
Bias update formula:
```c
b = b + learning_rate * (truth - prediction)
```

This rule adjusts the weights based on prediction error and helps the model learn the decision boundary over time.

---

## 🧪 Training Data

The perceptron can be trained on data representing an several different logic gates.

Logic gates included:
- AND
- OR
- NAND
- NOR

Example: OR gate table
| x1 | x2 | Output (y) |
|----|----|-------------|
| 1  | 1  | 1           |
| 1  | 0  | 1           |
| 0  | 1  | 1           |
| 0  | 0  | 0           |

---

## ⚙️ How It Works

1. Randomly initialize weights
2. Perform forward propagation with step activation
3. Compute error between prediction and ground truth
4. Update weights and bias using Rosenblatt’s rule
5. Repeat for a fixed number of iterations

---

## 🧰 Core Functions

- `randomFloat(min, max)` – Generates a random float between a given range
- `activate(z)` – Step activation function returning `0` or `1`
- `forward(inputs[batch], weights, bias)` – Computes the perceptron’s prediction
- `error(estimate, truth)` – Measures the error
- `adjustWeights(weights, inputs[batch], error)` – Updates weights using Rosenblatt’s rule
- `adjustBias(bias, error)` - Update bias using Rosenblatt's rule

---

## ⚙️ Parameters

- **Learning Rate:** e.g. `0.05`
- **Iterations:** e.g. `30`

---

## 💻 Usage

### 🧾 Compile and Run

```bash
gcc perceptron.c -o perceptron
./perceptron
```
---

## 🖥️ Sample Output

Iteration 1 cost: 2.0

Iteration 2 cost: 1.0

...

Input: [1, 1] => Output: 1 Expected Value: 1

Input: [1, 0] => Output: 1 Expected Value: 1

Input: [0, 1] => Output: 1 Expected Value: 1

Input: [0, 0] => Output: 0 Expected Value: 0

---

## 📚 References
- [Perceptron (Wikipedia)](https://en.wikipedia.org/wiki/Perceptron)
- Rosenblatt, F. (1958). The Perceptron: A Probabilistic Model for Information Storage and Organization in the Brain

---

## 📌 Notes
This is a minimal educational example. It demonstrates the foundations of supervised learning and **is not suitable** for solving non-linearly separable problems like XOR.
