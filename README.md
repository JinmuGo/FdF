# FdF

![fdf](https://github.com/user-attachments/assets/72f71fe2-f3aa-4912-b802-f6d27f459e45)

**FdF** is a 42cursus graphics project that reads a 3D height map from a file and renders a 2D wireframe projection using the MiniLibX graphics library. It is an introduction to basic computer graphics, coordinate transformations, and user interaction.

## Features

- Isometric and top-down projections of 3D height maps
- Real-time keyboard controls for:
  - Rotation on X, Y, Z axes (`Z/X`, `A/S`, `Q/W`)
  - Zoom in/out (`K` / `J`)
  - Height scaling (`+` / `-`)
  - Preset views (`I`, `V`)
  - Display options (toggle dots, lines, axes, extra lines)
  - Auto rotation toggle and planet mode
- Support for color gradients based on height
- Responsive redraw (`F` key) and Shift state handling

## Folder Structure

```text
src/
├── fdf.c               # Entry point of the program
├── draw/               # Drawing logic (map rendering, projection, edit)
├── hooks/              # Event handling (keyboard, mouse, etc.)
├── includes/           # Header files (global declarations, utilities)
├── lib/                # (Reserved for external or internal libraries)
├── utils/              # Utility modules (color, matrix, error, printing, etc.)
└── Makefile            # Top-level build script
```

## Getting Started

### Prerequisites

- macOS with X11 or Linux with X11
- `gcc`, `make`
- MiniLibX (provided within the project or install via 42's resources)

### Compilation

```bash
make
````

### Usage

```bash
./fdf [map_file.fdf]
```

Example:

```bash
./fdf maps/42.fdf
```

## Map Format

The `.fdf` map file should consist of space-separated integers representing height (z-values), optionally with color values in hexadecimal:

```text
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

<img width="1552" alt="42" src="https://github.com/user-attachments/assets/1eb99d09-3df4-481f-9d61-ab8c5ea38613" />

## Controls

| Key             | Action                                              |
|------------------|-----------------------------------------------------|
| `ESC`            | Exit the program                                    |
| `Z` / `X`        | Rotate on X-axis (positive / negative)              |
| `A` / `S`        | Rotate on Y-axis (positive / negative)              |
| `Q` / `W`        | Rotate on Z-axis (positive / negative)              |
| `J` / `K`        | Zoom out / Zoom in                                  |
| `+` / `-`        | Increase / Decrease height (z-axis scaling)         |
| `I`              | Set isometric view                                  |
| `V`              | Set top-down view                                   |
| `R`              | Toggle auto-rotation                                |
| `P`              | Toggle planet mode (resets Z-rotation)              |
| `1`              | Toggle display of dots                              |
| `2`              | Toggle display of lines                             |
| `3`              | Toggle display of axis                              |
| `E`              | Toggle extra line (1)                               |
| `D`              | Toggle extra line (2)                               |
| `F`              | Force redraw (only outside planet mode)            |
| `Shift`          | Activate shift mode (internal state toggle)         |

## Project Goals

- Learn basic computer graphics (projection, scaling, rotation)
- Manipulate 3D points in a 2D environment
- Gain experience using the **MiniLibX** graphics library
- Understand user input and real-time rendering loops

## Acknowledgements

This project is part of the [42 Cursus](https://42.fr/) core graphics curriculum. The goal is to build a visually interactive program while learning low-level graphics programming and coordinate transformation logic.

---

*Developed as part of the 42Seoul curriculum.*
