Perfect ✅ — you’re asking for exactly what every Oracle student needs: a **complete revision guide** to tie together all the practical SQL you’ve learned (DDL, DML, functions, joins, subqueries, views).

Here’s your **Ultimate SQL Revision Guide (Oracle Edition)** — everything neatly categorized with examples and quick explanations.

---

# 🧠 **Oracle SQL Ultimate Revision Guide**

---

## 🏗️ 1️⃣ DDL — Data Definition Language

DDL commands define and modify the structure of database objects (tables, constraints, etc.).

### 🔹 CREATE TABLE

```sql
CREATE TABLE employees (
    emp_id NUMBER(5) PRIMARY KEY,
    name VARCHAR2(50) NOT NULL,
    department VARCHAR2(30),
    salary NUMBER(8,2),
    hire_date DATE DEFAULT SYSDATE
);
```

### 🔹 CONSTRAINTS

| Constraint    | Description                | Example                                   |
| ------------- | -------------------------- | ----------------------------------------- |
| `PRIMARY KEY` | Unique + Not Null          | `emp_id NUMBER PRIMARY KEY`               |
| `FOREIGN KEY` | References another table   | `dept_id REFERENCES departments(dept_id)` |
| `UNIQUE`      | No duplicates allowed      | `email VARCHAR2(50) UNIQUE`               |
| `CHECK`       | Restricts values           | `salary CHECK (salary > 0)`               |
| `DEFAULT`     | Auto value if not provided | `hire_date DATE DEFAULT SYSDATE`          |
| `NOT NULL`    | Mandatory column           | `name VARCHAR2(50) NOT NULL`              |

---

### 🔹 ALTER TABLE

```sql
ALTER TABLE employees ADD job_title VARCHAR2(30);
ALTER TABLE employees MODIFY salary NUMBER(10,2);
ALTER TABLE employees DROP COLUMN job_title;
```

### 🔹 RENAME / DROP

```sql
RENAME employees TO staff;
DROP TABLE staff;
```

---

## ✍️ 2️⃣ DML — Data Manipulation Language

DML changes data inside tables.

### 🔹 INSERT

```sql
INSERT INTO employees VALUES (101, 'Rahul', 'IT', 45000, SYSDATE);
INSERT INTO employees (emp_id, name, department) VALUES (102, 'Sneha', 'HR');
```

Interactive insert:

```sql
INSERT INTO employees VALUES (&emp_id, '&name', '&department', &salary, TO_DATE('&hire_date','DD-MM-YYYY'));
```

---

### 🔹 UPDATE

```sql
UPDATE employees SET salary = salary + 5000 WHERE emp_id = 101;
```

### 🔹 DELETE

```sql
DELETE FROM employees WHERE department = 'HR';
```

### 🔹 TRUNCATE (removes all rows, faster)

```sql
TRUNCATE TABLE employees;
```

---

## 🧮 3️⃣ SQL FUNCTIONS

### 🟩 String Functions

| Function    | Example                                   | Result           |         |   |     |   |       |           |
| ----------- | ----------------------------------------- | ---------------- | ------- | - | --- | - | ----- | --------- |
| `UPPER()`   | `UPPER(name)`                             | RAHUL            |         |   |     |   |       |           |
| `LOWER()`   | `LOWER(name)`                             | rahul            |         |   |     |   |       |           |
| `INITCAP()` | `INITCAP(name)`                           | Rahul            |         |   |     |   |       |           |
| `LENGTH()`  | `LENGTH('Hello')`                         | 5                |         |   |     |   |       |           |
| `SUBSTR()`  | `SUBSTR('Computer',1,3)`                  | Com              |         |   |     |   |       |           |
| `INSTR()`   | `INSTR('Database','a')`                   | 2                |         |   |     |   |       |           |
| `REPLACE()` | `REPLACE('CSE','CSE','Computer Science')` | Computer Science |         |   |     |   |       |           |
| `CONCAT()`  | `CONCAT(emp_id, name)`                    | 101Rahul         |         |   |     |   |       |           |
| `           |                                           | `                | `emp_id |   | '-' |   | name` | 101-Rahul |

---

### 🟨 Numeric Functions

| Function  | Example            | Result |
| --------- | ------------------ | ------ |
| `ABS()`   | `ABS(-20)`         | 20     |
| `ROUND()` | `ROUND(45.678, 2)` | 45.68  |
| `TRUNC()` | `TRUNC(45.678, 1)` | 45.6   |
| `MOD()`   | `MOD(10,3)`        | 1      |
| `CEIL()`  | `CEIL(4.2)`        | 5      |
| `FLOOR()` | `FLOOR(4.9)`       | 4      |
| `POWER()` | `POWER(2,3)`       | 8      |

---

### 🟦 Date Functions

| Function                             | Example                  | Description                |
| ------------------------------------ | ------------------------ | -------------------------- |
| `SYSDATE`                            | —                        | Current date & time        |
| `ADD_MONTHS(date, n)`                | `ADD_MONTHS(SYSDATE, 6)` | Adds months                |
| `MONTHS_BETWEEN(d1,d2)`              | —                        | Difference in months       |
| `NEXT_DAY(date, 'MONDAY')`           | —                        | Next Monday                |
| `LAST_DAY(date)`                     | —                        | Last day of month          |
| `ROUND(date,'MONTH')`                | —                        | Rounds to nearest month    |
| `TRUNC(date,'YEAR')`                 | —                        | Truncates to start of year |
| `TO_DATE('25-08-2025','DD-MM-YYYY')` | —                        | Converts string to date    |
| `TO_CHAR(date,'DD-Mon-YYYY')`        | —                        | Converts date to string    |

---

## 🔄 4️⃣ JOINS

### 🟢 INNER JOIN

Show only matching records.

```sql
SELECT e.name, d.department_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id;
```

### 🟡 LEFT JOIN

All rows from left table + matches from right.

```sql
SELECT e.name, d.department_name
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.dept_id;
```

### 🔵 RIGHT JOIN

All rows from right + matches from left.

### 🔶 FULL OUTER JOIN

All rows from both sides.

---

## 🧩 5️⃣ SUBQUERIES

### 🔹 Single-row Subquery

```sql
SELECT name FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);
```

### 🔹 Multiple-row Subquery

```sql
SELECT name FROM employees
WHERE dept_id IN (SELECT dept_id FROM departments WHERE location = 'Pune');
```

### 🔹 Correlated Subquery

```sql
SELECT name, salary
FROM employees e
WHERE salary > (SELECT AVG(salary) FROM employees WHERE department = e.department);
```

---

## 🪟 6️⃣ VIEWS

A view is a **virtual table** (a saved SQL query).

### 🔹 CREATE VIEW

```sql
CREATE VIEW high_salary_emps AS
SELECT name, department, salary
FROM employees
WHERE salary > 50000;
```

### 🔹 USE VIEW

```sql
SELECT * FROM high_salary_emps;
```

### 🔹 MODIFY VIEW

```sql
CREATE OR REPLACE VIEW high_salary_emps AS
SELECT name, salary FROM employees WHERE salary > 60000;
```

### 🔹 DROP VIEW

```sql
DROP VIEW high_salary_emps;
```

---

## 💡 Extra: Commonly Used Clauses

| Clause                  | Example                         | Meaning               |
| ----------------------- | ------------------------------- | --------------------- |
| `ORDER BY`              | `ORDER BY salary DESC`          | Sort                  |
| `GROUP BY`              | `GROUP BY department`           | Aggregate by group    |
| `HAVING`                | `HAVING AVG(salary) > 50000`    | Filter after grouping |
| `DISTINCT`              | `SELECT DISTINCT department`    | Remove duplicates     |
| `BETWEEN`               | `WHERE marks BETWEEN 60 AND 80` | Range                 |
| `LIKE`                  | `WHERE name LIKE 'S%'`          | Pattern match         |
| `IS NULL / IS NOT NULL` | `WHERE salary IS NULL`          | Check nulls           |

---

## 🎯 7️⃣ Example Quick Queries

```sql
-- 1. Convert emp_id to string and concatenate with name
SELECT TO_CHAR(emp_id) || '-' || name AS emp_name_code FROM employees;

-- 2. Find number of months since hire date
SELECT name, MONTHS_BETWEEN(SYSDATE, hire_date) FROM employees;

-- 3. Extract first 3 letters of department
SELECT SUBSTR(department,1,3) FROM employees;

-- 4. Replace IT with Information Technology
SELECT REPLACE(department,'IT','Information Technology') FROM employees;
```

---
