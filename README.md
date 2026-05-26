# Program 4 – Movie Store Management System
**CSS 343 | Group 4 | Giselle McNeil, Nash Kumia**
**Instructor: Wooyoung Kim | May 19th, 2026**

---

## Overview

This program simulates a local movie store management system. It allows the store to manage its media catalogue, maintain customer accounts, and log and execute transactions. The system reads all data from input files and processes commands to borrow, return, and display inventory or customer history.

---

## Features

- Load and store a movie inventory organized by genre (Comedy, Drama, Classic)
- Load and manage customer accounts using a custom hash table
- Process transactions: Borrow, Return, display Inventory, display customer History
- Sorted inventory display per genre
- Customer transaction history displayed newest to oldest
- Graceful error handling — invalid input is reported and discarded without crashing

---

## How to Compile and Run

```bash
g++ -std=c++17 -o store *.cpp
./store
```

The program reads from three input files:
- `data4movies.txt` — movie inventory data
- `data4customers.txt` — customer account data
- `data4commands.txt` — transaction commands to process

---

## Input File Formats

### Movies (`data4movies.txt`)
Each line represents one movie. Format varies by genre:

| Genre | Format |
|---|---|
| Comedy (F) | `F stock director year title` |
| Drama (D) | `D stock director title` |
| Classic (C) | `C stock director title month year majorActor` |

### Customers (`data4customers.txt`)
```
customerID lastName firstName
```

### Commands (`data4commands.txt`)
| Command | Description |
|---|---|
| `B customerID mediaType genre ...` | Borrow a movie |
| `R customerID mediaType genre ...` | Return a movie |
| `I` | Display full inventory |
| `H customerID` | Display customer transaction history |

---

## System Architecture

The program is organized into three main subsystems connected through a central `Company` class:

### 1. Inventory System
- `Inventory` → `MovieList` → genre-specific sorted sets
- Movies are stored in sets sorted by genre-specific criteria:
  - **Comedy**: sorted by title, then year
  - **Drama**: sorted by director, then title
  - **Classic**: sorted by release date, then major actor

### 2. Customer Data System
- `CustomerData` — custom hash table using double hashing for collision resolution
- `Customer` — stores ID, name, and full transaction history

### 3. Transaction System
- `BorrowTransaction` — decrements stock
- `ReturnTransaction` — increments stock
- All transactions are stored in the customer's history vector

### Factory Classes
`MovieFactory`, `TransactionFactory`, `MediaFactory`, and `MediaListFactory` handle object creation at runtime to support extensibility for future media types or transaction types.

---

## Error Handling

| Situation | Behavior |
|---|---|
| Invalid command code | Print error, skip line, continue |
| Invalid media type | Print error, skip line, continue |
| Invalid customer ID | Print error, skip line, continue |
| Movie not found in inventory | Print error, skip line, continue |
| Borrow when out of stock | Print out-of-stock message; for Classics, suggest alternate actor |
| Return of never-borrowed movie | Print error, discard command |

The program will never crash on bad input. All errors are caught, reported, and discarded so processing continues normally.

---

## ClassicMovie Special Behavior

Multiple copies of a Classic movie may share the same title but have **different major actors**. Each actor version tracks its own individual stock, and a cumulative total is also maintained. Borrowing one actor's version does not affect availability of the alternate version.

---

## Implementation Order

The system was built bottom-up in the following order to minimize dependencies at each stage:

1. Core abstract classes (`Media`, `Movie`, `Transaction`)
2. Movie subclasses and comparators (`ComedyMovie`, `DramaMovie`, `ClassicMovie`)
3. Inventory storage system (`Inventory`, `MediaList`, `MovieList`)
4. Customer system (`Customer`, `CustomerData` hash table)
5. Company class integration
6. Factory classes
7. Transaction subclasses (`BorrowTransaction`, `ReturnTransaction`)
8. Command processing (`processCommands`, `executeTransaction`)

---

## Testing Summary

- **Unit testing** was performed on each class in isolation before integration
- **Inventory testing** verified sorted insertion, correct retrieval, and display formatting
- **Customer/HashTable testing** verified hashing distribution, collision handling, resize, and rehash behavior
- **Transaction testing** verified stock changes, history updates, and error cases
- **Full integration testing** used the provided input files to verify end-to-end behavior
- **Edge cases tested** include zero-stock movies, duplicate entries, ClassicMovies with multiple actors, forced hash collisions, and large input files

---

## File Structure

```
├── Company.h / Company.cpp
├── Inventory.h / Inventory.cpp
├── MediaList.h / MovieList.h / MovieList.cpp
├── Media.h / Movie.h
├── ComedyMovie.h / ComedyMovie.cpp
├── DramaMovie.h / DramaMovie.cpp
├── ClassicMovie.h / ClassicMovie.cpp
├── CustomerData.h / CustomerData.cpp
├── Customer.h / Customer.cpp
├── Transaction.h
├── BorrowTransaction.h / BorrowTransaction.cpp
├── ReturnTransaction.h / ReturnTransaction.cpp
├── MovieFactory.h / TransactionFactory.h
├── data4movies.txt
├── data4customers.txt
├── data4commands.txt
└── README.md
```
