"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.isFileNewer = void 0;
const isFileNewer = (file1, file2) => {
    return file1.mtimeMs > file2.mtimeMs;
};
exports.isFileNewer = isFileNewer;
//# sourceMappingURL=is-file-newer.js.map