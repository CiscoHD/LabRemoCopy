// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_mas:msg/SensorMeasurment.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__BUILDER_HPP_
#define MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_mas/msg/detail/sensor_measurment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_mas
{

namespace msg
{

namespace builder
{

class Init_SensorMeasurment_temperature
{
public:
  Init_SensorMeasurment_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_mas::msg::SensorMeasurment temperature(::my_mas::msg::SensorMeasurment::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_mas::msg::SensorMeasurment msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_mas::msg::SensorMeasurment>()
{
  return my_mas::msg::builder::Init_SensorMeasurment_temperature();
}

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__BUILDER_HPP_
