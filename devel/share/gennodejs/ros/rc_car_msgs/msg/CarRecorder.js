// Auto-generated. Do not edit!

// (in-package rc_car_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class CarRecorder {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.img_path = null;
      this.steer = null;
      this.throttle = null;
      this.velocity = null;
    }
    else {
      if (initObj.hasOwnProperty('img_path')) {
        this.img_path = initObj.img_path
      }
      else {
        this.img_path = '';
      }
      if (initObj.hasOwnProperty('steer')) {
        this.steer = initObj.steer
      }
      else {
        this.steer = 0.0;
      }
      if (initObj.hasOwnProperty('throttle')) {
        this.throttle = initObj.throttle
      }
      else {
        this.throttle = 0.0;
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CarRecorder
    // Serialize message field [img_path]
    bufferOffset = _serializer.string(obj.img_path, buffer, bufferOffset);
    // Serialize message field [steer]
    bufferOffset = _serializer.float32(obj.steer, buffer, bufferOffset);
    // Serialize message field [throttle]
    bufferOffset = _serializer.float32(obj.throttle, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.float32(obj.velocity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CarRecorder
    let len;
    let data = new CarRecorder(null);
    // Deserialize message field [img_path]
    data.img_path = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [steer]
    data.steer = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [throttle]
    data.throttle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.img_path.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rc_car_msgs/CarRecorder';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7ff232c3ef1ac97d91355af7dc5015af';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string   img_path
    float32  steer
    float32  throttle
    float32  velocity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CarRecorder(null);
    if (msg.img_path !== undefined) {
      resolved.img_path = msg.img_path;
    }
    else {
      resolved.img_path = ''
    }

    if (msg.steer !== undefined) {
      resolved.steer = msg.steer;
    }
    else {
      resolved.steer = 0.0
    }

    if (msg.throttle !== undefined) {
      resolved.throttle = msg.throttle;
    }
    else {
      resolved.throttle = 0.0
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0.0
    }

    return resolved;
    }
};

module.exports = CarRecorder;
