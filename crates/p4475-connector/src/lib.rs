//! Testable connector primitives, independent of any GUI toolkit.

mod bml;
mod codec_error;
mod dataraw_preflight;
mod detection;
mod encoded_block;
mod execution;
mod file_safety;
mod identity;
mod installation;
mod launch;
mod limits;
mod pin;
mod probe;
mod special_tracks;
#[cfg(test)]
mod test_fixture;
mod wire;
mod xml;

pub use bml::BmlObject;
pub use codec_error::PinCodecError;
pub use dataraw_preflight::{DataRawPreflightError, verify_dataraw_preflight};
pub use detection::{
    BuildDetectionError, BuildEvidence, PinDetectionSource, detect_p4475,
};
pub use encoded_block::{
    BlockEncoding, DEFAULT_KART_CRYPTO_KEY, DecodedBlock, EncodedBlockError, FLAG_KART_CRYPTO,
    FLAG_ZLIB, decode as decode_encoded_block, encode as encode_encoded_block,
};
pub use execution::{
    ConnectorCancellation, ConnectorExecution, ConnectorExecutionError, ConnectorPlan,
    ConnectorPlanError, ConnectorRequest, ConnectorStage, execute_connector,
    execute_connector_with_progress, execute_connector_with_progress_and_cancellation,
};
pub use file_safety::{
    ConnectorFileError, PersistentFilePreparation, PristineAction, PristineState,
};
pub use identity::{IdentityError, MAXIMUM_NICKNAME_LENGTH, normalize_nickname};
pub use installation::{
    DEFAULT_INSTALLATION_LOCK_TIMEOUT, DEFAULT_MAXIMUM_PERSISTENT_FILE_BYTES, InstallationError,
    InstallationOptions, PreparedInstallation, XUN_SIDECAR_SESSION_FILE, prepare_installation,
};
pub use launch::{
    LaunchError, LaunchRequest, LaunchSpec, LaunchStatus, LaunchedProcess, Runner, RunnerBackend,
};
pub use limits::CodecLimits;
pub use pin::{
    AuthMethod, P4475_MINOR_VERSION, P4475_PIN_MAGIC, P4475_RIDER_DATA_DIRECTORY,
    P4475_SCREENSHOT_DIRECTORY, P4475_STORAGE_ROOT, PinDocument, PinHeader, PinPatchOptions,
    PinPatchReport, ShallowPinHeader, decode_shallow_pin_header,
    decode_shallow_pin_header_with_limits, patch_p4475_pin, patch_p4475_pin_with_limits,
};
pub use probe::{DEFAULT_PROBE_TIMEOUT, ProbeError, probe_messenger, probe_tcp};
pub use special_tracks::{
    SAFE_BLOCKED_TRACK_IDS, SPECIAL_TRACK_OVERLAY_FILE, SpecialTrackPatchError,
    SpecialTrackPatchReport,
};
pub use xml::{
    LauncherProfileRole, launcher_profile_xml, launcher_profile_xml_for_role, server_config_xml,
};
