import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.0

// Main window
Window {
    visible: true
    minimumWidth: 400
    minimumHeight: 200

    // Table view displays list of person data
    TableView {
        anchors.fill: parent
        clip: true
        rowSpacing: 4
        columnSpacing: 4
        model: personModel              // Person data model described in c++

        property var columnWidths: [80, 110, 150]
        columnWidthProvider: function (column) { return columnWidths[column] } // set column widths

        // Data and background of one cell in the table
        delegate: Rectangle {
            color: "#e6e1e1"
            implicitHeight: cellText.implicitHeight
            Text {
                id: cellText
                text: tableData
                color: "#575454"
                font.pointSize: 10
                font.family: "Tahoma"
                font.bold: header
                anchors.fill: parent
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
            }
        }
    }

    // Button which shows dialog choosing a file to display in table
    Button {
        text: qsTr("Choose a file")
        anchors.bottom: parent.bottom
        anchors.margins: 10
        anchors.left: parent.left
        onClicked: fileDialog.open()
        font.pointSize: 10
        background: Rectangle {
            color: "#96cc6a"
            radius: 5
        }
    }

    //File dialog to choose a .txt file
    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a file")
        nameFilters: [ "Text files (*.txt)"]
        selectMultiple: false             // choose only one file
        onAccepted: {
            personModel.clear()           // clear old data
            personModel.openFile(fileUrl) // open file to display in model
        }
        onRejected: {
            fileDialog.close()
        }
    }
}
