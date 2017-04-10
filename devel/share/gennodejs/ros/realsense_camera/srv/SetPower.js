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

class SetPowerRequest {
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
    // Serializes a message object of type SetPowerRequest
    // Serialize message field [power_on]
    bufferOffset = _serializer.bool(obj.power_on, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetPowerRequest
    let len;
    let data = new SetPowerRequest(null);
    // Deserialize message field [power_on]
    data.power_on = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/SetPowerRequest';
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
    const resolved = new SetPowerRequest(null);
    if (msg.power_on !== undefined) {
      resolved.power_on = msg.power_on;
    }
    else {
      resolved.power_on = false
    }

    return resolved;
    }
};

class SetPowerResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetPowerResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetPowerResponse
    let len;
    let data = new SetPowerResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/SetPowerResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetPowerResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: SetPowerRequest,
  Response: SetPowerResponse,
  md5sum() { return 'a0a242e9c383e4ceb1b4d16e36607d54'; },
  datatype() { return 'realsense_camera/SetPower'; }
};
