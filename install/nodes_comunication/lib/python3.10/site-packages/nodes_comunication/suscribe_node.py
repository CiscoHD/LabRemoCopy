#!/usr/bin/env python3
import rospy 
from std_msgs.msg import String
from nodes_comunication.msg import measure_sensor

def callback(data):
    rospy.loginfo(f"Data Recived:({data.x},{data.y},{data.z})")

def listener():
    rospy.init_node("subscriber_Node",anonymous=True)
    rospy.Subcriber('Measure_Arduino',measure_sensor,callback)
    rospy.Spin()

if __name__ == '__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass