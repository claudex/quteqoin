#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class QQBoardsInfo;
class QQBouchot;
class QQDockPalmi;
class QQPalmipede;
class QQPinipede;
class QQPiniSearchWidget;
class QQSettings;
class QQTotozManager;

#if(QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
#define QML_PALMI 1
class QQuickWidget;
#endif

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	//QQPalmipede * getPalmi() {return m_palmi;}

public slots:
	void displayOptions();
	void doPostMessage(const QString &bouchot, const QString &message);
	void doPalmiStatusChanged(bool isPalmiMini, bool isPalmiDocked);
	void doPalmiVisibilityChanged(bool isVisible);

protected:
	virtual void changeEvent(QEvent *event);
	virtual void closeEvent(QCloseEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);

protected slots:
	void bouchotDestroyed(QQBouchot *bouchot);
	void bouchotGroupChanged(QQBouchot *bouchot, QString oldGroupName);
	void doFullRepaint();
	void doNetworkSettingsChanged();
	void initBouchot(QQBouchot *bouchot);
	void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
	void initBouchots();

	Ui::MainWindow *m_ui;

	QAction *m_actionDockPalmi;

	QQBoardsInfo *m_boardsInfo;
	QQDockPalmi *m_dockPalmi;
#ifdef QML_PALMI
	QQuickWidget *m_palmi;
#else
	QQPalmipede *m_palmi;
#endif
	QQPinipede *m_pini;
	QQPiniSearchWidget *m_pSearchW;
	QQTotozManager *m_totozManager;

	QSystemTrayIcon *m_trayIcon;
};

#endif // MAINWINDOW_H
