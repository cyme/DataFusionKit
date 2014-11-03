//
//  DFObjectObserving.h
//
//  Copyright (c) 2014 Cyril Meurillon. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DFObject;

@protocol DFObjectObserving <NSObject>

#pragma mark - Notification handlers

@optional

// Observer change notification methods, to be used for example by data and view controllers

// Implement the following 2 methods to catch respectively the beginning and the end of the change notification session

- (void)willChangeObjects;
- (void)didChangeObjects;

// Implement the following 2 methods to catch an object attribute change respectively before and after it is effected

- (void)willChangeObjectValue:(DFObject *)object forKey:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue remotely:(BOOL)remotely;
- (void)didChangeObjectValue:(DFObject *)object forKey:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue remotely:(BOOL)remotely;

// Implement the following 2 methods to catch the reset of an object attribute value caused by a voided transaction

- (void)willResetObjectValue:(DFObject *)object forKey:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue;
- (void)didResetObjectValue:(DFObject *)object forKey:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue;

// Implement the following method to prepare for an object deletion

- (void)willDeleteObject:(DFObject *)object remotely:(BOOL)remotely;

// Implement the following method to catch an object creation

- (void)didCreateObject:(DFObject *)object remotely:(BOOL)remotely;

@end