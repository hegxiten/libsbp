/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.logging.MsgFwd;


public class auto_check_sbp_logging_MsgFwdTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_logging_MsgFwdTest.test1");
        byte[] payload = new byte[] {(byte)0,(byte)0,(byte)86,(byte)81,(byte)68,(byte)47,(byte)81,(byte)103,(byte)65,(byte)69,(byte)65,(byte)65,(byte)65,(byte)65,(byte)65,(byte)69,(byte)97,(byte)103, };
        SBPMessage sbp = new SBPMessage( 0x42, 0x402, payload );
        MsgFwd msg = new MsgFwd( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.fwd_payload, "VQD/QgAEAAAAAEag" );
        value = msg.protocol;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.protocol + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.source;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.source + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}