# Simple Perceptron in C

This project demonstrates a basic implementation of a **single-layer perceptron** in C, based on the **Rosenblatt model**. It uses **Rosenblatt's learning rule** for binary classification and is trained to simulate the logical **OR** function.

---

## 🧠 Overview

A perceptron is a type of linear classifier introduced by **Frank Rosenblatt** in 1958. This implementation includes:

- Two binary input features (`x1`, `x2`)
- Two weights (`w1`, `w2`)
- A binary step activation function
- Weight updates using **Rosenblatt’s learning rule**

---

## 🔁 Rosenblatt’s Learning Rule

Weight update formula:
```c
w = w + learning_rate * (truth - prediction) * input
```

This rule adjusts the weights based on prediction error and helps the model learn the decision boundary over time.

---

## 🧪 Training Data

The perceptron is trained on data representing an OR logic gate:

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
4. Update weights using Rosenblatt’s rule
5. Repeat for a fixed number of iterations

---

## 🧰 Core Functions

- `randomFloat(min, max)` – Generates a random float between a given range
- `activate(z)` – Step activation function returning `0` or `1`
- `forward(x1, x2, w1, w2)` – Computes the perceptron’s prediction
- `cost(estimate, truth)` – Measures the error
- `adjustWeight(w, x, estimate, truth)` – Updates weights using Rosenblatt’s rule

---

## ⚙️ Parameters

- **Learning Rate:** `0.05`
- **Iterations:** `30`

---

## 💻 Usage

### 🧾 Compile and Run

```bash
gcc perceptron.c -o perceptron
./perceptron
```
---

## 🖥️ Sample Output

w1: 1.050000 w2: 0.950000    Iteration 1 cost: 2.000000
...
Output: 1.000000 Expected Value: 1.000000
...
Output: 0.000000 Expected Value: 0.000000

---

## 📚 References
- [Perceptron (Wikipedia)](https://en.wikipedia.org/wiki/Perceptron)
- Rosenblatt, F. (1958). The Perceptron: A Probabilistic Model for Information Storage and Organization in the Brain

---

## 📌 Notes
This is a minimal educational example. It demonstrates the foundations of supervised learning and **is not suitable** for solving non-linearly separable problems like XOR.
