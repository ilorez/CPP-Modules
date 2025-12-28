# CPP Module 06 – Type Conversion, Casts & Serialization

**Author path:** tailored for *Zobair Najdaoui* – 42/1337 student, C-first mindset, likes step-by-step reasoning, deep understanding, and clean design.

---

## 0. How to Use This Course (Important)

This is **not** just a solution guide.
This is a **learning path** designed to:

* Build **mental models** (not memorization)
* Explain **why Module 06 exists**
* Prepare you for **real C++ usage**, not just 42 validation

### How you should study:

1. Read **one section at a time**
2. Re‑write small examples by hand
3. Compile with:

```bash
g++ -Wall -Wextra -Werror -std=c++98
```

4. Test weird cases (invalid input, overflow, edge values)

---

## 1. Why Module 06 Exists (Big Picture)

Before Module 06, you already know:

* Classes
* Inheritance
* Exceptions
* Polymorphism

**But** you still don’t fully control:

* How data changes **type**
* How memory is **interpreted**
* When conversions are **safe vs dangerous**

> Module 06 teaches you: **"I know exactly what this value means in memory."**

This is the bridge between:

* High‑level C++
* Low‑level C mindset (which you already have)

---

## 2. Core Concepts of Module 06

Module 06 is built on **3 pillars**:

1. **Scalar type conversion** (ex00)
2. **Runtime type identification** (ex01)
3. **Serialization & reinterpretation** (ex02)

Each exercise adds **controlled danger**.
You are learning how to touch fire **without getting burned**.

---

## 3. Exercise 00 – Scalar Conversion

### Goal

Convert a string literal into:

* `char`
* `int`
* `float`
* `double`

### Why this matters

In real programs:

* Input is **always string** (CLI, files, network)
* Logic needs **typed values**

You are building a **safe conversion pipeline**.

---

### 3.1 What Is a Scalar?

Scalar = **single value type**

| Type   | Example |
| ------ | ------- |
| char   | 'a'     |
| int    | 42      |
| float  | 42.0f   |
| double | 42.0    |

---

### 3.2 Design Strategy (Very Important)

You should create:

```cpp
class ScalarConverter {
public:
    static void convert(const std::string &literal);
};
```

Why **static**?

* No state
* No object needed
* Pure utility

> This is **intentional design**, not a trick.

---

### 3.3 Conversion Flow (Mental Model)

```
input string
   ↓
identify type
   ↓
convert to all scalar types
   ↓
print result OR exception
```

Never try to convert blindly.
**Always detect first.**

---

### 3.4 Detecting Literal Type

Cases you must recognize:

| Input     | Meaning |
| --------- | ------- |
| 'a'       | char    |
| 42        | int     |
| 42.0f     | float   |
| 42.0      | double  |
| nan / inf | special |

Important rules:

* `'a'` → char
* single digit like `7` → int (not char)
* float **must** end with `f`

---

### 3.5 Conversion Rules (Critical)

| Conversion   | Rule                    |
| ------------ | ----------------------- |
| int → char   | printable only          |
| double → int | check overflow          |
| nan / inf    | impossible for char/int |

Use:

* `std::isdigit`
* `std::isprint`
* `std::strtod`

---

### 3.6 Output Format

Exact formatting matters:

```text
char: 'a'
int: 97
float: 97.0f
double: 97.0
```

If impossible:

```text
char: impossible
```

---

### 3.7 What You REALLY Learn Here

* Difference between **representation** and **meaning**
* Limits of types
* Floating‑point weirdness

> This exercise trains **defensive programming**.

---

## 4. Exercise 01 – RTTI (Runtime Type Identification)

### Goal

Identify the **real type** of an object through a base pointer.

---

### 4.1 The Setup

```cpp
class Base { public: virtual ~Base(); };
class A : public Base {};
class B : public Base {};
class C : public Base {};
```

You are given:

* `Base*`
* `Base&`

And must detect: A, B, or C.

---

### 4.2 Why This Exists

In real systems:

* You don’t know the exact type
* You receive **base interfaces**

This is **runtime polymorphism mastery**.

---

### 4.3 dynamic_cast (Your New Weapon)

Rules:

```cpp
A* a = dynamic_cast<A*>(basePtr);
```

* returns `NULL` if wrong type

```cpp
dynamic_cast<A&>(baseRef);
```

* throws exception if wrong

> Pointer → check NULL
> Reference → use try/catch

---

### 4.4 identify(Base*)

Strategy:

```cpp
if (dynamic_cast<A*>(p))
    std::cout << "A";
```

---

### 4.5 identify(Base&)

Strategy:

```cpp
try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A";
} catch (...) {}
```

Repeat for B, C.

---

### 4.6 What You REALLY Learn Here

* Polymorphism is **runtime truth**, not compile-time
* `virtual` enables RTTI
* Safe downcasting

This is **enterprise‑level C++ knowledge**.

---

## 5. Exercise 02 – Serialization

### Goal

Convert a pointer into an integer and back.

---

### 5.1 Why This Is Dangerous (And Powerful)

You are touching:

* Memory addresses
* Raw representation

Used in:

* Game engines
* Kernels
* Networking

---

### 5.2 The Data Structure

```cpp
struct Data {
    int value;
};
```

---

### 5.3 serialize()

```cpp
uintptr_t serialize(Data* ptr);
```

Implementation:

```cpp
return reinterpret_cast<uintptr_t>(ptr);
```

---

### 5.4 deserialize()

```cpp
Data* deserialize(uintptr_t raw);
```

Implementation:

```cpp
return reinterpret_cast<Data*>(raw);
```

---

### 5.5 Why reinterpret_cast?

Because:

* You are **not converting value**
* You are reinterpreting **bits**

This is the **lowest‑level cast** in C++.

---

### 5.6 What You REALLY Learn Here

* Pointer ≠ integer, but memory allows reinterpretation
* When C‑style casting is dangerous
* Why modern C++ prefers explicit casts

---

## 6. The 4 C++ Casts (Must Memorize)

| Cast             | Usage            |
| ---------------- | ---------------- |
| static_cast      | safe conversions |
| dynamic_cast     | RTTI             |
| const_cast       | remove const     |
| reinterpret_cast | raw memory       |

> If you understand **when** to use each → you passed Module 06 mentally.

---

## 7. Common Mistakes (42 Killers)

* Forgetting virtual destructor
* Using C‑style casts
* Not handling nan/inf
* Wrong output format
* No exception handling

---

## 8. Final Mental Model (Very Important)

Module 06 teaches:

> "I control types, memory, and runtime truth — not the compiler."

If Module 05 taught **rules**,
Module 06 teaches **reality**.

