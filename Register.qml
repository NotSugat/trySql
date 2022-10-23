import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Rectangle {
    anchors.fill: parent

    Text {
        id: emailText
        x: 229
        y: 89
        text: qsTr("Email")
    }
    TextField {
        id: emailInput
        x: 294
        y: 80

        placeholderText: "email"
    }

    Text {
        id: password
        x: 207
        y: 151
        text: qsTr("password")
    }

    TextField {
        id: passwordInput
        x: 294
        y: 142
        text: qsTr("")
        placeholderText: "password"
    }

    Button {
        id: registerBtn
        x: 304
        y: 220
        contentItem: Text {
            text: "Register"
        }
        onClicked: database.insertIntoTable(emailInput.text, passwordInput.text)
    }
}
