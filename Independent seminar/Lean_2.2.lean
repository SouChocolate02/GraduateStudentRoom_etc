/--自前で実装した自然数-/
inductive MyNat where
  /--ゼロ-/
  | zero
  /--後者関数(nに対してn+1を返す関数)-/
  | succ(n: MyNat)

  #check MyNat.zero
  #check MyNat.succ
