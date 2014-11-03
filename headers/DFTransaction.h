//
//  DFTransaction.h
//
//  Copyright (c) 2014 Cyril Meurillon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^DFTransactionBlock)();
@protocol DFTransactionDecoding;

@interface DFTransaction : NSObject <NSCoding>

+ (id)transactionInBackgroundWithBlock:(DFTransactionBlock)block;
+ (id)speculativeTransactionWithBlock:(DFTransactionBlock)block;                 // exposes transient states outside transaction block

+ (void)setTransactionDecoder:(id<DFTransactionDecoding>)decoder;

- (void)prepareForEncoderWithIdentifier:(NSString *)identifier context:(NSDictionary *)context;

@end
