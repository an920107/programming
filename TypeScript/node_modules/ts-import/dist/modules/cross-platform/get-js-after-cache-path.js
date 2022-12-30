"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getJsAfterCachePath = void 0;
const getJsAfterCachePath = (tsPath) => {
    let jsAfterCachePath = tsPath;
    if (process.platform === `win32`) {
        jsAfterCachePath = tsPath.split(`:`)[1];
    }
    return jsAfterCachePath;
};
exports.getJsAfterCachePath = getJsAfterCachePath;
//# sourceMappingURL=get-js-after-cache-path.js.map