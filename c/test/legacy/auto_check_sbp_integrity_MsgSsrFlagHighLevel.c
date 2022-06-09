/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/integrity.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_integrity_MsgSsrFlagHighLevel) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 3001, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 3001, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 185, 11, 66, 0, 31, 180, 0, 0,  0, 3,  0,   104,
        1,  0,   0,  6,  0, 10, 20,  0, 30, 0, 40, 1,   2,
        3,  0,   0,  0,  0, 0,  0,   4, 5,  6, 7,  102, 67,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_flag_high_level_t *test_msg =
        (msg_ssr_flag_high_level_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[0] = 180;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[1] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[2] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[3] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[4] = 3;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[5] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[6] = 104;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[7] = 1;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[8] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[9] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[10] = 6;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[11] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[12] = 10;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[13] = 20;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[14] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[15] = 30;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[16] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[17] = 40;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[18] = 1;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[19] = 2;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[20] = 3;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[21] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[22] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[23] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[24] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[25] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[26] = 0;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[27] = 4;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[28] = 5;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[29] = 6;
    if (sizeof(test_msg->stub) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stub[0]);
    }
    test_msg->stub[30] = 7;
    sbp_payload_send(&sbp_state, 3001, 66, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 66,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 66,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 3001,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_ssr_flag_high_level_t *check_msg =
        (msg_ssr_flag_high_level_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->stub[0] == 180,
                  "incorrect value for stub[0], expected 180, is %d",
                  check_msg->stub[0]);
    ck_assert_msg(check_msg->stub[1] == 0,
                  "incorrect value for stub[1], expected 0, is %d",
                  check_msg->stub[1]);
    ck_assert_msg(check_msg->stub[2] == 0,
                  "incorrect value for stub[2], expected 0, is %d",
                  check_msg->stub[2]);
    ck_assert_msg(check_msg->stub[3] == 0,
                  "incorrect value for stub[3], expected 0, is %d",
                  check_msg->stub[3]);
    ck_assert_msg(check_msg->stub[4] == 3,
                  "incorrect value for stub[4], expected 3, is %d",
                  check_msg->stub[4]);
    ck_assert_msg(check_msg->stub[5] == 0,
                  "incorrect value for stub[5], expected 0, is %d",
                  check_msg->stub[5]);
    ck_assert_msg(check_msg->stub[6] == 104,
                  "incorrect value for stub[6], expected 104, is %d",
                  check_msg->stub[6]);
    ck_assert_msg(check_msg->stub[7] == 1,
                  "incorrect value for stub[7], expected 1, is %d",
                  check_msg->stub[7]);
    ck_assert_msg(check_msg->stub[8] == 0,
                  "incorrect value for stub[8], expected 0, is %d",
                  check_msg->stub[8]);
    ck_assert_msg(check_msg->stub[9] == 0,
                  "incorrect value for stub[9], expected 0, is %d",
                  check_msg->stub[9]);
    ck_assert_msg(check_msg->stub[10] == 6,
                  "incorrect value for stub[10], expected 6, is %d",
                  check_msg->stub[10]);
    ck_assert_msg(check_msg->stub[11] == 0,
                  "incorrect value for stub[11], expected 0, is %d",
                  check_msg->stub[11]);
    ck_assert_msg(check_msg->stub[12] == 10,
                  "incorrect value for stub[12], expected 10, is %d",
                  check_msg->stub[12]);
    ck_assert_msg(check_msg->stub[13] == 20,
                  "incorrect value for stub[13], expected 20, is %d",
                  check_msg->stub[13]);
    ck_assert_msg(check_msg->stub[14] == 0,
                  "incorrect value for stub[14], expected 0, is %d",
                  check_msg->stub[14]);
    ck_assert_msg(check_msg->stub[15] == 30,
                  "incorrect value for stub[15], expected 30, is %d",
                  check_msg->stub[15]);
    ck_assert_msg(check_msg->stub[16] == 0,
                  "incorrect value for stub[16], expected 0, is %d",
                  check_msg->stub[16]);
    ck_assert_msg(check_msg->stub[17] == 40,
                  "incorrect value for stub[17], expected 40, is %d",
                  check_msg->stub[17]);
    ck_assert_msg(check_msg->stub[18] == 1,
                  "incorrect value for stub[18], expected 1, is %d",
                  check_msg->stub[18]);
    ck_assert_msg(check_msg->stub[19] == 2,
                  "incorrect value for stub[19], expected 2, is %d",
                  check_msg->stub[19]);
    ck_assert_msg(check_msg->stub[20] == 3,
                  "incorrect value for stub[20], expected 3, is %d",
                  check_msg->stub[20]);
    ck_assert_msg(check_msg->stub[21] == 0,
                  "incorrect value for stub[21], expected 0, is %d",
                  check_msg->stub[21]);
    ck_assert_msg(check_msg->stub[22] == 0,
                  "incorrect value for stub[22], expected 0, is %d",
                  check_msg->stub[22]);
    ck_assert_msg(check_msg->stub[23] == 0,
                  "incorrect value for stub[23], expected 0, is %d",
                  check_msg->stub[23]);
    ck_assert_msg(check_msg->stub[24] == 0,
                  "incorrect value for stub[24], expected 0, is %d",
                  check_msg->stub[24]);
    ck_assert_msg(check_msg->stub[25] == 0,
                  "incorrect value for stub[25], expected 0, is %d",
                  check_msg->stub[25]);
    ck_assert_msg(check_msg->stub[26] == 0,
                  "incorrect value for stub[26], expected 0, is %d",
                  check_msg->stub[26]);
    ck_assert_msg(check_msg->stub[27] == 4,
                  "incorrect value for stub[27], expected 4, is %d",
                  check_msg->stub[27]);
    ck_assert_msg(check_msg->stub[28] == 5,
                  "incorrect value for stub[28], expected 5, is %d",
                  check_msg->stub[28]);
    ck_assert_msg(check_msg->stub[29] == 6,
                  "incorrect value for stub[29], expected 6, is %d",
                  check_msg->stub[29]);
    ck_assert_msg(check_msg->stub[30] == 7,
                  "incorrect value for stub[30], expected 7, is %d",
                  check_msg->stub[30]);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_integrity_MsgSsrFlagHighLevel_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_integrity_MsgSsrFlagHighLevel");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_integrity_MsgSsrFlagHighLevel");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_integrity_MsgSsrFlagHighLevel);
  suite_add_tcase(s, tc_acq);
  return s;
}