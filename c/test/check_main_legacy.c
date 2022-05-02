/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated by generate.py. Do not modify by hand!

#include <check.h>
#include <stdlib.h>
#include "check_suites_legacy.h"

int main(void) {
  int number_failed;
  Suite *s = edc_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_xml(sr, "test_results.xml");
  srunner_add_suite(sr, sbp_suite());
  srunner_add_suite(sr, bitfield_macros_suite());

  // auto-generated tests:
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_acquisition_MsgAcqResultDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_acquisition_MsgAcqResultDepB_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_acquisition_MsgAcqResultDepC_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_ext_events_MsgExtEvent_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_file_io_MsgFileioWriteResp_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_imu_MsgImuAux_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_imu_MsgImuRaw_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_logging_MsgFwd_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_logging_MsgLog_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_logging_MsgPrintDep_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgAgeCorrections_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgBaselineECEF_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgBaselineNED_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_navigation_MsgBaselineNEDDepA_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgDops_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgDopsDepA_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgGPSTime_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgGPSTimeDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgGPSTimeGNSS_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosECEF_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosECEFCov_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgPosECEFCovGNSS_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgPosECEFDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgPosECEFGNSS_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosLLH_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosLLHCov_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosLLHDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgPosLlhGnss_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_navigation_MsgProtectionLevel_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgUTCTime_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgUTCTimeGNSS_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelBody_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelCog_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelECEF_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelECEFCov_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgVelECEFDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgVelEcefCovGnss_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgVelEcefGnss_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelNED_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelNEDCOV_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelNEDDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_navigation_MsgVelNedCovGnss_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_navigation_MsgVelNedGnss_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_MsgBasePosEcef_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_MsgEphemerisBds_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_MsgEphemerisGLO_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_MsgEphemerisGPS_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_MsgEphemerisGal_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgGloBiases_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgObs_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgObsDepB_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgObsDepC_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgOsr_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_MsgSvAzEl_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_msgEphemerisDepB_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_observation_msgEphemerisQzss_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_observation_msgObsDepA_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_orientation_MsgAngularRate_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_orientation_MsgOrientEuler_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_orientation_MsgOrientQuat_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_piksi_MsgDeviceMonitor_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_piksi_MsgIarState_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_piksi_MsgNetworkBandwidthUsage_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_piksi_MsgThreadState_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_piksi_MsgUartState_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_piksi_MsgUartStateDepA_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_sbas_MsgSbasRaw_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_settings_MsgSettingsReadByIndexDone_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_settings_MsgSettingsReadByIndexResp_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgDgnssStatus_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgGroupMeta_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgHeartbeat_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgInsStatus_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgInsUpdates_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgSensorAidEvent_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgStartup_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_system_MsgStatusJournal_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_tracking_MsgMeasurementState_suite());
  srunner_add_suite(sr,
                    legacy_auto_check_sbp_tracking_MsgTrackingState_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDep_suite());
  srunner_add_suite(
      sr, legacy_auto_check_sbp_tracking_MsgtrackingStateDepA_suite());
  srunner_add_suite(sr, legacy_auto_check_sbp_vehicle_MsgOdometry_suite());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}