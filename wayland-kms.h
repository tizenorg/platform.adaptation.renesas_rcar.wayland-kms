#ifndef WAYLAND_KMS_H
#define WAYLAND_KMS_H

#include <wayland-server.h>

#ifndef WL_KMS_FORMAT_ENUM
#define WL_KMS_FORMAT_ENUM
enum wl_kms_format {
	WL_KMS_FORMAT_C8 = 0x20203843,
	WL_KMS_FORMAT_RGB332 = 0x38424752,
	WL_KMS_FORMAT_BGR233 = 0x38524742,
	WL_KMS_FORMAT_XRGB4444 = 0x32315258,
	WL_KMS_FORMAT_XBGR4444 = 0x32314258,
	WL_KMS_FORMAT_RGBX4444 = 0x32315852,
	WL_KMS_FORMAT_BGRX4444 = 0x32315842,
	WL_KMS_FORMAT_ARGB4444 = 0x32315241,
	WL_KMS_FORMAT_ABGR4444 = 0x32314241,
	WL_KMS_FORMAT_RGBA4444 = 0x32314152,
	WL_KMS_FORMAT_BGRA4444 = 0x32314142,
	WL_KMS_FORMAT_XRGB1555 = 0x35315258,
	WL_KMS_FORMAT_XBGR1555 = 0x35314258,
	WL_KMS_FORMAT_RGBX5551 = 0x35315852,
	WL_KMS_FORMAT_BGRX5551 = 0x35315842,
	WL_KMS_FORMAT_ARGB1555 = 0x35315241,
	WL_KMS_FORMAT_ABGR1555 = 0x35314241,
	WL_KMS_FORMAT_RGBA5551 = 0x35314152,
	WL_KMS_FORMAT_BGRA5551 = 0x35314142,
	WL_KMS_FORMAT_RGB565 = 0x36314752,
	WL_KMS_FORMAT_BGR565 = 0x36314742,
	WL_KMS_FORMAT_RGB888 = 0x34324752,
	WL_KMS_FORMAT_BGR888 = 0x34324742,
	WL_KMS_FORMAT_XRGB8888 = 0x34325258,
	WL_KMS_FORMAT_XBGR8888 = 0x34324258,
	WL_KMS_FORMAT_RGBX8888 = 0x34325852,
	WL_KMS_FORMAT_BGRX8888 = 0x34325842,
	WL_KMS_FORMAT_ARGB8888 = 0x34325241,
	WL_KMS_FORMAT_ABGR8888 = 0x34324241,
	WL_KMS_FORMAT_RGBA8888 = 0x34324152,
	WL_KMS_FORMAT_BGRA8888 = 0x34324142,
	WL_KMS_FORMAT_XRGB2101010 = 0x30335258,
	WL_KMS_FORMAT_XBGR2101010 = 0x30334258,
	WL_KMS_FORMAT_RGBX1010102 = 0x30335852,
	WL_KMS_FORMAT_BGRX1010102 = 0x30335842,
	WL_KMS_FORMAT_ARGB2101010 = 0x30335241,
	WL_KMS_FORMAT_ABGR2101010 = 0x30334241,
	WL_KMS_FORMAT_RGBA1010102 = 0x30334152,
	WL_KMS_FORMAT_BGRA1010102 = 0x30334142,
	WL_KMS_FORMAT_YUYV = 0x56595559,
	WL_KMS_FORMAT_YVYU = 0x55595659,
	WL_KMS_FORMAT_UYVY = 0x59565955,
	WL_KMS_FORMAT_VYUY = 0x59555956,
	WL_KMS_FORMAT_AYUV = 0x56555941,
	WL_KMS_FORMAT_NV12 = 0x3231564e,
	WL_KMS_FORMAT_NV21 = 0x3132564e,
	WL_KMS_FORMAT_NV16 = 0x3631564e,
	WL_KMS_FORMAT_NV61 = 0x3136564e,
	WL_KMS_FORMAT_YUV410 = 0x39565559,
	WL_KMS_FORMAT_YVU410 = 0x39555659,
	WL_KMS_FORMAT_YUV411 = 0x31315559,
	WL_KMS_FORMAT_YVU411 = 0x31315659,
	WL_KMS_FORMAT_YUV420 = 0x32315559,
	WL_KMS_FORMAT_YVU420 = 0x32315659,
	WL_KMS_FORMAT_YUV422 = 0x36315559,
	WL_KMS_FORMAT_YVU422 = 0x36315659,
	WL_KMS_FORMAT_YUV444 = 0x34325559,
	WL_KMS_FORMAT_YVU444 = 0x34325659,
};
#endif				/* WL_KMS_FORMAT_ENUM */

struct wl_kms;

struct wl_kms_buffer {
	struct wl_resource *resource;
	struct wl_kms *kms;
	int32_t width, height;
	uint32_t stride, format;
	uint32_t handle;
	int fd;
};

struct wl_kms_buffer *wayland_kms_buffer_get(struct wl_resource *resource);

struct wl_kms *wayland_kms_init(struct wl_display *display, char *device_name, int fd);

void wayland_kms_uninit(struct wl_kms *kms);

uint32_t wayland_kms_buffer_get_format(struct wl_kms_buffer *buffer);

void *wayland_kms_buffer_get_buffer(struct wl_kms_buffer *buffer);

enum wl_kms_attribute {
	WL_KMS_WIDTH,
	WL_KMS_HEIGHT,
	WL_KMS_TEXTURE_FORMAT
};

int wayland_kms_query_buffer(struct wl_kms *kms, struct wl_resource *resource,
				enum wl_kms_attribute attr, int *value);

#endif
