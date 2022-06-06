use std::fs::File;
use std::io;
use std::io::{Read, Write};
use std::path::PathBuf;

use clap::Parser;
use sbp::json::{CompactFormatter, HaskellishFloatFormatter};

use converters::{sbp2json, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert binary SBP data to JSON.
///
/// Typical usage:
///
///     cat sbp.dat | sbp2json
///
/// Or combined with socat:
///
///     socat tcp:192.168.1.222:55555 - | sbp2json
#[derive(Debug, Parser)]
#[structopt(name = "sbp2json", verbatim_doc_comment, version)]
pub struct Options {
    /// Path to input file
    input: Option<PathBuf>,

    /// Path to output file
    output: Option<PathBuf>,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[clap(long)]
    float_compat: bool,

    /// Print debugging messages to standard error
    #[clap(short = 'd', long)]
    debug: bool,

    /// Buffer output before flushing
    #[clap(short, long)]
    buffered: bool,

    /// Stop on first error encountered
    #[clap(long)]
    fatal_errors: bool,
}

fn main() -> Result<()> {
    let options = Options::parse();

    if options.debug {
        std::env::set_var("RUST_LOG", "debug");
    }

    env_logger::init();

    let stdin: Box<dyn Read> = match options.input {
        Some(path) => Box::new(File::open(path)?),
        _ => Box::new(io::stdin()),
    };

    let stdout: Box<dyn Write> = match options.output {
        Some(path) => Box::new(File::create(path)?),
        _ => Box::new(io::stdout()),
    };

    if options.float_compat {
        sbp2json(
            stdin,
            stdout,
            HaskellishFloatFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    } else {
        sbp2json(
            stdin,
            stdout,
            CompactFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    }
}
