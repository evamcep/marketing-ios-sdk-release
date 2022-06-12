//
//  AFSQLManager.h
//  AFSQLManager
//
//  Created by Alvaro Franco on 4/17/14.
//  Copyright (c) 2014 AlvaroFranco. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface EvamSqliteManager : NSObject

typedef void (^statusBlock)(BOOL success, NSError *error);
typedef void (^completionBlock)(NSArray *row, NSError *error, BOOL finished);
typedef void (^countCompletionBlock)(int count, NSError *error, BOOL finished);

+(instancetype)sharedManager;

@property (nonatomic) sqlite3 *database;
@property (strong, nonatomic) NSString *databasePath;

-(void)createDatabaseWithName:(NSString *)name openImmediately:(BOOL)open withStatusBlock:(statusBlock)status;
-(void)openLocalDatabaseWithName:(NSString *)name andStatusBlock:(statusBlock)status;
-(void)closeLocalDatabaseWithName:(NSString *)name andStatusBlock:(statusBlock)status;
-(void)renameDatabaseWithName:(NSString *)originalName toName:(NSString *)newName andStatus:(statusBlock)status;
-(void)deleteDatabaseWithName:(NSString *)name andStatus:(statusBlock)status;
-(void)execute:(NSString *)query withBlock:(completionBlock)completion;
-(void)performQuery:(NSString *)query withBlock:(completionBlock)completion;
-(void)rowCount:(NSString *)query withBlock:(countCompletionBlock)completion;
-(void)prepareDb;
@end
