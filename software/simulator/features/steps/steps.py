from behave import *
import simulator

@when(u'I start the simulator')
def step_impl(context):
    simulator.start_simulator()


@then(u'the leds are shown')
def step_impl(context):
    raise NotImplementedError(u'STEP: Then the leds are shown')


@then(u'the led animation starts rightaway')
def step_impl(context):
    raise NotImplementedError(u'STEP: Then the led animation starts rightaway')


@given(u'the simulator is running')
def step_impl(context):
    raise NotImplementedError(u'STEP: Given the simulator is running')


@given(u'the animation is running')
def step_impl(context):
    raise NotImplementedError(u'STEP: Given the animation is running')


@then(u'the cube can be rotated with the mouse')
def step_impl(context):
    raise NotImplementedError(u'STEP: Then the cube can be rotated with the mouse')
