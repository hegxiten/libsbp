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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagTropoGridPoints.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_integrity_MsgSsrFlagTropoGridPoints0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_flag_tropo_grid_points_t> {
 public:
  Test_legacy_auto_check_sbp_integrity_MsgSsrFlagTropoGridPoints0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_flag_tropo_grid_points_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_flag_tropo_grid_points_t *>(
            last_msg_storage_)),
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
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_ssr_flag_tropo_grid_points_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_flag_tropo_grid_points_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_integrity_MsgSsrFlagTropoGridPoints0, Test) {
  uint8_t encoded_frame[] = {
      85, 195, 11, 66, 0, 21, 180, 0, 0,  0, 3,  0, 1,   2,   3,
      4,  0,   5,  0,  6, 3,  10,  0, 11, 0, 12, 0, 243, 150,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_flag_tropo_grid_points_t *test_msg =
      (msg_ssr_flag_tropo_grid_points_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[0] = 180;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[1] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[2] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[3] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[4] = 3;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[5] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[6] = 1;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[7] = 2;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[8] = 3;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[9] = 4;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[10] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[11] = 5;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[12] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[13] = 6;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[14] = 3;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[15] = 10;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[16] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[17] = 11;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[18] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[19] = 12;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[20] = 0;

  EXPECT_EQ(send_message(3011, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->stub[0], 180)
      << "incorrect value for stub[0], expected 180, is " << last_msg_->stub[0];
  EXPECT_EQ(last_msg_->stub[1], 0)
      << "incorrect value for stub[1], expected 0, is " << last_msg_->stub[1];
  EXPECT_EQ(last_msg_->stub[2], 0)
      << "incorrect value for stub[2], expected 0, is " << last_msg_->stub[2];
  EXPECT_EQ(last_msg_->stub[3], 0)
      << "incorrect value for stub[3], expected 0, is " << last_msg_->stub[3];
  EXPECT_EQ(last_msg_->stub[4], 3)
      << "incorrect value for stub[4], expected 3, is " << last_msg_->stub[4];
  EXPECT_EQ(last_msg_->stub[5], 0)
      << "incorrect value for stub[5], expected 0, is " << last_msg_->stub[5];
  EXPECT_EQ(last_msg_->stub[6], 1)
      << "incorrect value for stub[6], expected 1, is " << last_msg_->stub[6];
  EXPECT_EQ(last_msg_->stub[7], 2)
      << "incorrect value for stub[7], expected 2, is " << last_msg_->stub[7];
  EXPECT_EQ(last_msg_->stub[8], 3)
      << "incorrect value for stub[8], expected 3, is " << last_msg_->stub[8];
  EXPECT_EQ(last_msg_->stub[9], 4)
      << "incorrect value for stub[9], expected 4, is " << last_msg_->stub[9];
  EXPECT_EQ(last_msg_->stub[10], 0)
      << "incorrect value for stub[10], expected 0, is " << last_msg_->stub[10];
  EXPECT_EQ(last_msg_->stub[11], 5)
      << "incorrect value for stub[11], expected 5, is " << last_msg_->stub[11];
  EXPECT_EQ(last_msg_->stub[12], 0)
      << "incorrect value for stub[12], expected 0, is " << last_msg_->stub[12];
  EXPECT_EQ(last_msg_->stub[13], 6)
      << "incorrect value for stub[13], expected 6, is " << last_msg_->stub[13];
  EXPECT_EQ(last_msg_->stub[14], 3)
      << "incorrect value for stub[14], expected 3, is " << last_msg_->stub[14];
  EXPECT_EQ(last_msg_->stub[15], 10)
      << "incorrect value for stub[15], expected 10, is "
      << last_msg_->stub[15];
  EXPECT_EQ(last_msg_->stub[16], 0)
      << "incorrect value for stub[16], expected 0, is " << last_msg_->stub[16];
  EXPECT_EQ(last_msg_->stub[17], 11)
      << "incorrect value for stub[17], expected 11, is "
      << last_msg_->stub[17];
  EXPECT_EQ(last_msg_->stub[18], 0)
      << "incorrect value for stub[18], expected 0, is " << last_msg_->stub[18];
  EXPECT_EQ(last_msg_->stub[19], 12)
      << "incorrect value for stub[19], expected 12, is "
      << last_msg_->stub[19];
  EXPECT_EQ(last_msg_->stub[20], 0)
      << "incorrect value for stub[20], expected 0, is " << last_msg_->stub[20];
}
