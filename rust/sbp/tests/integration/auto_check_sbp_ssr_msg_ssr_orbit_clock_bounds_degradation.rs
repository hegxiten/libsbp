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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_degradation() {
    {
        let mut payload = Cursor::new(vec![
            85, 223, 5, 66, 0, 28, 180, 0, 0, 0, 3, 0, 1, 2, 3, 48, 15, 1, 10, 0, 0, 0, 0, 0, 0, 0,
            200, 199, 198, 197, 196, 195, 194, 193, 200, 117,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1503,
                    "Incorrect message type, expected 1503, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.const_id, 1,
                    "incorrect value for const_id, expected 1, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 48,
                    "incorrect value for header.sol_id, expected 48, is {}",
                    msg.header.sol_id
                );
                assert_eq!(
                    msg.header.time.tow, 180,
                    "incorrect value for header.time.tow, expected 180, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 3,
                    "incorrect value for header.time.wn, expected 3, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 3,
                    "incorrect value for header.update_interval, expected 3, is {}",
                    msg.header.update_interval
                );
                assert_eq!(msg.orbit_clock_bounds_degradation.clock_bound_mu_dot, 194, "incorrect value for orbit_clock_bounds_degradation.clock_bound_mu_dot, expected 194, is {}", msg.orbit_clock_bounds_degradation.clock_bound_mu_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.clock_bound_sig_dot, 193, "incorrect value for orbit_clock_bounds_degradation.clock_bound_sig_dot, expected 193, is {}", msg.orbit_clock_bounds_degradation.clock_bound_sig_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_along_bound_mu_dot, 199, "incorrect value for orbit_clock_bounds_degradation.orb_along_bound_mu_dot, expected 199, is {}", msg.orbit_clock_bounds_degradation.orb_along_bound_mu_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_along_bound_sig_dot, 196, "incorrect value for orbit_clock_bounds_degradation.orb_along_bound_sig_dot, expected 196, is {}", msg.orbit_clock_bounds_degradation.orb_along_bound_sig_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot, 198, "incorrect value for orbit_clock_bounds_degradation.orb_cross_bound_mu_dot, expected 198, is {}", msg.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot, 195, "incorrect value for orbit_clock_bounds_degradation.orb_cross_bound_sig_dot, expected 195, is {}", msg.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot, 200, "incorrect value for orbit_clock_bounds_degradation.orb_radial_bound_mu_dot, expected 200, is {}", msg.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot);
                assert_eq!(msg.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot, 197, "incorrect value for orbit_clock_bounds_degradation.orb_radial_bound_sig_dot, expected 197, is {}", msg.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot);
                assert_eq!(
                    msg.sat_bitmask, 10,
                    "incorrect value for sat_bitmask, expected 10, is {}",
                    msg.sat_bitmask
                );
                assert_eq!(
                    msg.ssr_iod, 15,
                    "incorrect value for ssr_iod, expected 15, is {}",
                    msg.ssr_iod
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockBoundsDegradation"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
