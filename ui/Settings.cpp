/*!

 Settings.h
 CS123 Support Code

 @author  Evan Wallace (edwallac)
 @date    9/1/2010

 This file contains various settings and enumerations that you will need to
 use in the various assignments. The settings are bound to the GUI via static
 data bindings.

**/

#include "Settings.h"
#include <QFile>
#include <QSettings>

Settings settings;

/*!
  @brief Loads the application settings, or, if no saved settings are available,
         loads default values for the settings. You can change the defaults here.
**/
void Settings::loadSettingsOrDefaults()
{
    // Set the default values below
    QSettings s;

    //fountain
    fillMode = s.value("fillMode", FILL_SHADED).toInt();
    lightingEnabled = s.value("lightingEnabled", true).toBool();
    shadingMode = s.value("shadingMode", SHADING_SMOOTH).toInt();
    fountain_pattern = s.value("fountainPattern", PATTERN_CONTINUOUS).toInt();
    dropSlowDown = 1.0;  //value to slow down, starts off realtime
    cameraZ = CAM_MAX_DIST;   //ranges from 0.02 to 5.0

    //set initial droplet size
    float complexity_inc = max(((SHAPE_COMPLEXITY_THRESHHOLD - cameraZ) / SHAPE_COMPLEXITY_THRESHHOLD), 0.0) * MAX_SLICES;

    settings.sphere_stacks = MIN_STACKS + (int) complexity_inc;
    settings.sphere_slices = MIN_SLICES + (int) complexity_inc;

    draw_type = DRAW_PARTICLES;

    // Shapes
    shapeType = s.value("shapeType", SHAPE_SPHERE).toInt();
    shapeParameter1 = s.value("shapeParameter1", 15).toInt();
    shapeParameter2 = s.value("shapeParameter2", 15).toInt();
    shapeParameter3 = s.value("shapeParameter3", 15).toDouble();
    useLighting = s.value("useLighting", true).toBool();
    drawWireframe = s.value("drawWireframe", true).toBool();
    drawNormals = s.value("drawNormals", false).toBool();

    // Camtrans
    useOrbitCamera = s.value("useOrbitCamera", true).toBool();
    cameraFov = s.value("cameraFov", 55).toDouble();
    cameraNear = s.value("cameraNear", 0.1).toDouble();
    cameraFar = s.value("cameraFar", 50).toDouble();

    // Ray
    useSuperSampling = s.value("useSuperSampling", false).toBool();
    numSuperSamples = s.value("numSuperSamples", 2).toInt();
    useAntiAliasing = s.value("useAntiAliasing", true).toBool();
    useShadows = s.value("useShadows", false).toBool();
    useTextureMapping = s.value("useTextureMapping", false).toBool();
    useReflection = s.value("useReflection", false).toBool();
    useRefraction = s.value("useRefraction", false).toBool();
    useMultiThreading = s.value("useMultiThreading", true).toBool();
    usePointLights = s.value("usePointLights", true).toBool();
    useDirectionalLights = s.value("useDirectionalLights", true).toBool();
    useSpotLights = s.value("useSpotLights", true).toBool();

    currentTab = s.value("currentTab", TAB_2D).toBool();

    // These are for computing deltas and the values don't matter, so start all dials in the up position
    cameraPosX = 0;
    cameraPosY = 0;
    cameraPosZ = 0;
    cameraRotU = 0;
    cameraRotV = 0;
    cameraRotN = 0;
}

void Settings::saveSettings()
{
    QSettings s;

    s.setValue("fillMode", fillMode);
    s.setValue("lightingEnabled", lightingEnabled);
    s.setValue("shadingMode", shadingMode);
    s.setValue("fountainPattern", fountain_pattern);

    // Camtrans
    s.setValue("useOrbitCamera", useOrbitCamera);
    s.setValue("cameraFov", cameraFov);
    s.setValue("cameraNear", cameraNear);
    s.setValue("cameraFar", cameraFar);

    s.setValue("currentTab", currentTab);
}

int Settings::getSceneMode()
{
    if (this->useSceneviewScene)
        return SCENEMODE_SCENEVIEW;
    else
        return SCENEMODE_SHAPES;
}

int Settings::getCameraMode()
{
    if (this->useOrbitCamera)
        return CAMERAMODE_ORBIT;
    else
        return CAMERAMODE_CAMTRANS;
}
