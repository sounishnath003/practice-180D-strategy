module.exports = {
  //param A : array of integers
  //param B : array of integers
  //param C : array of array of integers
  //return an integer
  solve: function (A, B, C) {
    C.unshift([0, 1]);
    var total = 0;
    var n = 0;

    for (var i = 0; i < C.length; i++) {
      //C[i].push(A[C[i][1] - 1]);
      //C[i].push(B[C[i][1] - 1]);
      total += A[C[i][1] - 1];
    }

    while (total > 0) {
      n++;
      for (var i = 0; i < C.length; i++) {
        var fruit = A[C[i][1] - 1];
        if (fruit > 0) {
          A[C[i][1] - 1]--;
          if (i == 0) {
            total--;
          } else {
            if (B[C[i][0] - 1] <= A[C[i][0] - 1]) total--;
            else A[C[i][0] - 1]++;
          }
        }
      }
    }
    return n;
  },
};
