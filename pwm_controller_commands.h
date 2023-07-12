#ifndef PWM_CONTROLLER_COMMANDS_H
#define PWM_CONTROLLER_COMMANDS_H

// The Serial baud rate used for command communication
// between ESP 01S and ATTiny85.
#define BAUD_RATE 9600

enum Command
{
  CommandStepUp = 'u',
  CommandStepDown = 'd',
  CommandSetValue = 'w',
  CommandGetValue = 'r',
  CommandSetMax = 'm',
  CommandSetMin = '0',
  CommandBlink = 'b',
  CommandReboot = 'p',
  CommandGetState = 's',
  CommandClearState = 'c',
  NoCommandUntilCarriageReturn = '#' 
};

enum State
{
  NormalState = 0,
  RebootRequested = 1,
  FactoryResetRequested = 2
};

// Is an alias of State
enum ButtonState
{
  ButtonUnpressed = 0,
  ButtonPressed = 1,
  ButtonLongPressed = 2
};

enum BlinkMode
{
  BlinkOff = '0',
  BlinkOn = 'm',
  BlinkSlow1s = '1',
  BlinkSlow2s = '2',
  BlinkSlow3s = '3',
  BlinkSlowInfinite = 's',
  BlinkFast1 = 'a',
  BlinkFast2 = 'b',
  BlinkFast3 = 'c',
  BlinkFastInfinite = 'f'
};

enum ExtraArgument
{
  NoExtraArgument = 0,
  ValueExtraArgument,
};

enum ReturnedValue
{
  NoReturnedValue = 0,
  ReturnsValue,
  ErrorCommandNotRecognized,
  ErrorCommandArgumentMissing,
  ErrorCommandTimedout,
};

struct Description
{
  Command command;
  ExtraArgument extraArg;
  ReturnedValue returnsValue;
  const char* message;
};

static const Description descriptions[] =
{
  {
    CommandStepUp,
    NoExtraArgument,
    NoReturnedValue,
    "Increment PWM by a fixed step",
  },
	{
    CommandStepDown,
    NoExtraArgument,
    NoReturnedValue,
    "Decrement PWM by a fixed step",
  },
  {
    CommandSetValue,
    ValueExtraArgument,
    NoReturnedValue,
    "Set PWM to a specific value",
  },
	{
    CommandGetValue,
    NoExtraArgument,
    ReturnsValue,
    "Read the current PWM value",
  },
  {
    CommandSetMax,
    NoExtraArgument,
    NoReturnedValue,
    "Set PWM to maximum value",
  },
  {
    CommandSetMin,
    NoExtraArgument,
    NoReturnedValue,
    "Set PWM to minimum value",
  },
  {
    CommandBlink,
    NoExtraArgument,
    NoReturnedValue,
    "Set LED1 blinking mode"
  },
  {
    CommandReboot,
    NoExtraArgument,
    NoReturnedValue,
    "Reboot the device"
  }
};

#endif // PWM_CONTROLLER_COMMANDS_H

