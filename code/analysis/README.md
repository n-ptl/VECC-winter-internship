# Analysis Macros

This directory contains the ROOT/C++ macros used for the analysis performed during the VECC winter internship.

## `momentum.C`

Compares particle distributions generated using **UrQMD** and **SMASH** within the CBMROOT framework.

The macro analyzes:

* Pseudorapidity (η)
* Transverse momentum (pT)
* Azimuthal angle (φ)
* Particle-species yields
* pT distributions across different η intervals
* SMASH/UrQMD ratios

## `read_pdg_code.C`

Analyzes simulated particle tracks and detector hits in the **MUCH** detector.

The macro studies:

* Particle identification using PDG codes
* Primary and secondary particles
* MUCH station and layer information
* Detector hit distributions
* Particle positions and momentum
* Primary/secondary contributions across detector layers
* Pseudorapidity distributions

Both macros were developed using **ROOT/C++ and CBMROOT** as part of the VECC winter internship project.
