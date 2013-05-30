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
import bb.cascades 1.0

// This the item component for the items in the bucket list. It is a StandardListItem
// with an action set for altering the state of an item and for entering the multi select state.

StandardListItem {
    id: formItem
    title: ListItemData.title
    description: ListItemData.desc
    status: ListItemData.status
    imageSource: ListItemData.image

    /*contextActions: [
        ActionSet {
            title: ListItemData.title
            subtitle: "Bucket action"
            
            ActionItem {
                title: "Todo"
                enabled: formItem.ListItem.view.dataModel.filter == "todo" ? false : true
                imageSource: "asset:///images/todo.png"
                
                onTriggered: {
                    if (enabled) {
                        formItem.ListItem.view.dataModel.setStatus(formItem.ListItem.indexPath, "todo");
                        formItem.ListItem.view.updateBBMStatus("Added to my bucket list: " + formItem.title, "images/todo.png");
                    }
                }
            }
            ActionItem {
                title: "Finished"
                enabled: formItem.ListItem.view.dataModel.filter == "finished" ? false : true
                imageSource: "asset:///images/finished.png"
                
                onTriggered: {
                    if (enabled) {
                        formItem.ListItem.view.dataModel.setStatus(formItem.ListItem.indexPath, "finished");
                        formItem.ListItem.view.updateBBMStatus("Kicked from my bucket list: " + formItem.title, "images/finished.png");
                    }
                }
            }
            ActionItem {
                title: "Chickened out"
                enabled: formItem.ListItem.view.dataModel.filter == "chickened" ? false : true
                imageSource: "asset:///images/chickened.png"
                
                onTriggered: {
                    if (enabled) {
                        formItem.ListItem.view.dataModel.setStatus(formItem.ListItem.indexPath, "chickened");
                        formItem.ListItem.view.updateBBMStatus("Chickened out on my bucket list: " + formItem.title, "images/chickened.png");
                    }
                }
            }
            ActionItem {
                title: "Share Item"
                imageSource: "asset:///images/ic_share.png"
                onTriggered: {
                    formItem.ListItem.view.dataModel.shareBucketItem(formItem.title);
                
                }
            }
            DeleteActionItem {
                title: "Delete"
                
                onTriggered: {
                    formItem.ListItem.view.dataModel.deleteBucketItems(formItem.ListItem.indexPath);
                }
            }
            
            MultiSelectActionItem {
                multiSelectHandler: formItem.ListItem.view.multiSelectHandler
                
                onTriggered: {
                    multiSelectHandler.active;    
                } 
            }
        }
    ]*/
}
