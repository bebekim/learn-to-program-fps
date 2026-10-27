import assert from 'node:assert/strict';
import { execFileSync } from 'node:child_process';
import { mkdtempSync, readFileSync, readdirSync, existsSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const root = dirname(fileURLToPath(import.meta.url));
const output = mkdtempSync(join(tmpdir(), 'nathan-lessons-'));
const compiler = process.env.CXX || 'c++';
const folders = readdirSync(root, { withFileTypes: true })
    .filter(entry => entry.isDirectory() && /^\d\d-/.test(entry.name))
    .map(entry => entry.name)
    .filter(name => existsSync(join(root, name, 'starter.cpp'))).sort();
assert.equal(folders.length, 24);
const binaries = new Map();
let checks = 0;
function check(condition, message) {
    assert.ok(condition, message);
    checks += 1;
}
function run(n, kind, input = '') {
    return execFileSync(binaries.get(`${n}-${kind}`), [], {
        input, encoding: 'utf8', timeout: 3000, maxBuffer: 1024 * 1024,
    }).replaceAll('\r\n', '\n');
}

// Lesson 00 has one supplied greeting rather than a starter/target pair.
const greeting = join(output, '00-hello');
execFileSync(compiler, ['-std=c++17', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
    join(root, '00-compile-and-run', 'hello.cpp'), '-o', greeting], { timeout: 30000 });
check(execFileSync(greeting, [], { encoding: 'utf8', timeout: 3000 })
    .replaceAll('\r\n', '\n') === 'Hello, maze explorer!\n', '00: build and run greeting');
console.log('Compiled and ran 00-compile-and-run: hello.cpp');

for (const folder of folders) {
    const n = Number(folder.slice(0, 2));
    const notes = readFileSync(join(root, folder, 'LESSON.md'), 'utf8');
    check(notes.length > 2000, `${folder}: substantive lesson content`);
    for (const match of notes.matchAll(/\]\(([^)]+)\)/g)) {
        if (!match[1].includes(':')) {
            check(existsSync(resolve(root, folder, match[1])), `${folder}: ${match[1]}`);
        }
    }
    for (const kind of ['starter', 'target']) {
        const binary = join(output, `${n}-${kind}`);
        execFileSync(compiler, ['-std=c++17', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
            join(root, folder, `${kind}.cpp`), '-o', binary], { timeout: 30000 });
        binaries.set(`${n}-${kind}`, binary);
        run(n, kind); // All checkpoints must exit safely even at immediate EOF.
    }
    console.log(`Compiled and ran ${folder}: starter + target`);
}

check(run(1, 'target') === 'The Hidden Maze\nMy first game program.\n', '01: rebuilt message');
check(run(2, 'target') === "Nathan's Maze\n#####\n#...#\n#####\n", '02: sequence');
check(run(3, 'target') === 'Health: 8\nRemembered health: 8\n', '03: shared value');
check(run(4, 'target') === 'Before: 0\nAfter: 2\nAfter another move: 3\n', '04: state trace');
check(run(5, 'target', 'd\n').endsWith('You typed: d\n'), '05: input');
for (const [input, response] of [['w', 'Walk'], ['q', 'Quit'], ['x', 'Use w to walk or q to quit']]) {
    check(run(6, 'target', input).endsWith(`${response}\n`), `06: ${input} branch`);
}
const loop = run(7, 'target', 'w\nx\nq\n');
check((loop.match(/w = walk, q = quit:/g) || []).length === 3, '07: three prompts');
check(loop.endsWith('Goodbye\n'), '07: termination');
check(run(8, 'target', 'd\nd\ns\na\nw\nq\n').endsWith('Position: 2, 1\n'), '08: route');
check(run(9, 'target') === 'Cell: .\nRows: 4\nColumns: 7\n', '09: row/column lookup');
check(run(10, 'target').includes('#.P...#\n'), '10: display overlay');
check(run(10, 'target').endsWith('Stored cell under P: .\n'), '10: drawing preserves model');
check(run(11, 'starter').includes('(7,1): true'), '11: intentional off-by-one demonstrated');
check(run(11, 'target') === '(0,0): true\n(6,3): true\n(7,1): false\n(-1,1): false\n', '11: bounds repaired');
check(run(12, 'target', 'w\nd\nd\ns\nq\n').includes('Position: 2, 2; moves: 2'), '12: blocked and accepted moves');
const win = 'd\ns\nd\nd\nw\n';
const bypass = 's\ns\nd\nd\nd\nw\nw\nq\n';
const start13 = run(13, 'starter', `${win}r\nq\n`);
const target13 = run(13, 'target', `${win}r\nq\n`);
check(start13.includes('Key: 1; won: 0; moves: 0'), '13: intentional reset fault reproduced');
check(target13.includes('You escaped'), '13: winning route');
check(target13.endsWith('Key: 0; won: 0; moves: 0\n'), '13: full reset');
check(run(13, 'target', bypass).includes('Need key'), '13: locked exit reachable without collecting key');
check(run(13, 'target', bypass).endsWith('Key: 0; won: 0; moves: 6\n'), '13: rejected exit does not count as a move');
const trace = `${win}d\nr\nx\nw\nq\n`;
function statuses(s) { return s.split('\n').filter(line => line.startsWith('Key: ')); }
assert.deepEqual(statuses(run(13, 'target', trace)), statuses(run(14, 'target', trace)));
checks += 1;
for (const [n, expected] of [[15, 'One second: 4\nTen short updates: 4\n'],
    [16, 'Direction: 1.000, 0.000\nAfter 2 units from (1,1): 3.000, 1.000\n'],
    [17, 'Wall: 1; distance: 4.5; samples: 37\n']]) {
    check(run(n, 'target') === expected, `${n}: arithmetic example`);
}
check(run(18, 'target').split('\n').filter(row => row === '#').length === 2, '18: two projected wall rows');
const image = run(19, 'target').trimEnd().split('\n');
check(image.length === 12 && image.every(row => row.length === 31), '19: frame dimensions');
check(run(19, 'starter') !== run(19, 'target'), '19: FOV edit is visible');
check(run(20, 'target') === 'Failures: 0\n', '20: explicit geometry checks');
check(run(21, 'target') === 'Sample: L\nEdge: P\n', '21: texture lookup and edge policy');
check(run(22, 'target') === 'Object: 2, 1\nObject: 2, 1\nObject: 4, 2\n', '22: shared updates');
check(run(23, 'starter') === 'Before cleanup: 1\nAfter cleanup: 0\n', '23: substeps detect intervening wall');
check(run(23, 'target') === 'Before cleanup: 1\nAfter cleanup: 1\n', '23: stationary live shot survives');
check(run(24, 'starter') === '#A###\n', '24: hidden object');
check(run(24, 'target') === '#A#B#\n', '24: nearer object visible');
console.log(`Passed: 49 builds/runs, ${checks} content/link/behaviour checks.`);
console.log('Scope: portable teaching checkpoints only; Windows/Geany and engine integration were not tested.');
