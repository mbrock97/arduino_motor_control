#include <ros.h>
#include <Servo.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;
Servo servo;

void servo_cb(const std_msgs::UInt16 &cmd_msg){
  servo.writeMicroseconds(cmd_msg.data);
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  servo.attach(9);
}

void loop() {
  nh.spinOnce();
  delay(1);
}