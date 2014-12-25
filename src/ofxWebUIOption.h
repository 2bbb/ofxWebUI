//
//  ofxWebUIOption.h
//
//  Created by ISHII 2bit on 2014/12/25.
//
//

#pragma once

#include "ofxJsonxx.h"
#include "ofxWebUIOptionKey.h"

class ofxWebUIOption {
public:
    ofxWebUIOption() {}
    
#pragma mark Basic
    
    template <typename T>
    ofxWebUIOption(const string &optionName, const T &value) {
        setOption(optionName, value);
    }
    
    template <typename T>
    void setOption(const string &optionName, const T &value) {
        option << optionName << value;
    }
    
#pragma mark Slider
    
    template <typename T>
    static ofxWebUIOption createRangeOption(const T &min, const T &max, const T &initial) {
        ofxWebUIOption o(ofxWebUIOptionKey::min, min);
        o.setOption(ofxWebUIOptionKey::max,      max);
        o.setOption(ofxWebUIOptionKey::initial,  initial);
        return o;
    }
    
    template <typename T>
    static ofxWebUIOption rangeOption0_255(const T &initial) {
        return createRangeOption(0, 255, initial);
    }
    
#pragma mark Select
    
    static ofxWebUIOption createSelectBoxOption(const vector<string> &labels, int initial = 0) {
        ofxJsonxx::Array arr;
        for(const auto &label : labels) {
            arr << label;
        }
        ofxWebUIOption o(ofxWebUIOptionKey::labels, arr);
        o.setOption("initial", initial);
        
        return o;
    }
    
#pragma mark Utils
    const ofxJsonxx::Object &getRaw() const {
        return option;
    }
private:
    ofxJsonxx::Object option;
};