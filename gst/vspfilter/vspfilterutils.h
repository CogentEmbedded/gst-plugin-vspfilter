/* GStreamer
 * Copyright (C) 2016 Renesas Electronics Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_VSPFILTER_UTILS_H__
#define __GST_VSPFILTER_UTILS_H__

#include <gst/video/video.h>
#include <linux/v4l2-mediabus.h>

#define CLEAR(x) memset (&(x), 0, sizeof (x))

static inline const gchar *
buftype_str (enum v4l2_buf_type buftype)
{
  if (buftype == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE)
    return "output";
  if (buftype == V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
    return "capture";

  return "unknown";
}

gint set_colorspace (GstVideoFormat vid_fmt, guint * fourcc,
    enum v4l2_mbus_pixelcode * code, guint * n_planes);
gint xioctl (gint fd, gint request, void * arg);
gboolean set_format (gint fd, guint width, guint height, guint format,
    gint stride[GST_VIDEO_MAX_PLANES], enum v4l2_buf_type buftype,
    enum v4l2_memory io);
gboolean request_buffers (gint fd, enum v4l2_buf_type buftype, guint * n_bufs,
    enum v4l2_memory io);

#endif /*__GST_VSPFILTER_UTILS_H__*/
