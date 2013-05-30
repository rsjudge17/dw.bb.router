import bb.cascades 1.0

MenuDefinition {
    id: appMenu
    signal openSettingsMenu()
    signal openHelpMenu()
    signal openSupportMenu()
    
    settingsAction: SettingsActionItem {
        onTriggered: {
            openSettingsMenu();
        }
    }
    helpAction: HelpActionItem {
        onTriggered: {
            openHelpMenu();
        }
    }
    actions: [
        ActionItem {
            title: "Support"
            imageSource: "asset:///images/ic_info.png"
            onTriggered: {
                openSupportMenu();
            }
        }
    ]
}