// Auto-generated. Do not edit!

// (in-package realsense_camera.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class CameraConfigurationRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CameraConfigurationRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CameraConfigurationRequest
    let len;
    let data = new CameraConfigurationRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/CameraConfigurationRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CameraConfigurationRequest(null);
    return resolved;
    }
};

class CameraConfigurationResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.configuration_str = null;
    }
    else {
      if (initObj.hasOwnProperty('configuration_str')) {
        this.configuration_str = initObj.configuration_str
      }
      else {
        this.configuration_str = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CameraConfigurationResponse
    // Serialize message field [configuration_str]
    bufferOffset = _serializer.string(obj.configuration_str, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CameraConfigurationResponse
    let len;
    let data = new CameraConfigurationResponse(null);
    // Deserialize message field [configuration_str]
    data.configuration_str = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.configuration_str.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/CameraConfigurationResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2c284890309b239ca006a289ca29b4d1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string configuration_str
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CameraConfigurationResponse(null);
    if (msg.configuration_str !== undefined) {
      resolved.configuration_str = msg.configuration_str;
    }
    else {
      resolved.configuration_str = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: CameraConfigurationRequest,
  Response: CameraConfigurationResponse,
  md5sum() { return '2c284890309b239ca006a289ca29b4d1'; },
  datatype() { return 'realsense_camera/CameraConfiguration'; }
};
