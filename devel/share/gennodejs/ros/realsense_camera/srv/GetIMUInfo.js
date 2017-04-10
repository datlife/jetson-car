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

let IMUInfo = require('../msg/IMUInfo.js');

//-----------------------------------------------------------

class GetIMUInfoRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetIMUInfoRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetIMUInfoRequest
    let len;
    let data = new GetIMUInfoRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/GetIMUInfoRequest';
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
    const resolved = new GetIMUInfoRequest(null);
    return resolved;
    }
};

class GetIMUInfoResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.accel = null;
      this.gyro = null;
    }
    else {
      if (initObj.hasOwnProperty('accel')) {
        this.accel = initObj.accel
      }
      else {
        this.accel = new IMUInfo();
      }
      if (initObj.hasOwnProperty('gyro')) {
        this.gyro = initObj.gyro
      }
      else {
        this.gyro = new IMUInfo();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetIMUInfoResponse
    // Serialize message field [accel]
    bufferOffset = IMUInfo.serialize(obj.accel, buffer, bufferOffset);
    // Serialize message field [gyro]
    bufferOffset = IMUInfo.serialize(obj.gyro, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetIMUInfoResponse
    let len;
    let data = new GetIMUInfoResponse(null);
    // Deserialize message field [accel]
    data.accel = IMUInfo.deserialize(buffer, bufferOffset);
    // Deserialize message field [gyro]
    data.gyro = IMUInfo.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += IMUInfo.getMessageSize(object.accel);
    length += IMUInfo.getMessageSize(object.gyro);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'realsense_camera/GetIMUInfoResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fcce7f85a63907f26a3912a7632e9630';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    IMUInfo accel
    IMUInfo gyro
    
    
    ================================================================================
    MSG: realsense_camera/IMUInfo
    # header.frame_id is either set to "imu_accel" or "imu_gyro"
    # to distinguish between "accel" and "gyro" info.
    std_msgs/Header header
    float64[12] data
    float64[3] noise_variances
    float64[3] bias_variances
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetIMUInfoResponse(null);
    if (msg.accel !== undefined) {
      resolved.accel = IMUInfo.Resolve(msg.accel)
    }
    else {
      resolved.accel = new IMUInfo()
    }

    if (msg.gyro !== undefined) {
      resolved.gyro = IMUInfo.Resolve(msg.gyro)
    }
    else {
      resolved.gyro = new IMUInfo()
    }

    return resolved;
    }
};

module.exports = {
  Request: GetIMUInfoRequest,
  Response: GetIMUInfoResponse,
  md5sum() { return 'fcce7f85a63907f26a3912a7632e9630'; },
  datatype() { return 'realsense_camera/GetIMUInfo'; }
};
