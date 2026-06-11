# Program 4 – Movie Store Management System
**CSS 343 | Group 4 | Giselle McNeil, Nash Kumia**
**Instructor: Wooyoung Kim | May 19th, 2026**

---

## Overview

This program simulates a local movie store management system. It allows 
the store to manage its movie catalogue, maintain customer accounts, and 
log and execute transactions. The system reads all data from input files 
and processes commands to borrow, return, and display inventory or 
customer history.

---

## How to Compile and Run

```bash
g++ -std=c++17 *.cpp -o Program4
./Program4
```

The program reads from three input files that must be in the same 
directory as the executable:
- `data4movies.txt` — movie inventory data
- `data4customers.txt` — customer account data
- `data4commands.txt` — transaction commands to process

---

## Input File Formats

### Movies (`data4movies.txt`)
Each line represents one movie. Format varies by genre:

| Genre | Format |
|---|---|
| Comedy (F) | `F, stock, director, title, year` |
| Drama (D) | `D, stock, director, title, year` |
| Classic (C) | `C, stock, director, title, majorActor month year` |

Invalid genre codes (e.g. Z) are discarded with an error message.

### Customers (`data4customers.txt`)
customerID lastName firstName

### Commands (`data4commands.txt`)
| Command | Format | Description |
|---|---|---|
| `B` | `B customerID D genre ...` | Borrow a movie |
| `R` | `R customerID D genre ...` | Return a movie |
| `I` | `I` | Display full inventory |
| `H` | `H customerID` | Display customer transaction history |

---

## System Architecture

The program is organized into three main subsystems connected 
through a central `Company` class:

### 1. Inventory System
- `Inventory` → `MovieList` → three genre-specific sorted sets
- Movies are stored in sets sorted by genre-specific criteria:
  - **Comedy**: sorted by title, then year
  - **Drama**: sorted by director, then title
  - **Classic**: sorted by release date, then major actor
- `MovieFactory` handles movie object creation at runtime

### 2. Customer Data System
- `CustomerData` — custom hash table using double hashing
  - `hash1(ID) = ID % capacity`
  - `hash2(ID) = 5 - (ID % 5)`
  - Probe sequence: `(hash1 + i * hash2) % capacity`
  - Resizes to next prime when load factor exceeds 50%
- `Customer` — stores ID, name, and full transaction history vector

### 3. Transaction System
- `Transaction` — abstract base class
- `BorrowTransaction` — finds real inventory movie, decrements stock
- `ReturnTransaction` — validates prior borrow, increments stock
- All transactions stored in customer history vector
- `TransactionFactory` handles transaction object creation

---

## Error Handling

| Situation | Behavior |
|---|---|
| Invalid command code | Print error, skip line, continue |
| Invalid media type | Print error, skip line, continue |
| Invalid genre code | Print error, skip line, continue |
| Invalid customer ID | Print error, skip line, continue |
| Movie not found in inventory | Print error, skip line, continue |
| Borrow when out of stock | Print error; suggest alternate actor for Classics |
| Return of never-borrowed movie | Print error, discard command |

The program never crashes on bad input. All errors are caught, 
reported, and discarded so processing continues normally.

---

## ClassicMovie Special Behavior

Multiple copies of a Classic movie may share the same title but have 
different major actors. Each actor version tracks its own individual 
stock. Borrowing one actor version does not affect the other. When a 
requested actor version is out of stock, available alternatives are 
suggested. The inventory displays each Classic title grouped together 
with individual and cumulative stock counts.

---

## Implementation Notes

- `Movie` is an abstract base class — cannot be instantiated directly
- Each movie subclass implements `display()`, `operator<`, and `operator==`
- Custom comparator structs control sorted insertion into `std::set`
- `Transaction` uses a clone pattern — each transaction owns its own 
  movie copy for history display while `execute()` modifies the real 
  inventory object
- `CustomerData` uses open addressing with double hashing — no STL 
  containers other than array

---

## Testing

- Unit tested each class in isolation before integration
- Inventory tested for sorted insertion, retrieval, and display
- Hash table tested for collision handling, resize, and rehash
- Transaction tested for stock changes, history, and error cases
- Full integration tested using provided input files
- Edge cases tested including zero stock, duplicate entries, 
  Classic movies with multiple actors, and forced hash collisions

---

## File Structure
```
├── driver.cpp
├── Company.h / Company.cpp
├── Inventory.h / Inventory.cpp
├── MovieList.h / MovieList.cpp
├── Movie.h / Movie.cpp
├── ComedyMovie.h / ComedyMovie.cpp
├── DramaMovie.h / DramaMovie.cpp
├── ClassicMovie.h / ClassicMovie.cpp
├── Transaction.h / Transaction.cpp
├── BorrowTransaction.h / BorrowTransaction.cpp
├── ReturnTransaction.h / ReturnTransaction.cpp
├── Customer.h / Customer.cpp
├── CustomerData.h / CustomerData.cpp
├── MovieFactory.h / MovieFactory.cpp
├── TransactionFactory.h / TransactionFactory.cpp
├── data4movies.txt
├── data4customers.txt
└── data4commands.txt
```
