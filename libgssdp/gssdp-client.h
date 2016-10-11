/* 
 * Copyright (C) 2006, 2007 OpenedHand Ltd.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
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
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef GSSDP_CLIENT_H
#define GSSDP_CLIENT_H

#include <glib-object.h>

G_BEGIN_DECLS

#define GSSDP_TYPE_CLIENT (gssdp_client_get_type ())

G_DECLARE_DERIVABLE_TYPE (GSSDPClient, gssdp_client, GSSDP, CLIENT, GObject)

typedef struct _GSSDPClient GSSDPClient;
typedef struct _GSSDPClientClass GSSDPClientClass;

struct _GSSDPClientClass {
        GObjectClass parent_class;

        /* future padding */
        void (* _gssdp_reserved1) (void);
        void (* _gssdp_reserved2) (void);
        void (* _gssdp_reserved3) (void);
        void (* _gssdp_reserved4) (void);
};

GSSDPClient *
gssdp_client_new              (const char   *iface,
                               GError      **error);

GSSDPClient *
gssdp_client_new_with_port    (const char *iface,
                               guint16     msearch_port,
                               GError    **error);

void
gssdp_client_set_server_id    (GSSDPClient  *client,
                               const char   *server_id);

const char *
gssdp_client_get_server_id    (GSSDPClient  *client);

const char *
gssdp_client_get_interface    (GSSDPClient  *client);

const char *
gssdp_client_get_host_ip      (GSSDPClient  *client);

void
gssdp_client_set_network      (GSSDPClient  *client,
                               const char   *network);

const char *
gssdp_client_get_network      (GSSDPClient  *client);

gboolean
gssdp_client_get_active       (GSSDPClient  *client);

void
gssdp_client_append_header    (GSSDPClient *client,
                               const char  *name,
                               const char  *value);

void
gssdp_client_remove_header    (GSSDPClient *client,
                               const char  *name);

void
gssdp_client_clear_headers    (GSSDPClient *client);

void
gssdp_client_add_cache_entry  (GSSDPClient  *client,
                               const char   *ip_address,
                               const char   *user_agent);

const char *
gssdp_client_guess_user_agent (GSSDPClient *client,
                               const char  *ip_address);

G_END_DECLS

#endif /* GSSDP_CLIENT_H */
