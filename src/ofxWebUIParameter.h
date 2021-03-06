//
//  ofxWebUIParameter.h
//
//  Created by ISHII 2bit on 2014/12/23.
//
//

#pragma once

#include "ofxJsonxx.h"
#include "ofxWebUIOption.h"

enum ofxWebUIType {
    ofxWebUITypeSlider,
    ofxWebUITypeButton,
    ofxWebUITypeText,
    ofxWebUITypeLongText,
    ofxWebUITypeToggle,
    ofxWebUITypeFlags,
    ofxWebUITypeSelect,
    ofxWebUITypeColor,
    ofxWebUITypeNum
};

static const char *ofxWebUITypeStrings[] = {
    "slider",
    "button",
    "text",
    "longText",
    "toggle",
    "flags",
    "select",
    "color"
};

enum ofxWebUIValueType {
    ofxWebUIValueTypeBool,
    ofxWebUIValueTypeUChar,
    ofxWebUIValueTypeChar,
    ofxWebUIValueTypeUShort,
    ofxWebUIValueTypeShort,
    ofxWebUIValueTypeUInt,
    ofxWebUIValueTypeInt,
    ofxWebUIValueTypeULong,
    ofxWebUIValueTypeLong,
    ofxWebUIValueTypeULongLong,
    ofxWebUIValueTypeLongLong,
    ofxWebUIValueTypeFloat,
    ofxWebUIValueTypeDouble,
    ofxWebUIValueTypeLongDouble,
    ofxWebUIValueTypeString,
    ofxWebUIValueTypeNum
};

class ofxWebUIParameter {
public:
    template <typename T>
    ofxWebUIParameter(const string &name, ofxWebUIType type, T &value, const ofxWebUIOption &option)
    : name(name)
    , type(type)
    , option(option)
    {
        set(value);
    };
    
#define u unsigned
#define CreateProperty(Type, ValueType)\
    void set(Type &value) {\
        valueType = ValueType;\
        this->value = (void *)&value;\
    }
    CreateProperty(bool, ofxWebUIValueTypeBool);
    CreateProperty(u char, ofxWebUIValueTypeUChar);
    CreateProperty(char, ofxWebUIValueTypeChar);
    CreateProperty(u short, ofxWebUIValueTypeUShort);
    CreateProperty(short, ofxWebUIValueTypeShort);
    CreateProperty(u int, ofxWebUIValueTypeUInt);
    CreateProperty(int, ofxWebUIValueTypeInt);
    CreateProperty(u long, ofxWebUIValueTypeULong);
    CreateProperty(long, ofxWebUIValueTypeLong);
    CreateProperty(u long long, ofxWebUIValueTypeULongLong);
    CreateProperty(long long, ofxWebUIValueTypeLongLong);
    CreateProperty(float, ofxWebUIValueTypeFloat);
    CreateProperty(double, ofxWebUIValueTypeDouble);
    CreateProperty(long double, ofxWebUIValueTypeLongDouble);
    CreateProperty(string, ofxWebUIValueTypeString);
#undef CreateProperty
    
    void get(const ofxNodejs::Object &value) {
        switch(valueType) {
            case ofxWebUIValueTypeBool:       get_<bool, bool>(value);          break;
            case ofxWebUIValueTypeUChar:      get_<u char, double>(value);      break;
            case ofxWebUIValueTypeChar:       get_<char, double>(value);        break;
            case ofxWebUIValueTypeUShort:     get_<u short, double>(value);     break;
            case ofxWebUIValueTypeShort:      get_<short, double>(value);       break;
            case ofxWebUIValueTypeUInt:       get_<u int, double>(value);       break;
            case ofxWebUIValueTypeInt:        get_<int, double>(value);         break;
            case ofxWebUIValueTypeULong:      get_<u long, double>(value);      break;
            case ofxWebUIValueTypeLong:       get_<long, double>(value);        break;
            case ofxWebUIValueTypeULongLong:  get_<u long long, double>(value); break;
            case ofxWebUIValueTypeLongLong:   get_<long long, double>(value);   break;
            case ofxWebUIValueTypeFloat:      get_<float, double>(value);       break;
            case ofxWebUIValueTypeDouble:     get_<double, double>(value);      break;
            case ofxWebUIValueTypeLongDouble: get_<long double, double>(value); break;
            case ofxWebUIValueTypeString:     get_<string, string>(value);      break;
            default: break;
        }
    }
#undef u
    
    template <typename T>
    void setOption(const string &optionName, T value) {
        option.setOption(optionName, value);
    }
    
    const string name;
    ofxWebUIType type;
    ofxWebUIValueType valueType;
    ofxWebUIOption option;
private:
    template <typename S, typename T>
    void get_(const ofxNodejs::Object &value) {
        *(static_cast<S *>(this->value)) = value.as<T>();
    }
    void *value;
};