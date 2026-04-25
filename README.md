# Paint for Kids
---

# Project Description

**Paint for Kids** is a colorful, kid-friendly drawing application that allows children to:
- Draw various geometric figures (Rectangle, Square, Triangle, Hexagon, Circle)
- Fill them with different colors
- Perform editing operations (Select, Swap, Rotate, Delete, Copy, Cut, Paste)
- Save and Load their drawings
- Play educational mini-games: **Matching Pairs** and **Missing Shapes**

The application is built using **strict Object-Oriented Programming (OOP)** principles, following the provided class framework and design (ApplicationManager, CFigure hierarchy, Action hierarchy, Input/Output classes).

It features two main modes:
- **Draw Mode** — Full drawing and editing tools
- **Play Mode** — Educational games to teach shapes and colors

---

# Key Features

### Draw Mode
- Add figures (Rectangle, Square, Triangle, Hexagon, Circle)
- Select (single & multiple) with magenta highlight
- Swap two selected figures
- Rotate figure (90° clockwise/counterclockwise)
- Delete selected figure(s)
- Clear All
- Copy / Cut / Paste
- Save Graph / Load Graph
- Switch to Play Mode
- Exit
- Undo / Redo
- 
### Play Mode
- **Matching Pairs**: Match identical shapes or colors
- **Missing Shapes**: Identify randomly hidden shapes
- Score tracking with restart functionality

---

# Technologies & Design

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (Inheritance, Polymorphism, Virtual Functions)
- **Key Classes**:
  - `ApplicationManager` (Maestro class)
  - `CFigure` (Base class for all shapes)
  - `Action` (Base class for all operations)
  - `Input` & `Output` (Handle all GUI interactions)
- Uses a provided open-source graphics library for drawing and mouse input

**Important**: The project strictly follows the given class responsibilities and design to demonstrate proper OOP.

---


# How to Build & Run

1. Open the project in **Visual Studio** (recommended)
2. Build the solution
3. Run the executable

All interactions are done via **mouse clicks** on the toolbar icons (no console input except for specific cases like color choice or missing shape name).

---

# Program Modes

- **Draw Mode**: Toolbar with drawing & editing tools
- **Play Mode**: Educational games using the drawn figures

You can switch between modes at any time.

---

# File Format (Save/Load)

The application saves/loads drawings in a simple text format:
- First line: Number of figures
- Each following line: `TYPE ID parameters... COLOR`

Example:
5
RECT 1 100 200 17 30 BLUE
TRIANG 3 10 20 70 30 220 190 BLACK
...
text---

# Sample Files

- `Sample-Graphs/` folder contains:
  - At least 3 different saved graph files (`.txt`)
  - Screenshots of the graphs
  - Screenshot of Play Mode in action

---

# Authors

- Yahia Ahmed Shaheen
- Maya Ramy Essam
- 
---

