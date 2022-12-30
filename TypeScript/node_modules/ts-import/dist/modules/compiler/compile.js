"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.compile = void 0;
const tsc = require("typescript");
const compile = (options) => {
    const program = tsc.createProgram({
        rootNames: [options.tsPath],
        options: options.compilerOptions,
    });
    program.emit();
};
exports.compile = compile;
//# sourceMappingURL=compile.js.map