/// <reference path="../index.d.ts" />

let winmgr;

(function main() {
    try {
        const { platform } = process;
        winmgr = require(`../build/Release/rinku_mousemgr_${platform}.node`);
    } catch (err) {
        console.log("[rinku-mousemgr] Unsupported platform! All primary functions won't work!");
    }
})();

function moveMouse(x: number, y: number): void {
    winmgr.moveMouse(x, y);
}

export { moveMouse };