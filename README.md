A simple RPG battle system made in C++.

A project I worked on for a few weeks to revisit programming design patterns. The goal here was to recreate the Pokemon battle system in a
way that would allow a developer to more easily add Moves with unique and complex rules. Many of the attacks in the pokemon games
depend on invisible statuses, like Focus Punch which requires the user to wait until the end of turn, and only attacks if they were not hit
by a damaging attack during that wait.

The project currently supports:
-Major status afflictions (Paralyzed, Frozen)
-Temporary move logic statuses (Focus Punch)
-Moves are built using a Component system, so moves can have Damage components, chance of StatChange components, chance of Status affliction components.
