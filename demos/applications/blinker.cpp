// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-stm32f4/output_pin.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

void delay_by_cycles(int cycles);
hal::status application()
{
  using namespace hal::literals;
  auto led = HAL_CHECK(
    hal::stm32f4::output_pin::get(hal::stm32f4::peripheral::gpio_a, 5));
  HAL_CHECK(led.level(true));
  while (true) {
    HAL_CHECK(led.level(false));
    delay_by_cycles(1000000);
    HAL_CHECK(led.level(true));
    delay_by_cycles(1000000);
  }
}

void delay_by_cycles(int cycles)
{
  volatile int i = 0;
  while (i < cycles) {
    i = i + 1;
  }
}