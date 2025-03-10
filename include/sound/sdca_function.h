/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * The MIPI SDCA specification is available for public downloads at
 * https://www.mipi.org/mipi-sdca-v1-0-download
 *
 * Copyright(c) 2024 Intel Corporation
 */

#ifndef __SDCA_FUNCTION_H__
#define __SDCA_FUNCTION_H__

/*
 * SDCA Function Types from SDCA specification v1.0a Section 5.1.2
 * all Function types not described are reserved
 * Note that SIMPLE_AMP, SIMPLE_MIC and SIMPLE_JACK Function Types
 * are NOT defined in SDCA 1.0a, but they were defined in earlier
 * drafts and are planned for 1.1.
 */

enum sdca_function_type {
	SDCA_FUNCTION_TYPE_SMART_AMP	= 0x01,	/* Amplifier with protection features */
	SDCA_FUNCTION_TYPE_SIMPLE_AMP	= 0x02,	/* subset of SmartAmp */
	SDCA_FUNCTION_TYPE_SMART_MIC	= 0x03,	/* Smart microphone with acoustic triggers */
	SDCA_FUNCTION_TYPE_SIMPLE_MIC	= 0x04,	/* subset of SmartMic */
	SDCA_FUNCTION_TYPE_SPEAKER_MIC	= 0x05,	/* Combination of SmartMic and SmartAmp */
	SDCA_FUNCTION_TYPE_UAJ		= 0x06,	/* 3.5mm Universal Audio jack */
	SDCA_FUNCTION_TYPE_RJ		= 0x07,	/* Retaskable jack */
	SDCA_FUNCTION_TYPE_SIMPLE_JACK	= 0x08,	/* Subset of UAJ */
	SDCA_FUNCTION_TYPE_HID		= 0x0A,	/* Human Interface Device, for e.g. buttons */
	SDCA_FUNCTION_TYPE_IMP_DEF	= 0x1F,	/* Implementation-defined function */
};

/* Human-readable names used for kernel logs and Function device registration/bind */
#define	SDCA_FUNCTION_TYPE_SMART_AMP_NAME	"SmartAmp"
#define	SDCA_FUNCTION_TYPE_SIMPLE_AMP_NAME	"SimpleAmp"
#define	SDCA_FUNCTION_TYPE_SMART_MIC_NAME	"SmartMic"
#define	SDCA_FUNCTION_TYPE_SIMPLE_MIC_NAME	"SimpleMic"
#define	SDCA_FUNCTION_TYPE_SPEAKER_MIC_NAME	"SpeakerMic"
#define	SDCA_FUNCTION_TYPE_UAJ_NAME		"UAJ"
#define	SDCA_FUNCTION_TYPE_RJ_NAME		"RJ"
#define	SDCA_FUNCTION_TYPE_SIMPLE_NAME		"SimpleJack"
#define	SDCA_FUNCTION_TYPE_HID_NAME		"HID"

enum sdca_entity0_controls {
	SDCA_CTL_ENTITY_0_COMMIT_GROUP_MASK		= 0x01,
	SDCA_CTL_ENTITY_0_FUNCTION_SDCA_VERSION		= 0x04,
	SDCA_CTL_ENTITY_0_FUNCTION_TYPE			= 0x05,
	SDCA_CTL_ENTITY_0_FUNCTION_MANUFACTURER_ID	= 0x06,
	SDCA_CTL_ENTITY_0_FUNCTION_ID			= 0x07,
	SDCA_CTL_ENTITY_0_FUNCTION_VERSION		= 0x08,
	SDCA_CTL_ENTITY_0_FUNCTION_EXTENSION_ID		= 0x09,
	SDCA_CTL_ENTITY_0_FUNCTION_EXTENSION_VERSION	= 0x0A,
	SDCA_CTL_ENTITY_0_FUNCTION_STATUS		= 0x10,
	SDCA_CTL_ENTITY_0_FUNCTION_ACTION		= 0x11,
	SDCA_CTL_ENTITY_0_MATCHING_GUID			= 0x12,
	SDCA_CTL_ENTITY_0_DEVICE_MANUFACTURER_ID	= 0x2C,
	SDCA_CTL_ENTITY_0_DEVICE_PART_ID		= 0x2D,
	SDCA_CTL_ENTITY_0_DEVICE_VERSION		= 0x2E,
	SDCA_CTL_ENTITY_0_DEVICE_SDCA_VERSION		= 0x2F,

	/* Function Status Bits */
	SDCA_CTL_ENTITY_0_DEVICE_NEWLY_ATTACHED		= BIT(0),
	SDCA_CTL_ENTITY_0_INTS_DISABLED_ABNORMALLY	= BIT(1),
	SDCA_CTL_ENTITY_0_STREAMING_STOPPED_ABNORMALLY	= BIT(2),
	SDCA_CTL_ENTITY_0_FUNCTION_FAULT		= BIT(3),
	SDCA_CTL_ENTITY_0_UMP_SEQUENCE_FAULT		= BIT(4),
	SDCA_CTL_ENTITY_0_FUNCTION_NEEDS_INITIALIZATION	= BIT(5),
	SDCA_CTL_ENTITY_0_FUNCTION_HAS_BEEN_RESET	= BIT(6),
	SDCA_CTL_ENTITY_0_FUNCTION_BUSY			= BIT(7),
};

#endif
