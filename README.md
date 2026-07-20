# Zapp – Pleasure Park Guest Management System

Zapp is a C++ system for managing guest movement around a pleasure park using a network of areas connected by bridges. Guests carry a personalised card that must be used (and loaded with credits) to cross bridges between areas. This build targets **Fantasia Pleasure Park**, with a view to rolling the system out to other ZAPP-managed parks.

## Overview

A park is modelled as a set of **areas** (leisure facilities), connected by **bridges**. Each bridge crossing costs a number of credits, which are deducted from a guest's **card**. Certain conditions must be satisfied before a card can be used to cross a bridge (e.g. card type, age restrictions, or other park-specific rules). Credits can be purchased and loaded onto a card at any time.

## Features

- Model a park as a graph of areas linked by bridges
- Track bridge crossing costs and any conditions required before a crossing is permitted
- Support multiple card types with different behaviours/eligibility rules:
  - **Card** – base guest card
  - **ChildCard** – card type for younger guests, with its own crossing rules
  - **TouristCard** – card type for visiting guests, with its own crossing rules
- **Company** entity for managing cards issued on behalf of a group/organisation
- Load credits onto a card at any time
- Deduct credits automatically on a valid bridge crossing
- Simple console-based UI for interacting with the park (`parkUI`)

## Project Structure

```
Zapp/
├── area/                  # Area class — represents a single park location
│   ├── area.cpp
│   ├── area.h
│   └── bridge/            # Bridge class — connects two areas, holds cost/conditions
│       ├── bridge.cpp
│       └── bridge.h
├── card/                  # Card class hierarchy and related entities
│   ├── card.cpp
│   ├── card.h
│   ├── childcard.cpp
│   ├── childcard.h
│   ├── touristcard.cpp
│   ├── touristcard.h
│   ├── company.cpp
│   └── company.h
├── park/                  # Park orchestration and user interface
│   ├── park.cpp
│   ├── park.h
│   ├── parkUI.cpp
│   └── zapp.h             # Top-level interface
└── CMakeLists.txt
```

## Architecture

- **Area** – represents a single location/facility in the park. Holds references to the bridges connecting it to neighbouring areas.
- **Bridge** – connects two areas, storing the credit cost of a crossing and any conditions that must be met before it can be used.
- **Card** – base class for a guest's personalised card, tracking a credit balance and handling top-ups and deductions.
  - **ChildCard** – a `Card` subclass with rules/restrictions specific to child guests.
  - **TouristCard** – a `Card` subclass with rules/restrictions specific to tourist guests.
- **Company** – represents an organisation that can hold or manage cards (e.g. for group bookings).
- **Park** – owns the full set of areas and bridges, and coordinates card validation, bridge crossings, and credit transactions across the park.
- **ParkUI** – console interface layer for interacting with the park (making crossings, topping up credits, viewing park state).
- **zapp.h** – top-level interface tying the system together.

## Build Instructions

This project uses CMake.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Then run the produced executable from the `build` directory.

## Usage

Launch the program to bring up the park interface (`parkUI`), where you can:

1. View the park's areas and the bridges connecting them
2. Select a card and attempt a bridge crossing (subject to cost and any crossing conditions)
3. Load additional credits onto a card at any time

## Future Work

- Roll out the system to additional ZAPP-managed parks beyond Fantasia
- Persist park layouts, cards, and balances between sessions
- Expand condition-checking rules for bridge crossings
- Add automated tests for card, bridge, and park logic
