import QtQuick 2.12
import QtQuick.Controls 2.5

Item {
    anchors.fill: parent

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "Login.qml"
    }
}
