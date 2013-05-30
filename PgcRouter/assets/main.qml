/* Copyright (c) 2012 Research In Motion Limited.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Import all our cascades functions.
import bb.cascades 1.0

TabbedPane {
    id: mainTabPane
    
    property variant menu
    Menu.definition: menu
    
    showTabsOnActionBar: false
    sidebarState: SidebarState.VisibleFull
    Tab {
        id: formsTab
        title: qsTr("Forms")
        imageSource: "asset:///images/ic_copy.png"
        NavigationPane {
            id: formPane
            FormListPage {
	            id: formListPage
	        } // FormListPage
            onCreationCompleted: {
                // this slot is called when declarative scene is created
                // write post creation initialization here
                console.log("TabbedPane - onCreationCompleted()")

                // enable layout to adapt to the device rotation
                // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
                OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
            }
        }
        
        onTriggered: {
            mainTabPane.activeTab = formsTab;
        }
    }
    Tab {
        id: trackerTab
        title: qsTr("Tracker")
        imageSource: "asset:///images/ic_map.png"
        NavigationPane {
            id: trackerPane;
            Page {
                id: trackerListPage
            } // ForPage
            onCreationCompleted: {
                // this slot is called when declarative scene is created
                // write post creation initialization here
                console.log("TabbedPane - onCreationCompleted()")

                // enable layout to adapt to the device rotation
                // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
                OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
            }
        }
        onTriggered: {
            mainTabPane.activeTab = trackerTab;
        }
    }
    /*Tab {
        id: supportTab
        title: qsTr("Support")
        imageSource: "asset:///images/ic_info.png"
        SupportPage {
            id: supportPage
        } // SupportPage
        onTriggered: {
            //mainTabPane.activePane = formPane;
            mainTabPane.activeTab = supportPage;
        }
    }
    Tab {
        id: helpTab
        title: qsTr("Help")
        imageSource: "asset:///images/ic_help.png"
        HelpPage {
            id: helpPage
        }
        onTriggered: {
            //mainTabPane.activePane = formPane;
            mainTabPane.activeTab = helpPage;
        }
    }*/
    attachedObjects: [
        RouterMenu {
            id: routerMenu
            onOpenSettingsMenu: {
                settingsSheet.open();
            }
            onOpenHelpMenu: {
                helpSheet.open();
            }
            onOpenSupportMenu: {
                supportSheet.open();
            }
        },
        Sheet {
            id: supportSheet
            SupportPage {
                id: supportPage
                onClose: {
                    supportSheet.close();
                }
                paneProperties: NavigationPaneProperties {
                    backButton: ActionItem {
                        title: "Back"
                        imageSource: "asset:///images/ic_previous.png"
                        onTriggered: {
                            supportPage.close();
                        }
                    }
                }
            }
        },
        Sheet {
            id: helpSheet
            HelpPage {
                id: helpPage
                onClose: {
                    helpSheet.close();
                }
                paneProperties: NavigationPaneProperties {
                    backButton: ActionItem {
                        title: "Back"
                        imageSource: "asset:///images/ic_previous.png"
                        onTriggered: {
                            helpPage.close();
                        }
                    }
                }
            }
        },
        Sheet {
            id: settingsSheet
            SettingsPage {
                id: settingsPage
                onClose: {
                    settingsSheet.close();
                }
                paneProperties: NavigationPaneProperties {
                    backButton: ActionItem {
                        title: "Back"
                        imageSource: "asset:///images/ic_previous.png"
                        onTriggered: {
                            settingsPage.close();
                        }
                    }
                }
            }
        }
    ]
    onCreationCompleted: {
        //navigation = formPane;
        menu = routerMenu;
        //mainTabPane.activeTab = formsTab;
    }
} // TabbedPane