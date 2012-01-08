/*!

  Main window class for CS123. See the header file for additional documentation.

  @author Evan Wallace (evan.exe@gmail.com)
  @author Ben Herila (ben@herila.net)

**/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Databinding.h"
#include "Settings.h"
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
