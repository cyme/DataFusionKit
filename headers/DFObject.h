//
//  DFObject.h
//
//  Copyright (c) 2014 Cyril Meurillon. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol DFObjectObserving;


@interface DFObject : NSObject <NSCoding>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Class methods for subclasses to override
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma mark - Class methods to override

// all subclasses must implement this method to provide the subclass name

+ (NSString *)className;

// by default, subclass properties are persisted in the cloud and synced across all app installs of the syncing group.
// subclasses can change this behavior on a per-property basis, and declare which property to not persist at all or
// to persist locally only.
// localPersistedProperties: should return an array of local property names that are persisted locally only
// localTransientProperties: should return an array of local property names that are not persisted at all

+ (NSArray *)localPersistedProperties;
+ (NSArray *)localTransientProperties;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Class methods that pertain to specific DFObject subclasses
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma mark - Class methods to call

// all subclasses must call this method to register.
// It can safely be called multiple times on the same subclass.
// This method will fail if used on DFObject rather than a subclass.

+ (void)registerSubclass;

// Create a new object of this subclass and add it to the database. Object property values (of all storage classes)
// can be specified in the dictionary.  The object instance is returned. This method will fail if used on DFObject
// rather than a subclass

+ (id)objectWithValues:(NSDictionary *)values;

// Call this method to set add or remove a class observer. Observers will be notified in the order they have registered
// to listen to the subclass
// addObserver: will retroactively notify the observer of any past object creations (fetched from device cache and locally/remotely created)

+ (void)addObserver:(id<DFObjectObserving>)observer;
+ (void)removeObserver:(id<DFObjectObserving>)observer;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Instance methods that pertain to an instance of DFObject or a subclass
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma mark - Instance methods to call

// Delete object from database, detach it from the global object registery and mark the object instance
// for deletion.

- (void)delete;

@end

extern NSString * const     DFErrorDomain;
extern NSInteger const      DFInvitationCodeDigits;
extern NSTimeInterval const DFInvitationTimeout;


enum {
    DFErrorSyncingRequestTimeout = 100,
    DFErrorSyncingRequestCancelled,
    DFErrorInvalidCode,
    DFErrorNoConnection
};