/*
 * Copyright 2025 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */
/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --user-data-dir=C:\Users\ZhangHan\AppData\Roaming\gui-guider --app-path=D:\Gui-Guider\resources\app.asar --no-sandbox --no-zygote --lang=zh-CN --device-scale-factor=1.75 --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=5 --time-ticks-at-unix-epoch=-1736483987085072 --launch-time-ticks=595470919 --mojo-platform-channel-handle=3000 --field-trial-handle=1756,i,7509744286013016899,15836359809165352679,131072 --disable-features=SpareRendererForSitePerProcess,WinRetrieveSuggestionsOnlyOnDemand /prefetch:1
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef LV_CUSTOMER_FONT_SIMKAI_20
#define LV_CUSTOMER_FONT_SIMKAI_20 1
#endif

#if LV_CUSTOMER_FONT_SIMKAI_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+538B "压" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x15, 0x60,
    0x0, 0x0, 0x0, 0x0, 0x83, 0x24, 0x7a, 0xdf,
    0xea, 0x10, 0x0, 0x0, 0x0, 0xd, 0xb9, 0x87,
    0x53, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc5,
    0x0, 0x8, 0x91, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xd, 0x30, 0x0, 0x5f, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf1, 0x0, 0x3, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0x0, 0x0, 0x2f, 0x4,
    0x50, 0x0, 0x0, 0x0, 0x6, 0xb0, 0x5, 0x7b,
    0xff, 0xc8, 0x0, 0x0, 0x0, 0x0, 0xa8, 0x0,
    0x46, 0x7f, 0x1, 0x0, 0x0, 0x0, 0x0, 0xe,
    0x40, 0x0, 0x2, 0xe0, 0x5e, 0x40, 0x0, 0x0,
    0x3, 0xe0, 0x0, 0x0, 0x2d, 0x0, 0x7d, 0x0,
    0x0, 0x0, 0xa8, 0x0, 0x0, 0x3, 0xd0, 0x0,
    0x20, 0x0, 0x0, 0x2d, 0x0, 0x0, 0x24, 0x8e,
    0x8a, 0xcd, 0xea, 0x0, 0xb, 0x30, 0xbe, 0xdb,
    0x97, 0x65, 0x44, 0x44, 0x51, 0x7, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+544A "告" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xd5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0x0, 0xe7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0x50, 0xe5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x10, 0xe8,
    0x8b, 0x50, 0x0, 0x0, 0x0, 0x0, 0x1, 0xec,
    0xce, 0xfd, 0xa7, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x9, 0x30, 0x21, 0xe2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xe1, 0x0, 0x1,
    0x21, 0x0, 0x0, 0x0, 0x0, 0x24, 0x79, 0xfc,
    0xde, 0xff, 0xff, 0x80, 0xa, 0xcd, 0xfe, 0xca,
    0x87, 0x53, 0x21, 0x0, 0x12, 0x20, 0x1, 0x54,
    0x10, 0x0, 0x0, 0x0, 0x22, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x64, 0x46, 0x9c, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xed, 0x64, 0x20,
    0x5f, 0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9b,
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5c, 0x0, 0x0, 0x8c, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2e, 0x68, 0xac, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0x54, 0x32,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+7535 "电" */
    0x0, 0x0, 0x3, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xf3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0x20, 0x1, 0x30,
    0x0, 0x0, 0x1, 0x0, 0x24, 0xf9, 0x9b, 0xdf,
    0xc2, 0x0, 0x0, 0xee, 0xb8, 0x6f, 0x10, 0x0,
    0xff, 0x40, 0x0, 0x7, 0xb0, 0x0, 0xe0, 0x0,
    0xf, 0x90, 0x0, 0x0, 0x3d, 0x5, 0x9f, 0xee,
    0x43, 0xf3, 0x0, 0x0, 0x0, 0xf1, 0x45, 0xe1,
    0x0, 0x6c, 0x0, 0x0, 0x0, 0xc, 0x20, 0x1d,
    0x0, 0xb, 0x50, 0x0, 0x0, 0x0, 0x98, 0x69,
    0xfb, 0xba, 0xd0, 0x0, 0x0, 0x0, 0x4, 0x83,
    0x2d, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xe0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0,
    0x0, 0xf, 0x10, 0x0, 0x0, 0x9, 0x20, 0x0,
    0x0, 0x0, 0xac, 0x30, 0x0, 0x6, 0xf8, 0x0,
    0x0, 0x0, 0x1, 0xaf, 0xfe, 0xef, 0xfb, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x13, 0x44, 0x20, 0x0,
    0x0,

    /* U+8B66 "警" */
    0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x50, 0xf, 0x20, 0x1d,
    0x10, 0x0, 0x0, 0x0, 0x0, 0xc, 0x75, 0xea,
    0xa4, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x6b, 0xca,
    0xa7, 0x31, 0xa3, 0x38, 0x80, 0x0, 0x0, 0x0,
    0x5, 0x14, 0x0, 0x1a, 0x8e, 0x40, 0x0, 0x0,
    0x0, 0x8, 0xd5, 0x7b, 0x85, 0x61, 0xe1, 0x0,
    0x0, 0x0, 0x5, 0x42, 0x81, 0x77, 0x2, 0xdc,
    0x30, 0x0, 0x0, 0x0, 0xd, 0x3b, 0x5d, 0x30,
    0x68, 0x4d, 0xe9, 0x50, 0x0, 0x0, 0x99, 0xa4,
    0xa8, 0x72, 0x0, 0x4, 0x20, 0x0, 0x0, 0x1,
    0x0, 0x0, 0x2a, 0x12, 0x45, 0x79, 0x82, 0x2,
    0x57, 0x89, 0xab, 0xbb, 0xb9, 0x87, 0x65, 0x54,
    0x10, 0x5, 0x64, 0x21, 0x13, 0x69, 0xa2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x87, 0x42,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x7a,
    0xbc, 0xa2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa, 0x74, 0x45, 0x8f, 0x60, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x69, 0x0, 0x3, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xc7, 0x89, 0xac,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 320, .box_w = 19, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 152, .adv_w = 320, .box_w = 20, .box_h = 19, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 342, .adv_w = 320, .box_w = 17, .box_h = 17, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 487, .adv_w = 320, .box_w = 19, .box_h = 20, .ofs_x = 0, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xbf, 0x21aa, 0x37db
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 21387, .range_length = 14300, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_customer_font_simkai_20 = {
#else
lv_font_t lv_customer_font_simkai_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font  default: (f.src.ascent - f.src.descent)*/
    .base_line = 4,                          /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_CUSTOMER_FONT_SIMKAI_20*/

