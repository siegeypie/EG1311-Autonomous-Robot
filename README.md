
# EG1311 — Autonomous Obstacle-Course Robot

**National University of Singapore | EG1311 Design and Make | AY2026/27 Semester 1**


## Project Overview

As part of NUS EG1311 Design and Make (AY2026/27 Semester 1), our six-member team designed, built, and tested an autonomous robot capable of navigating an obstacle course and delivering a ping-pong ball over a wall.

### Design Requirements

The robot was required to:

- Autonomously traverse a 30 mm square bump and a triangular ramp.
- Approach a wall and launch a ping-pong ball over it.
- Return behind the initial bump.
- Complete the entire sequence within 30 seconds.
- Minimise weight to compete for an additional bonus point.

### Final Outcome

**Final Result: 9/10 points**

Our final robot successfully completed the obstacle course, including the ball-launching and return manoeuvres.

The design featured:

- A lightweight chassis constructed primarily from cardboard, paper, and ice-cream sticks.
- Two independently driven rear wheels.
- An Arduino-controlled drivetrain and servo-actuated ball launcher.
- Ultrasonic distance sensing for wall detection.
- A multi-stage differential-drive turning manoeuvre inspired by a conventional three-point turn.

The project involved extensive physical prototyping, iterative testing, mechanical troubleshooting, and redesign under tight time constraints.

Although our final design achieved the functional objectives, we did not secure the additional point awarded for minimum weight.



## Final Robot

The final robot was developed through repeated physical prototyping and testing. Rather than following a CAD-first design process, our team primarily relied on hands-on experimentation, making adjustments based on observed performance.

### Final Assembly

![Final Robot - Front View](media/final-robot-front.jpg)

![Final Robot - Rear View](media/final-robot-rear.jpg)

### Hardware Architecture

| Component | Implementation |
|---|---|
| Microcontroller | Arduino |
| Motor Driver | L293D |
| Drivetrain | Dual-motor rear-wheel drive |
| Distance Sensing | HC-SR04 ultrasonic sensor |
| Ball Launcher | Directly servo-actuated paper arm and cup |
| Chassis | Cardboard with reinforced structural supports |
| Wheels | Direct-drive rear wheels with passive front wheels |
| Power Supply | 6 × AA battery pack for motors; separate 9V battery for Arduino |

### Key Design Principles

**1. Mechanical Simplicity**

Earlier launcher and drivetrain designs introduced unnecessary mechanical complexity and potential failure points.

The final configuration directly coupled the driving wheels to their motors and the lightweight launching arm to its servo, reducing the number of moving components.

**2. Stability and Weight Distribution**

We adopted a wider, reinforced chassis and positioned the centre of gravity closer to the rear driving wheels.

This improved traction and reduced the tendency to topple while traversing the ramp.

**3. Modularity and Repairability**

The final assembly incorporated removable components secured through friction-fit connections and tape.

This allowed us to reposition or replace components quickly during testing, which proved especially valuable under tight time constraints.

The final configuration prioritised reliability and repeatability over the original goal of achieving the lowest possible weight.


## Engineering Development

## Challenges and Solutions

## Final Demonstration

## Contributions and Credits
