/*!

  Main window class for CS123. See the header file for additional documentation.

  @author Evan Wallace (evan.exe@gmail.com)
  @author Ben Herila (ben@herila.net)

**/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Databinding.h"
#include "Settings.h"
#include "scenegraph/SceneviewScene.h"
#include "camera/CamtransCamera.h"
#include "CS123XmlSceneParser.h"
#include <QSettings>
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>
#include <assert.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Make sure the settings are loaded before the UI
    settings.loadSettingsOrDefaults();

    ui->setupUi(this);

    // Restore the UI settings
    QSettings qtSettings("CS123");
    restoreGeometry(qtSettings.value("geometry").toByteArray());
    restoreState(qtSettings.value("windowState").toByteArray());

    // Resize the window because the window is huge since all docks were visible
    resize(1000, 600);

    // Bind the UI elements to their properties in the global Settings object, using binding objects to simplify
    // the code.  Each binding object connects to its UI elements and keeps the UI and its setting in sync.

    QList<QAction*> actions;

#define SETUP_ACTION(dock, key) \
    actions.push_back(ui->dock->toggleViewAction()); \
    actions.back()->setShortcut(QKeySequence(key));

    ui->menuToolbars->addActions(actions);
#undef SETUP_ACTION

    dataBind();

    // Hide the "stop rendering" button until we need it
    ui->rayStopRenderingButton->setHidden(true);

    // Make certain radio buttons switch to the 2D canvas when clicked.
    QList<QRadioButton*> a;
    foreach (QRadioButton *rb, a)
        connect(rb, SIGNAL(clicked()), this, SLOT(activateCanvas2D()));

    a.clear();
    a += ui->shapeTypeCone;
    a += ui->shapeTypeCube;
    a += ui->shapeTypeCylinder;
    a += ui->shapeTypeSpecial1;
    a += ui->shapeTypeSpecial2;
    a += ui->shapeTypeSpecial3;
    foreach (QRadioButton *rb, a)
        connect(rb, SIGNAL(clicked()), this, SLOT(activateCanvas3D()));

}

MainWindow::~MainWindow()
{
    foreach (DataBinding *b, m_bindings)
        delete b;
    delete ui;
}

void MainWindow::dataBind()
{
    // Brush dock

#define BIND(b) { DataBinding *_b = (b); m_bindings.push_back(_b); assert(connect(_b, SIGNAL(dataChanged()), this, SLOT(settingsChanged()))); }

    // Shapes dock
    BIND( BoolBinding::bindCheckbox(ui->showSceneviewInstead, settings.useSceneviewScene) )
    BIND( ChoiceBinding::bindRadioButtons(NUM_SHAPE_TYPES, settings.shapeType,
                                    ui->shapeTypeCube,
                                    ui->shapeTypeCone,
                                    ui->shapeTypeSphere,
                                    ui->shapeTypeCylinder,
                                    ui->shapeTypeSpecial1,
                                    ui->shapeTypeSpecial2,
                                    ui->shapeTypeSpecial3) )
    BIND( IntBinding::bindSliderAndTextbox(ui->shapeParameterSlider1, ui->shapeParameterTextbox1, settings.shapeParameter1, 1, 100) )
    BIND( IntBinding::bindSliderAndTextbox(ui->shapeParameterSlider2, ui->shapeParameterTextbox2, settings.shapeParameter2, 1, 100) )
    BIND( FloatBinding::bindSliderAndTextbox(ui->shapeParameterSlider3, ui->shapeParameterTextbox3, settings.shapeParameter3, 1, 100) )
    BIND( BoolBinding::bindCheckbox(ui->useLightingCheckbox, settings.useLighting) )
    BIND( BoolBinding::bindCheckbox(ui->drawWireframeCheckbox, settings.drawWireframe) )
    BIND( BoolBinding::bindCheckbox(ui->drawNormalsCheckbox, settings.drawNormals) )

    // Camtrans dock
    BIND( BoolBinding::bindCheckbox(ui->cameraOrbitCheckbox, settings.useOrbitCamera) )
    BIND( FloatBinding::bindDial(ui->transX, settings.cameraPosX, -2, 2, true) )
    BIND( FloatBinding::bindDial(ui->transY, settings.cameraPosY, -2, 2, true) )
    BIND( FloatBinding::bindDial(ui->transZ, settings.cameraPosZ, -2, 2, true) )
    BIND( FloatBinding::bindDial(ui->rotU,   settings.cameraRotU, -20, 20, true) )
    BIND( FloatBinding::bindDial(ui->rotV,   settings.cameraRotV, -20, 20, true) )
    BIND( FloatBinding::bindDial(ui->rotN,   settings.cameraRotN, -180, 180, false) )
    BIND( FloatBinding::bindSliderAndTextbox(ui->cameraFovSlider, ui->cameraFovTextbox, settings.cameraFov, 1, 179) )
    BIND( FloatBinding::bindSliderAndTextbox(ui->cameraNearSlider, ui->cameraNearTextbox, settings.cameraNear, 0.1, 50) )
    BIND( FloatBinding::bindSliderAndTextbox(ui->cameraFarSlider, ui->cameraFarTextbox, settings.cameraFar, 0.1, 50) )

    // Ray dock
    BIND( BoolBinding::bindCheckbox(ui->raySuperSamping,          settings.useSuperSampling) )
    BIND( IntBinding::bindTextbox( ui->raySuperSamplesTextbox,   settings.numSuperSamples) )
    BIND( BoolBinding::bindCheckbox(ui->rayAntiAliasing,          settings.useAntiAliasing) )
    BIND( BoolBinding::bindCheckbox(ui->rayShadows,               settings.useShadows) )
    BIND( BoolBinding::bindCheckbox(ui->rayTextureMapping,        settings.useTextureMapping) )
    BIND( BoolBinding::bindCheckbox(ui->rayReflection,            settings.useReflection) )
    BIND( BoolBinding::bindCheckbox(ui->rayRefraction,            settings.useRefraction) )
    BIND( BoolBinding::bindCheckbox(ui->rayPointLights,           settings.usePointLights) )
    BIND( BoolBinding::bindCheckbox(ui->rayDirectionalLights,     settings.useDirectionalLights) )
    BIND( BoolBinding::bindCheckbox(ui->raySpotLights,            settings.useSpotLights) )
    BIND( BoolBinding::bindCheckbox(ui->rayMultiThreading,        settings.useMultiThreading) )

    BIND( ChoiceBinding::bindTabs(ui->tabWidget, settings.currentTab) )

#undef BIND

    // make sure the aspect ratio updates when ui->canvas3D changes size
    connect(ui->canvas3D, SIGNAL(aspectRatioChanged()), this, SLOT(updateAspectRatio()));
}


void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e); // allow the superclass to handle this for the most part...

    switch (e->type()) {

    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;

    default:
        break;

    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Save the settings before we quit
    settings.saveSettings();
    QSettings qtSettings("CS123");
    qtSettings.setValue("geometry", saveGeometry());
    qtSettings.setValue("windowState", saveState());

    QMainWindow::closeEvent(event);
}

void MainWindow::updateAspectRatio()
{
    // Update the aspect ratio text so the aspect ratio will be correct even if the
    // 3D canvas isn't visible (the 3D canvas isn't resized when it isn't visible)
    QSize activeTabSize = ui->tabWidget->currentWidget()->size();
    float aspectRatio = (float)activeTabSize.width() / (float)activeTabSize.height();
    ui->cameraAspectRatio->setText(QString("Aspect ratio: %1").arg(aspectRatio));
}

void MainWindow::settingsChanged()
{
    ui->canvas3D->settingsChanged();
}

void MainWindow::fileSave()
{
}

void MainWindow::setAllEnabled(bool enabled)
{
    QList<QWidget *> widgets;

    QList<QAction *> actions;
    actions += ui->actionSave;
    actions += ui->actionQuit;

    foreach (QWidget *widget, widgets)
        widget->setEnabled(enabled);
    foreach (QAction *action, actions)
        action->setEnabled(enabled);
}

void MainWindow::activateCanvas3D() {
    ui->tabWidget->setCurrentWidget(ui->tab3D);
}
