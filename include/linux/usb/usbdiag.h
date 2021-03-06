/*
 * Copyright (c) 2008-2010, 2012-2014, The Linux Foundation.
 * All rights reserved.
 *
 * All source code in this file is licensed under the following license except
 * where indicated.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can find it at http://www.fsf.org
 */

#ifndef _DRIVERS_USB_DIAG_H_
#define _DRIVERS_USB_DIAG_H_

#include <linux/err.h>

/*++ 2015/07/15, USB Team, PCN00017 ++*/
/*DRIVER_DIAG_FUNCTION*/
#define DIAG_ERR(fmt, args...) \
	printk(KERN_ERR "[USBDIAG:ERR] " fmt, ## args)
#define DIAG_WARNING(fmt, args...) \
	printk(KERN_WARNING "[USBDIAG] " fmt, ## args)
#define DIAG_INFO(fmt, args...) \
	printk(KERN_INFO "[USBDIAG] " fmt, ## args)
#define DIAG_DBUG(fmt, args...) \
	do { \
		if (diag7k_debug_mask) \
			printk(KERN_INFO "[USBDIAG] " fmt, ## args); \
		else \
			pr_debug("[USBDIAG] " fmt, ## args); \
	} while (0)

/*DRIVER_DIAGFWD_FUNCTION*/
#define DIAGFWD_ERR(fmt, args...) \
	printk(KERN_ERR "[DIAGFWD:ERR] " fmt, ## args)
#define DIAGFWD_WARNING(fmt, args...) \
	printk(KERN_WARNING "[DIAGFWD] " fmt, ## args)
#define DIAGFWD_INFO(fmt, args...) \
	printk(KERN_INFO "[DIAGFWD] " fmt, ## args)
#define DIAGFWD_DBUG(fmt, args...) \
	do { \
		if (diag7k_debug_mask) \
			printk(KERN_INFO "[DIAGFWD] " fmt, ## args); \
		else \
			pr_debug("[DIAGFWD] " fmt, ## args); \
	} while (0)


/* DRIVER_SDLOG_FUNCTION*/
#define SDLOG_ERR(fmt, args...) \
	printk(KERN_ERR "[DIAGSDLOG:ERR] " fmt, ## args)
#define SDLOG_WARNING(fmt, args...) \
	printk(KERN_WARNING "[DIAGSDLOG] " fmt, ## args)
#define SDLOG_INFO(fmt, args...) \
	printk(KERN_INFO "[DIAGSDLOG] " fmt, ## args)
#define SDLOG_DBUG(fmt, args...) \
	do { \
		if (diag7k_debug_mask) \
			printk(KERN_INFO "[DIAGSDLOG] " fmt, ## args); \
		else \
			pr_debug("[DIAGSDLOG] " fmt, ## args); \
	} while (0)
#define DIAG_XPST 1        /*++ 2015/10/23, USB Team, PCN00026 ++*/
/*-- 2015/07/15, USB Team, PCN00017 --*/
#define DIAG_LEGACY		"diag"
#define DIAG_MDM		"diag_mdm"
#define DIAG_QSC		"diag_qsc"
#define DIAG_MDM2		"diag_mdm2"

#define USB_DIAG_CONNECT	0
#define USB_DIAG_DISCONNECT	1
#define USB_DIAG_WRITE_DONE	2
#define USB_DIAG_READ_DONE	3

struct diag_request {
	char *buf;
	int length;
	int actual;
	int status;
	void *context;
};

struct usb_diag_ch {
	const char *name;
	struct list_head list;
	void (*notify)(void *priv, unsigned event, struct diag_request *d_req);
	void *priv;
	void *priv_usb;
};

#ifdef CONFIG_USB_G_ANDROID
int usb_diag_request_size(struct usb_diag_ch *ch);
struct usb_diag_ch *usb_diag_open(const char *name, void *priv,
		void (*notify)(void *, unsigned, struct diag_request *));
void usb_diag_close(struct usb_diag_ch *ch);
int usb_diag_alloc_req(struct usb_diag_ch *ch, int n_write, int n_read);
int usb_diag_read(struct usb_diag_ch *ch, struct diag_request *d_req);
int usb_diag_write(struct usb_diag_ch *ch, struct diag_request *d_req);
#else
static inline struct usb_diag_ch *usb_diag_open(const char *name, void *priv,
		void (*notify)(void *, unsigned, struct diag_request *))
{
	return ERR_PTR(-ENODEV);
}
static inline void usb_diag_close(struct usb_diag_ch *ch)
{
}
static inline
int usb_diag_alloc_req(struct usb_diag_ch *ch, int n_write, int n_read)
{
	return -ENODEV;
}
static inline
int usb_diag_read(struct usb_diag_ch *ch, struct diag_request *d_req)
{
	return -ENODEV;
}
static inline
int usb_diag_write(struct usb_diag_ch *ch, struct diag_request *d_req)
{
	return -ENODEV;
}

#endif /* CONFIG_USB_G_ANDROID */
/*++ 2015/10/23, USB Team, PCN00026 ++*/
int checkcmd_modem_epst(unsigned char *buf);
int modem_to_userspace(void *buf, int r, int cmdtype, int is9k);
extern int diag_initialized;
/*-- 2015/10/23, USB Team, PCN00026 --*/
#endif /* _DRIVERS_USB_DIAG_H_ */
