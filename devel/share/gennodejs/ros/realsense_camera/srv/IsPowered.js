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

class IsPoweredRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IsPoweredRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IsPoweredRequest
    let len;
    let data = new IsPoweredRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/IsPoweredRequest';
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
    const resolved = new IsPoweredRequest(null);
    return resolved;
    }
};

class IsPoweredResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_powered = null;
    }
    else {
      if (initObj.hasOwnProperty('is_powered')) {
        this.is_powered = initObj.is_powered
      }
      else {
        this.is_powered = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IsPoweredResponse
    // Serialize message field [is_powered]
    bufferOffset = _serializer.bool(obj.is_powered, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IsPoweredResponse
    let len;
    let data = new IsPoweredResponse(null);
    // Deserialize message field [is_powered]
    data.is_powered = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/IsPoweredResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7ee632447d6acea26ec2c412cc1e6ed5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_powered
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new IsPoweredResponse(null);
    if (msg.is_powered !== undefined) {
      resolved.is_powered = msg.is_powered;
    }
    else {
      resolved.is_powered = false
    }

    return resolved;
    }
};

module.exports = {
  Request: IsPoweredRequest,
  Response: IsPoweredResponse,
  md5sum() { return '7ee632447d6acea26ec2c412cc1e6ed5'; },
  datatype() { return 'realsense_camera/IsPowered'; }
};
