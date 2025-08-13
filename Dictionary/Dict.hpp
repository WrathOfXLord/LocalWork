// #ifndef __DICT_HPP__
// #define __DICT_HPP__

// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <iostream>
// #include <fstream>


// class JsonValue {
// public:
//     enum DTypes { none, null, boolean, number, string, array, object };
// private:
//     using DT = DTypes;
//     DTypes type;
//     union {
//         bool boolVal;
//         double numVal;
//         std::string *strVal;
//         std::vector<JsonValue> *arrayVal;
//         std::unordered_map<std::string, JsonValue> *objectVal;
//     };
//     const char *typeStr;
//     const char *type_in_str(DT val)  {
//         switch (val)
//         {
//             case DT::none:
//                 return "none";
//             case DT::null:
//                 return "null";
//             case DT::boolean:
//                 return "bool";
//             case DT::number:
//                 return "double";
//             case DT::string:
//                 return "string";
//             case DT::array:
//                 return "array";
//             case DT::object:
//                 return "object";
//         }
//         return "Invalid Data";
//     }
// public:
//     JsonValue() : type {DT::none}, typeStr {type_in_str(type)} {}
//     JsonValue(std::nullptr_t) : type {DT::null}, typeStr {type_in_str(type)} {}
//     JsonValue(bool val) : type {DT::boolean}, boolVal {val}, typeStr {type_in_str(type)} {}
//     JsonValue(double val) : type {DT::number}, numVal {val}, typeStr {type_in_str(type)} {}
//     JsonValue(std::string *val) : type {DT::string}, strVal {val}, typeStr {type_in_str(type)} {}
//     JsonValue(std::vector<JsonValue> *val) : type {DT::array}, arrayVal {val}, typeStr {type_in_str(type)} {}
//     JsonValue(std::unordered_map<std::string, JsonValue> *val) : type {DT::object}, objectVal {val}, typeStr {type_in_str(type)} {}
//     ~JsonValue() { 
//         switch(type) {
//             case DT::string:
//                 delete strVal;
//                 break;
//             case DT::array:
//                 delete arrayVal;
//                 break;
//             case DT::object:
//                 delete objectVal;
//         }
//     }

//     DTypes getType() const { return type; }
//     const char *typeToC_Str() const { return typeStr; }
//     bool isNone() const { return type == DT::none; }
//     bool isNull() const { return type == DT::null; }
//     bool isBoolean() const { return type == DT::boolean; }
//     bool isNumber() const { return type == DT::number; }
//     bool isString() const { return type == DT::string; }
//     bool isArray() const { return type == DT::array; }
//     bool isObject() const { return type == DT::object; }

//     JsonValue(const JsonValue &rhs) : type {rhs.type}, typeStr {rhs.typeStr} {
//         switch(type) {
//             case DT::null:
//                 numVal = 0.0;
//                 break;
//             case DT::boolean:
//                 boolVal = rhs.boolVal;
//                 break;
//             case DT::number:
//                 numVal = rhs.numVal;
//                 break;
//             case DT::string:
//                 strVal = new std::string{*rhs.strVal};
//                 break;
//             case DT::array:
//                 arrayVal = new std::vector<JsonValue>{*rhs.arrayVal};
//                 break;
//             case DT::object:
//                 objectVal = new std::unordered_map<std::string, JsonValue>{*rhs.objectVal};
//                 break;
//         }
//     }

//     JsonValue(JsonValue &&rhs) : type {rhs.type}, typeStr {rhs.typeStr} {
//         switch(type) {
//             case DT::null:
//                 numVal = 0.0;
//                 break;
//             case DT::boolean:
//                 boolVal = rhs.boolVal;
//                 break;
//             case DT::number:
//                 numVal = rhs.numVal;
//                 break;
//             case DT::string:
//                 strVal = rhs.strVal;
//                 rhs.strVal = nullptr;
//                 break;
//             case DT::array:
//                 arrayVal = rhs.arrayVal;
//                 rhs.arrayVal = nullptr;
//                 break;
//             case DT::object:
//                 objectVal = rhs.objectVal;
//                 rhs.objectVal = nullptr;
//                 break;
//         }
//     }

//     JsonValue &operator=(const JsonValue &rhs) {
//         if(this == &rhs)
//             return *this;
//         this->~JsonValue();
//         switch(rhs.type) {
//             case DT::null:
//                 numVal = 0.0;
//                 break;
//             case DT::boolean:
//                 boolVal = rhs.boolVal;
//                 break;
//             case DT::number:
//                 numVal = rhs.numVal;
//                 break;
//             case DT::string:
//                 strVal = new std::string{*rhs.strVal};
//                 break;
//             case DT::array:
//                 arrayVal = new std::vector<JsonValue>{*rhs.arrayVal};
//                 break;
//             case DT::object:
//                 objectVal = new std::unordered_map<std::string, JsonValue>{*rhs.objectVal};
//                 break;
//         }
//         return *this;
//     }

//     JsonValue &operator=(JsonValue &&rhs) {
//         if(this == &rhs)
//             return *this;
//         this->~JsonValue();
//         switch(rhs.type) {
//             case DT::null:
//                 numVal = 0.0;
//                 break;
//             case DT::boolean:
//                 boolVal = rhs.boolVal;
//                 break;
//             case DT::number:
//                 numVal = rhs.numVal;
//                 break;
//             case DT::string:
//                 strVal = rhs.strVal;
//                 rhs.strVal = nullptr;
//                 break;
//             case DT::array:
//                 arrayVal = rhs.arrayVal;
//                 rhs.arrayVal = nullptr;
//                 break;
//             case DT::object:
//                 objectVal = rhs.objectVal;
//                 rhs.objectVal = nullptr;
//                 break;
//         }
//         return *this;
//     }
// };

// class JsonParser {
// private:
//     std::string::const_iterator currentChar, end;
//     bool isWhiteSpace(char ch) { return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'; }
//     bool isEOF() { return currentChar == end; }
//     void skipWhiteSpace();
//     JsonValue parseValue();
//     JsonObject parseObject();
//     JsonArray parseArray();
//     std::string parseString();
//     JsonNumber parseNumber();
// public:
//     JsonValue parse(const std::string &jsonText);
    
// };

// void JsonParser::skipWhiteSpace() {
//     while(!isEOF() && isWhiteSpace(*currentChar)) {
//         ++currentChar;
//     }
// }

// JsonValue JsonParser::parse(const std::string &jsonText) {
//     currentChar = jsonText.cbegin();
//     end = jsonText.cend();
// }


// #endif