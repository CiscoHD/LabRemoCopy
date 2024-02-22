// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_mas:msg/SensorMeasurment.idl
// generated code does not contain a copyright notice

#ifndef MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_HPP_
#define MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_mas__msg__SensorMeasurment __attribute__((deprecated))
#else
# define DEPRECATED__my_mas__msg__SensorMeasurment __declspec(deprecated)
#endif

namespace my_mas
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorMeasurment_
{
  using Type = SensorMeasurment_<ContainerAllocator>;

  explicit SensorMeasurment_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temperature = 0.0f;
    }
  }

  explicit SensorMeasurment_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temperature = 0.0f;
    }
  }

  // field types and members
  using _temperature_type =
    float;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_mas::msg::SensorMeasurment_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_mas::msg::SensorMeasurment_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::SensorMeasurment_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_mas::msg::SensorMeasurment_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_mas__msg__SensorMeasurment
    std::shared_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_mas__msg__SensorMeasurment
    std::shared_ptr<my_mas::msg::SensorMeasurment_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorMeasurment_ & other) const
  {
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorMeasurment_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorMeasurment_

// alias to use template instance with default allocator
using SensorMeasurment =
  my_mas::msg::SensorMeasurment_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_mas

#endif  // MY_MAS__MSG__DETAIL__SENSOR_MEASURMENT__STRUCT_HPP_
