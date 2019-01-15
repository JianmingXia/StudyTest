// require modules
var fs = require("fs");
var archiver = require("archiver");
var stream = require("stream");
var pump = require("pump");

// create a file to stream archive data to.
var writeStream = fs.createWriteStream(__dirname + "/endEventFired.zip");
const output = new stream.PassThrough();
var archive = archiver("zip", {
  zlib: { level: 9 } // Sets the compression level.
});

// listen for all archive data to be written
// 'close' event is fired only when a file descriptor is involved
output.on("close", function() {
  console.log(archive.pointer() + " total bytes");
  console.log(
    "archiver has been finalized and the output file descriptor has closed."
  );
});

// This event is fired when the data source is drained no matter what was the data source.
// It is not part of this library but rather from the NodeJS Stream API.
// @see: https://nodejs.org/api/stream.html#stream_event_end
output.on("end", function() {
  console.log("end event is fired: Data has been drained");
});

// good practice to catch warnings (ie stat failures and other non-blocking errors)
archive.on("warning", function(err) {
  console.log("warning");
  if (err.code === "ENOENT") {
    // log warning
  } else {
    // throw error
    throw err;
  }
});

// good practice to catch this error explicitly
archive.on("error", function(err) {
  console.log("error");
  throw err;
});

// pipe archive data to the file
archive.pipe(output);

archive.append("", { name: "sdffsdfsd/" });
archive.append("string cheese!", { name: "file2.txt" });

archive.finalize();
pump(output, writeStream, err => {
  if (err) {
    console.log(err);
  }
});
