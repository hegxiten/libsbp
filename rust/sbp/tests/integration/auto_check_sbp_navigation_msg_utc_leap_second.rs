//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCLeapSecond.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_utc_leap_second() {
    {
        let mut payload = Cursor::new(vec![
            85, 58, 2, 66, 0, 14, 1, 0, 2, 0, 3, 4, 5, 0, 6, 0, 7, 0, 8, 9, 50, 232,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcLeapSecond(msg) => {
                assert_eq!(
                    msg.message_type(),
                    570,
                    "Incorrect message type, expected 570, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.bias_coeff, 1,
                    "incorrect value for bias_coeff, expected 1, is {}",
                    msg.bias_coeff
                );
                assert_eq!(
                    msg.count_after, 9,
                    "incorrect value for count_after, expected 9, is {}",
                    msg.count_after
                );
                assert_eq!(
                    msg.count_before, 4,
                    "incorrect value for count_before, expected 4, is {}",
                    msg.count_before
                );
                assert_eq!(
                    msg.drift_coeff, 2,
                    "incorrect value for drift_coeff, expected 2, is {}",
                    msg.drift_coeff
                );
                assert_eq!(
                    msg.drift_rate_coeff, 3,
                    "incorrect value for drift_rate_coeff, expected 3, is {}",
                    msg.drift_rate_coeff
                );
                assert_eq!(
                    msg.ref_dn, 8,
                    "incorrect value for ref_dn, expected 8, is {}",
                    msg.ref_dn
                );
                assert_eq!(
                    msg.ref_wn, 7,
                    "incorrect value for ref_wn, expected 7, is {}",
                    msg.ref_wn
                );
                assert_eq!(
                    msg.tow_s, 5,
                    "incorrect value for tow_s, expected 5, is {}",
                    msg.tow_s
                );
                assert_eq!(
                    msg.wn, 6,
                    "incorrect value for wn, expected 6, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcLeapSecond"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
