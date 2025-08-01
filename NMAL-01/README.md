# 🔍 Bisection Method – Root Finding in C++

This project implements the **Bisection Method** in C++ to find the root of a nonlinear equation.

---

## 📌 What is the Bisection Method?

**Bisection Method** is a way to find the value of `x` where `f(x) = 0`,  by cutting the interval `[a, b]` into half again and again, as long as the sign of `f(x)` changes between `a` and `b`.

It will work if:

- The function is continuous (no breaks)  
- `f(a)` and `f(b)` have opposite signs (`f(a) * f(b) < 0`)

---

## ✅ How It Works

1. Choose initial interval \([a, b]\)
2. Compute midpoint \( c = (a + b) / 2 \)
3. If \( f(c) \) is close to 0, return \( c \)
4. Else, update the interval:
   - If \( f(a) `*` f(c) < 0 \): set \( b = c \)
   - Else: set \( a = c \)
5. Repeat until the error \( |b - a| < tolerance \)

---

## 🆚 Traditional vs Improved Approach

| Feature                  | Traditional Bisection        | Improved Bisection               |
|--------------------------|------------------------------|----------------------------------|
| Function calls           | Recomputes `f(a)` and `f(b)` every time | Stores `f(a)` and `f(b)` and updates only when needed |
| Performance              | Slower                       | Faster (less computation)        |
| Recommended for          | Simple problems              | Complex or heavy functions       |

---

## 🧠 Better Approach: Auto Range Detection

Instead of manually selecting a range \([a, b]\),  
this version scans over a large interval and finds where the function changes sign.

### 🔧 How:
1. Scan `x` from `start` to `end` with step `h`
2. Check if \( f(x) \cdot f(x+h) < 0 \)
3. If yes → use \([x, x+h]\) as starting range

This gives a **smaller and more accurate interval**, reducing iterations.

---


