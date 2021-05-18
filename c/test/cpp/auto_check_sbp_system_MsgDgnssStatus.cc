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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgDgnssStatus.yaml by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>
class Test_auto_check_sbp_system_MsgDgnssStatus0 : 
  public ::testing::Test, 
  public sbp::State, 
  public sbp::IReader, 
  public sbp::IWriter, 
  sbp::MessageHandler<msg_dgnss_status_t>
{
public:
  Test_auto_check_sbp_system_MsgDgnssStatus0() : 
        ::testing::Test(), 
        sbp::State(), 
        sbp::IReader(), 
        sbp::IWriter(), 
        sbp::MessageHandler<msg_dgnss_status_t>(this), 
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dgnss_status_t*>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(), 
        n_callbacks_logged_(), 
        dummy_wr_(), 
        dummy_rd_(), 
        dummy_buff_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override
  {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override
  {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const msg_dgnss_status_t &msg) override
  {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dgnss_status_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_system_MsgDgnssStatus0, Test)     
{

    uint8_t encoded_frame[] = {85,2,255,66,0,11,0,50,0,12,83,107,121,108,97,114,107,202,1, };

    uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
    uint8_t test_msg_len = 0;
    msg_dgnss_status_t* test_msg = ( msg_dgnss_status_t* )test_msg_storage;
    test_msg_len = (uint8_t)sizeof(*test_msg);
    test_msg->flags = 0;
    test_msg->latency = 50;
    test_msg->num_signals = 12;
    {
      const char assign_string[] = { (char)83,(char)107,(char)121,(char)108,(char)97,(char)114,(char)107 };
      memcpy(test_msg->source, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->source) == 0) {
        test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
      }
    }
                                                                              
    EXPECT_EQ(send_message( 0xff02, 66, test_msg_len, test_msg_storage), SBP_OK);
                                                                              
    EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (dummy_rd_ < dummy_wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(last_msg_len_, test_msg_len);
    EXPECT_EQ(last_msg_->flags, 0) << "incorrect value for flags, expected 0, is " << last_msg_->flags;
    EXPECT_EQ(last_msg_->latency, 50) << "incorrect value for latency, expected 50, is " << last_msg_->latency;
    EXPECT_EQ(last_msg_->num_signals, 12) << "incorrect value for num_signals, expected 12, is " << last_msg_->num_signals;
    {
      const char check_string[] = { (char)83,(char)107,(char)121,(char)108,(char)97,(char)114,(char)107 };
      EXPECT_EQ(memcmp(last_msg_->source, check_string, sizeof(check_string)), 0) << "incorrect value for last_msg_->source, expected string '" << check_string << "', is '" << last_msg_->source << "'";
    }
}