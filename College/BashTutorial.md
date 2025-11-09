

---

# 🐚 Bash Scripting Basics — Syntax + Exercises

This guide covers all the **basic Bash syntaxes** — input/output, variables, conditionals, loops, and switch statements — along with **10 solved exercises** to help you practice.

---

## 🧩 1. Basic Input & Output

### ✅ Echo (Output)
```bash
echo "Hello, World!"
echo "Your name is $name"
````

### ✅ Read (Input)

```bash
echo "Enter your name: "
read name
echo "Hello, $name!"
```

or shorter:

```bash
read -p "Enter your age: " age
echo "You are $age years old."
```

---

## ⚙️ 2. Variables and Arithmetic

### ✅ Assign Variables

```bash
name="Shagnik"
age=20
```

> No spaces around `=` !

### ✅ Arithmetic

```bash
a=5
b=3
sum=$((a + b))
echo "Sum is $sum"
```

Other operations:

```bash
$((a - b))
$((a * b))
$((a / b))
$((a % b))
```

---

## 🧠 3. If / Else / Else If

### ✅ Basic `if`

```bash
if [ $a -gt $b ]
then
  echo "a is greater"
fi
```

### ✅ If-Else

```bash
if [ $a -gt $b ]
then
  echo "a is greater"
else
  echo "b is greater"
fi
```

### ✅ If – Else If – Else

```bash
if [ $a -gt $b ]
then
  echo "a is greater"
elif [ $a -eq $b ]
then
  echo "a and b are equal"
else
  echo "b is greater"
fi
```

### ⚙️ Comparison Operators

| Operator    | Meaning        | Example            |
| ----------- | -------------- | ------------------ |
| `-eq`       | equal to       | `[ $a -eq $b ]`    |
| `-ne`       | not equal to   | `[ $a -ne $b ]`    |
| `-gt`       | greater than   | `[ $a -gt $b ]`    |
| `-lt`       | less than      | `[ $a -lt $b ]`    |
| `-ge`       | ≥              | `[ $a -ge $b ]`    |
| `-le`       | ≤              | `[ $a -le $b ]`    |
| `==` / `!=` | string compare | `[ "$a" == "$b" ]` |

---

## 🔁 4. Loops

### ✅ For Loop

```bash
for i in {1..5}
do
  echo "Number $i"
done
```

**C-style:**

```bash
for ((i=1; i<=5; i++))
do
  echo "Number $i"
done
```

**Loop through list:**

```bash
for item in apple banana cherry
do
  echo "Fruit: $item"
done
```

---

### ✅ While Loop

```bash
count=1
while [ $count -le 5 ]
do
  echo "Count: $count"
  ((count++))
done
```

---

### ✅ Until Loop

```bash
count=1
until [ $count -gt 5 ]
do
  echo "Count: $count"
  ((count++))
done
```

---

## 🔀 5. Case / Switch

```bash
read -p "Enter a letter: " letter

case $letter in
  "a") echo "You chose A" ;;
  "b") echo "You chose B" ;;
  "c"|"d") echo "You chose C or D" ;;
  *) echo "Invalid option" ;;
esac
```

---

## 🧩 6. Functions

```bash
greet() {
  echo "Hello, $1!"
}

greet "Shagnik"
```

> `$1`, `$2`, etc. represent function arguments.

---

## 📁 7. File Tests

```bash
file="test.txt"

if [ -f "$file" ]; then
  echo "File exists"
else
  echo "File not found"
fi
```

| Flag | Meaning          |
| ---- | ---------------- |
| `-f` | file exists      |
| `-d` | directory exists |
| `-r` | readable         |
| `-w` | writable         |
| `-x` | executable       |

---

## 🧮 8. Combining Conditions

```bash
if [ $a -gt 0 ] && [ $b -gt 0 ]; then
  echo "Both positive"
fi

if [ $a -eq 10 ] || [ $b -eq 20 ]; then
  echo "One is special"
fi
```

---

## 🎯 9. Command Substitution

```bash
current_date=$(date)
echo "Today is $current_date"
```

---

# 🧑‍💻 10. Exercises with Solutions

---

### 🧠 1. Sum of Two Numbers

```bash
read -p "Enter first number: " a
read -p "Enter second number: " b
sum=$((a + b))
echo "Sum = $sum"
```

---

### 🧠 2. Even or Odd

```bash
read -p "Enter a number: " num
if [ $((num % 2)) -eq 0 ]
then
  echo "Even"
else
  echo "Odd"
fi
```

---

### 🧠 3. Positive / Negative / Zero

```bash
read -p "Enter a number: " num
if [ $num -gt 0 ]; then
  echo "Positive"
elif [ $num -lt 0 ]; then
  echo "Negative"
else
  echo "Zero"
fi
```

---

### 🧠 4. Simple Calculator

```bash
read -p "Enter first number: " a
read -p "Enter second number: " b
read -p "Enter operator (+ - * /): " op

case $op in
  "+") echo "Result = $((a + b))" ;;
  "-") echo "Result = $((a - b))" ;;
  "*") echo "Result = $((a * b))" ;;
  "/") echo "Result = $((a / b))" ;;
  *) echo "Invalid operator" ;;
esac
```

---

### 🧠 5. Print 1 to N

```bash
read -p "Enter N: " n
for ((i=1; i<=n; i++))
do
  echo $i
done
```

---

### 🧠 6. Factorial of a Number

```bash
read -p "Enter a number: " n
fact=1
while [ $n -gt 0 ]
do
  fact=$((fact * n))
  ((n--))
done
echo "Factorial = $fact"
```

---

### 🧠 7. Largest of Three Numbers

```bash
read -p "Enter a: " a
read -p "Enter b: " b
read -p "Enter c: " c

if [ $a -ge $b ] && [ $a -ge $c ]; then
  echo "$a is largest"
elif [ $b -ge $a ] && [ $b -ge $c ]; then
  echo "$b is largest"
else
  echo "$c is largest"
fi
```

---

### 🧠 8. Check File Existence and Create if Missing

```bash
read -p "Enter filename: " file
if [ -f "$file" ]; then
  echo "File already exists."
else
  echo "File not found. Creating..."
  touch "$file"
  echo "$file created."
fi
```

---

### 🧠 9. Sum of Digits of a Number

```bash
read -p "Enter a number: " n
sum=0
while [ $n -gt 0 ]
do
  rem=$((n % 10))
  sum=$((sum + rem))
  n=$((n / 10))
done
echo "Sum of digits = $sum"
```

---

### 🧠 10. Reverse a String

```bash
read -p "Enter a string: " str
rev=$(echo $str | rev)
echo "Reversed: $rev"
```

---

# 🎉 You're Done!

You’ve now learned:

* Input/Output in Bash
* Variables and Arithmetic
* If-Else, Elif
* For, While, Until loops
* Case/Switch
* Functions and File Handling

✅ Try modifying each exercise slightly to get comfortable with syntax.

---

**Author:** ChatGPT Bash Tutor
**Last updated:** November 2025



