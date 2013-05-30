import bb.cascades 1.0
import "form"

Page {
    property alias filterValue: filerOption.selectedValue;
    
    id: formListPage
    actionBarVisibility: ChromeVisibility.Visible
    actionBarAutoHideBehavior: ActionBarAutoHideBehavior.Default
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        scrollBehavior: TitleBarScrollBehavior.Sticky
        //title: "Forms"
        kind: TitleBarKind.FreeForm
        kindProperties: FreeFormTitleBarKindProperties {
            id: filter
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                leftPadding: 10
                rightPadding: 10
                //ImageView {
                //    id: formIcon
                //    verticalAlignment: VerticalAlignment.Center
                //    imageSource: "asset:///images/ic_copy.png"
                //}
                Label {
                    id: formText
                    text: "Forms"
                    textStyle {
                        color: Color.White
                    }
                    verticalAlignment: VerticalAlignment.Center
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }
                }
            }
            expandableArea {
                content: RadioGroup {
                    id: filerOption
                    leftPadding: 10
                    rightPadding: 10
                    Option {
                        id: optionAll
                        text: "Forms"
                        //imageSource: "asset:///images/ic_copy.png"
                        selected: true
                        value: text
                    }
                    Option {
                        id: optionInbox
                        text: "Inbox"
                        //imageSource: "asset:///images/ic_receive.png"
                        value: text
                    }
                    Option {
                        id: optionOutbox
                        text: "Outbox"
                        //imageSource: "asset:///images/ic_save.png"
                        value: text
                    }
                    Option {
                        id: optionSentItems
                        text: "Sent Items"
                        //imageSource: "asset:///images/ic_send.png"
                        value: text
                    }
                    onSelectedValueChanged: {
                        console.log("onSelectedValueChanged");

                        filter.expandableArea.setExpanded(false);
                        formText.text = selectedValue;
                        
                        _formList.setFilter(selectedValue);
                        //formIcon.imageSource = selectedOption.imageSource;
                    }
                }
                indicatorVisibility: TitleBarExpandableAreaIndicatorVisibility.Visible
                expanded: toggleExpanded.checked
                onExpandedChanged: {
                    console.log("onExpandedChanged");
                    //toggleExpanded.checked = expanded
                }
                onToggleAreaChanged: {
                    console.log("onToggleAreaChanged");
                }
            }
        }
    }
    actions: [
        ActionItem {
            title: "Top"
            imageSource: "asset:///images/ic_to_top.png"
            shortcuts: SystemShortcut {
                type: SystemShortcuts.JumpToTop
            }
            onTriggered: {
                _app.invokeEditor("pen_Jan_22_20.21.02.pgc");
            }
        },
        ActionItem {
            title: "Bottom"
            imageSource: "asset:///images/ic_to_bottom.png"
            shortcuts: SystemShortcut {
                type: SystemShortcuts.JumpToBottom
            }
            onTriggered: {
                _app.invokeViewer("pen_Jan_22_20.21.02.pgc");
            }
        },
        ActionItem {
            title: "Verification"
            imageSource: "asset:///images/ic_settings.png"
            onTriggered: {
                //_app.showSettings();
                //var sheet = settingsSheetDefinition.createObject();
                //sheet.closed.connect(deleteLater);
                //sheet.open();

                settingsSheetDefinition.open();
            }
        }
    ]
    RouterContainer {
        Container {
            layout: DockLayout {
            }
            // Spacequota 1 is set so that the list will fit in the space available beneath the title.
	        layoutProperties: StackLayoutProperties {
	            spaceQuota: 1
	        }

            contextActions: [
                ActionSet {
                    title: "Forms"
                    actions: [
                        ActionItem {
                            title: "Edit"
                            imageSource: "asset:///images/ic_edit.png"
                            shortcuts: SystemShortcut {
                                    type: SystemShortcuts.Edit
                            }
                        },
                        ActionItem {
                            title: "Open"
                            imageSource: "asset:///images/ic_open.png"
                            shortcuts: SystemShortcut {
                                type: SystemShortcuts.None
                            }
                        },
                        ActionItem {
                            title: "send"
                            imageSource: "asset:///images/ic_send.png"
                            shortcuts: SystemShortcut {
                                type: SystemShortcuts.None
                            }
                        },
                        DeleteActionItem {
                            onTriggered: {
                                _app.invokePhotoAttach("");
                            }
                        }
                    ]
                } // end of ActionSet
            ] // end of contextActions list
	        // An activity indicator that will be shown when weather data is loaded
	        ActivityIndicator {
	            id: dataLoadIndicator
	            preferredWidth: 400
	            preferredHeight: 400
	            horizontalAlignment: HorizontalAlignment.Center
	            verticalAlignment: VerticalAlignment.Top
	        }
	
	        // The list of weather forecasts
	        FormList {
	            id: formList

                dataModel: _formList
                // An XML model is also available to populate the preview.
                //dataModel: XmlDataModel {
                //    source: "asset:///model/inbox.xml"
                //}
            }
        } // Container
    } // Container
} // Page
