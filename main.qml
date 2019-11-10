import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {

        id:start;

        objectName: "strat_btn"

        text:"QTextStream"
    }

    Button {

        id:start_1;

        objectName: "strat_btn_1"

        anchors.left: start.right;

        text:"File"
    }

    Image {

        id:img;

        objectName: "img"

        anchors.top: start.bottom;

        source: "";

    }
}
