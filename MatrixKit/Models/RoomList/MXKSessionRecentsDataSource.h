/*
 Copyright 2015 OpenMarket Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <UIKit/UIKit.h>
#import <MatrixSDK/MatrixSDK.h>

#import "MXKDataSource.h"
#import "MXKRecentCellData.h"
#import "MXKEventFormatter.h"

/**
 Identifier to use for cells that display a room in the recents list.
 */
extern NSString *const kMXKRecentCellIdentifier;

/**
 The recents data source based on a unique matrix session.
 */
@interface MXKSessionRecentsDataSource : MXKDataSource {

@protected

    /**
     The data for the cells served by `MXKSessionRecentsDataSource`.
     */
    NSMutableArray *cellDataArray;
    
    /**
     The filtered recents: sub-list of `cellDataArray` defined by `searchWithPatterns:` call.
     */
    NSMutableArray *filteredCellDataArray;
}

/**
 The current number of cells.
 */
@property (nonatomic, readonly) NSInteger numberOfCells;

/**
 The total count of unread messages.
 */
@property (nonatomic, readonly) NSUInteger unreadCount;


#pragma mark - Configuration

/**
 The events to display texts formatter.
 `MXKRecentCellDataStoring` instances can use it to format text.
 */
@property (nonatomic) MXKEventFormatter *eventFormatter;


#pragma mark - Life cycle

/**
 Mark all messages as read
 */
- (void)markAllAsRead;

/**
 Filter the current recents list according to the provided patterns.
 When patterns are not empty, the search result is stored in `filteredCellDataArray`,
 this array provides then data for the cells served by `MXKRecentsDataSource`.
 
 @param patternsList the list of patterns (`NSString` instances) to match with. Set nil to cancel search.
 */
- (void)searchWithPatterns:(NSArray*)patternsList;

/**
 Get the data for the cell at the given index.

 @param index the index of the cell in the array
 @return the cell data
 */
- (id<MXKRecentCellDataStoring>)cellDataAtIndex:(NSInteger)index;

/**
 Get height of the cell at the given index.

 @param index the index of the cell in the array
 @return the cell height
 */
- (CGFloat)cellHeightAtIndex:(NSInteger)index;

@end