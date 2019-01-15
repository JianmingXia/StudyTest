var fs = require("fs");
var archiver = require("archiver");

var output = fs.createWriteStream(__dirname + "/example.zip");
var archive = archiver("zip", {
  zlib: { level: 9 },
  comment: "testtest"
});

output.on("close", function() {
  console.log(archive.pointer() + " total bytes");
  console.log(
    "archiver has been finalized and the output file descriptor has closed."
  );
});

archive.on("warning", function(err) {
  console.log(err);
});

// good practice to catch this error explicitly
archive.on("error", function(err) {
  console.log(err);
});

archive.pipe(output);

// 追加一个文件流
archive.append(fs.createReadStream(__dirname + "/sourceFiles/1.txt"), { name: "file1.txt" });

// 追加一个string
archive.append("string cheese!", { name: "file2.txt" });

// 追加一个buffer
var buffer = Buffer.from("buff it!");
archive.append(buffer, { name: "file3.txt" });

// 追加一个现有文件
archive.file("sourceFiles/1.txt", { name: "file4.txt" });

// 追加一个目录（子目录也会被增加）
archive.directory("sourceFiles/", "new-subdir");

// 追加一个目录——类似于直接复制
archive.directory("sourceFiles/");

// 将目标目录中的文件追加至根目录
archive.directory("sourceFiles/", false);

// 新增空文件夹
archive.append('', { name: "empty-dir/" });

// append files from a glob pattern
archive.glob("*.js");

archive.finalize();
