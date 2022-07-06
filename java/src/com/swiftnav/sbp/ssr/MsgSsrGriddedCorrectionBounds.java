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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION_BOUNDS (0x05FE).
 *
 * <p>You can have MSG_SSR_GRIDDED_CORRECTION_BOUNDS inherent its fields directly from an inherited
 * SBP object, or construct it inline using a dict of its fields.
 *
 * <p>Note 1: Range: 0-17.5 m. i{@literal <}= 200, mean = 0.01i; 200{@literal <}i{@literal <}=230,
 * mean=2+0.1(i-200); i{@literal >}230, mean=5+0.5(i-230).
 */
public class MsgSsrGriddedCorrectionBounds extends SBPMessage {
    public static final int TYPE = 0x05FE;

    /** Header of a bounds message. */
    public BoundsHeader header;

    /** IOD of the correction. */
    public int ssr_iod_atmo;

    /** Set this tile belongs to. */
    public int tile_set_id;

    /** Unique identifier of this tile in the tile set. */
    public int tile_id;

    /** Tropo Quality Indicator. Similar to RTCM DF389. */
    public int tropo_qi;

    /** Index of the Grid Point. */
    public int grid_point_id;

    /** Tropospheric delay at grid point. */
    public TroposphericDelayCorrection tropo_delay_correction;

    /** Vertical Hydrostatic Error Bound Mean. */
    public int tropo_v_hydro_bound_mu;

    /** Vertical Hydrostatic Error Bound StDev. */
    public int tropo_v_hydro_bound_sig;

    /** Vertical Wet Error Bound Mean. */
    public int tropo_v_wet_bound_mu;

    /** Vertical Wet Error Bound StDev. */
    public int tropo_v_wet_bound_sig;

    /** Number of satellites. */
    public int n_sats;

    /** Array of STEC polynomial coefficients and its bounds for each space vehicle. */
    public STECSatElementIntegrity[] stec_sat_list;

    public MsgSsrGriddedCorrectionBounds(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrGriddedCorrectionBounds() {
        super(TYPE);
    }

    public MsgSsrGriddedCorrectionBounds(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new BoundsHeader().parse(parser);
        ssr_iod_atmo = parser.getU8();
        tile_set_id = parser.getU16();
        tile_id = parser.getU16();
        tropo_qi = parser.getU8();
        grid_point_id = parser.getU16();
        tropo_delay_correction = new TroposphericDelayCorrection().parse(parser);
        tropo_v_hydro_bound_mu = parser.getU8();
        tropo_v_hydro_bound_sig = parser.getU8();
        tropo_v_wet_bound_mu = parser.getU8();
        tropo_v_wet_bound_sig = parser.getU8();
        n_sats = parser.getU8();
        stec_sat_list = parser.getArray(STECSatElementIntegrity.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU8(ssr_iod_atmo);
        builder.putU16(tile_set_id);
        builder.putU16(tile_id);
        builder.putU8(tropo_qi);
        builder.putU16(grid_point_id);
        tropo_delay_correction.build(builder);
        builder.putU8(tropo_v_hydro_bound_mu);
        builder.putU8(tropo_v_hydro_bound_sig);
        builder.putU8(tropo_v_wet_bound_mu);
        builder.putU8(tropo_v_wet_bound_sig);
        builder.putU8(n_sats);
        builder.putArray(stec_sat_list);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("ssr_iod_atmo", ssr_iod_atmo);
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("tropo_qi", tropo_qi);
        obj.put("grid_point_id", grid_point_id);
        obj.put("tropo_delay_correction", tropo_delay_correction.toJSON());
        obj.put("tropo_v_hydro_bound_mu", tropo_v_hydro_bound_mu);
        obj.put("tropo_v_hydro_bound_sig", tropo_v_hydro_bound_sig);
        obj.put("tropo_v_wet_bound_mu", tropo_v_wet_bound_mu);
        obj.put("tropo_v_wet_bound_sig", tropo_v_wet_bound_sig);
        obj.put("n_sats", n_sats);
        obj.put("stec_sat_list", SBPStruct.toJSONArray(stec_sat_list));
        return obj;
    }
}
