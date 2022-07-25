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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgHeartbeat.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_system_msg_heartbeat() {
    {
        let mut payload = Cursor::new(vec![85, 255, 255, 246, 215, 4, 0, 50, 0, 0, 249, 216]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgHeartbeat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xffff,
                    "Incorrect message type, expected 0xffff, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 12800,
                    "incorrect value for flags, expected 12800, is {}",
                    msg.flags
                );
            }
            _ => panic!("Invalid message type! Expected a MsgHeartbeat"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 255, 255, 195, 4, 4, 0, 0, 0, 0, 66, 57]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgHeartbeat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xffff,
                    "Incorrect message type, expected 0xffff, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
            }
            _ => panic!("Invalid message type! Expected a MsgHeartbeat"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_system_msg_heartbeat() {
    {
        let json_input = r#"{"sender": 55286, "msg_type": 65535, "crc": 55545, "length": 4, "flags": 12800, "preamble": 85, "payload": "ADIAAA=="}"#.as_bytes();

        let sbp_msg = {
            // Json to Sbp message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // Json to Sbp message from payload
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgHeartbeat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xffff,
                    "Incorrect message type, expected 0xffff, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 12800,
                    "incorrect value for flags, expected 12800, is {}",
                    msg.flags
                );
            }
            _ => panic!("Invalid message type! Expected a MsgHeartbeat"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 65535, "crc": 14658, "length": 4, "flags": 0, "preamble": 85, "payload": "AAAAAA=="}"#.as_bytes();

        let sbp_msg = {
            // Json to Sbp message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // Json to Sbp message from payload
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgHeartbeat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xffff,
                    "Incorrect message type, expected 0xffff, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
            }
            _ => panic!("Invalid message type! Expected a MsgHeartbeat"),
        };
    }
}
