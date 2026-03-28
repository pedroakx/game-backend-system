# 🎮 Game Backend System

## 📌 Overview

This project is a simple **game backend architecture** combining **C++ (performance layer)** and **Python (API layer)**.

It simulates a matchmaking system with rating calculation (ELO).

---

## 🧠 Architecture

```
Client → FastAPI → C++ Server → Game Logic
```

---

## ⚙️ Tech Stack

* C++
* Python (FastAPI)
* Docker
* CMake

---

## 🚀 Features

* Player queue simulation
* ELO rating system
* API endpoint for matchmaking
* Modular backend architecture

---

## 🛠️ How to Run

### With Docker

```bash
docker-compose up --build
```

### Without Docker

#### Run C++ server:

```bash
cd server
cmake .
make
./server 1 1200
```

#### Run API:

```bash
cd api
pip install fastapi uvicorn
uvicorn main:app --reload
```

---

## 📡 API Endpoints

### POST /queue

```json
{
  "player_id": 1,
  "rating": 1200
}
```

---

## 📈 Future Improvements

* Replace subprocess with gRPC
* Add Redis queue system
* Persistent database (PostgreSQL)
* Real matchmaking system

---

## 👤 Author

Your Name
