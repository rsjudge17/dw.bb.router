import bb.cascades 1.0

Page {
    id: helpPage
    // Signals for canceling, saving, and showing a second Sheet for fruit selection.
    signal close()
    
    titleBar: TitleBar {
        id: helpBar
        title: "Help"
        dismissAction: ActionItem {
            title: "Close"
            onTriggered: {
                helpPage.close();
            }
        }
    } // titleBar
    actions: [
        ActionItem {
            title: "Call"
            imageSource: "asset:///images/ic_show_dialpad.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
            }
        },
        ActionItem {
            title: "Email"
            imageSource: "asset:///images/ic_email.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
            }
        }
        /*InvokeActionItem {
            title: "Email"
            ActionBar.placement: ActionBarPlacement.OnBar
            query {
                invokeTargetId: "sys.pim.uib.email.hybridcomposer"
                invokeActionId: "bb.action.COMPOSE"
                mimeType: "message/rfc822"
                uri: "file:///path/to/my/textfile.txt"
            }
        }*/
    ]
    
    RouterContainer {
        layout: DockLayout {
        }

        // A Container for the list is padded at the top and bottom to make room for decorations.
        Container {
            topPadding: 15
            bottomPadding: topPadding
        } // Container
    } // RouterContainer
} // RouterPage