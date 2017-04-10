// Auto-generated. Do not edit!

// (in-package realsense_camera.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class IMUInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.data = null;
      this.noise_variances = null;
      this.bias_variances = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = new Array(12).fill(0);
      }
      if (initObj.hasOwnProperty('noise_variances')) {
        this.noise_variances = initObj.noise_variances
      }
      else {
        this.noise_variances = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('bias_variances')) {
        this.bias_variances = initObj.bias_variances
      }
      else {
        this.bias_variances = new Array(3).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IMUInfo
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [data] has the right length
    if (obj.data.length !== 12) {
      throw new Error('Unable to serialize array field data - length must be 12')
    }
    // Serialize message field [data]
    bufferOffset = _arraySerializer.float64(obj.data, buffer, bufferOffset, 12);
    // Check that the constant length array field [noise_variances] has the right length
    if (obj.noise_variances.length !== 3) {
      throw new Error('Unable to serialize array field noise_variances - length must be 3')
    }
    // Serialize message field [noise_variances]
    bufferOffset = _arraySerializer.float64(obj.noise_variances, buffer, bufferOffset, 3);
    // Check that the constant length array field [bias_variances] has the right length
    if (obj.bias_variances.length !== 3) {
      throw new Error('Unable to serialize array field bias_variances - length must be 3')
    }
    // Serialize message field [bias_variances]
    bufferOffset = _arraySerializer.float64(obj.bias_variances, buffer, bufferOffset, 3);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IMUInfo
    let len;
    let data = new IMUInfo(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.float64(buffer, bufferOffset, 12)
    // Deserialize message field [noise_variances]
    data.noise_variances = _arrayDeserializer.float64(buffer, bufferOffset, 3)
    // Deserialize message field [bias_variances]
    data.bias_variances = _arrayDeserializer.float64(buffer, bufferOffset, 3)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 144;
  }

  static datatype() {
    // Returns string type for a message object
    return 'realsense_camera/IMUInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b8a77fbb6e4146ae79c8a943413e4f62';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new IMUInfo(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = new Array(12).fill(0)
    }

    if (msg.noise_variances !== undefined) {
      resolved.noise_variances = msg.noise_variances;
    }
    else {
      resolved.noise_variances = new Array(3).fill(0)
    }

    if (msg.bias_variances !== undefined) {
      resolved.bias_variances = msg.bias_variances;
    }
    else {
      resolved.bias_variances = new Array(3).fill(0)
    }

    return resolved;
    }
};

module.exports = IMUInfo;
