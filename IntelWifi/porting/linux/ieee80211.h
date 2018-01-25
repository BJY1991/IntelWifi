//
//  ieee80211.h
//  IntelWifi
//
//  Created by Roman Peshkov on 28/12/2017.
//  Copyright © 2017 Roman Peshkov. All rights reserved.
//

#ifndef ieee80211_h
#define ieee80211_h

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/netdevice.h>


#define IEEE80211_FCTL_VERS        0x0003
#define IEEE80211_FCTL_FTYPE        0x000c
#define IEEE80211_FCTL_STYPE        0x00f0
#define IEEE80211_FCTL_TODS        0x0100
#define IEEE80211_FCTL_FROMDS        0x0200
#define IEEE80211_FCTL_MOREFRAGS    0x0400
#define IEEE80211_FCTL_RETRY        0x0800
#define IEEE80211_FCTL_PM        0x1000
#define IEEE80211_FCTL_MOREDATA        0x2000
#define IEEE80211_FCTL_PROTECTED    0x4000
#define IEEE80211_FCTL_ORDER        0x8000
#define IEEE80211_FCTL_CTL_EXT        0x0f00


// line 149
/* miscellaneous IEEE 802.11 constants */
#define IEEE80211_MAX_FRAG_THRESHOLD    2352
#define IEEE80211_MAX_RTS_THRESHOLD    2353
#define IEEE80211_MAX_AID        2007
#define IEEE80211_MAX_TIM_LEN        251
#define IEEE80211_MAX_MESH_PEERINGS    63
/* Maximum size for the MA-UNITDATA primitive, 802.11 standard section
 6.2.1.1.2.
 
 802.11e clarifies the figure in section 7.1.2. The frame body is
 up to 2304 octets long (maximum MSDU size) plus any crypt overhead. */
#define IEEE80211_MAX_DATA_LEN        2304
/* 802.11ad extends maximum MSDU size for DMG (freq > 40Ghz) networks
 * to 7920 bytes, see 8.2.3 General frame format
 */
#define IEEE80211_MAX_DATA_LEN_DMG    7920
/* 30 byte 4 addr hdr, 2 byte QoS, 2304 byte MSDU, 12 byte crypt, 4 byte FCS */
#define IEEE80211_MAX_FRAME_LEN        2352

/* Maximal size of an A-MSDU that can be transported in a HT BA session */
#define IEEE80211_MAX_MPDU_LEN_HT_BA        4095

/* Maximal size of an A-MSDU */
#define IEEE80211_MAX_MPDU_LEN_HT_3839        3839
#define IEEE80211_MAX_MPDU_LEN_HT_7935        7935

#define IEEE80211_MAX_MPDU_LEN_VHT_3895        3895
#define IEEE80211_MAX_MPDU_LEN_VHT_7991        7991
#define IEEE80211_MAX_MPDU_LEN_VHT_11454    11454

#define IEEE80211_MAX_SSID_LEN        32

#define IEEE80211_MAX_MESH_ID_LEN    32

#define IEEE80211_FIRST_TSPEC_TSID    8
#define IEEE80211_NUM_TIDS        16

/* number of user priorities 802.11 uses */
#define IEEE80211_NUM_UPS        8
/* number of ACs */
#define IEEE80211_NUM_ACS        4

#define IEEE80211_QOS_CTL_LEN        2
/* 1d tag mask */
#define IEEE80211_QOS_CTL_TAG1D_MASK        0x0007
/* TID mask */
#define IEEE80211_QOS_CTL_TID_MASK        0x000f
/* EOSP */
#define IEEE80211_QOS_CTL_EOSP            0x0010
/* ACK policy */
#define IEEE80211_QOS_CTL_ACK_POLICY_NORMAL    0x0000
#define IEEE80211_QOS_CTL_ACK_POLICY_NOACK    0x0020
#define IEEE80211_QOS_CTL_ACK_POLICY_NO_EXPL    0x0040
#define IEEE80211_QOS_CTL_ACK_POLICY_BLOCKACK    0x0060
#define IEEE80211_QOS_CTL_ACK_POLICY_MASK    0x0060
/* A-MSDU 802.11n */
#define IEEE80211_QOS_CTL_A_MSDU_PRESENT    0x0080
/* Mesh Control 802.11s */
#define IEEE80211_QOS_CTL_MESH_CONTROL_PRESENT  0x0100

/* Mesh Power Save Level */
#define IEEE80211_QOS_CTL_MESH_PS_LEVEL        0x0200
/* Mesh Receiver Service Period Initiated */
#define IEEE80211_QOS_CTL_RSPI            0x0400

/* U-APSD queue for WMM IEs sent by AP */
#define IEEE80211_WMM_IE_AP_QOSINFO_UAPSD    (1<<7)
#define IEEE80211_WMM_IE_AP_QOSINFO_PARAM_SET_CNT_MASK    0x0f

/* U-APSD queues for WMM IEs sent by STA */
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_VO    (1<<0)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_VI    (1<<1)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_BK    (1<<2)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_BE    (1<<3)
#define IEEE80211_WMM_IE_STA_QOSINFO_AC_MASK    0x0f

/* U-APSD max SP length for WMM IEs sent by STA */
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_ALL    0x00
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_2    0x01
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_4    0x02
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_6    0x03
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_MASK    0x03
#define IEEE80211_WMM_IE_STA_QOSINFO_SP_SHIFT    5



/* 802.11 BAR control masks */
#define IEEE80211_BAR_CTRL_ACK_POLICY_NORMAL    0x0000
#define IEEE80211_BAR_CTRL_MULTI_TID        0x0002
#define IEEE80211_BAR_CTRL_CBMTID_COMPRESSED_BA    0x0004
#define IEEE80211_BAR_CTRL_TID_INFO_MASK    0xf000
#define IEEE80211_BAR_CTRL_TID_INFO_SHIFT    12

#define IEEE80211_HT_MCS_MASK_LEN        10

// line 188
/* number of ACs */
#define IEEE80211_NUM_ACS        4


struct mac_address {
    u8 addr[ETH_ALEN];
};



/* Notice of Absence attribute - described in P2P spec 4.1.14 */
/* Typical max value used here */
#define IEEE80211_P2P_NOA_DESC_MAX    4

struct ieee80211_p2p_noa_desc {
    u8 count;
    __le32 duration;
    __le32 interval;
    __le32 start_time;
} __packed;

struct ieee80211_p2p_noa_attr {
    u8 index;
    u8 oppps_ctwindow;
    struct ieee80211_p2p_noa_desc desc[IEEE80211_P2P_NOA_DESC_MAX];
} __packed;

#define IEEE80211_P2P_OPPPS_ENABLE_BIT        BIT(7)
#define IEEE80211_P2P_OPPPS_CTWINDOW_MASK    0x7F

/**
 * struct ieee80211_bar - HT Block Ack Request
 *
 * This structure refers to "HT BlockAckReq" as
 * described in 802.11n draft section 7.2.1.7.1
 */
struct ieee80211_bar {
    __le16 frame_control;
    __le16 duration;
    __u8 ra[ETH_ALEN];
    __u8 ta[ETH_ALEN];
    __le16 control;
    __le16 start_seq_num;
} __packed;

/* 802.11 BAR control masks */
#define IEEE80211_BAR_CTRL_ACK_POLICY_NORMAL    0x0000
#define IEEE80211_BAR_CTRL_MULTI_TID        0x0002
#define IEEE80211_BAR_CTRL_CBMTID_COMPRESSED_BA    0x0004
#define IEEE80211_BAR_CTRL_TID_INFO_MASK    0xf000
#define IEEE80211_BAR_CTRL_TID_INFO_SHIFT    12

#define IEEE80211_HT_MCS_MASK_LEN        10


/**
 * line 1257
 * struct ieee80211_mcs_info - MCS information
 * @rx_mask: RX mask
 * @rx_highest: highest supported RX rate. If set represents
 *    the highest supported RX data rate in units of 1 Mbps.
 *    If this field is 0 this value should not be used to
 *    consider the highest RX data rate supported.
 * @tx_params: TX parameters
 */
struct ieee80211_mcs_info {
    u8 rx_mask[IEEE80211_HT_MCS_MASK_LEN];
    __le16 rx_highest;
    u8 tx_params;
    u8 reserved[3];
} __packed;

/* 802.11n HT capability MSC set */
#define IEEE80211_HT_MCS_RX_HIGHEST_MASK    0x3ff
#define IEEE80211_HT_MCS_TX_DEFINED        0x01
#define IEEE80211_HT_MCS_TX_RX_DIFF        0x02
/* value 0 == 1 stream etc */
#define IEEE80211_HT_MCS_TX_MAX_STREAMS_MASK    0x0C
#define IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT    2
#define        IEEE80211_HT_MCS_TX_MAX_STREAMS    4
#define IEEE80211_HT_MCS_TX_UNEQUAL_MODULATION    0x10



/*
 * 802.11n D5.0 20.3.5 / 20.6 says:
 * - indices 0 to 7 and 32 are single spatial stream
 * - 8 to 31 are multiple spatial streams using equal modulation
 *   [8..15 for two streams, 16..23 for three and 24..31 for four]
 * - remainder are multiple spatial streams using unequal modulation
 */
#define IEEE80211_HT_MCS_UNEQUAL_MODULATION_START 33
#define IEEE80211_HT_MCS_UNEQUAL_MODULATION_START_BYTE \
(IEEE80211_HT_MCS_UNEQUAL_MODULATION_START / 8)

/**
 * struct ieee80211_ht_cap - HT capabilities
 *
 * This structure is the "HT capabilities element" as
 * described in 802.11n D5.0 7.3.2.57
 */
struct ieee80211_ht_cap {
    __le16 cap_info;
    u8 ampdu_params_info;
    
    /* 16 bytes MCS information */
    struct ieee80211_mcs_info mcs;
    
    __le16 extended_ht_cap_info;
    __le32 tx_BF_cap_info;
    u8 antenna_selection_info;
} __packed;


/* 802.11n HT capabilities masks (for cap_info) */
#define IEEE80211_HT_CAP_LDPC_CODING        0x0001
#define IEEE80211_HT_CAP_SUP_WIDTH_20_40    0x0002
#define IEEE80211_HT_CAP_SM_PS            0x000C
#define        IEEE80211_HT_CAP_SM_PS_SHIFT    2
#define IEEE80211_HT_CAP_GRN_FLD        0x0010
#define IEEE80211_HT_CAP_SGI_20            0x0020
#define IEEE80211_HT_CAP_SGI_40            0x0040
#define IEEE80211_HT_CAP_TX_STBC        0x0080
#define IEEE80211_HT_CAP_RX_STBC        0x0300
#define        IEEE80211_HT_CAP_RX_STBC_SHIFT    8
#define IEEE80211_HT_CAP_DELAY_BA        0x0400
#define IEEE80211_HT_CAP_MAX_AMSDU        0x0800
#define IEEE80211_HT_CAP_DSSSCCK40        0x1000
#define IEEE80211_HT_CAP_RESERVED        0x2000
#define IEEE80211_HT_CAP_40MHZ_INTOLERANT    0x4000
#define IEEE80211_HT_CAP_LSIG_TXOP_PROT        0x8000

/* 802.11n HT extended capabilities masks (for extended_ht_cap_info) */
#define IEEE80211_HT_EXT_CAP_PCO        0x0001
#define IEEE80211_HT_EXT_CAP_PCO_TIME        0x0006
#define        IEEE80211_HT_EXT_CAP_PCO_TIME_SHIFT    1
#define IEEE80211_HT_EXT_CAP_M4CS_FB        0x0300
#define        IEEE80211_HT_EXT_CAP_MCS_FB_SHIFT    8
#define IEEE80211_HT_EXT_CAP_HTC_SUP        0x0400
#define IEEE80211_HT_EXT_CAP_RD_RESPONDER    0x0800

/* 802.11n HT capability AMPDU settings (for ampdu_params_info) */
#define IEEE80211_HT_AMPDU_PARM_FACTOR        0x03
#define IEEE80211_HT_AMPDU_PARM_DENSITY        0x1C
#define        IEEE80211_HT_AMPDU_PARM_DENSITY_SHIFT    2


// line 870
#define WLAN_SA_QUERY_TR_ID_LEN 2
#define WLAN_MEMBERSHIP_LEN 8
#define WLAN_USER_POSITION_LEN 16




/* line 1344
 * Maximum length of AMPDU that the STA can receive in high-throughput (HT).
 * Length = 2 ^ (13 + max_ampdu_length_exp) - 1 (octets)
 */
enum ieee80211_max_ampdu_length_exp {
    IEEE80211_HT_MAX_AMPDU_8K = 0,
    IEEE80211_HT_MAX_AMPDU_16K = 1,
    IEEE80211_HT_MAX_AMPDU_32K = 2,
    IEEE80211_HT_MAX_AMPDU_64K = 3
};

/* line 1355
 * Maximum length of AMPDU that the STA can receive in VHT.
 * Length = 2 ^ (13 + max_ampdu_length_exp) - 1 (octets)
 */
enum ieee80211_vht_max_ampdu_length_exp {
    IEEE80211_VHT_MAX_AMPDU_8K = 0,
    IEEE80211_VHT_MAX_AMPDU_16K = 1,
    IEEE80211_VHT_MAX_AMPDU_32K = 2,
    IEEE80211_VHT_MAX_AMPDU_64K = 3,
    IEEE80211_VHT_MAX_AMPDU_128K = 4,
    IEEE80211_VHT_MAX_AMPDU_256K = 5,
    IEEE80211_VHT_MAX_AMPDU_512K = 6,
    IEEE80211_VHT_MAX_AMPDU_1024K = 7
};

#define IEEE80211_HT_MAX_AMPDU_FACTOR 13

/* Minimum MPDU start spacing */
enum ieee80211_min_mpdu_spacing {
    IEEE80211_HT_MPDU_DENSITY_NONE = 0,    /* No restriction */
    IEEE80211_HT_MPDU_DENSITY_0_25 = 1,    /* 1/4 usec */
    IEEE80211_HT_MPDU_DENSITY_0_5 = 2,    /* 1/2 usec */
    IEEE80211_HT_MPDU_DENSITY_1 = 3,    /* 1 usec */
    IEEE80211_HT_MPDU_DENSITY_2 = 4,    /* 2 usec */
    IEEE80211_HT_MPDU_DENSITY_4 = 5,    /* 4 usec */
    IEEE80211_HT_MPDU_DENSITY_8 = 6,    /* 8 usec */
    IEEE80211_HT_MPDU_DENSITY_16 = 7    /* 16 usec */
};


/**
 * line 1453
 * struct ieee80211_vht_mcs_info - VHT MCS information
 * @rx_mcs_map: RX MCS map 2 bits for each stream, total 8 streams
 * @rx_highest: Indicates highest long GI VHT PPDU data rate
 *    STA can receive. Rate expressed in units of 1 Mbps.
 *    If this field is 0 this value should not be used to
 *    consider the highest RX data rate supported.
 *    The top 3 bits of this field are reserved.
 * @tx_mcs_map: TX MCS map 2 bits for each stream, total 8 streams
 * @tx_highest: Indicates highest long GI VHT PPDU data rate
 *    STA can transmit. Rate expressed in units of 1 Mbps.
 *    If this field is 0 this value should not be used to
 *    consider the highest TX data rate supported.
 *    The top 3 bits of this field are reserved.
 */
struct ieee80211_vht_mcs_info {
    __le16 rx_mcs_map;
    __le16 rx_highest;
    __le16 tx_mcs_map;
    __le16 tx_highest;
} __packed;

struct ieee80211_hdr {
    __le16 frame_control;
    __le16 duration_id;
    u8 addr1[ETH_ALEN];
    u8 addr2[ETH_ALEN];
    u8 addr3[ETH_ALEN];
    __le16 seq_ctrl;
    u8 addr4[ETH_ALEN];
} __packed __aligned(2);

/* line 1791
 * Information Element IDs
 */
enum ieee80211_eid {
    WLAN_EID_SSID = 0,
    WLAN_EID_SUPP_RATES = 1,
    WLAN_EID_FH_PARAMS = 2, /* reserved now */
    WLAN_EID_DS_PARAMS = 3,
    WLAN_EID_CF_PARAMS = 4,
    WLAN_EID_TIM = 5,
    WLAN_EID_IBSS_PARAMS = 6,
    WLAN_EID_COUNTRY = 7,
    /* 8, 9 reserved */
    WLAN_EID_REQUEST = 10,
    WLAN_EID_QBSS_LOAD = 11,
    WLAN_EID_EDCA_PARAM_SET = 12,
    WLAN_EID_TSPEC = 13,
    WLAN_EID_TCLAS = 14,
    WLAN_EID_SCHEDULE = 15,
    WLAN_EID_CHALLENGE = 16,
    /* 17-31 reserved for challenge text extension */
    WLAN_EID_PWR_CONSTRAINT = 32,
    WLAN_EID_PWR_CAPABILITY = 33,
    WLAN_EID_TPC_REQUEST = 34,
    WLAN_EID_TPC_REPORT = 35,
    WLAN_EID_SUPPORTED_CHANNELS = 36,
    WLAN_EID_CHANNEL_SWITCH = 37,
    WLAN_EID_MEASURE_REQUEST = 38,
    WLAN_EID_MEASURE_REPORT = 39,
    WLAN_EID_QUIET = 40,
    WLAN_EID_IBSS_DFS = 41,
    WLAN_EID_ERP_INFO = 42,
    WLAN_EID_TS_DELAY = 43,
    WLAN_EID_TCLAS_PROCESSING = 44,
    WLAN_EID_HT_CAPABILITY = 45,
    WLAN_EID_QOS_CAPA = 46,
    /* 47 reserved for Broadcom */
    WLAN_EID_RSN = 48,
    WLAN_EID_802_15_COEX = 49,
    WLAN_EID_EXT_SUPP_RATES = 50,
    WLAN_EID_AP_CHAN_REPORT = 51,
    WLAN_EID_NEIGHBOR_REPORT = 52,
    WLAN_EID_RCPI = 53,
    WLAN_EID_MOBILITY_DOMAIN = 54,
    WLAN_EID_FAST_BSS_TRANSITION = 55,
    WLAN_EID_TIMEOUT_INTERVAL = 56,
    WLAN_EID_RIC_DATA = 57,
    WLAN_EID_DSE_REGISTERED_LOCATION = 58,
    WLAN_EID_SUPPORTED_REGULATORY_CLASSES = 59,
    WLAN_EID_EXT_CHANSWITCH_ANN = 60,
    WLAN_EID_HT_OPERATION = 61,
    WLAN_EID_SECONDARY_CHANNEL_OFFSET = 62,
    WLAN_EID_BSS_AVG_ACCESS_DELAY = 63,
    WLAN_EID_ANTENNA_INFO = 64,
    WLAN_EID_RSNI = 65,
    WLAN_EID_MEASUREMENT_PILOT_TX_INFO = 66,
    WLAN_EID_BSS_AVAILABLE_CAPACITY = 67,
    WLAN_EID_BSS_AC_ACCESS_DELAY = 68,
    WLAN_EID_TIME_ADVERTISEMENT = 69,
    WLAN_EID_RRM_ENABLED_CAPABILITIES = 70,
    WLAN_EID_MULTIPLE_BSSID = 71,
    WLAN_EID_BSS_COEX_2040 = 72,
    WLAN_EID_BSS_INTOLERANT_CHL_REPORT = 73,
    WLAN_EID_OVERLAP_BSS_SCAN_PARAM = 74,
    WLAN_EID_RIC_DESCRIPTOR = 75,
    WLAN_EID_MMIE = 76,
    WLAN_EID_ASSOC_COMEBACK_TIME = 77,
    WLAN_EID_EVENT_REQUEST = 78,
    WLAN_EID_EVENT_REPORT = 79,
    WLAN_EID_DIAGNOSTIC_REQUEST = 80,
    WLAN_EID_DIAGNOSTIC_REPORT = 81,
    WLAN_EID_LOCATION_PARAMS = 82,
    WLAN_EID_NON_TX_BSSID_CAP =  83,
    WLAN_EID_SSID_LIST = 84,
    WLAN_EID_MULTI_BSSID_IDX = 85,
    WLAN_EID_FMS_DESCRIPTOR = 86,
    WLAN_EID_FMS_REQUEST = 87,
    WLAN_EID_FMS_RESPONSE = 88,
    WLAN_EID_QOS_TRAFFIC_CAPA = 89,
    WLAN_EID_BSS_MAX_IDLE_PERIOD = 90,
    WLAN_EID_TSF_REQUEST = 91,
    WLAN_EID_TSF_RESPOSNE = 92,
    WLAN_EID_WNM_SLEEP_MODE = 93,
    WLAN_EID_TIM_BCAST_REQ = 94,
    WLAN_EID_TIM_BCAST_RESP = 95,
    WLAN_EID_COLL_IF_REPORT = 96,
    WLAN_EID_CHANNEL_USAGE = 97,
    WLAN_EID_TIME_ZONE = 98,
    WLAN_EID_DMS_REQUEST = 99,
    WLAN_EID_DMS_RESPONSE = 100,
    WLAN_EID_LINK_ID = 101,
    WLAN_EID_WAKEUP_SCHEDUL = 102,
    /* 103 reserved */
    WLAN_EID_CHAN_SWITCH_TIMING = 104,
    WLAN_EID_PTI_CONTROL = 105,
    WLAN_EID_PU_BUFFER_STATUS = 106,
    WLAN_EID_INTERWORKING = 107,
    WLAN_EID_ADVERTISEMENT_PROTOCOL = 108,
    WLAN_EID_EXPEDITED_BW_REQ = 109,
    WLAN_EID_QOS_MAP_SET = 110,
    WLAN_EID_ROAMING_CONSORTIUM = 111,
    WLAN_EID_EMERGENCY_ALERT = 112,
    WLAN_EID_MESH_CONFIG = 113,
    WLAN_EID_MESH_ID = 114,
    WLAN_EID_LINK_METRIC_REPORT = 115,
    WLAN_EID_CONGESTION_NOTIFICATION = 116,
    WLAN_EID_PEER_MGMT = 117,
    WLAN_EID_CHAN_SWITCH_PARAM = 118,
    WLAN_EID_MESH_AWAKE_WINDOW = 119,
    WLAN_EID_BEACON_TIMING = 120,
    WLAN_EID_MCCAOP_SETUP_REQ = 121,
    WLAN_EID_MCCAOP_SETUP_RESP = 122,
    WLAN_EID_MCCAOP_ADVERT = 123,
    WLAN_EID_MCCAOP_TEARDOWN = 124,
    WLAN_EID_GANN = 125,
    WLAN_EID_RANN = 126,
    WLAN_EID_EXT_CAPABILITY = 127,
    /* 128, 129 reserved for Agere */
    WLAN_EID_PREQ = 130,
    WLAN_EID_PREP = 131,
    WLAN_EID_PERR = 132,
    /* 133-136 reserved for Cisco */
    WLAN_EID_PXU = 137,
    WLAN_EID_PXUC = 138,
    WLAN_EID_AUTH_MESH_PEER_EXCH = 139,
    WLAN_EID_MIC = 140,
    WLAN_EID_DESTINATION_URI = 141,
    WLAN_EID_UAPSD_COEX = 142,
    WLAN_EID_WAKEUP_SCHEDULE = 143,
    WLAN_EID_EXT_SCHEDULE = 144,
    WLAN_EID_STA_AVAILABILITY = 145,
    WLAN_EID_DMG_TSPEC = 146,
    WLAN_EID_DMG_AT = 147,
    WLAN_EID_DMG_CAP = 148,
    /* 149 reserved for Cisco */
    WLAN_EID_CISCO_VENDOR_SPECIFIC = 150,
    WLAN_EID_DMG_OPERATION = 151,
    WLAN_EID_DMG_BSS_PARAM_CHANGE = 152,
    WLAN_EID_DMG_BEAM_REFINEMENT = 153,
    WLAN_EID_CHANNEL_MEASURE_FEEDBACK = 154,
    /* 155-156 reserved for Cisco */
    WLAN_EID_AWAKE_WINDOW = 157,
    WLAN_EID_MULTI_BAND = 158,
    WLAN_EID_ADDBA_EXT = 159,
    WLAN_EID_NEXT_PCP_LIST = 160,
    WLAN_EID_PCP_HANDOVER = 161,
    WLAN_EID_DMG_LINK_MARGIN = 162,
    WLAN_EID_SWITCHING_STREAM = 163,
    WLAN_EID_SESSION_TRANSITION = 164,
    WLAN_EID_DYN_TONE_PAIRING_REPORT = 165,
    WLAN_EID_CLUSTER_REPORT = 166,
    WLAN_EID_RELAY_CAP = 167,
    WLAN_EID_RELAY_XFER_PARAM_SET = 168,
    WLAN_EID_BEAM_LINK_MAINT = 169,
    WLAN_EID_MULTIPLE_MAC_ADDR = 170,
    WLAN_EID_U_PID = 171,
    WLAN_EID_DMG_LINK_ADAPT_ACK = 172,
    /* 173 reserved for Symbol */
    WLAN_EID_MCCAOP_ADV_OVERVIEW = 174,
    WLAN_EID_QUIET_PERIOD_REQ = 175,
    /* 176 reserved for Symbol */
    WLAN_EID_QUIET_PERIOD_RESP = 177,
    /* 178-179 reserved for Symbol */
    /* 180 reserved for ISO/IEC 20011 */
    WLAN_EID_EPAC_POLICY = 182,
    WLAN_EID_CLISTER_TIME_OFF = 183,
    WLAN_EID_INTER_AC_PRIO = 184,
    WLAN_EID_SCS_DESCRIPTOR = 185,
    WLAN_EID_QLOAD_REPORT = 186,
    WLAN_EID_HCCA_TXOP_UPDATE_COUNT = 187,
    WLAN_EID_HL_STREAM_ID = 188,
    WLAN_EID_GCR_GROUP_ADDR = 189,
    WLAN_EID_ANTENNA_SECTOR_ID_PATTERN = 190,
    WLAN_EID_VHT_CAPABILITY = 191,
    WLAN_EID_VHT_OPERATION = 192,
    WLAN_EID_EXTENDED_BSS_LOAD = 193,
    WLAN_EID_WIDE_BW_CHANNEL_SWITCH = 194,
    WLAN_EID_VHT_TX_POWER_ENVELOPE = 195,
    WLAN_EID_CHANNEL_SWITCH_WRAPPER = 196,
    WLAN_EID_AID = 197,
    WLAN_EID_QUIET_CHANNEL = 198,
    WLAN_EID_OPMODE_NOTIF = 199,
    
    WLAN_EID_VENDOR_SPECIFIC = 221,
    WLAN_EID_QOS_PARAMETER = 222,
    WLAN_EID_CAG_NUMBER = 237,
    WLAN_EID_AP_CSN = 239,
    WLAN_EID_FILS_INDICATION = 240,
    WLAN_EID_DILS = 241,
    WLAN_EID_FRAGMENT = 242,
    WLAN_EID_EXTENSION = 255
};


// line 2442
#define WLAN_OUI_WFA            0x506f9a
#define WLAN_OUI_TYPE_WFA_P2P        9
#define WLAN_OUI_MICROSOFT        0x0050f2
#define WLAN_OUI_TYPE_MICROSOFT_WPA    1
#define WLAN_OUI_TYPE_MICROSOFT_WMM    2
#define WLAN_OUI_TYPE_MICROSOFT_WPS    4




#endif /* ieee80211_h */
