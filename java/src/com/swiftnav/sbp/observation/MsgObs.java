/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_OBS (0x004A).
 *
 * <p>You can have MSG_OBS inherent its fields directly from an inherited SBP object, or construct
 * it inline using a dict of its fields.
 *
 * <p>The GPS observations message reports all the raw pseudorange and carrier phase observations
 * for the satellites being tracked by the device. Carrier phase observation here is represented as
 * a 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles). The observations are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
public class MsgObs extends SBPMessage {
    public static final int TYPE = 0x004A;

    /** Header of a GPS observation message */
    public ObservationHeader header;

    /** Pseudorange and carrier phase observation for a satellite being tracked. */
    public PackedObsContent[] obs;

    public MsgObs(int sender) {
        super(sender, TYPE);
    }

    public MsgObs() {
        super(TYPE);
    }

    public MsgObs(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new ObservationHeader().parse(parser);
        obs = parser.getArray(PackedObsContent.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArray(obs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("obs", SBPStruct.toJSONArray(obs));
        return obj;
    }
}
