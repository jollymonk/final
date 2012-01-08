Molly Junck (mjunck)

Ray README

The recursion limit MAX_RAY_DEPTH  is the max number of times one can recur to calculate a reflection, it is set in line 16 of RayScene.h

I implemented Multithreading in Intersect, to change the number of threads, change the constant NUM_THREADS in line 16 of RayScene.h.

Naming Convention:

p_<foo>		a point
v_<foo>		a vector
mat_<foo>	a matrix
<foo>_ws	world space
<foo>_os	object space

Almost all of my functionality is in RayThread, I tried to pull out the main methods as much as possible to make things as straight-forward as possible, for example calcReflections(...), calcSpecular(...), etc., all take care of their functionality.  The method castRay(...) now takes in a depth parameter and is used recursively for reflections.

Known Bug:

The QFileDialog (a.k.a. Open File window) has been known to hang, as if it can?t access the file system.  If it does, I have found that closing the window and relaunching it has done the trick, as annoying as that is.  I?ve tried a bunch of stuff and I?m not really sure why it does it, and my fix currently opens you up in the current directory (also kind of annoying), but so long as you have test directories bookmarked, it?s a lot less painful.  

The program sometimes crashes after a scene is loaded and you try to paint on it with the Brush.  For whatever reason, the Brush doesn?t register that Canvas2D size has changed.  It was barely a problem and since it isn?t really the focus of the project, I am not worrying about it too much.  

Reflections are slow.  Lowering the number of recursions helps some depending on the scene, but I didn?t correctly get it to stop recurring once the contribution is minimal.  The output is correct and pretty, though, and multithreading helps.  