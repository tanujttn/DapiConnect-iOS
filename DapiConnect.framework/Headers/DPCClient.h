//
//  DPCClient.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/19/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCConfigurations.h"
#import "DPCConnect.h"
#import "DPCPayment.h"
#import "DPCAutoFlow.h"
#import "DPCAuth.h"
#import "DPCData.h"
#import "DPCMetadata.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiClient)
@interface DPCClient : NSObject

@property (class, nonatomic, strong, readonly) DPCClient *instance;
@property (class, nonatomic, copy, readonly) NSArray<DPCClient *> *instances;

/*!
 @discussion Let's you control the appKey, environment, base URL and set custom end points, etc.
*/
@property (nonatomic, strong) DPCConfigurations *configurations;

/*!
 @discussion Dapi's userID.
 This userID is a single connection to the bank and it differs between banks. For example, when a user connects their account to bank A and bank B, you will have 2 userIDs. Later, when you call any API, it will be called on this user's bank account.
*/
@property (nonatomic, copy) NSString *userID;

- (instancetype)initWithConfigurations:(DPCConfigurations *)configurations;
- (instancetype)init __attribute__((unavailable("use initWithConfigurations:")));

/*!
 @discussion Removes the client from DapiClient.instances.
*/
- (void)dispose;

// MARK: - UI

/*!
 @discussion Show the connect scene where users can login to their bank account.
*/
@property (nonatomic, strong, readonly) DPCConnect *connect;

/*!
 @discussion Shows the connected accounts, gives the option for users to login to their bank account and let your user transfer money.
*/
@property (nonatomic, strong, readonly) DPCAutoFlow *autoFlow;


// MARK: - APIs

/*!
 @discussion Dapi Authetication APIs
*/
@property (nonatomic, strong, readonly) DPCAuth *auth;

/*!
 @discussion Dapi Data APIs
*/
@property (nonatomic, strong, readonly) DPCData *data;

/*!
 @discussion Dapi Metadata APIs
*/
@property (nonatomic, strong, readonly) DPCMetadata *metadata;

/*!
 @discussion Dapi Payment APIs
*/
@property (nonatomic, strong, readonly) DPCPayment *payment;

@end

NS_ASSUME_NONNULL_END
