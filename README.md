# UrQMD vs SMASH Comparison for CBM-MUCH

## Overview

This repository contains the simulation and analysis work carried out during my winter internship at the **Variable Energy Cyclotron Centre (VECC), Kolkata**.

The project involved comparing the **UrQMD** and **SMASH** event generators within the **CBMROOT** framework for studies related to the **Muon Chamber (MUCH)** detector of the **Compressed Baryonic Matter (CBM)** experiment at FAIR.

## Project Objective

The study investigates differences in particle production predicted by UrQMD and SMASH and examines their implications for muon detection and dilepton studies in the CBM experiment.

## Simulation & Analysis

The simulation workflow involved:

* Event generation using **UrQMD** and **SMASH**
* Particle transport using **GEANT4**
* Detector digitization and hit formation
* Track reconstruction
* Muon selection
* Analysis of particle distributions

The comparison included **pseudorapidity (η)**, **transverse momentum (pT)**, and **pion production**, including a study across different pseudorapidity intervals.

## Key Result

The two generators show reasonable agreement in the softer, more central region. However, at **forward pseudorapidities (η > 3)**, SMASH predicts substantially higher particle production than UrQMD.

This highlights the importance of understanding event-generator differences when estimating particle and muon yields for CBM detector studies.

## Tools

* C++
* ROOT
* CBMROOT
* GEANT4
* UrQMD
* SMASH
* Linux / Ubuntu

## Internship

**Variable Energy Cyclotron Centre (VECC), Kolkata**
Winter Internship

**Research area:** Heavy-Ion Physics, Detector Simulation & Dilepton Analysis
