module.exports = {
  //param A : integer
  //param B : array of array of integers
  //param C : integer
  //return an integer
  solve: function (A, B, C) {
    var tTree = {};
    var ret = 0;
    //B.sort(comp1);
    for (var i = A - 2; i >= 0; i--) {
      var p = B[i][0],
        c = B[i][1],
      if (tTree[c] == null) {
        tTree[c] = 0;
      }
      if (tTree[p] == null) tTree[p] = tTree[c] + 1;
      else tTree[p] += tTree[c] + 1;
    }
    for (var i = 0; i < A - 1; i++) {
      B[i][2] = B[i][2] * (tTree[B[i][1]] + 1);
    }
    function comp2(a, b) {
      if (a[2] > b[2]) return 1;
      if (a[2] < b[2]) return -1;
      else return 0;
    }
    B.sort(comp2);
    for (var i = 0; i < A - 1 && (i < A - 1 - C || B[i][2] < 0); i++)
      ret += B[i][2];

    if (ret < 0) return 1000000007 - ((ret * -1) % 1000000007);
    else return ret % 1000000007;
  },
};
