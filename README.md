# Purdue Robomasters Control Base Template
A template repository which containes contains the shared code for Purdue Robomasters robots.

## Workflow and Tools
Write develop code using Kiel uVision.
Projects generated with STM32 CubeMX.
Before writing any changes, commit changes to a new branch, and submit a pull request. DO NOT COMMIT TO MAIN.

## Usage
1. Generate a new repository from this template. 
2. Clone the repository onto your local machine using
```git clone https://github.com/irvingywang/Control-Base-Template.git```
3. Open the project file located in /MDK-ARM/Base_Template.uvprojx using Kiel uVision.

## Development Conventions
**All names must use snake_case.**

Variable names are all lowercase.
```c
 float example_float = 1.5f;
```

Macros should be all UPPERCASE.
```c
 #define EXAMPLE_MACRO 3.14f 
```

Function names should capitalize the first letter of each word.
```c
 float Example_Function() {}
```

Wrapper functions should capitalize the first word.
```c
 float MOTOR_Example_Function() {}
```

Struct names should capitalize the first letter of each word and end in _t. 
```c
 struct Example_Struct_t {} 
```

When using struct pointers, don't put a space between the arrow
```c
 struct Example_Struct_t {
    int example_struct_member;
 } example_struct;
 // access member
 example_struct->example_struct_member;
```

Enum names should capitalized the first letter of each word and end in _e.
```c
 enum Example_Enum_e {};
```

In general, Indent code blocks for functions and if statments as such, but for switches put cases in the same line
```c
void some_func()
{
   if (some_condition)
   {
      switch(some_num)
      {
      case 0:
         break;
      default:
         break;
      }
   }
}
```

For multiline macros, indent as such:
```c
#define YOUR_MACRO        \
   {                      \
      FIRST_LINE = 0,     \
         SECOND_LINE = 1, \
         THIRD_LINE = 2,  \
   }
```