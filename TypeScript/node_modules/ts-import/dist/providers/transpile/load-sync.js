"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.loadSync = void 0;
const compiler = require("../../modules/compiler");
const loadSync = (options) => {
    return compiler.transpileSync(options);
};
exports.loadSync = loadSync;
//# sourceMappingURL=load-sync.js.map