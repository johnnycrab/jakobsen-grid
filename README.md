# jakobsen-grid
Move a grid with Jakobsen algorithm


# Writing grid displays

One has the possibility to simply draw own versions of the current state of the object. 

![screen1](https://raw.githubusercontent.com/johnnycrab/jakobsen-grid/master/screen1.png)
![screen2](https://raw.githubusercontent.com/johnnycrab/jakobsen-grid/master/screen2.png)
![screen3](https://raw.githubusercontent.com/johnnycrab/jakobsen-grid/master/screen3.png)
![screen4](https://raw.githubusercontent.com/johnnycrab/jakobsen-grid/master/screen4.png)

---

Here's how to do it:

### 1. Create the grid display class

Create a class that extends `GridDisplay`:

```c++
#include <stdio.h>
#include "GridDisplay.h"

class Circles_GridDisplay : public GridDisplay { // make a public extension
private:

public:
    Circles_GridDisplay():GridDisplay() {}; // don't forget to add a standard constructor which calls parent constructor
    
    void setup(); 	// REQUIRED
    void update(); 	// REQUIRED
    void draw(); 	// REQUIRED
};
```

The class needs to declare and define the functions `setup`, `update` and `draw`.

### 2. Define setup, update, draw

- **setup** gets called after a grid has been initially set up, i.e. all points have been created and their positions set initially.
- **update** gets called after each update iteration of the grid, that is, when the points start to attract/reject other point masses.
- **draw** is the function which should handle all drawing stuff and gets called in the app's `draw`-method.

**A class that is derived from `GridDisplay` has access to several private members:**

- `Grid* grid`: Pointer to the current grid. Normally one only needs access to the position of the point masses. A point mass at a specified (x,y)-position (where x is number of row, y number of column) can be accessed via `grid->pointMassAt(x,y)`. This returns a copy of the `PointMass` at the position (so the original grid cannot be altered). To get the position (returns `ofVec3f`) of such a point mass, call  `grid->pointMassAt(x,y).getPosition()`
- `int gridWidth`: The number of rows of the current grid
- `int gridHeight`: The number of columns of the current grid
- `float gridPointDistance`: This defines the distance a point mass has to its left,right,upper,lower neighbor.

Example (in e.g. `Circles_GridDisplay.cpp`):

```c++
#include "Circles_GridDisplay.h"

// we do not need to setup anything, as we don't need to keep track
void Circles_GridDisplay::setup() {
}

// same here -> no update
void Circles_GridDisplay::update() {
}

void Circles_GridDisplay::draw() {
    ofClear(0,0,0,255);
    ofSetColor(56,112,188);
    ofFill();
    
    float radius = gridPointDistance / 4;

	// here we iterate over all points    
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            PointMass p = grid->pointMassAt(i,j); // we get a copy of the point mass
            ofDrawCircle(p.getPosition(), radius); // access the position and draw a circle at its place
        }
    }
}
```

### 3. Register the display on the app

In `ofApp.h`, create a member which will hold an instance of your class, e.g. 

```c++
Circles_GridDisplay circlesDisplay;
```

In `ofApp::setup`, register the display in the following way right before `setupShape`:

```c++
    // REGISTER GRID DISPLAYS HERE!
    
    registerGridDisplay(&circlesDisplay, "circles"); // you need to pass the address of to the function!
    // ---
    setupShape();
```

The second argument is a name, as each display automatically gets a check box to toggle the drawing.

