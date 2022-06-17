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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_reference_frame_param() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 2, 66, 0, 124, 1, 102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 0, 6, 0, 7, 0, 0, 0, 8, 0,
            0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 0, 0, 0, 13, 0, 0, 0, 14, 0, 0, 0, 15,
            0, 0, 0, 16, 0, 0, 0, 17, 0, 0, 0, 18, 0, 0, 0, 19, 0, 0, 0, 20, 0, 6, 161,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgReferenceFrameParam(msg) => {
                assert_eq!(
                    msg.message_type(),
                    580,
                    "Incorrect message type, expected 580, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.delta_x0, 7,
                    "incorrect value for delta_x0, expected 7, is {}",
                    msg.delta_x0
                );
                assert_eq!(
                    msg.delta_y0, 8,
                    "incorrect value for delta_y0, expected 8, is {}",
                    msg.delta_y0
                );
                assert_eq!(
                    msg.delta_z0, 9,
                    "incorrect value for delta_z0, expected 9, is {}",
                    msg.delta_z0
                );
                assert_eq!(
                    msg.dot_delta_x0, 14,
                    "incorrect value for dot_delta_x0, expected 14, is {}",
                    msg.dot_delta_x0
                );
                assert_eq!(
                    msg.dot_delta_y0, 15,
                    "incorrect value for dot_delta_y0, expected 15, is {}",
                    msg.dot_delta_y0
                );
                assert_eq!(
                    msg.dot_delta_z0, 16,
                    "incorrect value for dot_delta_z0, expected 16, is {}",
                    msg.dot_delta_z0
                );
                assert_eq!(
                    msg.dot_scale, 20,
                    "incorrect value for dot_scale, expected 20, is {}",
                    msg.dot_scale
                );
                assert_eq!(
                    msg.dot_theta_01, 17,
                    "incorrect value for dot_theta_01, expected 17, is {}",
                    msg.dot_theta_01
                );
                assert_eq!(
                    msg.dot_theta_02, 18,
                    "incorrect value for dot_theta_02, expected 18, is {}",
                    msg.dot_theta_02
                );
                assert_eq!(
                    msg.dot_theta_03, 19,
                    "incorrect value for dot_theta_03, expected 19, is {}",
                    msg.dot_theta_03
                );
                assert_eq!(
                    msg.re_t0, 6,
                    "incorrect value for re_t0, expected 6, is {}",
                    msg.re_t0
                );
                assert_eq!(
                    msg.scale, 13,
                    "incorrect value for scale, expected 13, is {}",
                    msg.scale
                );
                assert_eq!(
                    msg.sin, 4,
                    "incorrect value for sin, expected 4, is {}",
                    msg.sin
                );
                assert_eq!(
                    msg.sn.to_string(),
                    "foo                             ".to_string(),
                    "incorrect value for msg.sn, expected string '{}', is '{}'",
                    "foo                             ".to_string(),
                    msg.sn
                );
                assert_eq!(
                    msg.ssr_iod, 1,
                    "incorrect value for ssr_iod, expected 1, is {}",
                    msg.ssr_iod
                );
                assert_eq!(
                    msg.theta_01, 10,
                    "incorrect value for theta_01, expected 10, is {}",
                    msg.theta_01
                );
                assert_eq!(
                    msg.theta_02, 11,
                    "incorrect value for theta_02, expected 11, is {}",
                    msg.theta_02
                );
                assert_eq!(
                    msg.theta_03, 12,
                    "incorrect value for theta_03, expected 12, is {}",
                    msg.theta_03
                );
                assert_eq!(
                    msg.tn.to_string(),
                    "bar                             ".to_string(),
                    "incorrect value for msg.tn, expected string '{}', is '{}'",
                    "bar                             ".to_string(),
                    msg.tn
                );
                assert_eq!(
                    msg.utn, 5,
                    "incorrect value for utn, expected 5, is {}",
                    msg.utn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgReferenceFrameParam"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
