/**
 @file    Settings.h

 @author  Evan Wallace (edwallac@cs.brown.edu)
 @author  Ben Herila (ben@herila.net)
 @date    9/1/2010

 @brief
    This file contains various settings and enumerations that you will need to
 use in the various assignments. The settings are bound to the GUI via static
 data bindings.

**/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <CS123Algebra.h>

// fountain settings
#define NUM_EMITTERS 400
#define DROP_FREQ 1
#define FTN_WIDTH 3.0
#define FTN_TOP 1.5             //top of fountain in world coords
#define FTN_BOTTOM -1.9         //bottom of fountain in world coords
#define FTN_LEFT -1.5           //left wall of fountain in world coords
#define FTN_DEPTH 0.0           //depth of fountain in world coords
#define FRAMES_PER_SEC 30.0

//camera settings
#define CAM_MAX_DIST 5.0
#define CAM_MIN_DIST 0.04
#define DROPLET_THRESHHOLD 3.0 //threshold at which we start rendering droplets instead of particles

//drop settings
#define MAX_CONSEC_DROPS 5
#define X_VARIATION .02
#define Y_VARIATION .005
#define NUM_STRIPES 5
#define MIN_STACKS 2
#define MIN_SLICES 3
#define MAX_SLICES 15
#define DROP_SIZE 0.008
#define ACCELERATION 0.0005
#define SHAPE_COMPLEXITY_THRESHHOLD 2.0

//interaction settings
#define CLICK_RADIUS 20

// Enumeration values for the fill modes from which the user can choose in the GUI.
enum FillMode
{
    FILL_POINTS,
    FILL_WIREFRAME,
    FILL_SHADED,
    NUM_FILL_MODES
};

// Enumeration values for the Shapes that the user can select in the GUI.
enum ShadingMode
{
    SHADING_FLAT,
    SHADING_SMOOTH,
    NUM_SHADING_MODES
};

enum FountainPattern
{
    PATTERN_CONTINUOUS,
    PATTERN_FAN,
    PATTERN_CHECKERED,
    PATTERN_ZEBRA,
    PATTERN_STRIPED,
    PATTERN_OTHER,
    NUM_PATTERNS
};

enum DrawType
{
    DRAW_PARTICLES,
    DRAW_DROPLETS
};


/*! Enumeration values for the different interaction modes that the user
  can use. You'll implement these in the Modelling lab. */
enum InteractionMode
{
    OBJ_FILM_PLANE_TRANSLATE,
    OBJ_LOOK_VECTOR_TRANSLATE,
    OBJ_TRACKBALL_ROTATE,
    OBJ_UNIFORM_SCALE,
    NUM_OBJ_TOOLS
};

//! Enumeration values for the two tabs (2D, 3D) at the bottom of the Window.
enum UITab
{
    TAB_2D,
    TAB_3D,
    NUM_TABS
};

//! Enumeration values for the currently selected scene type
enum SceneMode
{
    SCENEMODE_SHAPES,
    SCENEMODE_SCENEVIEW
};

//! Enumeration values for the currently selected camera type
enum CameraMode
{
    CAMERAMODE_ORBIT,
    CAMERAMODE_CAMTRANS
};

/*!

    @struct Settings
    @brief  Stores application settings for the CS123 GUI.

        You can access all app settings through the "settings" global variable.
    The settings will be automatically updated when things are changed in the
    GUI (the reverse is not true however: changing the value of a setting does
    not update the GUI).

*/
struct Settings
{
    /*! Loads settings from disk, or fills in default values if no saved
      settings exist.  */
    void loadSettingsOrDefaults();

    //! Saves the current settings to disk.
    void saveSettings();

    // Camtrans
    bool useOrbitCamera;        /// Use the built-in orbiting camera instead of the Camtrans perspective camera
    REAL cameraPosX;
    REAL cameraPosY;
    REAL cameraPosZ;
    REAL cameraRotU;
    REAL cameraRotV;
    REAL cameraRotN;
    REAL cameraFov;             /// The camera's field of view. The field of view is twice the height angle.
    REAL cameraNear;            /// The distance from the camera's position to the near clipping plane.
    REAL cameraFar;             /// The distance from the camera's position to the far clipping plane.

    // Modeler
    int objTool;                /// The currently selected modeler tool. @see InteractionMode

    int getSceneMode();
    int getCameraMode();

    int currentTab;

    int fillMode;      // The drawing mode used to draw primitives.
    bool lightingEnabled;      // Enable or disable lighting.
    int shadingMode;    // The shading mode to be used.
    float dropSlowDown;  //varies from 0 to 1, stopped to full speed
    float cameraZ;
    int num_sphere_divs;
    int sphere_stacks;
    int sphere_slices;
    int draw_type;
    int fountain_pattern;

};

// The global Settings object, will be initialized by MainWindow
extern Settings settings;

#endif // SETTINGS_H
