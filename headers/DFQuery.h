//
//  DFQuery.h
//
//  Copyright (c) 2014 Cyril Meurillon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DFQueryObserving;

@protocol DFQueryObserving <NSObject>

- (void)objectsDidQualify:(NSArray *)objects forQuery:(DFQuery *)query;
- (void)objectsDidDisqualify:(NSArray *)objects forQuery:(DFQuery *)query;

@end

@interface DFQuery : NSObject

@property (nonatomic, readonly) NSString        *identifier;

+ (DFQuery)staticQueryWithPredicate:(NSPredicate *)predicate waitForConnection:(BOOL)wait resultBlock:(void(^)(NSArray *))block;
+ (DFQuery)liveQueryWithPredicate:(NSPredicate *)predicate identifier:(NSString *)identifier observer:(id<DFQueryObserving>)observer;
+ (DFQuery)standingQueryWithPredicate:(NSPredicate *)predicate identifier:(NSString *)identifier observer:(id<DFQueryObserving>)observer;

+ (DFQuery)queryWithIdentifier:(NSString *)identifier;

- (void)invalidate;

@end
