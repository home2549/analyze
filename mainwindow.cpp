#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>
#include "surfacegraph.h"

#include "trafficsettings.h"
#include "alg/trafficalg.h"
#include "lasterdevunit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Q3DSurface *graph = new Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);
    //! [0]

    if (!graph->hasContext()) {
        qDebug()<<("Couldn't initialize the OpenGL context.");
        return;
    }

    this->setCentralWidget(container);
    modifier = new SurfaceGraph(graph);
    connect(this,SIGNAL(sigAppendRow(const QList<QVector2D> &)),modifier,SLOT(slotAppendRow(const QList<QVector2D> &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init()
{
    mAlgThread = new QThread(this);
    m_alg = new TrafficAlg(0);
    m_alg->moveToThread(mAlgThread);
    connect(mAlgThread,SIGNAL(destroyed()),m_alg,SLOT(deleteLater()));
    connect(m_alg,SIGNAL(signal_Frame(const QList<QPointF> &)),this,SLOT(slot_Frame(const QList<QPointF> &)));
    mAlgThread->start();

#ifdef DEV_TEST
    m_Vdev = new LasterDevUnit(TrafficSettings::instance()->vLmsIp(),
                              TrafficSettings::instance()->vLmsPort(),
                              LasterDevUnit::CONTINUE_FRAME,this); //SINGLE_FRAME CONTINUE_FRAME
#else
    m_Vdev = new LasterDevUnit(TrafficSettings::instance()->vLmsIp(),
                              TrafficSettings::instance()->vLmsPort(),
                              LasterDevUnit::CONTINUE_FRAME,this); //SINGLE_FRAME CONTINUE_FRAME
#endif

    connect(m_Vdev,SIGNAL(signal_data(const LasterData &)),m_alg,SLOT(slot_vLastData(const LasterData &)));


#ifdef DBG_LASTER
    m_Vdev->stopRequest(true);
#endif

#ifdef DEV_TEST
    m_Qdev = new LasterDevUnit(TrafficSettings::instance()->qLmsIp(),
                               TrafficSettings::instance()->qLmsPort(),
                               LasterDevUnit::CONTINUE_FRAME,this);
#else
    m_Qdev = new LasterDevUnit(TrafficSettings::instance()->qLmsIp(),
                               TrafficSettings::instance()->qLmsPort(),
                               LasterDevUnit::CONTINUE_FRAME,this);
#endif
    connect(m_Qdev,SIGNAL(signal_data(const LasterData &)),m_alg,SLOT(slot_qLastData(const LasterData &)));

#ifdef DBG_LASTER
    connect(m_alg,SIGNAL(signal_VehicleDetect(bool)),m_Qdev,SLOT(slot_speedup(bool)));
#endif
}


void MainWindow::slot_Frame(const QList<QPointF> & npts)
{
    QList<QVector2D> nRowData;

    QListIterator<QPointF> iEveryItem(npts);
    while(iEveryItem.hasNext()){
        const QPointF & nItem = iEveryItem.next();
        nRowData.append(QVector2D(nItem));
    }
    emit sigAppendRow(nRowData);
}
