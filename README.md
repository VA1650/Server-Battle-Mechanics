# ⚔️ Server Warfare: Console Strategy

A turn-based tactical game implemented in C++. This project began as a simple game in 2021 and has evolved into a showcase of fundamental game design and AI programming principles.

## 🚀 Project Evolution

The repository preserves the commit history, reflecting the transition from linear procedural code to a structured architecture:

* **v1.0 (Legacy):** Basic logic embedded within `main()`, relying on `rand()`.
* **v2.0 (Refactored):** Introduction of data structures, function decomposition, and input validation.
* **v2.1 (Smart AI):** Implementation of a heuristic AI with move-memory and ANSI-color visualization.

## 🧠 AI Features

The AI in this game is more than just a random number generator. It utilizes:

* **Lethal Range Priority:** Prioritizes searching for nodes that can be neutralized in a single turn.
* **Counter-Defense Logic:** The bot remembers the player's previous defensive move and has an 80% probability of attacking unprotected nodes.
* **Smart Fortification:** Prioritizes the defense of its own most vulnerable servers.

## 🛠 Technology Stack

* **Standard:** C++17 (utilizing Structured Bindings for AI move returns).
* **Interface:** CLI using ANSI sequences for event color-coding and visualization.
