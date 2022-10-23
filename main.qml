import QtQuick 2.5
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1
import Qt.labs.qmlmodels 1.0



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        id: rowLayout
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 5

        spacing: 10

        Text {text: qsTr("Имя")}
        TextField {id: fnameField}
        Text {text: qsTr("Фамилия")}
        TextField { id: snameField}
        Text {text: qsTr("НИК")}
        TextField {id: nikField}

        Button {
            text: qsTr("Add")

            // Make a new entry in the database
            onClicked: {
                database.inserIntoTable(fnameField.text , snameField.text, nikField.text)
                myModel.updateModel() // And updates the data model with a new record
            }
        }
    }


}
