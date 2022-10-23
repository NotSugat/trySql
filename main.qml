import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "gray"

    Text {
        id: loginText
        text: "Login"
    }

    Loader {
        id: mainLoader
        anchors {
            left: parent.left
            right: parent.right
            top: loginText.bottom
            bottom: parent.bottom
        }
        source: "stackView.qml"
    }
}
