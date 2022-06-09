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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml
// by generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation) {
  static sbp_msg_callbacks_node_t n;

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

    sbp_callback_register(&sbp_state, 1503, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 223, 5,   66,  0,   28,  180, 0,   0,   0,   3,   0,
        1,  2,   3,   48,  15,  1,   10,  0,   0,   0,   0,   0,
        0,  0,   200, 199, 198, 197, 196, 195, 194, 193, 200, 117,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_orbit_clock_bounds_degradation.n_stub = 28;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[0] = 180;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[1] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[2] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[3] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[4] = 3;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[5] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[6] = 1;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[7] = 2;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[8] = 3;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[9] = 48;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[10] = 15;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[11] = 1;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[12] = 10;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[13] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[14] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[15] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[16] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[17] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[18] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[19] = 0;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[20] = 200;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[21] = 199;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[22] = 198;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[23] = 197;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[24] = 196;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[25] = 195;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[26] = 194;

    test_msg.ssr_orbit_clock_bounds_degradation.stub[27] = 193;

    sbp_message_send(&sbp_state, SbpMsgSsrOrbitClockBoundsDegradation, 66,
                     &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
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

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrOrbitClockBoundsDegradation,
                                  &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.n_stub == 28,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.n_stub, "
                  "expected 28, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.n_stub);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[0] == 180,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[0], expected "
        "180, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[0]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[1] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[1], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[1]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[2] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[2], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[2]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[3] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[3], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[3]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[4] == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[4], "
                  "expected 3, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[4]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[5] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[5], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[5]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[6] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[6], "
                  "expected 1, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[6]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[7] == 2,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[7], "
                  "expected 2, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[7]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[8] == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[8], "
                  "expected 3, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[8]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[9] == 48,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[9], "
                  "expected 48, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[9]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[10] == 15,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[10], expected "
        "15, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[10]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[11] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[11], "
                  "expected 1, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[11]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[12] == 10,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[12], expected "
        "10, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[12]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[13] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[13], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[13]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[14] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[14], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[14]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[15] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[15], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[15]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[16] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[16], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[16]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[17] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[17], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[17]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[18] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[18], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[18]);
    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[19] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[19], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[19]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[20] == 200,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[20], expected "
        "200, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[20]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[21] == 199,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[21], expected "
        "199, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[21]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[22] == 198,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[22], expected "
        "198, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[22]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[23] == 197,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[23], expected "
        "197, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[23]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[24] == 196,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[24], expected "
        "196, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[24]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[25] == 195,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[25], expected "
        "195, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[25]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[26] == 194,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[26], expected "
        "194, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[26]);
    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[27] == 193,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[27], expected "
        "193, is %d",
        last_msg.msg.ssr_orbit_clock_bounds_degradation.stub[27]);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation");
  tcase_add_test(tc_acq,
                 test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation);
  suite_add_tcase(s, tc_acq);
  return s;
}