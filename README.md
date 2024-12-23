# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
<Add information to this section about the time you've taken for this task along with a professional changelist.>
* Fixed compiler issue caused by circular includes (5 min)
* Added basic screen shake effect when a life is lost (10 min)
* Implemented a seemingly abandoned mechanic of having powerups smoothly change colour over time (15 min)
* Made the game randomise the RNG seed on launch (2 min)
* Made the game work regardless of window size (15 min)
* Spent a lot of time inbetween staring at the code trying to figure out what to change/improve, code tests are definitely somewhere I need to improve