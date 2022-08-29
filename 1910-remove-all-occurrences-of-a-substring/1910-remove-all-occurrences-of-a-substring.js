/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
var removeOccurrences = function(s, part) {
    let lenS=s.length;
    let lenP=part.length;
    while(s.includes(part)){
        let pos = s.indexOf(part);
        s = s.slice(0,pos) + s.slice(pos+lenP);
    }
    return s;
};