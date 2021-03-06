const { printTitle, printRed, printGreen, printBasic } = require("./utility");

let parserCount = {
  passed: 0,
  failed: 0,
  maps: []
};
let leaksCount = {
  passed: 0,
  failed: 0,
  maps: []
};

const makeReport = () => {

  printTitle("REPORT", "\n\n");
  printBasic(`PARSER : ${parserCount.passed}/${parserCount.passed + parserCount.failed}`);
  printBasic(`LEAKS  : ${leaksCount.passed}/${leaksCount.passed + leaksCount.failed}`);

  for ([index, mapFailed] of parserCount.maps.entries()) {
    if (!index) printBasic(`PARSER FAILED MAP : `, "\n", `\tπ ${mapFailed}`);
    else printBasic(mapFailed, "\t\t\tπ");
  }

  for ([index, mapFailed] of leaksCount.maps.entries()) {
    if (!index) printBasic(`LEAKS FAILED MAP : `, "\n", `\tπ ${mapFailed}`);
    else printBasic(mapFailed, "\t\t\tπ");
  }

  if (!parserCount.failed && !leaksCount.failed) printGreen("βΊοΈ NICE JOB βΊοΈ", "\nCONCLUSION : ");
  else printRed("π© Your cub3D is poop π©", "\nCONCLUSION : ");
};

module.exports = {
  makeReport,
  parserCount,
  leaksCount,
};
