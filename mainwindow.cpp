#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QSpinBox>
#include <QToolBar>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new PaintCanvas(this);
    setCentralWidget(canvas);

    // pen width
    QLabel *penWidthLabel = new QLabel("Pen width", this);
    QSpinBox *penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setValue(2);
    penWidthSpinBox->setRange(1, 15);

    // Pen color
    QLabel *penColorLabel = new QLabel("Pen Color", this);
    penColorButton = new QPushButton(this);

    // Fill color
    QLabel *fillColorLabel = new QLabel("Fill Color", this);
    fillColorButton = new QPushButton(this);

    // fill
    fillCheckBox = new QCheckBox("Fill Shape", this);

    // Tool Buttons
    QPushButton *rectButton = new QPushButton(this);
    rectButton->setIcon(QIcon("D:/QtWorkspace/PaintAppV1/images/rectangle.png"));
    rectButton->setIconSize(QSize(32, 32));
    rectButton->setToolTip("Rectangle");


    QPushButton *penButton = new QPushButton(this);
    penButton->setIcon(QIcon("D:/QtWorkspace/PaintAppV1/images/pen.png"));
    penButton->setFlat(true);
    penButton->setIconSize(QSize(32, 32));
    penButton->setToolTip("Pen");

    QPushButton *ellipseButton = new QPushButton(this);
    ellipseButton->setIcon(QIcon("D:/QtWorkspace/PaintAppV1/images/circle.png"));
    ellipseButton->setIconSize(QSize(32, 32));
    ellipseButton->setToolTip("Circle/Ellipse");

    QPushButton *eraserButton = new QPushButton(this);
    eraserButton->setIcon(QIcon("D:/QtWorkspace/PaintAppV1/images/eraser.png"));
    eraserButton->setIconSize(QSize(32, 32));
    eraserButton->setToolTip("Eraser");

    // Slots connection
    connect(penWidthSpinBox, SIGNAL(valuechanged(int)), this, SLOT(penWidthChanged(int)));
    connect(penColorButton, SIGNAL(clicked()), this, SLOT(changePenColor()));
    connect(fillColorButton, SIGNAL(clicked()), this, SLOT(changeFillcolor()));
    connect(fillCheckBox, SIGNAL(clicked), this, SLOT(changeFillColor()));

    QToolBar *mainToolbar = new QToolBar(this);
    mainToolbar->setIconSize(QSize(32, 32));
    mainToolbar->addWidget(penWidthLabel);
    mainToolbar->addWidget(penWidthSpinBox);
    mainToolbar->addWidget(penColorLabel);
    mainToolbar->addWidget(penColorButton);
    mainToolbar->addWidget(fillColorLabel);
    mainToolbar->addWidget(fillColorButton);
    mainToolbar->addWidget(fillCheckBox);
    mainToolbar->addSeparator();

    // Add as spacer to push next widgets to the right
    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainToolbar->addWidget(spacer);
    mainToolbar->addWidget(penButton);
    mainToolbar->addWidget(rectButton);
    mainToolbar->addWidget(ellipseButton);
    mainToolbar->addWidget(eraserButton);

    addToolBar(Qt::TopToolBarArea, mainToolbar);
}

void MainWindow::penWidthChanged(int width){

}

void MainWindow::changePenColor() {

}

void MainWindow::changeFillColor() {

}

void MainWindow::changeFillProperty() {

}

MainWindow::~MainWindow()
{
    delete ui;
}
