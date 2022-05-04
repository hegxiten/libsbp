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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPoints.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_integrity_MsgSsrFlagIonoGridPoints0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ssr_flag_iono_grid_points_t> {
 public:
  Test_auto_check_sbp_integrity_MsgSsrFlagIonoGridPoints0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ssr_flag_iono_grid_points_t>(this),
        last_msg_(),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_ssr_flag_iono_grid_points_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ssr_flag_iono_grid_points_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_integrity_MsgSsrFlagIonoGridPoints0, Test) {
  uint8_t encoded_frame[] = {
      85, 199, 11, 66, 0, 21, 180, 0, 0,  0, 3,  0, 1,  2, 3,
      4,  0,   5,  0,  6, 3,  10,  0, 11, 0, 12, 0, 53, 7,
  };

  sbp_msg_ssr_flag_iono_grid_points_t test_msg{};
  test_msg.n_stub = 21;

  test_msg.stub[0] = 180;

  test_msg.stub[1] = 0;

  test_msg.stub[2] = 0;

  test_msg.stub[3] = 0;

  test_msg.stub[4] = 3;

  test_msg.stub[5] = 0;

  test_msg.stub[6] = 1;

  test_msg.stub[7] = 2;

  test_msg.stub[8] = 3;

  test_msg.stub[9] = 4;

  test_msg.stub[10] = 0;

  test_msg.stub[11] = 5;

  test_msg.stub[12] = 0;

  test_msg.stub[13] = 6;

  test_msg.stub[14] = 3;

  test_msg.stub[15] = 10;

  test_msg.stub[16] = 0;

  test_msg.stub[17] = 11;

  test_msg.stub[18] = 0;

  test_msg.stub[19] = 12;

  test_msg.stub[20] = 0;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_stub, 21)
      << "incorrect value for last_msg_.n_stub, expected 21, is "
      << last_msg_.n_stub;
  EXPECT_EQ(last_msg_.stub[0], 180)
      << "incorrect value for last_msg_.stub[0], expected 180, is "
      << last_msg_.stub[0];
  EXPECT_EQ(last_msg_.stub[1], 0)
      << "incorrect value for last_msg_.stub[1], expected 0, is "
      << last_msg_.stub[1];
  EXPECT_EQ(last_msg_.stub[2], 0)
      << "incorrect value for last_msg_.stub[2], expected 0, is "
      << last_msg_.stub[2];
  EXPECT_EQ(last_msg_.stub[3], 0)
      << "incorrect value for last_msg_.stub[3], expected 0, is "
      << last_msg_.stub[3];
  EXPECT_EQ(last_msg_.stub[4], 3)
      << "incorrect value for last_msg_.stub[4], expected 3, is "
      << last_msg_.stub[4];
  EXPECT_EQ(last_msg_.stub[5], 0)
      << "incorrect value for last_msg_.stub[5], expected 0, is "
      << last_msg_.stub[5];
  EXPECT_EQ(last_msg_.stub[6], 1)
      << "incorrect value for last_msg_.stub[6], expected 1, is "
      << last_msg_.stub[6];
  EXPECT_EQ(last_msg_.stub[7], 2)
      << "incorrect value for last_msg_.stub[7], expected 2, is "
      << last_msg_.stub[7];
  EXPECT_EQ(last_msg_.stub[8], 3)
      << "incorrect value for last_msg_.stub[8], expected 3, is "
      << last_msg_.stub[8];
  EXPECT_EQ(last_msg_.stub[9], 4)
      << "incorrect value for last_msg_.stub[9], expected 4, is "
      << last_msg_.stub[9];
  EXPECT_EQ(last_msg_.stub[10], 0)
      << "incorrect value for last_msg_.stub[10], expected 0, is "
      << last_msg_.stub[10];
  EXPECT_EQ(last_msg_.stub[11], 5)
      << "incorrect value for last_msg_.stub[11], expected 5, is "
      << last_msg_.stub[11];
  EXPECT_EQ(last_msg_.stub[12], 0)
      << "incorrect value for last_msg_.stub[12], expected 0, is "
      << last_msg_.stub[12];
  EXPECT_EQ(last_msg_.stub[13], 6)
      << "incorrect value for last_msg_.stub[13], expected 6, is "
      << last_msg_.stub[13];
  EXPECT_EQ(last_msg_.stub[14], 3)
      << "incorrect value for last_msg_.stub[14], expected 3, is "
      << last_msg_.stub[14];
  EXPECT_EQ(last_msg_.stub[15], 10)
      << "incorrect value for last_msg_.stub[15], expected 10, is "
      << last_msg_.stub[15];
  EXPECT_EQ(last_msg_.stub[16], 0)
      << "incorrect value for last_msg_.stub[16], expected 0, is "
      << last_msg_.stub[16];
  EXPECT_EQ(last_msg_.stub[17], 11)
      << "incorrect value for last_msg_.stub[17], expected 11, is "
      << last_msg_.stub[17];
  EXPECT_EQ(last_msg_.stub[18], 0)
      << "incorrect value for last_msg_.stub[18], expected 0, is "
      << last_msg_.stub[18];
  EXPECT_EQ(last_msg_.stub[19], 12)
      << "incorrect value for last_msg_.stub[19], expected 12, is "
      << last_msg_.stub[19];
  EXPECT_EQ(last_msg_.stub[20], 0)
      << "incorrect value for last_msg_.stub[20], expected 0, is "
      << last_msg_.stub[20];
}
