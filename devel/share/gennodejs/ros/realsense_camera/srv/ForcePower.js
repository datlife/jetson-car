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

class ForcePowerRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.power_on = null;
    }
    else {
      if (initObj.hasOwnProperty('power_on')) {
        this.power_on = initObj.power_on
      }
      else {
        this.power_on = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ForcePowerRequest
    // Serialize message field [power_on]
    bufferOffset = _serializer.bool(obj.power_on, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ForcePowerRequest
    let len;
    let data = new ForcePowerRequest(null);
    // Deserialize message field [power_on]
    data.power_on = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/ForcePowerRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0a07d78fa0214ec8d773e5045aa5087a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool power_on
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ForcePowerRequest(null);
    if (msg.power_on !== undefined) {
      resolved.power_on = msg.power_on;
    }
    else {
      resolved.power_on = false
    }

    return resolved;
    }
};

class ForcePowerResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ForcePowerResponse
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ForcePowerResponse
    let len;
    let data = new ForcePowerResponse(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/ForcePowerResponse';
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
    const resolved = new ForcePowerResponse(null);
    return resolved;
    }
};

module.exports = {
  Request: ForcePowerRequest,
  Response: ForcePowerResponse,
  md5sum() { return '0a07d78fa0214ec8d773e5045aa5087a'; },
  datatype() { return 'realsense_camera/ForcePower'; }
};
