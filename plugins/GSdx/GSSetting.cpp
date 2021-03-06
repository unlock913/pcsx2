/*
 *	Copyright (C) 2007-2015 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "stdafx.h"
#include "GSSetting.h"
#ifdef _WIN32
#include "resource.h"
#endif

const char* dialog_message(int ID, bool* updateText) {
	if (updateText)
		*updateText = true;
	switch (ID)
	{
		case IDC_FILTER:
			return "Control the texture filtering of the emulation.\n\n"
				"Nearest:\nAlways disable interpolation, rendering will be blocky.\n\n"
				"Bilinear PS2:\nUse same mode as the PS2. It is the more accurate option.\n\n"
				"Bilinear Forced:\nAlways enable interpolation. Rendering is smoother but it could generate some glitches.\n\n"
				"Trilinear:\nUse OpenGL trilinear interpolation when PS2 uses mipmaps.\n\n"
				"Trilinear Forced Bilinear:\nSame as above but always enable bilinear interpolation.\n\n"
				"Trilinear Ultra:\nAlways enable full trilinear interpolation. Warning Slow!\n\n";
		case IDC_CRC_LEVEL:
			return "Control the number of Auto-CRC hacks applied to games.\n\n"
				"None:\nRemove nearly all CRC hacks (debug only).\n\n"
				"Minimum:\nEnable a couple of CRC hacks (23).\n\n"
				"Partial:\nEnable most of the CRC hacks.\nRecommended OpenGL setting (Accurate/depth options may be required).\n\n"
				"Full:\nEnable all CRC hacks.\nRecommended Direct3D setting.\n\n"
				"Aggressive:\nUse more aggressive CRC hacks. Only affects a few games, removing some effects which might make the image sharper/clearer.\n"
				"Affected games: FFX, FFX2, FFXII, GOW2, ICO, SoTC, SSX3, SMT3, SMTDDS1, SMTDDS2.\n"
				"Works as a speedhack for: Steambot Chronicles.";
		case IDC_SKIPDRAWHACK:
		case IDC_SKIPDRAWHACKEDIT:
			return "Skips drawing n surfaces completely. "
				"Use it, for example, to try and get rid of bad post processing effects."
				" Try values between 1 and 100.";
		case IDC_ALPHAHACK:
			return "Different alpha handling. Can work around some shadow problems.";
		case IDC_OFFSETHACK:
			return "Might fix some misaligned fog, bloom, or blend effect.";
		case IDC_SPRITEHACK:
			return "Helps getting rid of black inner lines in some filtered sprites."
				" Half option is the preferred one. Use it for Mana Khemia or Ar tonelico for example."
				" Full can be used for Tales of Destiny.";
		case IDC_WILDHACK:
			return "Lowers the GS precision to avoid gaps between pixels when upscaling. Fixes the text on Wild Arms games.";
		case IDC_MSAACB:
			return "Enables hardware Anti-Aliasing. Needs lots of memory."
				" The Z-24 modes might need to have LogarithmicZ to compensate for the bits lost (only in DX9 mode).\n\n"
				" MSAA is not implemented on the OpenGL renderer.";
		case IDC_ALPHASTENCIL:
			return "Extend stencil based emulation of destination alpha to perform stencil operations while drawing.\n\n"
				"Improves many shadows which are normally overdrawn in parts, may affect other effects.\n"
				"Will disable partial transparency in some games or even prevent drawing some elements altogether.";
		case IDC_CHECK_DISABLE_ALL_HACKS:
			return "FOR TESTING ONLY!!\n\n"
				"Disable all CRC hacks - will break many games. Overrides CrcHacksExclusion at gsdx.ini\n"
				"\n"
				"It's possible to exclude CRC hacks also via the gsdx.ini. E.g.:\n"
				"CrcHacksExclusions=all\n"
				"CrcHacksExclusions=0x0F0C4A9C, 0x0EE5646B, 0x7ACF7E03";
		case IDC_ALIGN_SPRITE:
			return "Fixes issues with upscaling(vertical lines) in Namco games like Ace Combat, Tekken, Soul Calibur, etc.";
		case IDC_ROUND_SPRITE:
			return "Corrects the sampling of 2D sprite textures when upscaling.\n\n"
				"Fixes lines in sprites of games like Ar tonelico when upscaling.\n\n"
				"Half option is for flat sprites, Full is for all sprites.";
		case IDC_TCOFFSETX:
		case IDC_TCOFFSETX2:
		case IDC_TCOFFSETY:
		case IDC_TCOFFSETY2:
			return "Offset for the ST/UV texture coordinates. Fixes some odd texture issues and might fix some post processing alignment too.\n\n"
				"  0500 0500, fixes Persona 3 minimap, helps Haunting Ground.\n"
				"  0000 1000, fixes Xenosaga hair edges (DX10+ Issue)";
		case IDC_PALTEX:
			return "When checked 4/8 bits texture will be send to the GPU with a palette. GPU will be in charge of the conversion.\n\n"
				"When unchecked the CPU will convert directly the texture to 32 bits.\n\n"
				"It is basically a trade-off between GPU/CPU.";
		case IDC_ACCURATE_DATE:
			return "Implement a more accurate algorithm to compute GS destination alpha testing.\n\n"
				"It could be slower when the effects are used.";
		case IDC_ACCURATE_BLEND_UNIT:
			return "Control the accuracy level of the GS blending unit emulation.\n\n"
				"None:\nFast but introduce various rendering issues. It is intended for slow computer.\n\n"
				"Basic:\nEmulate correctly most of the effects with a limited speed penalty. It is the recommended setting.\n\n"
				"Medium:\nExtend it to all sprites. Performance impact remains reasonable in 3D game.\n\n"
				"High:\nExtend it to destination alpha blending and color wrapping. (help shadow and fog effect). A good CPU is required.\n\n"
				"Full:\nExcept few cases, the blending unit will be fully emulated by the shader. It is ultra slow! It is intended for debug.\n\n"
				"Ultra:\nThe blending unit will be completely emulated by the shader. It is ultra slow! It is intended for debug.";
		case IDC_TC_DEPTH:
			return "Disable the support of Depth buffer in the texture cache.\n"
				"It can help to increase speed but it will likely create various glitches.";
		case IDC_AFCOMBO:
			return "Reduces texture aliasing at extreme viewing angles. High performance impact.";
		case IDC_AA1:
			return "Internal GS feature. Reduces edge aliasing of lines and triangles when the game requests it.";
		case IDC_SWTHREADS:
		case IDC_SWTHREADS_EDIT:
			return "Number of rendering threads: 0 for single thread, 2 or more for multithread (1 is for debugging)";
		case IDC_SHADEBOOST:
			return "Allows brightness, contrast and saturation to be manually adjusted.";
		case IDC_SHADER_FX:
			return "Enables external shader for additional post-processing effects.";
		case IDC_FXAA:
			return "Enables fast approximate anti-aliasing. Small performance impact.";
		case IDC_AUTO_FLUSH:
			return "Force a primitive flush when a framebuffer is also an input texture. Fixes some processing effects such as the shadows in the Jak series and radiosity in GTA:SA.\n"
				"Warning: it's very costly on the performance.\n\n"
				"Note: OpenGL HW renderer is able to handle Jak shadows at full speed without this option.";
		case IDC_UNSCALE_POINT_LINE:
			return "Increases the width of lines at higher than native resolutions. This ensures that the lines will keep the correct proportions and prevents aliasing. Avoids empty lines on the screen in games such as Ridge Racer V, and clears FMV's obscured by a grid like Silent Hill series and Dirge of Cerberus.";
#ifdef _WIN32
		// DX9 only
		case IDC_FBA:
			return "Makes textures partially or fully transparent as required by emulation. May cause unusual slowdowns for some games.";
		case IDC_LOGZ:
			return "Treat depth as logarithmic instead of linear. Recommended setting is on unless it causes graphical glitches.";
#endif
#ifdef __linux__
		case IDC_LINEAR_PRESENT:
			return "Use bilinear filtering when Upscaling/Downscaling the image to the screen. Disable it if you want a sharper/pixelated output.";
#endif
		// Exclusive for Hardware Renderer
		case IDC_PRELOAD_GS:
			return "Uploads GS data when rendering a new frame to reproduce some effects accurately. Fixes black screen issues in games like Armored Core: Last Raven.";
		case IDC_MIPMAP:
			return "Enables mipmapping, which some games require to render correctly.";
		case IDC_FAST_TC_INV:
			return "By default, the texture cache handles partial invalidations. Unfortunately it is very costly to compute CPU wise."
				"\n\nThis hack replaces the partial invalidation with a complete deletion of the texture to reduce the CPU load.\n\nIt helps snowblind engine game.";
		case IDC_LARGE_FB:
			return "Allocate a large framebuffer to be compliant with GS memory (Prevents FMV flickering).\n"
				"It increases GPU/memory requirements.";
		default:
			if (updateText)
				*updateText = false;
			return "";
	}
}
