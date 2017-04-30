#!/bin/bash
cp ./mods/nvadsp/Makefile.t18x     /usr/src/kernel/t18x/drivers/platform/tegra/nvadsp
cp ./mods/rtcpu/Makefile.t18x      /usr/src/kernel/t18x/drivers/platform/tegra/rtcpu
cp ./mods/devfreq/Makefile         /usr/src/kernel/kernel-4.4/drivers/devfreq
cp ./mods/nvgpu/Makefile.nvgpu     /usr/src/kernel/nvgpu/drivers/gpu/nvgpu
cp ./mods/sound/Makefile           /usr/src/kernel/kernel-4.4/sound/soc/tegra-alt
# Haven't been able to figure out how to correct this properly:
cp /usr/src/kernel/kernel-4.4/drivers/media/platform/tegra/vi/vi.h /usr/src/kernel/t18x/drivers/video/tegra/host/vi


