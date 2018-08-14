#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector2D>
namespace Ui {
class MainWindow;
}

class SurfaceGraph;
class TrafficAlg;
class LasterDevUnit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   signals:
    void sigAppendRow(const QList<QVector2D> &);
public slots:
    void slot_Frame(const QList<QPointF> &);
protected:
    void init();
private:
    Ui::MainWindow *ui;
    SurfaceGraph *modifier;

    TrafficAlg *m_alg;
    QThread *mAlgThread;
    //Vertical
    LasterDevUnit* m_Vdev;
    //slant
    LasterDevUnit* m_Qdev;
};

#endif // MAINWINDOW_H
