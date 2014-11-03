//
//  DFTransactionDecoding.h
//  ShoppingList
//
//  Copyright (c) 2014 Cyril Meurillon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DFTransaction.h"

@protocol DFTransactionDecoding <NSObject>

- (DFTransactionBlock)decodeTransactionWithIdentifier:(NSString *)identifier context:(NSDictionary *)context;

@end
