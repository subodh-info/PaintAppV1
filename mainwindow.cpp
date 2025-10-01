#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QSpinBox>
#include <QToolBar>
#include <QPixmap>
#include <QColorDialog>
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

    connect(rectButton, &QPushButton::clicked, [=](){
        canvas->setTool(PaintCanvas::Rect);
        statusBar()->showMessage("Current tool: Pen");
    });

    connect(penButton, &QPushButton::clicked, [=](){
        canvas->setTool(PaintCanvas::Pen);
        statusBar()->showMessage("Current tool: Ellipse");
    });

    connect(ellipseButton, &QPushButton::clicked, [=](){
        canvas->setTool(PaintCanvas::Ellipse);
        statusBar()->showMessage("Current tool: Ellipse");
    });

    connect(eraserButton, &QPushButton::clicked, [=](){
        canvas->setTool(PaintCanvas::Eraser);
        statusBar()->showMessage("Current tool: Eraser");
    });
    // Slots connection
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penWidthChanged(int)));
    connect(penColorButton, SIGNAL(clicked()), this, SLOT(changePenColor()));
    connect(fillColorButton, SIGNAL(clicked()), this, SLOT(changeFillColor()));
    connect(fillCheckBox, SIGNAL(clicked()), this, SLOT(changeFillProperty()));

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

    QString _css = QString("background-color: %1").arg(canvas->getPenColor().name());
    penColorButton->setStyleSheet(_css);

    _css = QString("background-color: %1").arg(canvas->getFillColor().name());
    fillColorButton->setStyleSheet(_css);
}

void MainWindow::penWidthChanged(int width){
    canvas->setPenWidth(width);
}

void MainWindow::changePenColor() {
    QColor _color = QColorDialog::getColor(canvas->getPenColor());
    if(_color.isValid()){
        canvas->setPenColor(_color);
        QString css = QString("background-color: %1").arg(_color.name());
        penColorButton->setStyleSheet(css);
    }
}

void MainWindow::changeFillColor() {
    QColor _color = QColorDialog::getColor(canvas->getFillColor());
    if(_color.isValid()) {
        canvas->setFillColor(_color);
        QString css = QString("background-color: %1").arg(_color.name());
        fillColorButton->setStyleSheet(css);
    }
}

void MainWindow::changeFillProperty() {
    canvas->setFill(fillCheckBox->isCheckable());
}

MainWindow::~MainWindow()
{
    delete ui;
}
