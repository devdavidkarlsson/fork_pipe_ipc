//
//  main.m
//  openAL_commandline
//
//  Created by David Karlsson on 03/03/15.
//  Copyright (c) 2015 David Karlsson. All rights reserved.
//

//#import <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <string>
#include <iostream>


#import "SoundController.h"


int main(int argc, const char * argv[]) {
  @autoreleasepool {
      // insert code here...
      NSLog(@"Player program started");
    SoundController *snd = [[SoundController  alloc] init];
    [snd initAL];
    for(;;){
      //sleep(5);
      NSLog(@"Waiting for input!");
      std::string t;
      read()
      std::getline(std::cin,t);
      if(t.compare("play")==0)
        [snd play];
      else{
        NSLog(@"Unrecognized command");
      }
    }
  }
    return 0;
}
