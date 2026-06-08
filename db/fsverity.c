// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2024 Red Hat, Inc.
 * All Rights Reserved.
 */

#include "libxfs.h"
#include "type.h"
#include "faddr.h"
#include "fprint.h"
#include "field.h"
#include "bit.h"
#include "init.h"
#include "fsverity.h"

const struct field	vdesc_hfld[] = {
	{ "", FLDT_FSVERITY_DESCR, OI(0), C1, 0, TYP_NONE },
	{ NULL }
};

#ifdef HAVE_FSVERITY_DESCR
# define	OFF(f)	bitize(offsetof(struct fsverity_descriptor, f))
const field_t	vdesc_flds[] = {
	{ "version", FLDT_UINT8D, OI(OFF(version)), C1, 0, TYP_NONE },
	{ "hash_algorithm", FLDT_UINT8D, OI(OFF(hash_algorithm)), C1, 0, TYP_NONE },
	{ "log_blocksize", FLDT_UINT8D, OI(OFF(log_blocksize)), C1, 0, TYP_NONE },
	{ "salt_size", FLDT_UINT8D, OI(OFF(salt_size)), C1, 0, TYP_NONE },
	{ "data_size", FLDT_UINT64D_LE, OI(OFF(data_size)), C1, 0, TYP_NONE },
	{ "root_hash", FLDT_HEXSTRING, OI(OFF(root_hash)), CI(64), 0, TYP_NONE },
	{ "salt", FLDT_HEXSTRING, OI(OFF(salt)), CI(32), 0, TYP_NONE },
	{ NULL }
};
# undef OFF
#else
const field_t	vdesc_flds[] = {
	{ NULL }
};
#endif

