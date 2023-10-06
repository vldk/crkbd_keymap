


## RGB

I took a big inspiration from Drashna's RGB configuration and tweaked it.

- `RGB_UND`: Toggles underglow indicators on and off. Each layer has its own color.
- `RGB_IDL`: This will enable/disable idle mode. By default an "active" RGB mode will be used. When the idle timeout has exceeded the secondary animation will be activated, which is a passive animation. When switching to `GAMING` layer the timeout will be reduced and the idle animation changed to `RGB_MATRIX_RAINBOW_PINWHEELS`.
   When disabling idle mode, the current idle animation will be activated.
   On idling, on idling, the underglow layer indication will be deactivated and the animation RGB will be set instead.
- `RGB_ATG`: Cylces through three active modes: `RGB_MATRIX_SOLID_REACTIVE_SIMPLE` -> `RGB_MATRIX_TYPING_HEATMAP` -> `RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS`
- `RGB_PST`: Cycles through three passive modes: `RGB_MATRIX_SOLID_COLOR` -> `RGB_MATRIX_BREATHING` -> `RGB_MATRIX_CYCLE_ALL`
- `RGB_PCT`: Cycles through two, more colorful, passive modes: `RGB_MATRIX_RAINBOW_PINWHEELS` -> `RGB_MATRIX_CYCLE_LEFT_RIGHT`

## Building

`qmk flash -bl dfu -kb crkbd -km vldk`

 `qmk flash -kb crkbd -km vldk -bl avrdude-split-left`
 `qmk flash -kb crkbd -km vldk -bl avrdude-split-right`
