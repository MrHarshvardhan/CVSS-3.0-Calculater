# CVSS 3.0 Calculator

![Python](https://img.shields.io/badge/Python-3.6%2B-blue)

CVSS (Common Vulnerability Scoring System) is a standard for assessing and rating the severity of security vulnerabilities. This is a simple command-line CVSS 3.0 Calculator that allows users to calculate the CVSS scores based on provided metrics.

## Features

- Calculates the Base, Temporal, and Environmental CVSS scores.
- Provides the CVSS 3.0 Vector output in the desired format.
- User-friendly interface with simple questions for input.

## Requirements

- Python 3.6 or higher

## Usage

1. Clone the repository to your local machine:


2. Run the CVSS Calculator:


3. Answer the questions asked for each CVSS metric, and the script will display the Base, Temporal, and Environmental scores along with the CVSS Vector output.

## Example

Welcome to CVSS 3.0 Web Application Calculator
Is the Attack Vector (options: Network [N], Adjacent [A], Local [L], Physical [P]): N
Is the Attack Complexity (options: Low [L], High [H]): L
Are Privileges Required? (options: None [N], Low [L], High [H]): N
Is User Interaction Required? (options: None [N], Required [R]): N
Is the Scope (options: Unchanged [U], Changed [C]): C
Is the Confidentiality Requirement High, Low, or None? High
Is the Integrity Requirement High, Low, or None? High
Is the Availability Requirement High, Low, or None? High

Base Score: 9.1
Temporal Score: 9.1
CVSS v3.0 Vector: CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:C/C:H/I:H/A:H

Do you want to calculate another vulnerability? (yes/no): no
