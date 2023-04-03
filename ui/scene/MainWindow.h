#include <QQuickView>

#include "QtScrcpyCore.h"
#include "adbprocess.h"

#include "ui/service/ResourceService.h"
#include "ui/service/WebSocketService.h"
#include "ui/service/udp/Broadcast.h"

class MainWindow : public QQuickView {

public:
    MainWindow(QQuickView *parent = nullptr);
    ~MainWindow();

    Q_INVOKABLE void test(QString name);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:

    ResourceService *resourceService = nullptr;
    Broadcast *m_broadcast = nullptr;
};

