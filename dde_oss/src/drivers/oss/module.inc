/*
 * \brief  This file is included for every driver
 * \author Sebastian Sumpf
 * \date   2012-11-20
 *
 * See: Files in 'target/build/', which are generated by 'srcconf'
 */

/*
 * Copyright (C) 2012-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#include <oss_config.h>

/* Dummies */
#define DEFINE_CLASS_0(a,b,c,d)
#define TUNABLE_INT(a,b)
#define DRIVER_MODULE(name, b, c, d, e, f)

/* defined in specific driver file */
extern int DRIVER_ATTACH(struct _oss_device_t *);
extern int DRIVER_DETACH(struct _oss_device_t *);

/* setup driver structure */
static struct oss_driver driver =
{
	.name     = DRIVER_NICK,
	.id_table = id_table,
	.attach   = DRIVER_ATTACH,
	.detach   = DRIVER_DETACH
};

/**
 * Register driver upon startup
 */
static void __attribute__((constructor)) init(void)
{
	register_driver(&driver);
}


